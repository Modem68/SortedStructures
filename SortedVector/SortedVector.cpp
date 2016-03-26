#ifndef __CS235_SORTED_VECTOR_CPP_
#define __CS235_SORTED_VECTOR_CPP_

#include "SortedVector.h"

template<class T, class Comparator>
void SortedVector<T, Comparator>::display() {
    if (empty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for (int i = 0; i < size()-1; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[size()-1] << std::endl;
}


template<class T, class Comparator>
void SortedVector<T, Comparator>::insert(const T& data) {
    if (empty()) {
        vec.push_back(data);
        return;
    }
    Comparator comparator;
    auto iterator = std::lower_bound(vec.begin(), vec.end(), data, comparator);
    vec.insert(iterator, data);
}

#endif