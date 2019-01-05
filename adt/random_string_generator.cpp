/*
 * Filename:	random_string_generator.cpp
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		2018-12-25 17:54:35 CST
 * Last-update:	2018-12-25 17:54:35 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License:
 * Copyright (c) 2018 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#include <iostream>
#include <random>

using namespace std;

template<typename ForwardIterator>
void echo(ForwardIterator first, ForwardIterator last) {
	copy(first, last, ostream_iterator<typename iterator_traits<ForwardIterator>::value_type>(cout, ", "));
	cout << "\n";
}

template<typename Container>
void echo(Container container) {
	echo(container.begin(), container.end());
}

template<typename RandomNumberEngine,
typename StringLengthDistribution,
typename AlphabetDistribution>
class RandomStringGenerator {
	const string m_alphabet;
	RandomNumberEngine m_engine;
	StringLengthDistribution m_string_length_distribution;
	AlphabetDistribution m_alphabet_distribution;
public:
	RandomStringGenerator(const string& alphabet, size_t length) : RandomStringGenerator(alphabet, length, length) {}
	RandomStringGenerator(const string& alphabet,
						  size_t min_length, size_t max_length) :
	m_alphabet(alphabet),
	m_string_length_distribution(min_length, max_length),
	m_alphabet_distribution(0, m_alphabet.length()-1)
	{}
	string operator()() {
		string s;
		for (size_t i = 0; i < static_cast<size_t>(m_string_length_distribution(m_engine)); ++i) {
			s += m_alphabet[m_alphabet_distribution(m_engine)];
		}
		return s;
	}
};

#include <gtest/gtest.h>
TEST(RandomStringGenerator, RandomStringGenerator) {
    vector<string> v(1<<3);
	generate(v.begin(), v.end(), RandomStringGenerator<mt19937_64, normal_distribution<double>, uniform_int_distribution<size_t>>("abcdefghijklmnopqrstuvwxyz", 26));
	EXPECT_EQ(v.size(), 1<<3);
}
