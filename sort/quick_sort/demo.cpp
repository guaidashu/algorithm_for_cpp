/**
 * Created by yy on 2019-03-20.
 */

#include <iostream>
#include "../common/SortTestHelper.h"
#include "../common/SortAll.h"

using namespace std;

int main(void) {
    int n = 1000000;
    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 100);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);

    SortTestHelper::testSort("Merge Sort: ", SortAll::mergeSort, arr1, n);
    SortTestHelper::testSort("Quick Sort: ", SortAll::quickSort, arr2, n);

    delete[] arr1;
    delete[] arr2;
    return 0;
}