#ifndef __CS235_SORTED_VECTOR_H_
#define __CS235_SORTED_VECTOR_H_

#include <iostream>
#include <vector>

template<class T>
class SortedVector{
public:
    SortedVector() { vec.reserve(50); }

    unsigned int capacity() { return vec.capacity(); }
    unsigned int size() { return vec.size(); }
    bool empty() { return vec.empty(); }
    void clear() { vec.clear(); }

    T& front() { return vec.front(); }
    T& back() { return vec.back(); }
    T& at(unsigned int pos) { return vec.at(pos); }
    T& pop_back() { T& data = back(); vec.pop_back(); return data; }
    T& remove(unsigned int pos) { T& data = at(pos); vec.erase(vec.begin()+pos); return data; }

    void insert(const T& data);

    unsigned int count(const T& data);
    void display();
    
private:
    std::vector<T> vec;

};

#include "SortedVector.cpp"

#endif