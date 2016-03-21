## Warmup Assignment II - SortedVector
Static arrays in C++ pose a very common problem—the need to know exactly how big the array should
be at compile time. Frequently, we do not know this information because the values come from a
variable input source, such as a file of unknown size. Dynamic arrays solve this problem by allowing the
number of values stored to be determined at run time.


A vector serves as a wrapper for a dynamic array—a wrapper in that it surrounds the array with a class,
creating an interface that provides certain functionality, such as accessing, removing, or counting the
underlying elements. A further benefit is that vectors handle the dynamic memory allocation and
resizing of arrays as necessary under the hood. 


This program implements the vector class, except with an extra twist. This vector maintains a condition 
of sorted-ness. At any given moment, all of the elements in the vector are in ascending sorted order.


In order to compile this program, run the following command:

``` make all ```

Then, execute the compiled program with the following command:

``` ./sorted_vector ```

Upon successfully running the program, it should output: "All your tests have passed!" This indicates 
that all the SortedVector functionality works. If an assertion is triggered (and the program aborts), this 
indicates that a piece of functionality is incorrectly implemented. Find the source of the assertion and fix 
the bug in the relevant function's code.