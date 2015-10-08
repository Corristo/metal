// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef METAL_LAMBDA_INVOKE_HPP
#define METAL_LAMBDA_INVOKE_HPP

namespace metal
{
    /// \ingroup lambda
    /// \brief ...
    template<typename...>
    struct invoke
    {};

    /// \ingroup lambda
    /// \brief Eager adaptor for \ref invoke.
    template<typename... args>
    using invoke_t = typename invoke<args...>::type;
}

#include <metal/lambda/arg.hpp>
#include <metal/lambda/defer.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/lift.hpp>
#include <metal/list/at.hpp>
#include <metal/number/number.hpp>
#include <metal/optional/eval.hpp>

namespace metal
{
    template<template<typename...> class expr, typename... args>
    struct invoke<lambda<expr>, args...> :
        defer<lift_t<lambda<eval>>, defer<lambda<expr>, args...>>
    {};

    template<
        template<typename...> class expr,
        typename... params,
        typename... args
    >
    struct invoke<expr<params...>, args...> :
        invoke<lift_t<lambda<expr>>, invoke<params, args...>...>
    {};

    template<typename val, typename... args>
    struct invoke<val, args...>
    {
        using type = val;
    };

    template<std::size_t n, typename... args>
    struct invoke<arg<n>, args...> :
        at<invoke<arg<n>, args...>, number<std::size_t, n>>
    {};

    template<typename x, typename y, typename... tail>
    struct invoke<arg<2U>, x, y, tail...>
    {
        using type = y;
    };

    template<typename x, typename... tail>
    struct invoke<arg<1U>, x, tail...>
    {
        using type = x;
    };

    template<typename... args>
    struct invoke<arg<0U>, args...>
    {};
}

#endif
