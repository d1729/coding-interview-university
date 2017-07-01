#include <iostream>
using namespace std;

int peakUtil(int arr[], int lo, int hi, int n){
    int mid = lo + (hi - lo) / 2;
    if((mid == 0 || arr[mid] >= arr[mid - 1]) && (mid == n || arr[mid + 1] <= arr[mid]))
        return mid;
    else if(arr[mid] < arr[mid - 1])
        return peakUtil(arr, lo, mid - 1, n);
    else
        return peakUtil(arr, mid + 1, hi, n);
}

int peak(int arr[], int n)
{
   return peakUtil(arr, 0, n - 1, n);
}

int main(int argc, char const *argv[]) {
    int t, n, *arr;
    cin>>t;
    while(t--){
        cin>>n;
        arr = new int[n];
        for(int i = 0; i < n; ++i)cin>>arr[i];
        cout<<peak(arr, n)<<"\n";
        delete [] arr;
    }
    return 0;
}
