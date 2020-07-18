//
//  heap.cpp
//  Interview
//
//  Created by 云心逸 on 2019/1/2.
//  Copyright © 2019 Errpro,Inc. All rights reserved.
//

#include "heap.hpp"
#include <sstream>

#include <gtest/gtest.h>

using namespace std;

class T {
public:
	T(int i) : m_index(i) { cout << "T::ctor/" << this->str() << "\n"; }
	T(const T&rhs) : m_index(rhs.m_index) { cout << "T::copy/" << this->str() << "\n"; }
	T(T&& rhs) noexcept : m_index(0) {
		swap(rhs);
		cout << "T::move/" << this->str() << "\n";
	}
	T& operator=(T rhs) noexcept {
		swap(rhs);
		cout << "T::assign/" << this->str() << "\n";
		return *this;
	}
	~T() { cout << "T::dtor/" << this->str() << "\n"; }
	void swap(T& rhs) {
		std::swap(m_index, rhs.m_index);
	}
	
	bool operator<(const T& rhs) const { return m_index < rhs.m_index; }
	string str() const {
		stringstream ss;
		ss << "T(" << m_index << ")[" << addressof(*this) << "]";
		return ss.str();
	}
	friend ostream& operator<<(ostream& os, const T& v) {
		auto s = v.str();
        os.write(s.c_str(), s.size());
		return os;
	}
private:
	int m_index;
};

TEST(heap, heap) {
/*
	heap::heap<T> h;
	vector<T> v;
	const T t(233);
	cout << "--------\n";
	h.emplace(1234);
	h.push(T(9999));
	h.push(t);
	cout << "--------\n";
	v.emplace_back(2234);
	v.push_back(T(8888));
	v.push_back(t);
	cout << "EOF\n";
	make_heap(v.begin(), v.end());
*/
//	cout << "ECHO: ";
//	for (int i = 0; i < h.size(); ++i) cout << h[i] << ", ";
//	cout << "EOP\n";
}
