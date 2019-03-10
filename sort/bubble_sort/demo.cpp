/**
 * Created by yy on 2019-03-10.
 */

#include <iostream>
#include <algorithm>
#include "../common/SortTestHelper.h"
#include "../common/SortAll.h"

using namespace std;

int main(void) {
    int n = 10000;
    int *arr = SortTestHelper::generateNearlyOrderedArray(n, 100);
    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr, n);
    delete[] arr;
    return 0;
}