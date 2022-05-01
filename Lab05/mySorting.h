#include <algorithm>

template <class T, size_t N>
void mySort(T (&arr)[N]) {
    std::sort(arr, arr + N);
}

template <class T>
void mySort(std::vector<T> v) {
    std::sort(begin(v), end(v));
}

