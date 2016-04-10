#ifndef __CS235_SORTED_VECTOR_CPP_
#define __CS235_SORTED_VECTOR_CPP_

#include "SortedVector.h"

template<class T, class Comparator>
void SortedVector<T, Comparator>::display() 
{
    if (empty()) 
    {
        std::cout << "(empty)" << std::endl;
        return;
    }

    for (int i = 0; i < size()-1; i++) 
    {
        std::cout << vec[i] << ", ";
    }
    std::cout << vec[size()-1] << std::endl;
}

template<class T, class Comparator>
void SortedVector<T, Comparator>::insert(const T& data) 
{
    if (empty()) 
    {
        vec.push_back(data);
        return;
    }
    
    // Temporary use of O(n) search algorithm 
    // to handle lower_bound issues
    Comparator comparator;
    int index = vec.size();
    for(int i = 0; i < vec.size(); ++i)
    {
        if(comparator(vec[i], data))
    	{
    	    continue;
    	}
    	else
    	{
    	    index = i;
    	    break;
        }
    }    
    
    vec.insert(vec.begin()+index, data);
}

#endif
