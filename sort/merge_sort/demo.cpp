/**
 * Created by yy on 2019-03-10.
 */

#include <iostream>
#include "../common/SortTestHelper.h"
#include "../common/SortAll.h"

using namespace std;

int main(void) {
    int n = 100000;
    int *arr1 = SortTestHelper::generateNearlyOrderedArray(n, 10);
    int *arr2 = SortTestHelper::copyIntArray(arr1, n);
    SortTestHelper::testSort("Insert Sort", SortAll::insertSort, arr1, n);
    SortTestHelper::testSort("Merge Sort", SortAll::mergeSort, arr2, n);
    delete[] arr1;
    delete[] arr2;
    return 0;
}