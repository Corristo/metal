// Copyright Bruno Dutra 2015-2016
// Distributed under the Boost Software License, Version 1.0.
// See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt

#include <metal/lambda/lambda.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    ASSERT((metal::is_lambda<VAL(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<NUM(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<VECT(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<PAIR(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<LIST(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<MAP(N)>), (FALSE)); \
    ASSERT((metal::is_lambda<LBD(N)>), (TRUE)); \
    ASSERT((metal::is_lambda<LBD(_)>), (TRUE)); \
    ASSERT((metal::is_lambda<test::lambda<metal::is_lambda>>), (TRUE)); \
    ASSERT((metal::is_lambda<metal::lambda<metal::is_lambda>>), (TRUE)); \
/**/

GEN(MATRIX)
