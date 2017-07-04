/*
*   Given an array A[ ] of N sorted positive integers, find the smallest
*   positive integer S such that S cannot be represented as sum of elements of
*   any subset of the given array set.
*/
#include <iostream>
using namespace std;

int first(int arr[], int n){
    int res = 1;
    for(int i = 0; i < n && arr[i] <= res; ++i)
        res += arr[i];
    return res;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cout<<first(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
