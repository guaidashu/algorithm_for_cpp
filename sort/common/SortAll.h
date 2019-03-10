//
// Created by yy on 2019-03-03.
//

#ifndef CPP_STUDY_SORTALL_H
#define CPP_STUDY_SORTALL_H

#include <iostream>
#include <algorithm>

using namespace std;

/**
 * 选择排序 O(n^2)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n; i++) {
        // 首先定义一个位置(记录最小的值的位置)
        int minIndex = i;
        // 循环数组，进行比对，找到最小值
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

/**
 * 插入排序 时间复杂度  O(n^2) 在一定有序的情况下可能达到近乎 O(n)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void insertSort(T arr[], int n) {
    for (int i = 1; i < n; i++) {
        T e = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > e; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = e;
    }
}

/**
 * 希尔排序 的 插入排序部分
 * @tparam T
 * @param arr
 * @param gap
 * @param pos
 */
template<typename T>
void insertSortForShell(T arr[], int gap, int pos) {
    T temp = arr[pos];
    int i;
    for (i = pos; i >= gap && arr[i - gap] > temp; i -= gap) {
        arr[i] = arr[i - gap];
    }
    arr[i] = temp;
}

/**
 * 希尔排序算法 O(n^(2/3))
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void shellSort(T arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            insertSortForShell<T>(arr, gap, i);
        }
    }
}

/**
 * 冒泡排序 时间复杂度 O(n^2)
 * @tparam T
 * @param arr
 * @param n
 */
template<typename T>
void bubbleSort(T *arr, int n) {
    // 设置记录判断是否排过序的变量
    int flag;
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = n-1; j > i; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                flag = 1;
            }
        }
        if (flag == 0){
            break;
        }
    }
}

#endif //CPP_STUDY_SORTALL_H
