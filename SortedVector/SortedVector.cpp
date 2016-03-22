#ifndef __CS235_SORTED_VECTOR_CPP_
#define __CS235_SORTED_VECTOR_CPP_

#include "SortedVector.h"

template<class T>
void SortedVector<T>::display() {
    if (empty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for (int i = 0; i < size()-1; i++) {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[size()-1] << std::endl;
}

template<class T>
unsigned int SortedVector<T>::count(const T& data) {
    unsigned int count = 0;
    bool foundStart = false;
    
    // since the vector is sorted, we can expect that the same
    // values will exist directly next to one another in a row
    for (int i = 0; i < size(); i++) {
        if (vec[i] == data) {
            foundStart = true;
            count++;
        }
        else if (foundStart) { // early break when we've passed the last instance
            break;
        }
    }
    
    return count;
}


template<class T>
void SortedVector<T>::insert(const T& data) {
    if (empty()) {
        vec.push_back(data);
        return;
    }
    auto iterator = std::lower_bound(vec.begin(), vec.end(), data);
    vec.insert(iterator, data);
}

#endif