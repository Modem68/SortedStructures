//
//  SortedLinkedListTester.cpp
//  AssignmentTester
//
//  Created by Simon Ayzman on 2/21/16.
//  Copyright © 2016 Simon Ayzman. All rights reserved.
//

#include <iostream>
#include <assert.h>

#include "SortedLinkedListTester.h"

void runTests() {
    
    testBaseFunctions();
    testPopBack();
    //testRemove();
    //testCount();
    //testEqualityOperator();

    std::cout << "All your tests have passed!\n";
}

void testBaseFunctions()
{
    SortedLinkedList<int> sortedLinkedList;
    
    // Test empty state
    sortedLinkedList.clear();
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 0);
    assert(sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    // try { sortedLinkedList.at(0); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(1); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with one element
    sortedLinkedList.clear();
    sortedLinkedList.insert(100);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 1);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 100);
    // try { sortedLinkedList.at(1); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (no resize)
    sortedLinkedList.clear();
    sortedLinkedList.insert(3);
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(2);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 3);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 1);
    assert(sortedLinkedList.at(1) == 2);
    assert(sortedLinkedList.at(2) == 3);
    // try { sortedLinkedList.at(3); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (one resize)
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(4);
    sortedLinkedList.insert(3);
    sortedLinkedList.insert(2);
    // assert(sortedLinkedList.capacity() == 6);
    assert(sortedLinkedList.size() == 4);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    for (unsigned int i = 0; i < sortedLinkedList.size(); ++i) {
        assert(sortedLinkedList.at(i) == (int)i+1);
    }
    // try { sortedLinkedList.at(4); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(5); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (two resizes)
    sortedLinkedList.clear();
    sortedLinkedList.insert(2);
    sortedLinkedList.insert(7);
    sortedLinkedList.insert(4);
    sortedLinkedList.insert(6);
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(5);
    sortedLinkedList.insert(3);
    // assert(sortedLinkedList.capacity() == 12);
    assert(sortedLinkedList.size() == 7);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    for (unsigned int i = 0; i < sortedLinkedList.size(); ++i) {
        assert(sortedLinkedList.at(i) == (int)i+1);
    }
    // try { sortedLinkedList.at(7); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(9); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(11); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple duplicate elements
    sortedLinkedList.clear();
    for (int i = 0; i < 9; ++i) {
        sortedLinkedList.clear();
        for (int j = 1; j < 8; j+=2) {
            sortedLinkedList.insert(j);
            assert(isSorted(sortedLinkedList));
        }
        for (int k = 0; k < 4; ++k) {
            sortedLinkedList.insert(i);
            assert(isSorted(sortedLinkedList));
        }
    }
    for (int i = 0; i < 9; ++i) {
        sortedLinkedList.clear();
        for (int j = 1; j < 6; j+=2) {
            sortedLinkedList.insert(j);
            assert(isSorted(sortedLinkedList));
        }
        for (int k = 0; k < 4; ++k) {
            sortedLinkedList.insert(i);
            assert(isSorted(sortedLinkedList));
        }
    }
    
    // Test in backwards insertion order
    sortedLinkedList.clear();
    for (unsigned int i = 20; i > 0; --i) {
        sortedLinkedList.insert(i);
    }
    // assert(sortedLinkedList.capacity() == 24);
    assert(sortedLinkedList.size() == 20);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    for (unsigned int i = 0; i < sortedLinkedList.size(); ++i) {
        assert(sortedLinkedList.at(i) == (int)i+1);
    }
    // try { sortedLinkedList.at(20); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(22); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(23); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
}

void testPopBack() {
    SortedLinkedList<int> sortedLinkedList;
    
    // Test pop_back on an empty vector
    sortedLinkedList.clear();
    // try { sortedLinkedList.pop_back(); throw -100; }
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test pop_back on a vector one element
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.pop_back() == 1);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 0);
    assert(sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    
    // Test pop_back on a vector multiple elements
    sortedLinkedList.clear();
    sortedLinkedList.insert(3);
    sortedLinkedList.insert(2);
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.pop_back() == 3);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 2);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 1);
    assert(sortedLinkedList.at(1) == 2);
    
    // Test pop_back on a larger vector with multiple elements
    sortedLinkedList.clear();
    sortedLinkedList.insert(500);
    sortedLinkedList.insert(400);
    sortedLinkedList.insert(300);
    sortedLinkedList.insert(200);
    sortedLinkedList.insert(100);
    assert(sortedLinkedList.pop_back() == 500);
    // assert(sortedLinkedList.capacity() == 6);
    assert(sortedLinkedList.size() == 4);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 100);
    assert(sortedLinkedList.at(1) == 200);
    assert(sortedLinkedList.at(2) == 300);
    assert(sortedLinkedList.at(3) == 400);
    
    // Test pop_back for entire vector
    sortedLinkedList.clear();
    for (int i = 19; i >= 0; --i) {
        sortedLinkedList.insert(i);
    }
    for (int i = 19; i != 0; --i) {
        assert(sortedLinkedList.pop_back() == i);
        assert((int)sortedLinkedList.size() == i);
    }
}

