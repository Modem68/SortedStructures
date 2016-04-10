#ifndef __CS235_SORTED_LINKED_LIST_H_
#define __CS235_SORTED_LINKED_LIST_H_

#include <iostream>
#include <list>
#include <algorithm>

/*
    This class implements a sorted doubly linked list, 
    using the STL list as its underlying container.

    This class' condition of "sorted-ness" implies that any 
    literal or object type (T) that this class contains must 
    have the ability to be "compared." This will manifest in
    the form of a call to operator<. Therefore, the object type 
    (T) must at least implement operator<.

    HOWEVER, if this class will hold POINTERS to OBJECTS, you 
    must go one step further. You must create a "comparator" 
    struct/class that implements the operator() function. Inside 
    of this function, you must return the result of a "less than"
    comparison (simply, *obj1 < *obj2!). Then, you must supply 
    this comparator struct as the second template parameter.
*/
template<class T, class Comparator = std::less<T>>
class SortedLinkedList{
public:
    SortedLinkedList() {}

    // O(1) operations
    unsigned int size() { return linkedList.size(); }
    bool empty() { return linkedList.empty(); }

    T& front() { return linkedList.front(); }
    T& back() { return linkedList.back(); }

    T& pop_front() { T& data = front(); linkedList.pop_front(); return data; }
    T& pop_back() { T& data = back(); linkedList.pop_back(); return data; }

    // O(n) operations
    void clear() { linkedList.clear(); }
    T& at(unsigned int pos) { auto it = linkedList.begin(); std::advance(it,pos); return *it; }
    void display();

    void insert(const T& data);
    T& remove(unsigned int pos) { T& data = at(pos); linkedList.erase(linkedList.begin()+pos); return data; }

    
private:
    
    std::list<T> linkedList;

};

#include "SortedLinkedList.cpp"

#endif