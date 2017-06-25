#include <iostream>
using namespace std;

int binSearch(int arr[], int lo, int hi){
        if(lo == hi)
                return arr[lo];
        if(lo + 1 == hi && arr[lo] > arr[hi])
                return arr[lo];
        if(lo + 1 == hi && arr[lo] < arr[hi])
                return arr[hi];
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
                return arr[mid];
        else if(arr[mid] > arr[mid - 1])
                return binSearch(arr, mid + 1, hi);
        else
                return binSearch(arr, lo, mid - 1);
}

int main() {
        int t, n;
        cin>>t;
        while(t--) {
                cin>>n;
                int *arr = new int[n];
                for(int i = 0; i < n; ++i)
                        cin>>arr[i];
                cout<<binSearch(arr, 0, n - 1)<<"\n";
                delete []arr;
        }
        return 0;
}
