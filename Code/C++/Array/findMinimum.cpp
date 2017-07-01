/*
*Find the minimum number in a rotated and sorted array
*/

#include <iostream>
using namespace std;

int findMinimum(int arr[], int lo, int hi){
    if(lo > hi)return arr[lo];
    if(lo == hi)return arr[lo];
    int mid = lo + (hi - lo) / 2;
    if(mid < hi && arr[mid] > arr[mid + 1])return arr[mid + 1];
    if(mid > lo && arr[mid] < arr[mid + 1])return arr[mid];
    else if(arr[mid] < arr[hi])return findMinimum(arr, lo, mid - 1);
    return findMinimum(arr, mid + 1, hi);
}

int main(int argc, char const *argv[]) {
    int arr[] = {};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<findMinimum(arr, 0, n - 1)<<"\n";
    return 0;
}
