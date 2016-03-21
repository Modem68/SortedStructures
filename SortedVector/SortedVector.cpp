#ifndef __CS235_SORTED_VECTOR_CPP_
#define __CS235_SORTED_VECTOR_CPP_

#include "SortedVector.h"

template<class T>
T SortedVector<T>::at(unsigned int pos) {
    if (isIndexOutOfBounds(pos)) {
        throw -1; 
    }
    return arr[pos];
}

template<class T>
void SortedVector<T>::display() {
    if (empty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for (int i = 0; i < vecSize-1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[vecSize-1] << std::endl;
}

template<class T>
unsigned int SortedVector<T>::count(const T& data) {
    int count = 0;
    bool foundStart = false;
    
    // since the vector is sorted, we can expect that the same
    // values will exist directly next to one another in a row
    for (int i = 0; i < vecSize; i++) {
        if (arr[i] == data) {
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
        arr[vecSize++] = data;
        return;
    }
    
    if (vecSize == vecCapacity) {
        resize(vecCapacity * 2);
    }
    
    int start = 0;
    int end = vecSize-1;
    int middle = (start + end) / 2;
    while (start <= end) {
        middle = (start + end) / 2;
        T valueAtMiddle = arr[middle];
        if (data < valueAtMiddle) {
            end = middle-1;
        }
        else if (data > valueAtMiddle) {
            start = middle+1;
        }
        else { // values are equal
            break;
        }
    }
    
    // If start and end converge to the same index position, this
    // indicates that the search took place all the way to the end
    // However, if they have not converged, this indicates that an equal value
    // was found and can therefore be freely inserted at that location
    unsigned int index = (start <= end) ? middle : start;
    for (int i = vecSize; i > index; --i) { // Shift everything over
        arr[i] = arr[i-1];
    }
    arr[index] = data;
    vecSize++;
}

template<class T>
T SortedVector<T>::pop_back() {
    if (empty()) { 
        throw -1; 
    }
    return arr[--vecSize];
}


template<class T>
T SortedVector<T>::remove(unsigned int pos) {
    if (isIndexOutOfBounds(pos)) {
        throw -1;
    }

    T value = arr[pos];
    for (int i = pos; i < vecSize; ++i) { // Shift everything over
        arr[i] = arr[i+1];
    }
    vecSize--;

    return value;
}

template<class T>
bool SortedVector<T>::operator==(const SortedVector<T>& rhs) {
    if (vecSize != rhs.vecSize || vecCapacity != rhs.vecCapacity) {
        return false;
    }
    for (int i = 0; i < vecSize; i++) {
        if (arr[i] != rhs.arr[i]) { 
            return false; 
        }
    }
    return true;
}

template<class T>
void SortedVector<T>::clear() {
    delete[] arr;
    vecSize = 0; 
    vecCapacity = 3;
    arr = new T[vecCapacity];
}

// Private helper functions

template<class T>
void SortedVector<T>::resize(unsigned int newCapacity) {
    vecCapacity = newCapacity;
    T* oldArr = arr;
    arr = new T[vecCapacity];
    for (int i = 0; i < vecSize; i++) {
        arr[i] = oldArr[i];
    }
    delete[] oldArr;
}

#endif