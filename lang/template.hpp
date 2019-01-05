//
//  template.hpp
//  Interview
//
//  Created by 云心逸 on 2019/1/1.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#ifndef template_hpp
#define template_hpp

#include <iostream>
#include <string>
#include <sstream>

template <typename Fn, typename... Args>
void for_each_argument(Fn&& f, Args&&... args) {
	return (void)std::initializer_list<int>{(std::forward<Fn>(f)(args), 0)...};
}

template<size_t n>
struct fibonacci {
	enum { value = fibonacci<n-1>::value + fibonacci<n-2>::value };
};

template<> // specialization
struct fibonacci<0> {
	enum { value = 1 };
};

template<>
struct fibonacci<1> {
	enum { value = 1 };
};

constexpr size_t fib(size_t n) { // constexpr function
	return n < 2 ? 1 : fib(n - 1) + fib(n - 2);
}

template <typename T>
struct is_pointer_type : std::false_type {};

template <typename T>
struct is_pointer_type<T*> : std::true_type {};

template <typename T>
constexpr bool is_pointer_type_v = is_pointer_type<T>::value;

//constexpr
size_t fib_it(size_t n) { // iterative
	if (n < 2) return 1;
	auto prev(1), curr(1);
	for (; n > 1; --n) {
		std::swap(prev, curr);
		curr += prev;
	}
	return curr;
}

namespace templated {
	template <typename T>
	struct make_ptr {
		using type = T *;
	};
	
	template <typename T>
	struct make_ptr<T *> {
		using type = T *;
	};
}

template <typename T>
struct pointer {
	using type = T;
};

template <typename T>
auto make_ptr(pointer<T>) {
	if constexpr (std::is_pointer_v<T>) {
		return pointer<T>{};
	} else {
		return pointer<T *>{};
	}
}

namespace variadic {
	template <typename Array>
	constexpr auto _reverse(Array arr) {
		Array reversed{};
		auto begin = arr.rbegin();
		for (auto& a : reversed)
			a = *begin++;
		return reversed;
	}
	
	template <bool FIN, size_t... n>
	struct fibonacci;
	
	template <size_t... n>
	struct fibonacci<true, n...> {
		static constexpr std::array<size_t, sizeof...(n)> sequence = _reverse(std::array<size_t, sizeof...(n)>{n...});
	};
	
	template <size_t prev, size_t curr, size_t... n>
	struct fibonacci<false, prev, curr, n...> : fibonacci<std::numeric_limits<size_t>::max() - curr - prev<curr, prev+curr, curr, prev, n...>
	{};
}
	
namespace SFINAE {
	template <bool, typename T=void>
	struct enable_type_if{};
	
	template <typename T>
	struct enable_type_if<true, T> { typedef T type; };
	
	template <bool cond, typename T>
	using enable_type_if_t = typename enable_type_if<cond, T>::type;
}

// curiously recurring template pattern (CRTP)/F-bound polymorphism

template<typename T>
struct shape {
	const std::string render() {
		return static_cast<T*>(this)->_render();
	}
	static const std::string name() {
		return T::_name();
	}
};

struct circle : shape<circle> {
	const std::string _render() { return "circle"; }
	static const std::string _name() { return "circle"; }
};

struct square : shape<square> {
	const std::string _render() { return "square"; }
	static const std::string _name() { return "square"; }
};

#endif /* template_hpp */
