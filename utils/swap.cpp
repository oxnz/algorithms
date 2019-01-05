template <typename T>
void value_swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

void numeric_diff_swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

void numeric_xor_swap(int&a, int&b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
