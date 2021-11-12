#include <iostream>
#include "src/SortTestHelper.h"
#include "src/n-pingfang/SelectionSort.h"
#include "src/n-pingfang/InsertSort.h"
#include "src/n-pingfang/BubbleSort.h"
#include "src/n-pingfang/ShellSort.h"
#include "src/nlogn/MergeSort.h"
#include "src/nlogn/MergeSortBU.h"
#include "src/nlogn/QuickSort.h"
#include "src/nlogn/QuickSort2Ways.h"
#include "src/nlogn/QuickSort3Ways.h"

using namespace std;

int main() {

    int n = 200000;

    cout << "Test for Random array" << endl;

    int *arr1 = SortTestHelper::generateRandomArray(n, 0, 20);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);
    SortTestHelper::testSort("Quick Sort", quickSort2Ways, arr1, n);
    SortTestHelper::testSort("Quick Sort 3ways", quickSort3Ways, arr1, n);

    delete[] arr1;
    delete[] arr2;


    return 0;
}
