#ifndef __CS235_SORTED_VECTOR_H_
#define __CS235_SORTED_VECTOR_H_

#include <iostream>
#include <vector>

/*
    This class implements a sorted vector, using the STL 
    vector as its underlying container.

    This class' condition of "sorted-ness" implies that any 
    literal or object type (T) that this class contains must 
    implement the comparison operators (>,<,>=,<=,==,!=). 
    Otherwise, you will not be able to use this class.
*/
template<class T>
class SortedVector{
public:
    SortedVector() { vec.reserve(50); }

    // O(1) operations
    unsigned int capacity() { return vec.capacity(); }
    unsigned int size() { return vec.size(); }
    bool empty() { return vec.empty(); }

    T& at(unsigned int pos) { return vec.at(pos); }
    T& front() { return vec.front(); }
    T& back() { return vec.back(); }
    T& pop_back() { T& data = back(); vec.pop_back(); return data; }

    // O(n) operations
    void clear() { vec.clear(); }
    unsigned int count(const T& data);
    void display();

    void insert(const T& data);
    T& remove(unsigned int pos) { T& data = at(pos); vec.erase(vec.begin()+pos); return data; }
    
private:
    std::vector<T> vec;

};

#include "SortedVector.cpp"

#endif