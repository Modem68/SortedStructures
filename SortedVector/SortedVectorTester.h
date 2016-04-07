//
//  SortedVectorTester.h
//  AssignmentTester
//
//  Created by Simon Ayzman on 2/21/16.
//  Copyright © 2016 Simon Ayzman. All rights reserved.
//

#ifndef SortedVectorTester_h
#define SortedVectorTester_h

#include "SortedVector.h"

// Program will stop whenever an assertion hits an unmet invariant.
// In other words, the condition provided to an assertion must be true
// because it represents a "should-be" condition at that point in the program.
// If the condition is false, the assertion triggers a program abort.
void runTests();

void testBaseFunctions(); //capacity, size, empty, at, insert
void testPopBack();
//void testRemove();
void testCount();
//void testEqualityOperator();

bool isSorted(SortedVector<int>& sortedVector);

#endif /* SortedVectorTester_h */
