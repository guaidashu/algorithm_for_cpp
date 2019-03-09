//
// Created by yy on 2019-03-02.
//

#ifndef CPP_STUDY_SORTTESTHELPER_H
#define CPP_STUDY_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <string>
#include <assert.h>

using namespace std;

namespace SortTestHelper {
    /**
     * 生成一个随机数组
     * @param n 取值个数
     * @param rangeL 取值范围开始
     * @param rangeR 取值范围结束
     * @return
     */
    int *generateRandomArray(int n, int rangeL, int rangeR) {
        assert(rangeL <= rangeR);
        int *arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        }
        return arr;
    }

    int *generateNearlyOrderedArray(int n, int swapTimes) {
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int i = 0; i < swapTimes; i++) {
            int posx = rand() % n;
            int posy = rand() % n;
            swap(arr[posx], arr[posy]);
        }
        return arr;
    }

    /**
     * 打印数组
     * @tparam T
     * @param arr
     * @param n
     */
    template<class T>
    void printArray(T arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    /**
     * 是否排序成功
     * @tparam T
     * @param arr
     * @param n
     * @return bool(true or false)
     */
    template<typename T>
    bool isSorted(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * 测试排序函数的效率(时间)
     * @tparam T 数组类型
     * @param sortName 排序名
     * @param sort 排序函数指针
     * @param arr 数组
     * @param n 数组大小
     */
    template<typename T>
    void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        assert(isSorted(arr, n));
        cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    }

    template<typename T>
    T *copyIntArray(T a[], int n) {
        T *arr = new T[n];
        copy(a, a + n, arr);
        return arr;
    }

}

#endif //CPP_STUDY_SORTTESTHELPER_H
