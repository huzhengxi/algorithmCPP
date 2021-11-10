cmake_minimum_required(VERSION 3.19)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(algorithm main.cpp src/SortTestHelper.h src/n-pingfang/SelectionSort.h src/n-pingfang/InsertSort.h src/n-pingfang/BubbleSort.h src/n-pingfang/ShellSort.h src/nlogn/MergeSort.h src/nlogn/MergeSortBU.h)