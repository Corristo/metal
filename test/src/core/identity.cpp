/// @copyright Bruno Dutra 2015
/// Distributed under the Boost Software License, Version 1.0.
/// (See accompanying file LICENSE.txt or copy at http://boost.org/LICENSE_1_0.txt)

#include <metal/core/identity.hpp>

#include "test/main.hpp"

using namespace metal;

METAL_ASSERT((std::is_same<identity<void>::type, void>));