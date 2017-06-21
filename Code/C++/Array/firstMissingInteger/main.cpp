/*
 * Find out the first missing number in a sorted array of n elements where the elements range from 0 to m-1(no duplicates)
 */
#include <iostream>
using namespace std;

int firstMissingNumber(int arr[], int lo, int hi){
    if(lo > hi)
        return hi + 1;
    if(arr[lo] != lo)
        return lo;
    int mid = lo + (hi - lo) / 2;
    if(arr[mid] != mid)
        return firstMissingNumber(arr, lo, mid );
    else
        return firstMissingNumber(arr, mid + 1,  hi);
}

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int missingNum = firstMissingNumber(arr, 0, size - 1);
    cout<<missingNum<<"\n";
    return 0;
}