//
//  misc.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/19.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef misc_hpp
#define misc_hpp

#include <iostream>
#include <tuple>

template <size_t index, size_t count, typename... Args>
struct _print_tuple {
	static void print(std::ostream& os, const std::tuple<Args...>& t) {
		os << std::get<index>(t) << (index+1 == count ? "" : ",");
		_print_tuple<index+1, count, Args...>::print(os, t);
	}
};

template <size_t count, typename... Args>
struct _print_tuple<count, count, Args...> {
	static void print(std::ostream&, const std::tuple<Args...>&) {}
};

template <typename... Args>
std::ostream& operator<<(std::ostream& os, const std::tuple<Args...>& t) {
	os << "[";
	_print_tuple<0, sizeof... (Args), Args...>::print(os, t);
	return os << "]";
}

#endif /* misc_hpp */
