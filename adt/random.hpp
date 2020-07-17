//
//  random.hpp
//  algorithms
//
//  Created by 云心逸 on 2019/1/10.
//  Copyright © 2019 云心逸. All rights reserved.
//

#ifndef random_h
#define random_h

#include <random>
#include <string>

namespace r {

template<typename RandomNumberEngine>
class random_string_generator {
	const std::string m_alphabet;
	RandomNumberEngine m_engine;
	std::uniform_int_distribution<size_t> m_string_length_distribution;
	std::uniform_int_distribution<size_t> m_alphabet_distribution;
public:
	random_string_generator(const std::string& alphabet, size_t min_length, size_t max_length)
	    : m_alphabet(alphabet),
	m_string_length_distribution(min_length, max_length),
	m_alphabet_distribution(0, m_alphabet.length()-1) {}
	random_string_generator(const std::string& alphabet, size_t length)
	    : random_string_generator(alphabet, length, length) {}
	random_string_generator() : random_string_generator("abcdefghijklmnopqrstuvwxyz", 1, 20) {}

	std::string operator()() {
		size_t len = static_cast<size_t>(m_string_length_distribution(m_engine));
		std::string s;
		while (len-- > 0)
			s += m_alphabet[m_alphabet_distribution(m_engine)];
		return s;
	}
};

	template <typename T>
	class random_number_generator {
		std::mt19937_64 m_engine;
		std::uniform_int_distribution<T> m_distribution;
	public:
		random_number_generator(T min_, T max_) : m_engine(), m_distribution(min_, max_) {}
		T operator()() {
			return m_distribution(m_engine);
		}
	};

}

#endif /* random_h */
