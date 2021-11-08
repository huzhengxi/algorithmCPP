//
// Created by 虎正玺 on 2021/11/8.
//

#ifndef ALGORITHM_BUBBLESORT_H
#define ALGORITHM_BUBBLESORT_H

/**
 * 冒泡排序
 */

#include <algorithm>

using namespace std;

template<typename T>
void bubbleSort(T arr[], int n) {
    bool swapped;
    do {
        swapped = false;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                swapped = true;
            }
        }
        //优化，每一趟 Bubble Sort 都将最大的元素放在了最后位置
        //所以下一次排序，最后的元素不再考虑
        n--;
    } while (swapped);
}

template<typename T>
void bubbleSort2(T arr[], int n) {
    int newn;//使用newn进行优化
    do {
        newn = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                swap(arr[i - 1], arr[i]);
                //记录最后一次交换位置，在此之后的元素在下一轮扫描中均不考虑
                newn = i;
            }
        }
        n = newn;
    } while (newn > 0);
}

#endif //ALGORITHM_BUBBLESORT_H
