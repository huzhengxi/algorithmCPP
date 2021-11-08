#include <iostream>
#include "src/SortTestHelper.h"
#include "src/n-pingfang/SelectionSort.h"
#include "src/n-pingfang/InsertSort.h"
#include "src/n-pingfang/BubbleSort.h"
#include "src/n-pingfang/ShellSort.h"

using namespace std;

int main() {

    int n = 20000;

    // 测试2 测试近乎有序的数组
    int swapTimes = 100;

    cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    int *arr3 = SortTestHelper::copyIntArray(arr1, n);
    int *arr4 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    return 0;
}
