/*
 * This file is part of mpl2, a free software.
 * Use, modification and distribution is subject to the BSD 2-clause license.
 * See accompanying file LICENSE for its full text.
 */

#ifndef _BOOST_MPL2_COMPAT_VARIADIC_HPP_
#define _BOOST_MPL2_COMPAT_VARIADIC_HPP_

#include <boost/mpl2/config/options/variadic_templates.hpp>
#include <boost/mpl2/compat/numbered.hpp>

#if defined(BOOST_MPL2_CFG_NO_VARIADIC_TEMPLATES)
    #define __BOOST_MPL2_FOR_EACH_VARIADIC_ARG(N, PREFIX, MACRO, DATA) \
            __BOOST_MPL2_FOR_EACH_ARG(N, PREFIX, MACRO, DATA)

    #define BOOST_MPL2_VARIADIC_ARGS(N, PREFIX) \
            BOOST_MPL2_ARGS(N, PREFIX)

    #define BOOST_MPL2_VARIADIC_PARAMS(N, PREFIX) \
            BOOST_MPL2_PARAMS(N, PREFIX)

    #define BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(N, PREFIX) \
            BOOST_MPL2_OPTIONAL_PARAMS(N, PREFIX)
#else
    #include <boost/preprocessor/if.hpp>
    #include <boost/preprocessor/expr_if.hpp>
    #include <boost/preprocessor/expand.hpp>
    #include <boost/preprocessor/identity.hpp>
    #include <boost/preprocessor/tuple/eat.hpp>

    #define __BOOST_MPL2_FOR_EACH_VARIADIC_ARG(N, PREFIX, MACRO, DATA) \
            BOOST_PP_IF(N, BOOST_PP_EXPAND, BOOST_PP_TUPLE_EAT(1))(MACRO BOOST_PP_IDENTITY((DATA, PREFIX))()...)

    #define BOOST_MPL2_VARIADIC_ARGS(N, PREFIX) \
            BOOST_PP_EXPR_IF(N, PREFIX...)

    #define BOOST_MPL2_VARIADIC_PARAMS(N, PREFIX) \
            BOOST_PP_EXPR_IF(N, typename... PREFIX)

    #define BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(N, PREFIX) \
            BOOST_MPL2_VARIADIC_PARAMS(N, PREFIX)
#endif

// CALL FOR EACH
#define BOOST_MPL2_CALL_FOR_EACH_VARIADIC_ARG(N, PREFIX, FUNC) \
    __BOOST_MPL2_FOR_EACH_VARIADIC_ARG(N, PREFIX, __BOOST_MPL2_CALL_FOR_ARG, FUNC)

#define BOOST_MPL2_CALL_FOR_EACH_LEADING_VARIADIC_ARG(N, PREFIX, FUNC) \
    BOOST_MPL2_CALL_FOR_EACH_VARIADIC_ARG(N, PREFIX, FUNC) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_CALL_FOR_EACH_TRAILING_VARIADIC_ARG(N, PREFIX, FUNC) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_CALL_FOR_EACH_VARIADIC_ARG(N, PREFIX, FUNC)

// WRAP EACH
#define BOOST_MPL2_WRAP_EACH_VARIADIC_ARG(N, PREFIX, WRAP) \
    __BOOST_MPL2_FOR_EACH_VARIADIC_ARG(N, PREFIX, __BOOST_MPL2_WRAP_ARG, WRAP)

#define BOOST_MPL2_WRAP_EACH_LEADING_VARIADIC_ARG(N, PREFIX, WRAP) \
    BOOST_MPL2_WRAP_EACH_VARIADIC_ARG(N, PREFIX, WRAP) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_WRAP_EACH_TRAILING_VARIADIC_ARG(N, PREFIX, WRAP) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_WRAP_EACH_VARIADIC_ARG(N, PREFIX, WRAP)

// ARGS
#define BOOST_MPL2_LEADING_VARIADIC_ARGS(N, PREFIX) \
    BOOST_MPL2_VARIADIC_ARGS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_VARIADIC_ARGS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_VARIADIC_ARGS(N, PREFIX)

// PARAMS
#define BOOST_MPL2_LEADING_VARIADIC_PARAMS(N, PREFIX) \
    BOOST_MPL2_VARIADIC_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_VARIADIC_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_VARIADIC_PARAMS(N, PREFIX)

// OPTIONAL PARAMS
#define BOOST_MPL2_LEADING_VARIADIC_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(N, PREFIX) BOOST_PP_COMMA_IF(N)

#define BOOST_MPL2_TRAILING_VARIADIC_OPTIONAL_PARAMS(N, PREFIX) \
    BOOST_PP_COMMA_IF(N) BOOST_MPL2_VARIADIC_OPTIONAL_PARAMS(N, PREFIX)

#endif