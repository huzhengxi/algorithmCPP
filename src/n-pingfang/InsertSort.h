//
// Created by 虎正玺 on 2021/11/8.
//

#ifndef ALGORITHM_INSERTSORT_H
#define ALGORITHM_INSERTSORT_H

/**
 * 插入排序
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertionSort_old(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        //寻找元素arr[i]合适的插入位置
        // 缺点是：每次比较过后 都需要一次交换，交换两个数值的过程中产生了三次赋值操作，耗时较久
        for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
            swap(arr[j], arr[j - 1]);
        }
    }
}


template<typename T>
void insertionSort(T arr[], int n) {
    for (int i = 0; i < n; ++i) {
        //寻找元素arr[i]合适的插入位置
        T element = arr[i];
        int j = i;
        for (; j > 0 && arr[j - 1] > element; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = element;
    }
}

#endif //ALGORITHM_INSERTSORT_H
