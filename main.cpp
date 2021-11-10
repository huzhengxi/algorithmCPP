#include <iostream>
#include "src/SortTestHelper.h"
#include "src/n-pingfang/SelectionSort.h"
#include "src/n-pingfang/InsertSort.h"
#include "src/n-pingfang/BubbleSort.h"
#include "src/n-pingfang/ShellSort.h"
#include "src/nlogn/MergeSort.h"
#include "src/nlogn/MergeSortBU.h"

using namespace std;

int main() {

    int n = 50000;

    // 测试2 测试近乎有序的数组
    int swapTimes = 0;

    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", mergeSortBU, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}
