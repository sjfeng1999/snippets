#pragma once

/***************************************************
 * Definition
***************************************************/

#define MACRO_CONCAT(A, B)                                          MACRO_CONCAT_IMPL(A, B)
#define MACRO_REMOVE_PARENS(value)                                  MACRO_REMOVE_PARENS_IMPL value
#define MACRO_TUPLE_SIZE(tuple)                                     MACRO_TUPLE_SIZE_IMPL(tuple)
#define MACRO_TUPLE_GET(N, tuple)                                   MACRO_TUPLE_GET_IMPL(N, MACRO_REMOVE_PARENS(tuple))

#define MACRO_COND_IF(pred, cond1, cond2)                           cond1

/***************************************************
 * Implementation
***************************************************/

#define MACRO_CONCAT_IMPL(A, B)                                     A ## B
#define MACRO_REMOVE_PARENS_IMPL(...)                               __VA_ARGS__

#define MACRO_TUPLE_GET_IMPL(N, ...)                                MACRO_CONCAT(MACRO_TUPLE_GET_IMPL_, N)(__VA_ARGS__)
#define MACRO_TUPLE_GET_IMPL_0(_0, ...)                             _0
#define MACRO_TUPLE_GET_IMPL_1(_0, _1, ...)                         _1
#define MACRO_TUPLE_GET_IMPL_2(_0, _1, _2, ...)                     _2
#define MACRO_TUPLE_GET_IMPL_3(_0, _1, _2, _3, ...)                 _3
#define MACRO_TUPLE_GET_IMPL_4(_0, _1, _2, _3, _4,...)              _4
#define MACRO_TUPLE_GET_IMPL_5(_0, _1, _2, _3, _4, _5, ...)         _5
