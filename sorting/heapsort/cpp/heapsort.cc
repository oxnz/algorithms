#include <iostream>

struct Node {
    double element; // the data
    Node* left; // left child
    Node* right; // right child
    // Node* parent; // parent
};

class Tree {
public:
    Tree();
    Tree(const Tree& t);
    ~Tree();

    bool empty() const;
    double root(); // decomposition (access functions)
    Tree& left();
    Tree& right();

    // Tree& parent(double x);

    // ... update ...
    void insert(const double x); // compose x into a Tree
    void remove(const double x); // decompose x from a Tree
};

template<typename RandomAccessIterator, typename Compare>
void sift_up(RandomAccessIterator first, RandomAccessIterator last, Compare cmp, RandomAccessIterator current) {
	typedef typename iterator_traits<RandomAccessIterator>::difference_type T;
	T i = current - first;
	for (T p = (i-1)>>1; p >= 0 && p != i && cmp(*(first+p), *(first+i)); i = p, p = (i-1)>>1) iter_swap(first+p, first+i);
}

template<typename RandomAccessIterator, typename Compare>
void sift_down(RandomAccessIterator first, RandomAccessIterator last, Compare cmp, RandomAccessIterator current) {
	typedef typename iterator_traits<RandomAccessIterator>::difference_type T;
	T n = last - first;
	T i = current - first;
	for (T p = (i<<1)+1; p < n; i = p, p = (i<<1)+1) {
		if (p+1 < n && cmp(*(first+p), *(first+p+1))) ++p;
		if (cmp(*(first+i), *(first+p))) iter_swap(first+i, first+p);
		else break;
	}
}

template<typename RandomAccessIterator, typename Compare>
void heap_make(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
	typedef typename iterator_traits<RandomAccessIterator>::difference_type T;
	T n = last - first;
	if (n < 2) return;
	for (T i = (n>>1) - 1; i >= 0; --i)
		sift_down(first, last, cmp, first+i);
}

template<typename RandomAccessIterator>
void heap_make(RandomAccessIterator first, RandomAccessIterator last) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	heap_make(first, last, less<T>());
}

template<typename RandomAccessIterator, typename Compare>
void heap_push(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
	typedef typename iterator_traits<RandomAccessIterator>::difference_type T;
	T n = last - first;
	if (n > 1) sift_up(first, last, cmp, first+n-1);
}

template<typename RandomAccessIterator>
void heap_push(RandomAccessIterator first, RandomAccessIterator last) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	heap_push(first, last, less<T>());
}

template<typename RandomAccessIterator, typename Compare>
void heap_pop(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
	if (last - first > 1) {
		iter_swap(first, --last);
		sift_down(first, last, cmp, first);
	}
}

template<typename RandomAccessIterator>
void heap_pop(RandomAccessIterator first, RandomAccessIterator last) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	heap_pop(first, last, less<T>());
}

template<typename RandomAccessIterator, typename Compare>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last, Compare cmp) {
	heap_make(first, last, cmp);
	while (--last != first) heap_pop(first, last+1, cmp);
}

template<typename RandomAccessIterator>
void heap_sort(RandomAccessIterator first, RandomAccessIterator last) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	heap_sort(first, last, less<T>());
}

template<typename RandomAccessIterator, typename Compare>
void heap_adjust(RandomAccessIterator first, RandomAccessIterator last, Compare cmp, RandomAccessIterator current) {
	typedef typename iterator_traits<RandomAccessIterator>::difference_type T;
	T i = current - first;
	if (i > 0 and cmp(*(first+((i-1)>>1)), *current)) sift_up(first, last, cmp, current);
	else sift_down(first, last, cmp, current);
}

template<typename RandomAccessIterator>
void heap_adjust(RandomAccessIterator first, RandomAccessIterator last, RandomAccessIterator current) {
	typedef typename iterator_traits<RandomAccessIterator>::value_type T;
	heap_adjust(first, last, less<T>(), current);
}

int main() {
	vector<int> v;
	v.reserve(100);
	for (int i = 0; i < 10; ++i) {
		v.push_back(i+1);
		heap_push(v.begin(), v.end());
		if (not is_heap(v.begin(), v.end())) cout << "Nah push" << endl;
	}
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
		shuffle(v.begin(), v.end(), mt19937(2));
		heap_make(v.begin(), v.end());
		if (not is_heap(v.begin(), v.end())) cout << "Nah heap" << endl;
		heap_sort(v.begin(), v.end());
		if (not is_sorted(v.begin(), v.end())) cout << "Nah sorted" << endl;
	}
	for (int i = 0; i < 10; ++i) {
		heap_make(v.begin(), v.end());
		auto it = v.begin() + rand()%v.size();
		*it = rand()%10+rand()%10;
		heap_adjust(v.begin(), v.end(), it);
		if (not is_heap(v.begin(), v.end())) cout << "Nah heap" << endl;
	}
	heap_make(v.begin(), v.end());
	while (v.size() > 0) {
		heap_pop(v.begin(), v.end());
		v.pop_back();
		if (not is_heap(v.begin(), v.end())) cout << "Nah pop" << endl;
	}
	cout << "END" << endl;
	return 0;
}

