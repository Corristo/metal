#include <metal.hpp>

#include "test.hpp"

#define MATRIX(M, N) \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) VALUES(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) VALUES(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) NUMBERS(N)>), (BOOL(M || N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) PAIRS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) LISTS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) MAPS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) NUMBERS(M) COMMA(N) LAMBDAS(N)>), (BOOL(M && !N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) PAIRS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LISTS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) MAPS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) VALUES(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) NUMBERS(N)>), (BOOL(!M && N))); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) PAIRS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) LISTS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) MAPS(N)>), (FALSE)); \
    CHECK((metal::is_invocable<metal::lambda<metal::min> COMMA(M) LAMBDAS(M) COMMA(N) LAMBDAS(N)>), (FALSE)); \
    CHECK((metal::min<NUMBER(M) COMMA(N) NUMBERS(N)>), (NUMBER(IF(N)(0, M)))); \
/**/

GEN(MATRIX)
