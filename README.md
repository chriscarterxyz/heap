# Max-Heap Implementation

Here's an auto-resizing max-heap implementation in C. In case, you know, you ever need one.

A max-heap is a data structure that functions like a binary tree that satisfies the _heap property_: every child of a node must have a key which is less than or equal to the key of that node (greater than or equal to for a min-heap). 

This means that the max value is accessible in constant time (O(1)) simply by looking at the root element of the node, implemented here in `heap_peek()`. This is useful in applications where items must be queued and accessed according to priority. Pushing to the heap (`heap_push()`) adds a new element to the heap and re-heapifys to preserve the heap property. Popping (`heap_pop()`) returns and removes the root element and also re-heapifys. Heapification takes O(lg(n)) time.

