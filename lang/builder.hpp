//
//  builder.hpp
//  lang
//
//  Created by Max Zhang on 2020/2/15.
//

#ifndef builder_hpp
#define builder_hpp

#include <memory>

template <typename T>
class builder {
    builder();
    builder(const T&);
    T build();
};

#endif /* builder_hpp */
