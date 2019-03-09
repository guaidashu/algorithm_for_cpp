//
// Created by yy on 2019-03-02.
//

#include <iostream>
#include "../common/SortTestHelper.h"
#include "../common/SortAll.h"

using namespace std;

/**
 * 插入排序复杂度  O(n^2)
 * @return
 */
int main(void) {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Insertion Sort", insertSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    delete[] arr2;
    delete[] arr;
    return 0;
}