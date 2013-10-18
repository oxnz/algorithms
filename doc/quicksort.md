#Quick Sort

##1. Overview

Sort algorithms are ordering the elements of an array according to a
predefined order. Quicksort is a divide and conquer algorithm. In a
divide and conquer sorting algorithm their the original data is
separated into two parts (divide) which are individually sorted
(conquered) and then combined.

##2. Description of the algorithm

If the array contains only one element or zero elements then the array
is sorted.

If the array contains more then one element then:

* Select an element from the array. This element is called the "pivot
element". For example select the element in the middle of the array.
* All elements which are smaller then the pivot element are placed in
one array and all elements which are larger are placed in another
array.
* Sort both arrays by recursively applying Quicksort to them.
* Combine the arrays

Quicksort can be implemented to sort "in-place". This means that the
sorting takes place in the array and that no additional array need to
be created.

##3. Complexity Analysis

The following describes the runtime complexity of quicksort.

Fast, recursive, non-stable sort algorithm which works by the divide
and conquer principle. Quicksort will in the best case divide the
array into almost two identical parts. It the array contains n
elements then the first run will need O(n). Sorting the remaining two
sub-arrays takes 2* O(n/2). This ends up in a performance of O(n log
n).

In the worst case quicksort selects only one element in each
iteration. So it is O(n) + O(n-1) + (On-2).. O(1) which is equal to
O(n^2).

The average case of quicksort is O(n log n).
