#include <iostream>
#include <algorithm>
#include "Student.h"
#include "../common/SortTestHelper.h"

using namespace std;

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
 * 选择排序  O(n^2)
 * @return
 */
int main(void) {
    int n = 100000;
    int *arr = SortTestHelper::generateRandomArray(n, 0, n);

    SortTestHelper::testSort<int>("Selection Sort", selectionSort, arr, n);
    // selectionSort(arr, n);
    // SortTestHelper::printArray(arr, n);
    // cout << endl;
    // Student d[4] = {{"D", 90},
    //                 {"C", 100},
    //                 {"B", 95},
    //                 {"A", 95}};
    // selectionSort<Student>(d, 4);
    // SortTestHelper::printArray(d, 4);

    delete[] arr;
    return 0;
}
