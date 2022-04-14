# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (CMakeTarget 
"Algorithms/Searching/binary-search.cpp" 
"Algorithms/Sorting/bubble-sort.cpp" 
"Algorithms/Sorting/selection-sort.cpp" 
"Algorithms/Sorting/merge-sort.cpp" 
"Algorithms/Sorting/insertion-sort.cpp" 
"Data Structures/Array/Class Implementation/Array.cpp" 
"Data Structures/Array/Class Implementation/Array.h" 
"Data Structures/Stack/Class Implementation/main.cpp"
"Data Structures/Array/Library Implementation/main.cpp"
"Data Structures/Doubly Linked List/Class Implementation/DoublyLinkedList.cpp" 
"Data Structures/Doubly Linked List/Class Implementation/DoublyLinkedList.h" 
"Data Structures/Doubly Linked List/Class Implementation/main.cpp"
"Data Structures/Doubly Linked List/STL Implementation/main.cpp"
 "Algorithms/Sorting/quicksort-end-pivot.cpp" 
 "Algorithms/Sorting/quicksort-start-pivot.cpp" 
 "Algorithms/Math/sieve-of-eratosthenes.cpp" 
 "Data Structures/Stack/Class Implementation/Stack.cpp" 
 "Data Structures/Stack/Class Implementation/Stack.h" 
 "Data Structures/Stack/Class Implementation/main.cpp" 
 "Data Structures/Stack/STL Implementation/main.cpp" 
 "Algorithms/Dynamic Programming/maximum-subarray.cpp" 
 "Data Structures/Queue/Class Implementation/main.cpp" 
 "Data Structures/Queue/Class Implementation/Queue.cpp"   
 "Data Structures/Queue/Class Implementation/Queue.h" 
 "Data Structures/Queue/STL Implementation/main.cpp"  
 "Data Structures/Graphs/Undirected Graphs/undirected-graph-adjacency-list.cpp" 
 "Data Structures/Graphs/Undirected Graphs/undirected-graph-adjacency-matrix.cpp" 
 "Algorithms/Math/infix-to-postfix.cpp"   
 "Algorithms/Searching/Breadth First Search/bfs-graph.cpp" 
 "Algorithms/Searching/Depth First Search/dfs-graph.cpp" 
 "Algorithms/Math/euclid-algorithm.cpp")

# TODO: Add tests and install targets if needed.