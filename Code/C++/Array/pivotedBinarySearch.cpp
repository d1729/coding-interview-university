#include <iostream>
using namespace std;

int modifiedBinarySearch(int arr[], int l, int r, int key){
    if(l > r)return -1;
    int mid = l + (r - l) / 2;
    if(arr[mid] == key)return mid;
    if(arr[l] <= arr[mid - 1]){
        if(key >= arr[l] && key <= arr[mid - 1])
            return modifiedBinarySearch(arr, l, mid - 1, key);
        else
            return modifiedBinarySearch(arr, mid + 1, r, key);
    }
    else{
        if(key >= arr[mid + 1] && key <= arr[r])
            return modifiedBinarySearch(arr, mid + 1, r, key);
        else
            return modifiedBinarySearch(arr, l, mid - 1, key);
    }
}

int main(int argc, char const *argv[]) {
    int i, n, *arr, key;
    cin>>n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cin>>key;
    int val = modifiedBinarySearch(arr, 0, n - 1, key);
    if(val == -1)
        cout<<"Key not present in the array\n";
    else
        cout<<"Key found at "<<val<<"\n";
    return 0;
}
