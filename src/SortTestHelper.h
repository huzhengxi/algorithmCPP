//
// Created by 虎正玺 on 2021/11/8.
//

#ifndef ALGORITHM_SORTTESTHELPER_H
#define ALGORITHM_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;
namespace SortTestHelper {
    /**
     * 生成n个元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
     * @param n  待生成数组的长度
     * @param rangeL  左边界
     * @param rangeR   有边界
     * @return 返回生成的数组
     */
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }


    int *generateNearlyOrderedArray(int n, int randomTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }

        srand(time(NULL));
        for (int i = 0; i < randomTimes; ++i) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    /**
     * 打印数组的前n个元素
     * @tparam T 模板
     * @param arr 待打印的数组
     * @param n 表示打印数组的元素的长度
     */
    template<typename T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * 判断数组是否已排序
     * @tparam T  模板
     * @param arr 待判断的数组
     * @param n 数组的长度
     * @return 返回判断结果
     */
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
            return true;
        }
    }

    /**
     * 测试排序元素的执行效率
     * @tparam T
     * @param sortName
     * @param sort
     * @param arr
     * @param n
     */
    template<typename T>
    void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    /**
     * 拷贝一个数组
     * @param a  待拷贝的数组
     * @param n  数组的长度
     * @return 返回拷贝后的数组
     */
    int *copyIntArray(int a[], int n) {
        int *arr = new int[n];
        copy(a, a + n, arr);
        return arr;
    }

}
#endif //ALGORITHM_SORTTESTHELPER_H
