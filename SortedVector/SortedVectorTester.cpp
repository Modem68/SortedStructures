//
//  SortedVectorTester.cpp
//  AssignmentTester
//
//  Created by Simon Ayzman on 2/21/16.
//  Copyright © 2016 Simon Ayzman. All rights reserved.
//

#include <iostream>
#include <assert.h>

#include "SortedVectorTester.h"

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
    SortedVector<int> sortedVector;
    
    // Test empty state
    sortedVector.clear();
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 0);
    assert(sortedVector.empty());
    assert(isSorted(sortedVector));
    // try { sortedVector.at(0); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(1); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with one element
    sortedVector.clear();
    sortedVector.insert(100);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 1);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 100);
    // try { sortedVector.at(1); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (no resize)
    sortedVector.clear();
    sortedVector.insert(3);
    sortedVector.insert(1);
    sortedVector.insert(2);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 3);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 1);
    assert(sortedVector.at(1) == 2);
    assert(sortedVector.at(2) == 3);
    // try { sortedVector.at(3); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (one resize)
    sortedVector.clear();
    sortedVector.insert(1);
    sortedVector.insert(4);
    sortedVector.insert(3);
    sortedVector.insert(2);
    // assert(sortedVector.capacity() == 6);
    assert(sortedVector.size() == 4);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    for (unsigned int i = 0; i < sortedVector.size(); ++i) {
        assert(sortedVector.at(i) == (int)i+1);
    }
    // try { sortedVector.at(4); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(5); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple elements (two resizes)
    sortedVector.clear();
    sortedVector.insert(2);
    sortedVector.insert(7);
    sortedVector.insert(4);
    sortedVector.insert(6);
    sortedVector.insert(1);
    sortedVector.insert(5);
    sortedVector.insert(3);
    // assert(sortedVector.capacity() == 12);
    assert(sortedVector.size() == 7);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    for (unsigned int i = 0; i < sortedVector.size(); ++i) {
        assert(sortedVector.at(i) == (int)i+1);
    }
    // try { sortedVector.at(7); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(9); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(11); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test with multiple duplicate elements
    sortedVector.clear();
    for (int i = 0; i < 9; ++i) {
        sortedVector.clear();
        for (int j = 1; j < 8; j+=2) {
            sortedVector.insert(j);
            assert(isSorted(sortedVector));
        }
        for (int k = 0; k < 4; ++k) {
            sortedVector.insert(i);
            assert(isSorted(sortedVector));
        }
    }
    for (int i = 0; i < 9; ++i) {
        sortedVector.clear();
        for (int j = 1; j < 6; j+=2) {
            sortedVector.insert(j);
            assert(isSorted(sortedVector));
        }
        for (int k = 0; k < 4; ++k) {
            sortedVector.insert(i);
            assert(isSorted(sortedVector));
        }
    }
    
    // Test in backwards insertion order
    sortedVector.clear();
    for (unsigned int i = 20; i > 0; --i) {
        sortedVector.insert(i);
    }
    // assert(sortedVector.capacity() == 24);
    assert(sortedVector.size() == 20);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    for (unsigned int i = 0; i < sortedVector.size(); ++i) {
        assert(sortedVector.at(i) == (int)i+1);
    }
    // try { sortedVector.at(20); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(22); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(23); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.at(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
}

void testPopBack() {
    SortedVector<int> sortedVector;
    
    // Test pop_back on an empty vector
    sortedVector.clear();
    // try { sortedVector.pop_back(); throw -100; }
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test pop_back on a vector one element
    sortedVector.clear();
    sortedVector.insert(1);
    assert(sortedVector.pop_back() == 1);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 0);
    assert(sortedVector.empty());
    assert(isSorted(sortedVector));
    
    // Test pop_back on a vector multiple elements
    sortedVector.clear();
    sortedVector.insert(3);
    sortedVector.insert(2);
    sortedVector.insert(1);
    assert(sortedVector.pop_back() == 3);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 2);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 1);
    assert(sortedVector.at(1) == 2);
    
    // Test pop_back on a larger vector with multiple elements
    sortedVector.clear();
    sortedVector.insert(500);
    sortedVector.insert(400);
    sortedVector.insert(300);
    sortedVector.insert(200);
    sortedVector.insert(100);
    assert(sortedVector.pop_back() == 500);
    // assert(sortedVector.capacity() == 6);
    assert(sortedVector.size() == 4);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 100);
    assert(sortedVector.at(1) == 200);
    assert(sortedVector.at(2) == 300);
    assert(sortedVector.at(3) == 400);
    
    // Test pop_back for entire vector
    sortedVector.clear();
    for (int i = 19; i >= 0; --i) {
        sortedVector.insert(i);
    }
    for (int i = 19; i != 0; --i) {
        assert(sortedVector.pop_back() == i);
        assert((int)sortedVector.size() == i);
    }
}

