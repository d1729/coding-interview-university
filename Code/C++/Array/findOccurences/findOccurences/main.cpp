/*
 *Find the number of occurences of an array in a sorted array
 */
#include <iostream>
#include <algorithm>
using namespace std;

int leftBinarySearch(int arr[], int left, int right, int key){
    if(left <= right){
        int mid = left + (right - left) / 2;
        if ((mid == left || arr[mid - 1] != key) && arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return leftBinarySearch(arr, mid + 1, right, key);
        else
            return leftBinarySearch(arr, left, mid - 1, key);
    }
    return -1;
}

int rightBinarySearch(int arr[], int left, int right, int key){
    if(left <= right){
        int mid = left +(right - left) / 2;
        if((mid == right || arr[mid + 1] != key) && arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            return rightBinarySearch(arr, left, mid - 1, key);
        else
            return rightBinarySearch(arr, mid + 1, right, key);
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int arr[] = {1,1,2,2,2,2,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 2;
    if(!binary_search(arr, arr + size, key))
        cout<<0<<"\n";
    else
        cout<<upper_bound(arr, arr + 7, key) - lower_bound(arr, arr + size, key)<<"\n";//rightBinSearch - leftBinarySearch
    return 0;
}
