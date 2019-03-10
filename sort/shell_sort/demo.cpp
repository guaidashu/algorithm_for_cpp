/**
 * Created by yy on 2019-03-09.
 */

#include <iostream>
#include "../common/SortTestHelper.h"
#include "../common/SortAll.h"

using namespace std;

int main(void) {
    int n = 100000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 30);
    int *arr1 = SortTestHelper::copyIntArray(arr, n);
    int *arr2 = SortTestHelper::copyIntArray(arr, n);
    SortTestHelper::testSort<int>("Shell Sort", shellSort, arr, n);
    SortTestHelper::testSort<int>("insert Sort", insertSort, arr2, n);
    SortTestHelper::testSort<int>("Selection Sort", selectionSort, arr1, n);
    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    return 0;
}