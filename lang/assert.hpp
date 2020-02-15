//
//  assert.hpp
//  lang
//
//  Created by Max Zhang on 2020/2/15.
//

#ifndef assert_hpp
#define assert_hpp

//#include <cstdlib>

#include <cstdio>
#include <experimental/memory_resource>
namespace m {

//[[noreturn]]
void require(const char* expr, const char* msg, const char* file, unsigned int lino, const char* func) {
    printf("<%s:%u> %s: %s (%s)", file, lino, func, msg, expr);
//    ::abort();
}

#define verify(expr, msg) \
    ((expr) ? static_cast<void>(0) : m::require(#expr, msg, __FILE__, __LINE__, __PRETTY_FUNCTION__))
}

#endif /* assert_hpp */
