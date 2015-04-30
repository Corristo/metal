// Copyright Bruno Dutra 2015
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#ifndef BOOST_MPL2_LAMBDA_INVOKE_HPP
#define BOOST_MPL2_LAMBDA_INVOKE_HPP

#include <boost/mpl2/lambda/logical/and.hpp>
#include <boost/mpl2/lambda/pack.hpp>
#include <boost/mpl2/lambda/eval.hpp>
#include <boost/mpl2/lambda/traits.hpp>

namespace boost
{
    namespace mpl2
    {
        template<typename... args>
        struct invoke :
                eval<head<args...>::type::template call, tail<args...> >
        {};

        template<typename function, typename... args>
        struct is_invocable :
                and_<
                    is_function<function>,
                    is_evaluable<invoke, function, args...>
                >
        {};
    }
}

#endif