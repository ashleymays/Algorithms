# CMakeList.txt : CMake project for Algorithms, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Algorithms")

# Add source to this project's executable.
add_executable (Algorithms   "Searching/BinarySearch.cpp" "Sorting/SelectionSort.cpp")

# TODO: Add tests and install targets if needed.