/*
void testRemove() {
    SortedVector<int> sortedVector;
    
    // Test remove on an empty vector
    sortedVector.clear();
    // try { sortedVector.remove(0); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.remove(1); throw -100; } // An index between OBLE and capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.remove(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.remove(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test remove on beginning of a vector with one element
    sortedVector.clear();
    sortedVector.insert(1);
    assert(sortedVector.remove(0) == 1);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 0);
    assert(sortedVector.empty());
    assert(isSorted(sortedVector));
    // try { sortedVector.remove(1); throw -100; } // An index one beyond last element (OBLE)
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.remove(2); throw -100; } // An index at capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    // try { sortedVector.remove(100); throw -100; } // An index above capacity
    // catch (int e) { assert(e == -1 ? true : false); }
    
    // Test remove on beginning of a vector with multiple elements
    sortedVector.clear();
    sortedVector.insert(3);
    sortedVector.insert(2);
    sortedVector.insert(1);
    assert(sortedVector.remove(0) == 1);
    // assert(sortedVector.capacity() == 3);
    assert(sortedVector.size() == 2);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 2);
    assert(sortedVector.at(1) == 3);
    
    // Test remove on middle of vector
    sortedVector.clear();
    sortedVector.insert(400);
    sortedVector.insert(300);
    sortedVector.insert(200);
    sortedVector.insert(150);
    sortedVector.insert(100);
    assert(sortedVector.remove(1) == 150);
    // assert(sortedVector.capacity() == 6);
    assert(sortedVector.size() == 4);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 100);
    assert(sortedVector.at(1) == 200);
    assert(sortedVector.at(2) == 300);
    assert(sortedVector.at(3) == 400);
    
    // Test remove on end of vector
    sortedVector.clear();
    sortedVector.insert(300);
    sortedVector.insert(200);
    sortedVector.insert(150);
    sortedVector.insert(100);
    assert(sortedVector.remove(3) == 300);
    // assert(sortedVector.capacity() == 6);
    assert(sortedVector.size() == 3);
    assert(!sortedVector.empty());
    assert(isSorted(sortedVector));
    assert(sortedVector.at(0) == 100);
    assert(sortedVector.at(1) == 150);
    assert(sortedVector.at(2) == 200);
}


void testCount() {
    SortedVector<int> sortedVector;
    
    sortedVector.clear();
    
    // Test count on vector with zero instances
    assert(sortedVector.count(10) == 0);
    
    // Test count on vector with one instance
    sortedVector.insert(10);
    assert(sortedVector.count(10) == 1);
    
    sortedVector.clear();
    sortedVector.insert(1);
    sortedVector.insert(10);
    assert(sortedVector.count(10) == 1);
    
    sortedVector.clear();
    sortedVector.insert(1);
    sortedVector.insert(10);
    sortedVector.insert(1);
    assert(sortedVector.count(10) == 1);
    
    // Test count on vector with multiple instances
    sortedVector.clear();
    sortedVector.insert(1);
    sortedVector.insert(10);
    sortedVector.insert(1);
    sortedVector.insert(10);
    sortedVector.insert(10);
    sortedVector.insert(1);
    assert(sortedVector.count(10) == 3);
    
    // sortedVector.remove(0);
    // assert(sortedVector.count(10) == 3);
    // sortedVector.remove(4);
    // assert(sortedVector.count(10) == 2);
    // sortedVector.remove(0);
    // assert(sortedVector.count(10) == 2);
    // sortedVector.remove(2);
    // assert(sortedVector.count(10) == 1);
    // sortedVector.remove(0);
    // assert(sortedVector.count(10) == 1);
    // sortedVector.remove(0);
    // assert(sortedVector.count(10) == 0);
}


void testEqualityOperator() {
    SortedVector<int> sortedVector1;
    SortedVector<int> sortedVector2;
    
    // Test == when both empty and equal
    sortedVector1.clear();
    sortedVector2.clear();
    assert(sortedVector1 == sortedVector2);
    
    // Test == when one is empty and the other isn't
    sortedVector1.clear();
    sortedVector2.clear();
    sortedVector1.insert(1);
    assert(!(sortedVector1 == sortedVector2));
    
    // Test == when both are nonempty and equally sized and equal
    sortedVector1.clear();
    sortedVector2.clear();
    sortedVector1.insert(1);
    sortedVector2.insert(1);
    assert(sortedVector1 == sortedVector2);
    
    sortedVector1.clear();
    sortedVector2.clear();
    for (unsigned int i = 0; i < 10; i++) {
        sortedVector1.insert(i);
        sortedVector2.insert(i);
    }
    assert(sortedVector1 == sortedVector2);
    
    // Test == when both are nonempty and equally sized and not equal
    sortedVector1.clear();
    sortedVector2.clear();
    sortedVector1.insert(1);
    sortedVector2.insert(2);
    assert(!(sortedVector1 == sortedVector2));
    
    sortedVector1.clear();
    sortedVector2.clear();
    for (unsigned int i = 0; i < 10; i++) {
        sortedVector1.insert(i);
        sortedVector2.insert(i*2);
    }
    assert(!(sortedVector1 == sortedVector2));
    
    // Test == when both are nonempty and non equally sized
    sortedVector1.clear();
    sortedVector2.clear();
    sortedVector1.insert(1);
    sortedVector1.insert(2);
    sortedVector2.insert(1);
    assert(!(sortedVector1 == sortedVector2));
}
*/

bool isSorted(SortedVector<int>& sortedVector) {
    if (sortedVector.empty()) {
        return true;
    }
    
    int previousValue = sortedVector.at(0);
    for (unsigned int i = 1; i < sortedVector.size(); ++i) {
        int currentValue = sortedVector.at(i);
        if (currentValue < previousValue) {
            return false;
        }
        previousValue = currentValue;
    }
    
    return true;
}
