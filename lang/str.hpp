//
//  str.hpp
//  Interview
//
//  Created by 云心逸 on 2018/12/31.
//  Copyright © 2018 Errpro,Inc. All rights reserved.
//

#ifndef str_h
#define str_h

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

class str {
public:
    enum case_sensitivity : bool { case_sensitive, case_insensitive };
    using size_type = size_t;
    using value_type = char;
public:
    str(const char* p, size_type n) : m_size(n), m_capacity(n), m_data(new value_type[m_capacity]) {
        std::copy(p, p+m_size, m_data.get());
    }
    str(const char* p = "") : str(p, strlen(p)) {}
    str(const str& rhs) : str(rhs.m_data.get(), rhs.m_size) {}
    str(str&& rhs) noexcept : m_size(0), m_capacity(0), m_data(nullptr) { // transfer ownership
        swap(rhs);
    }
    ~str() {} // destructor prevents implicit move assignment
public: // api
    void swap(str& rhs) noexcept {
        std::swap(m_size, rhs.m_size);
        std::swap(m_capacity, rhs.m_capacity);
        std::swap(m_data, rhs.m_data);
    }
    str& operator=(const str& rhs) {
        if (&rhs == this) return *this; // check for self-assignment
        if (m_size != rhs.m_size) { // reuse storage when possible
            m_data.reset(new char[rhs.m_size]);
            m_size = rhs.m_size;
        }
        std::copy(rhs.m_data.get(), rhs.m_data.get() + m_size, m_data.get());
        return *this;
    } // note: copy-and-swap would always cause a reallocation
    str& operator=(str&& rhs) noexcept {
        swap(rhs);
        return *this;
    }
    /*
     str& operator=(str rhs) noexcept { // copy-and-swap form assignment
     swap(rhs);
     return *this;
     }
     */
    size_type size() const { return m_size; }
    size_type capacity() const { return m_capacity; }

    str& append(const str& rhs) {
        if (m_capacity < m_size + rhs.m_size) {
            std::unique_ptr<value_type[]> data{new value_type[m_size+rhs.m_size]};
            std::copy(m_data.get(), m_data.get()+m_size, data.get());
            std::swap(m_data, data);
            m_capacity = m_size + rhs.m_size;
        }
        std::copy(rhs.m_data.get(), rhs.m_data.get()+rhs.m_size, m_data.get()+m_size);
        m_size += rhs.m_size;
        return *this;
    }
    str operator+(const str& rhs) {
        str s(*this);
        s.append(rhs);
        return s;
    }
    str& operator+=(const str& rhs) { return append(rhs); }

public: // test
    bool empty() const { return m_size == 0; }
    bool is_lower() const {
        return std::all_of(m_data.get(), m_data.get()+m_size, [](const char& ch) { return islower(ch); });
    }
    bool is_upper() const {
        return std::all_of(m_data.get(), m_data.get()+m_size, [](const char& ch) { return isupper(ch); });
    }

public: // comparison

    int compare(const str& rhs, case_sensitivity cs = case_sensitive) const {
        if (m_size < rhs.m_size) return -1;
        else if (m_size > rhs.m_size) return 1;
        else {
            for (size_t i = 0; i < m_size; ++i) {
                if (m_data[i] != rhs.m_data[i] or
                        (cs == case_insensitive and tolower(m_data[i]) != tolower(rhs.m_data[i])))
                    return cs == case_sensitive ?
                                m_data[i] - rhs.m_data[i] : tolower(m_data[i] - tolower(rhs.m_data[i]));
            }
        }
        return 0;
    }
    bool operator<(const str& rhs) const { return compare(rhs) < 0; }
    bool operator<=(const str& rhs) const { return compare(rhs) <= 0; }
    bool operator>(const str& rhs) const { return compare(rhs) > 0; }
    bool operator>=(const str& rhs) const { return compare(rhs) >= 0; }
    bool operator==(const str& rhs) const { return compare(rhs) == 0; }
    bool operator!=(const str& rhs) const { return not operator==(rhs); }

public: // search and find
    bool contains(const str& rhs, case_sensitivity cs = case_sensitive) const {
        auto cmp = cs == case_sensitive ? [](const char& a, const char& b) { return a == b; }
        : [](const char& a, const char& b) { return a == b || tolower(a) == tolower(b); };
        return m_data.get()+m_size != std::search(m_data.get(), m_data.get()+m_size, rhs.m_data.get(), rhs.m_data.get()+rhs.m_size, cmp);
    }
    bool starts_with(const str& rhs, case_sensitivity cs = case_sensitive) const;
    bool ends_with(const str& rhs, case_sensitivity cs = case_sensitive) const;

    char& operator[](size_t index) { return m_data[index]; }
    char& at(size_t index) {
        if (index < m_size) return m_data[index];
        else throw new std::out_of_range("invalid index");
    }
public:
    friend std::istream& operator>>(std::istream& is, str& s);
    friend std::ostream& operator<<(std::ostream& os, const str& s) {
        os.write(s.m_data.get(), s.size());
        return os;
    }
private:
    size_type m_size;
    size_type m_capacity;
    std::unique_ptr<value_type[]> m_data;
};

void swap(str& lhs, str& rhs) noexcept(noexcept(lhs.swap(rhs))) {
    lhs.swap(rhs);
}

template <typename OutputIterator>
void split(const std::string& s, const std::string& delim, OutputIterator result) {
    using size_type = std::string::size_type;
    size_type pos = 0;
    for (auto it = s.find(delim); it != std::string::npos; it = s.find(delim, pos)) {
        *result++ = s.substr(pos, it-pos);
        pos = it + delim.length();
    }
    if (pos < s.size())
        *result = s.substr(pos);
}

template <typename OutputIter>
OutputIter split_s(const std::string& s, const std::string& delim, OutputIter it) {
    size_t pos = 0;
    for (size_t i = 0; pos < s.length() && i != std::string::npos; pos = i + delim.length()) {
        i = s.find(delim, pos);
        if (i == std::string::npos) break;
        if (i != pos) *it++ = s.substr(pos, i - pos);
    }
    if (pos < s.length()) *it++ = s.substr(pos);
    return it;
}


#endif /* str_h */
