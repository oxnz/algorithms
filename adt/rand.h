/*
 * Filename:	rand.h
 *
 * Author:		Oxnz
 * Email:		yunxinyi@gmail.com
 * Created:		[2020-02-19 02:39:30 CST]
 * Last-update:	2020-02-19 02:39:30 CST
 * Description: anchor
 *
 * Version:		0.0.1
 * Revision:	[NONE]
 * Revision history:	[NONE]
 * Date Author Remarks:	[NONE]
 *
 * License: 
 * Copyright (c) 2013 Oxnz
 *
 * Distributed under terms of the [LICENSE] license.
 * [license]
 *
 */

#ifndef _RAND_H_
#define _RAND_H_

#include <random>
#include <sstream>
#include <string>

namespace m {

template <typename T>
struct random_generator {
    T operator()();
};

template <typename Engine=std::mt19937, typename Distribution=std::uniform_int_distribution<int>>
class randint_generator {
public:
    randint_generator(int min, int max) : m_engine(m_device()), m_dist(min, max) {}
    int operator()() { return m_dist(m_engine); }

private:
    std::random_device m_device{};
    Engine m_engine;
    Distribution m_dist;
};

template<typename Engine = std::mt19937,
         typename AlphabetDistribution = std::uniform_int_distribution<int>,
         typename LengthDistribution = std::uniform_int_distribution<int>>
class randstr_generator {
    std::random_device m_device{};
    Engine m_engine;
    const std::string m_alphabet;
    AlphabetDistribution m_alphabet_dist;
    LengthDistribution m_len_dist;

public:
    randstr_generator(const std::string& alphabet, size_t length) : randstr_generator(alphabet, length, length) {}
    randstr_generator(const std::string &alphabet, size_t min_length, size_t max_length)
        : m_engine(m_device()), m_alphabet(alphabet), m_alphabet_dist(0, alphabet.empty() ? 0 : alphabet.length()-1), m_len_dist(min_length, max_length)
    {}
    std::string operator()() {
        std::string s(m_len_dist(m_engine), ' ');
        for (int i = 0; i < s.length(); ++i)
            s[i] = m_alphabet[m_alphabet_dist(m_engine)];
        return s;
    }
};
}

#endif//_RAND_H_


