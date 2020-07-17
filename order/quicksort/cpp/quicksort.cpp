#include <iostream>

using namespace std;

template<typename T, typename Index>
void quicksort(T array[], Index left, Index right) {
    if (left < right) {
        Index l = left;
        Index r = right;
        T m = array[l];
        while (l < r) {
            while (l < r && array[r] >= m)
                --r;
            if (l < r)
                array[l++] = array[r];
            while (l < r && array[l] < m)
                ++l;
            if (l < r)
                array[r--] = array[l];
        }
        array[l] = m;
        quicksort(array, left, l-1);
        quicksort(array, l+1, right);
    }
}

template <typename T, typename Index>
void printArray(T a[], Index maxIndex) {
    for (Index i = 0; i < maxIndex; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    int a[20] = {0, 4, 332232, 434, 5454, 423, 7, 32132131, 4343, 434};
    printArray(a, 20);
    quicksort(a, 0, 19);
    printArray(a, 20);
    
    return 0;
}
