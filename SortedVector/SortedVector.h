#ifndef __CS235_SORTED_VECTOR_H_
#define __CS235_SORTED_VECTOR_H_

#include <iostream>

template<class T>
class SortedVector{
public:
    SortedVector(unsigned int newCapacity = 3) : vecSize(0), vecCapacity(newCapacity) { arr = new T[vecCapacity]; }
    ~SortedVector() { delete[] arr; }

    // Vector state functions
    unsigned int capacity() { return vecCapacity; }
    unsigned int size() { return vecSize; }
    bool empty() { return vecSize == 0; }
    T at(unsigned int pos);
    void display();
    unsigned int count(const T& data);

    // Data manipulation functions
    void insert(const T& data);
    T remove(unsigned int pos);
    T pop_back();

    // Operator overloads
    bool operator==(const SortedVector& rhs);

    // Miscellaneous Functions
    void clear();
    
private:
    T* arr;
    unsigned int vecSize;
    unsigned int vecCapacity;

    void resize(unsigned int newCapacity);
    bool isIndexOutOfBounds(unsigned int pos) { return (empty() || pos >= vecSize); }

};

#include "SortedVector.cpp"

#endif