#ifndef __CS235_SORTED_LINKED_LIST_CPP_
#define __CS235_SORTED_LINKED_LIST_CPP_

#include "SortedLinkedList.h"

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::display() 
{
    if (empty()) 
    {
        std::cout << "(empty)" << std::endl;
        return;
    }

    auto it = linkedList.begin();
    std::cout << *it;
    for (++it; it != linkedList.end(); ++it) 
    {
        std::cout << ", " << *it;
    }
    std::cout << std::endl;
}

template<class T, class Comparator>
void SortedLinkedList<T, Comparator>::insert(const T& data) 
{
    if (empty()) 
    {
        linkedList.push_front(data);
        return;
    }

    Comparator comparator;
    auto it = linkedList.begin();
    for (; it != linkedList.end(); ++it) 
    {
        if (comparator(data,*it)) 
        {
            linkedList.insert(it, data);
            break;
        }
    }
    if(it == linkedList.end()) 
    {
        linkedList.insert(it, data);
    }
}

#endif