/*
void testRemove() {
    SortedLinkedList<int> sortedLinkedList;
    
    // Test remove on an empty vector
    sortedLinkedList.clear();
    // try { sortedLinkedList.remove(0); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.remove(1); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.remove(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.remove(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test remove on beginning of a vector with one element
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.remove(0) == 1);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 0);
    assert(sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    // try { sortedLinkedList.remove(1); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.remove(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedLinkedList.remove(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test remove on beginning of a vector with multiple elements
    sortedLinkedList.clear();
    sortedLinkedList.insert(3);
    sortedLinkedList.insert(2);
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.remove(0) == 1);
    // assert(sortedLinkedList.capacity() == 3);
    assert(sortedLinkedList.size() == 2);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 2);
    assert(sortedLinkedList.at(1) == 3);
    
    // Test remove on middle of vector
    sortedLinkedList.clear();
    sortedLinkedList.insert(400);
    sortedLinkedList.insert(300);
    sortedLinkedList.insert(200);
    sortedLinkedList.insert(150);
    sortedLinkedList.insert(100);
    assert(sortedLinkedList.remove(1) == 150);
    // assert(sortedLinkedList.capacity() == 6);
    assert(sortedLinkedList.size() == 4);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 100);
    assert(sortedLinkedList.at(1) == 200);
    assert(sortedLinkedList.at(2) == 300);
    assert(sortedLinkedList.at(3) == 400);
    
    // Test remove on end of vector
    sortedLinkedList.clear();
    sortedLinkedList.insert(300);
    sortedLinkedList.insert(200);
    sortedLinkedList.insert(150);
    sortedLinkedList.insert(100);
    assert(sortedLinkedList.remove(3) == 300);
    // assert(sortedLinkedList.capacity() == 6);
    assert(sortedLinkedList.size() == 3);
    assert(!sortedLinkedList.empty());
    assert(isSorted(sortedLinkedList));
    assert(sortedLinkedList.at(0) == 100);
    assert(sortedLinkedList.at(1) == 150);
    assert(sortedLinkedList.at(2) == 200);
}


void testCount() {
    SortedLinkedList<int> sortedLinkedList;
    
    sortedLinkedList.clear();
    
    // Test count on vector with zero instances
    assert(sortedLinkedList.count(10) == 0);
    
    // Test count on vector with one instance
    sortedLinkedList.insert(10);
    assert(sortedLinkedList.count(10) == 1);
    
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(10);
    assert(sortedLinkedList.count(10) == 1);
    
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(10);
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.count(10) == 1);
    
    // Test count on vector with multiple instances
    sortedLinkedList.clear();
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(10);
    sortedLinkedList.insert(1);
    sortedLinkedList.insert(10);
    sortedLinkedList.insert(10);
    sortedLinkedList.insert(1);
    assert(sortedLinkedList.count(10) == 3);
    
    // sortedLinkedList.remove(0);
    // assert(sortedLinkedList.count(10) == 3);
    // sortedLinkedList.remove(4);
    // assert(sortedLinkedList.count(10) == 2);
    // sortedLinkedList.remove(0);
    // assert(sortedLinkedList.count(10) == 2);
    // sortedLinkedList.remove(2);
    // assert(sortedLinkedList.count(10) == 1);
    // sortedLinkedList.remove(0);
    // assert(sortedLinkedList.count(10) == 1);
    // sortedLinkedList.remove(0);
    // assert(sortedLinkedList.count(10) == 0);
}


void testEqualityOperator() {
    SortedLinkedList<int> sortedLinkedList1;
    SortedLinkedList<int> sortedLinkedList2;
    
    // Test == when both empty and equal
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    assert(sortedLinkedList1 == sortedLinkedList2);
    
    // Test == when one is empty and the other isn't
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    sortedLinkedList1.insert(1);
    assert(!(sortedLinkedList1 == sortedLinkedList2));
    
    // Test == when both are nonempty and equally sized and equal
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    sortedLinkedList1.insert(1);
    sortedLinkedList2.insert(1);
    assert(sortedLinkedList1 == sortedLinkedList2);
    
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    for (unsigned int i = 0; i < 10; i++) {
        sortedLinkedList1.insert(i);
        sortedLinkedList2.insert(i);
    }
    assert(sortedLinkedList1 == sortedLinkedList2);
    
    // Test == when both are nonempty and equally sized and not equal
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    sortedLinkedList1.insert(1);
    sortedLinkedList2.insert(2);
    assert(!(sortedLinkedList1 == sortedLinkedList2));
    
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    for (unsigned int i = 0; i < 10; i++) {
        sortedLinkedList1.insert(i);
        sortedLinkedList2.insert(i*2);
    }
    assert(!(sortedLinkedList1 == sortedLinkedList2));
    
    // Test == when both are nonempty and non equally sized
    sortedLinkedList1.clear();
    sortedLinkedList2.clear();
    sortedLinkedList1.insert(1);
    sortedLinkedList1.insert(2);
    sortedLinkedList2.insert(1);
    assert(!(sortedLinkedList1 == sortedLinkedList2));
}
*/

bool isSorted(SortedLinkedList<int>& sortedLinkedList) {
    if (sortedLinkedList.empty()) {
        return true;
    }
    
    int previousValue = sortedLinkedList.at(0);
    for (unsigned int i = 1; i < sortedLinkedList.size(); ++i) {
        int currentValue = sortedLinkedList.at(i);
        if (currentValue < previousValue) {
            return false;
        }
        previousValue = currentValue;
    }
    
    return true;
}
