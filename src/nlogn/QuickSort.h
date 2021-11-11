//
// Created by 虎正玺 on 2021/11/11.
//

/**
 * 快速排序
 */


#ifndef ALGORITHM_QUICKSORT_H
#define ALGORITHM_QUICKSORT_H

#include <algorithm>

using namespace std;

/**
 * 对 arr[l...r] 部分进行 partition 操作
 *
 * @tparam T
 * @param arr
 * @param l
 * @param r
 * @return  返回 p, 使得 arr[l...p-1] < arr[p], arr[p+1...r] > arr[p]
 */
template<typename T>
int partition(T arr[], int l, int r) {
    swap(arr[l], arr[rand() % (r - l + 1) + l]);
    T v = arr[l];
    // arr[l+1...j]  < v; arr[j+1...i) > v
    int j = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < v) {
            swap(arr[++j], arr[i]);
        }
    }
    swap(arr[l], arr[j]);
    return j;
}

/**
 * 对 arr[l...r]部分进行快速排序
 * @tparam T
 * @param arr
 * @param l
 * @param r
 */
template<typename T>
void __quickSort(T arr[], int l, int r) {
    if (l >= r) { return; }
    int p = partition(arr, l, r);
    __quickSort(arr, l, p - 1);
    __quickSort(arr, p + 1, r);
}

template<typename T>
void quickSort(T arr[], int n) {
    srand(time(NULL));
    __quickSort(arr, 0, n - 1);
}

#endif //ALGORITHM_QUICKSORT_H
