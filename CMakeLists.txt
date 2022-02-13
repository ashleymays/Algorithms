# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (Algorithms   "Searching/Binary-Search.cpp" "Sorting/Selection-Sort.cpp" "Sorting/Bubble-Sort.cpp" "Sorting/Insertion-Sort.cpp"     "Sorting/Merge-Sort.cpp" "Data Structures/Array/Class Implementation/Array.h")

# TODO: Add tests and install targets if needed.
