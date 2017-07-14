/*
* Given an array of size n, the array contains numbers in range from 0 to k-1 where k is a positive integer and k <= n.
* Find the maximum repeating number in this array.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int maxRepeating(int arr[], int n, int k){
    for(int i = 0; i < n; i++)
        arr[arr[i] % k] += k;
    int max_val = -1, max_occur = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] / k > max_occur){
            max_val = i;
            max_occur = arr[i] / k;
        }
    }
    return max_val;
}

int main() {
	int t, n, k, *arr;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cout<<maxRepeating(arr, n, k)<<"\n";
	    delete [] arr;
	}
	return 0;
}
