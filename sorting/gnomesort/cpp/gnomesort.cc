#include <iostream>
#include "../../../utils/utils.h"
using namespace std;

template<typename T>
void gnome_sort(T data[], int n) {
    int i = 0;
    while (i < n) {
        if (i == 0 || data[i-1] <= data[i])
            ++i;
        else {
            swap(data[i], data[i-1]);
            --i;
        }
    }
}

// 地精在回头检查花盘顺序前记下当前位置，整理完就瞬间转移到之前位置的下一个位置。瞬间转移，很强大，哈哈。
template<typename T>
void gnome_sort2(T data[], int n) {
    int i = 0;
    int p = -1; // previous position
    while (i < n) {
        if (i == 0 || data[i-1] <= data[i]) {
            if (p == -1)
                ++i;
            else { // After traverse backward, go to the position next to the previous
                i = p+1;
                p = -1;
            }
        } else {
            if (p == -1)
                p = i;
            swap(data[i], data[i-1]);
            --i;
        }
    }
}

void print_array(int* a, int n) {
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << endl;
}

int main(void) {
    int a[20] = {23, 32, 12, 432, 54, 65, 76, 43, 32, 54, 0, -1, 32};
    print_array(a, 20);
    gnome_sort2(a, 20);
    print_array(a, 20);

    return 0;
}
