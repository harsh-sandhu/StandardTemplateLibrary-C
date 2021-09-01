# Standard Template Library-C
### Why Standard Template Library for C language? 
Being a low-level language, not having object-oriented properties and not having a standard library providing any data-structure, C programming language makes it difficult to cope 
with today's programming problems and lack of time makes it even more difficult

To solve this problem, this is a ***Standard Template Library*** which provides different data structures to make problems easier to solve.

### What is a Standard Template Library?
Standard Template Library is a set of structures and fucntions which helps in different functionality. Languages, for example, C++ has Standard template Library and Java has Collection Interface which provides a big set of data structures and functions which can be used according to different problems to optimize both space and time, solving the problem more efficiently. It is basically set of some generic data structures which have extensive usage in real world problems.

### What is provided by Standard Template Library-C ?
This Standard Template Library designed for C provideds
* ***Linked-List*** (Functions like insertion, deletion, checkCycle, etc...) 
  * Singly-Linked-List
  * Doubly-Linked-List
* ***Stacks*** (Functions like push, pop, minimum element, maximum element, etc...)
  * Standard stack
  * Min-Stack
  * Max-Stack
* ***Queues*** (Function like enqueue, dequeue, peek, etc...) 
  * Standard Queue
  * Double-ended Queue ( Deque )
* ***Binary Tree and Binary Search Tree*** (Function like in-order,post-order and pre-order traversal, level-order traversal, etc...)
* ***Sorting Algorithms***
  * Quick Sort
  * Merge Sort
* ***Searching Algorithms***

### Specifications of some ***Basic functions*** of Different Data-structures
| Data Structure | Functions | Time Complexity | Space Complexity |
|----------------|-----------|-----------------|------------------|
|Linked-List| insertFromHead() | O(1) | O(1) |
|           | insertFromTail() | O(1) | O(1) |
|           | deleteFromHead() | O(1) | O(1) |
|           | deleteFromTail() | O(1) | O(1) |
|   Stack   |      push()      | O(1) | O(1) |
|           |      pop()       | O(1) | O(1) |
|           |      top()       | O(1) | O(1) |
|   Queue   |    enqueue()     | O(1) | O(1) |
|           |    dequeue()     | O(1) | O(1) |
|           |    peek()        | O(1) | O(1) |

### How to use this Standard Template Library in C?
To use this library, download the files in same folder where you have your file in which you want to use this library, then include this header libaray named CSTL.h
```C
 #include "CSTL.h"
```
User can also download files in any place and use the path in include statement of the program where you want to use the library.

