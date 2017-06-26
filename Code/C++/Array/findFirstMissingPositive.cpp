#include <iostream>
#include <algorithm>
using namespace std;

int firstValue(int arr[], int n){
    int pos = 0;
    for(size_t i = 0; i < n; ++i){
        if(arr[i] <= 0){
            swap(arr[i], arr[pos]);
            ++pos;
        }
    }
    for(size_t i = pos; i < n; ++i)
        if(abs(arr[i]) + pos <= n && arr[abs(arr[i]) + pos - 1] > 0)
            arr[abs(arr[i]) + pos - 1] = -arr[abs(arr[i]) + pos - 1];
    int val = 1;
    for(size_t i = pos; i < n; ++i){
        if(arr[i] > 0)
            return val;
        else
            ++val;
    }
    return val;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cout<<firstValue(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
