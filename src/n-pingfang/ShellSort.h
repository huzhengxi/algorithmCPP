//
// Created by 虎正玺 on 2021/11/8.
//

#ifndef ALGORITHM_SHELLSORT_H
#define ALGORITHM_SHELLSORT_H

/**
 * 希尔排序
 */

template<typename T>
void shellSort(T arr[], int n) {
    int h = 1;
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        for (int i = h; i < n; i++) {
            // 对 arr[i], arr[i-h], arr[i-2*h], arr[i-3*h]... 使用插入排序
            T e = arr[i];
            int j;
            for (j = i; i >= h && e < arr[j - h]; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = e;
        }
        //缩小h
        h /= 3;
    }
}

#endif //ALGORITHM_SHELLSORT_H
