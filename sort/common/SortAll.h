//
// Created by yy on 2019-03-03.
//

#ifndef CPP_STUDY_SORTALL_H
#define CPP_STUDY_SORTALL_H

#include <iostream>
#include <algorithm>

using namespace std;

namespace SortAll {

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
     * 插入排序（用于归并排序优化）
     * @tparam T
     * @param arr
     * @param l
     * @param r
     */
    template<typename T>
    void insertSortForMerge(T *arr, int l, int r) {
        for (int i = l + 1; i <= r; i++) {
            T e = arr[i];
            int j;
            for (j = i; j > l && arr[j - 1] > e; j--)
                arr[j] = arr[j - 1];
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
            for (int j = n - 1; j > i; j--) {
                if (arr[j] < arr[j - 1]) {
                    swap(arr[j], arr[j - 1]);
                    flag = 1;
                }
            }
            if (flag == 0) {
                break;
            }
        }
    }

    /**
     * 归并排序归并方法
     * @tparam T
     * @param arr
     * @param l
     * @param mid
     * @param r
     */
    template<typename T>
    void __merge(T *arr, int l, int mid, int r) {
        T aux[r - l + 1];
        // 复制数组
        for (int i = l; i <= r; i++)
            aux[i - l] = arr[i];
        // 进行归并
        int i = l, j = mid + 1;
        for (int k = l; k <= r; k++) {
            if (i > mid) {
                arr[k] = aux[j - l];
                j++;
            } else if (j > r) {
                arr[k] = aux[i - l];
                i++;
            } else if (aux[i - l] < aux[j - l]) {
                arr[k] = aux[i - l];
                i++;
            } else {
                arr[k] = aux[j - l];
                j++;
            }
        }

    }

    /**
     * 归并排序递归 拆分 方法
     * @tparam T
     * @param arr
     * @param l
     * @param r
     */
    template<typename T>
    void __mergeSort(T *arr, int l, int r) {
        // if (l >= r)
        //     return;
        if (r - l <= 15) {
            insertSortForMerge<T>(arr, l, r);
            return;
        }
        // l+r可能会出现溢出的问题，稍后做修改
        int mid = (l + r) / 2;
        __mergeSort<T>(arr, l, mid);
        __mergeSort<T>(arr, mid + 1, r);
        // 若是对近乎有序的数组进行排序，则加上if语句。
        if (arr[mid] > arr[mid + 1])
            __merge<T>(arr, l, mid, r);
    }

    /**
     * 归并排序 自顶向下
     * @tparam T
     * @param arr
     * @param n
     */
    template<typename T>
    void mergeSort(T *arr, int n) {

        __mergeSort<T>(arr, 0, n - 1);
    }

    /**
     * 自底向上的归并排序
     * @tparam T
     * @param arr
     * @param n
     */
    template<typename T>
    void mergeSortBU(T *arr, int n) {
        // 首先设置归并的间距1, 2, 4, 8 ...
        for (int sz = 1; sz <= n; sz += sz) {
            for (int i = 0; i + sz < n; i += sz + sz) {
                __merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));
            }
        }
    }
};

#endif //CPP_STUDY_SORTALL_H
