# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (CMakeTarget 
"Searching/binary-search.cpp" 
"Sorting/bubble-sort.cpp" 
"Sorting/selection-sort.cpp" 
"Sorting/merge-sort.cpp" 
"Sorting/insertion-sort.cpp" 
"Array/Class Implementation/Array.cpp" 
"Array/Class Implementation/Array.h" 
"Stack/Class Implementation/main.cpp"
"Array/Library Implementation/main.cpp"
"Doubly Linked List/Class Implementation/DoublyLinkedList.cpp" 
"Doubly Linked List/Class Implementation/DoublyLinkedList.h" 
"Doubly Linked List/Class Implementation/main.cpp"
"Doubly Linked List/STL Implementation/main.cpp"
 "Sorting/quicksort-end-pivot.cpp" 
 "Sorting/quicksort-start-pivot.cpp" 
 "Math/sieve-of-eratosthenes.cpp" 
 "Stack/Class Implementation/Stack.cpp" 
 "Stack/Class Implementation/Stack.h" 
 "Stack/Class Implementation/main.cpp" 
 "Stack/STL Implementation/main.cpp" 
 "Dynamic Programming/maximum-subarray.cpp" 
 "Queue/Class Implementation/main.cpp" 
 "Queue/Class Implementation/Queue.cpp"   
 "Queue/Class Implementation/Queue.h" 
 "Queue/STL Implementation/main.cpp"  
 "Graphs/Undirected Graphs/undirected-graph-adjacency-list.cpp" 
 "Graphs/Undirected Graphs/undirected-graph-adjacency-matrix.cpp" 
 "Math/infix-to-postfix.cpp"   
 "Searching/Breadth First Search/bfs-graph.cpp" 
 "Searching/Depth First Search/dfs-graph.cpp" 
 "Math/euclid-algorithm.cpp")

# TODO: Add tests and install targets if needed.