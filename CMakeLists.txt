# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (CMakeTarget 
"Algorithms/Searching/Binary-Search.cpp" 
"Algorithms/Sorting/Bubble-Sort.cpp" 
"Algorithms/Sorting/Selection-Sort.cpp" 
"Algorithms/Sorting/Merge-Sort.cpp" 
"Algorithms/Sorting/Insertion-Sort.cpp" 
"Data Structures/Array/Class Implementation/Array.cpp" 
"Data Structures/Array/Class Implementation/Array.h" 
"Data Structures/Stack/Class Implementation/main.cpp"
"Data Structures/Array/Library Implementation/main.cpp"
"Data Structures/Doubly Linked List/Class Implementation/DoublyLinkedList.cpp" 
"Data Structures/Doubly Linked List/Class Implementation/DoublyLinkedList.h" 
"Data Structures/Doubly Linked List/Class Implementation/main.cpp"
"Data Structures/Doubly Linked List/STL Implementation/main.cpp"
 "Algorithms/Sorting/Quicksort-End-Pivot.cpp" 
 "Algorithms/Sorting/Quicksort-Start-Pivot.cpp" 
 "Algorithms/Math/Sieve-of-Eratosthenes.cpp" 
 "Data Structures/Stack/Class Implementation/Stack.cpp" 
 "Data Structures/Stack/Class Implementation/Stack.h" 
 "Data Structures/Stack/Class Implementation/main.cpp" 
 "Data Structures/Stack/STL Implementation/main.cpp" 
 "Algorithms/Dynamic Programming/Maximum Subarray .cpp" 
 "Data Structures/Queue/Class Implementation/main.cpp" 
 "Data Structures/Queue/Class Implementation/Queue.cpp"   
 "Data Structures/Queue/Class Implementation/Queue.h" 
 "Data Structures/Queue/STL Implementation/main.cpp")

# TODO: Add tests and install targets if needed.