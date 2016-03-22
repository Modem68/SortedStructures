#ifndef __CS235_SORTED_LINKED_LIST_CPP_
#define __CS235_SORTED_LINKED_LIST_CPP_

#include "SortedLinkedList.h"

template<class T>
void SortedLinkedList<T>::display() {
    if (empty()) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    auto it = linkedList.begin();
    std::cout << *it;
    for (++it; it != linkedList.end(); ++it) {
        std::cout << ", " << *it;
    }
    std::cout << std::endl;
}

template<class T>
unsigned int SortedLinkedList<T>::count(const T& data) {
    unsigned int count = 0;
    bool foundStart = false;
    
    // since the linked list is sorted, we can expect that the same
    // values will exist directly next to one another in a row
    for (auto it = linkedList.begin(); it != linkedList.end(); ++it) {
        if (*it == data) {
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
void SortedLinkedList<T>::insert(const T& data) {
    if (empty()) {
        linkedList.push_front(data);
        return;
    }

    auto it = linkedList.begin();
    for (; it != linkedList.end(); ++it) {
        if (*it >= data) {
            linkedList.insert(it, data);
            break;
        }
    }
    if(it == linkedList.end()) {
        linkedList.insert(it, data);
    }
}

#endif