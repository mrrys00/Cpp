#include <algorithm>

template <class T, size_t N>
void mySort(T (&arr)[N]) {
    std::sort(arr, arr + N);
}

template <class T>
void mySort(std::vector<T> v) {
    std::sort(begin(v), end(v));
}

template <class T>
void mySort(MyList<T> &l){
    vector<T> v;
    while(l.size() > 0)
        v.push_back(l.pop_front());
    sort(begin(v), end(v));
    for (auto ptr = v.begin(); ptr < v.end(); ptr++)
        l.push_front(*ptr);
}