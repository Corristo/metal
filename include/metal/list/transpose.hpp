// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#ifndef METAL_LIST_TRANSPOSE_HPP
#define METAL_LIST_TRANSPOSE_HPP

#include <metal/config.hpp>

#include <metal/list/list.hpp>
#include <metal/list/transform.hpp>
#include <metal/lambda/partial.hpp>
#include <metal/lambda/lambda.hpp>
#include <metal/lambda/apply.hpp>

namespace metal
{
    /// \ingroup list
    ///
    /// ### Description
    /// ...
    template<typename seq>
    using transpose = metal::apply<
        metal::partial<
            metal::lambda<metal::transform>,
            metal::lambda<metal::list>
        >,
        seq
    >;
}

#endif
