//
// Created by 虎正玺 on 2021/11/12.
//

/**
 * 双路快排
 */
#ifndef ALGORITHM_QUICKSORTDOUBLEPOINT_H
#define ALGORITHM_QUICKSORTDOUBLEPOINT_H

#include <algorithm>

using namespace std;

template<typename T>
int _partitionDoublePoint(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];

    int i = l + 1, j = r;
    while (true) {
        while (i <= r && arr[i] < v) i++;
        while (j >= l + 1 && arr[j] > v) j--;
        if (i > j) { break; }
        swap(arr[i++], arr[j--]);
    }
    swap(arr[l], arr[j]);
    return j;
}


template<typename T>
void __quickSortDoublePoint(T arr[], int l, int r) {
    if (l >= r) { return; }

    int p = _partitionDoublePoint(arr, l, r);

    __quickSortDoublePoint(arr, l, p - 1);
    __quickSortDoublePoint(arr, p + 1, r);
}

template<typename T>
void quickSortDoublePoint(T arr[], int n) {

    __quickSortDoublePoint(arr, 0, n - 1);
}

#endif //ALGORITHM_QUICKSORTDOUBLEPOINT_H
