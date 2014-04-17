template <typename T>
void swap(T& a, T& b) {
	T t = a;
	a = b;
	b = t;
}

int swap(int& a, int& b) {
	a = a + b;
	b = a - b;
	a = a - b;
}

int swap(int&a, int&b) {
	a ^= b;
	b ^= a;
	a ^= b;
}
