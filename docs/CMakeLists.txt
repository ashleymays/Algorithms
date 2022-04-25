# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (CMakeTarget 
"01-Searching/binary-search.cpp" 
"02-Sorting/bubble-sort.cpp" 
"02-Sorting/selection-sort.cpp" 
"02-Sorting/merge-sort.cpp" 
"02-Sorting/insertion-sort.cpp" 
"05-Array/Class Implementation/Array.cpp" 
"05-Array/Class Implementation/Array.h" 
"06-Stack/Class Implementation/main.cpp"
"05-Array/STL Implementation/main.cpp"
"08-Doubly Linked List/Class Implementation/DoublyLinkedList.cpp" 
"08-Doubly Linked List/Class Implementation/DoublyLinkedList.h" 
"08-Doubly Linked List/Class Implementation/main.cpp"
"08-Doubly Linked List/STL Implementation/main.cpp"
 "02-Sorting/quicksort-end-pivot.cpp" 
 "02-Sorting/quicksort-start-pivot.cpp" 
 "03-Math/sieve-of-eratosthenes.cpp" 
 "06-Stack/Class Implementation/Stack.cpp" 
 "06-Stack/Class Implementation/Stack.h" 
 "06-Stack/Class Implementation/main.cpp" 
 "06-Stack/STL Implementation/main.cpp" 
 "04-Dynamic Programming/maximum-subarray.cpp" 
 "07-Queue/Class Implementation/main.cpp" 
 "07-Queue/Class Implementation/Queue.cpp"   
 "07-Queue/Class Implementation/Queue.h" 
 "07-Queue/STL Implementation/main.cpp"  
 "09-Graphs/Undirected Graph/undirected-graph-adjacency-list.cpp" 
 "09-Graphs/Undirected Graph/undirected-graph-adjacency-matrix.cpp" 
 "03-Math/infix-to-postfix.cpp"   
 "01-Searching/Breadth First Search/bfs-graph.cpp" 
 "01-Searching/Depth First Search/dfs-graph.cpp" 
 "03-Math/euclid-algorithm.cpp")

# TODO: Add tests and install targets if needed.