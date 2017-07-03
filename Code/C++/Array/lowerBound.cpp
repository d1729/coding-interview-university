/*
* Find the first index where the element(Array[i]) is larger than the given key 
*/
#include <iostream>
using namespace std;

int lower_bound(int arr[], int l, int r, int key){
    if(l > r)return l;
    int mid = l + (r - l) / 2;
    if(mid > l && arr[mid - 1] < key && arr[mid] >= key)return mid;
    if(mid == l && arr[mid] >= key)return mid;
    if(arr[mid] < key)
        return lower_bound(arr, mid + 1, r, key);
    return lower_bound(arr, l, mid - 1, key);
}

int main(int argc, char const *argv[]) {
    int t, n, *arr, key;
    cin>>t;
    while(t--){
        cin>>n;
        arr = new int[n];
        for(int i = 0; i < n; ++i)cin>>arr[i];
        cin>>key;
        cout<<lower_bound(arr, 0, n - 1, key)<<"\n";
        delete [] arr;
    }
    return 0;
}
