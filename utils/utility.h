//
//  utility.hpp
//  Interview
//
//  Created by 云心逸 on 2018/12/31.
//  Copyright © 2018 Errpro,Inc. All rights reserved.
//

#ifndef utility_hpp
#define utility_hpp

#include <type_traits>

template<typename T, typename U>
struct _is_same_type : std::false_type {};

template<typename T>
struct _is_same_type<T, T> : std::true_type {};

template<typename T, typename U>
bool is_same_type() {
	return _is_same_type<T, U>::value;
}

#endif /* utility_hpp */
