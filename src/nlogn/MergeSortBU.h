//
// Created by 虎正玺 on 2021/11/10.
//

#ifndef ALGORITHM_MERGESORTBU_H
#define ALGORITHM_MERGESORTBU_H

#include "MergeSort.h"
#include <algorithm>

/**
 * 自底向上的归并排序
 */

template<typename T>
void mergeSortBU(T arr[], int n) {
    for (int size = 1; size <= n; size += size) {
        for (int i = 0; i + size < n; i += size + size) {
            __merge(arr, i, i + size - 1, min(i + size + size - 1, n - 1));
        }
    }
}

#endif //ALGORITHM_MERGESORTBU_H
