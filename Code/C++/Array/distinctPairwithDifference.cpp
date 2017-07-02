/*
* Given an array find number of pairs of (A[i], A[j]) such that difference is equal to k
*/
#include <iostream>
#include <map>
using namespace std;

int findDiffPairs(int *arr, int n, int k){
    map<int, int>m;
    int count = 0;
    for(int i = 0; i < n; ++i){
        if(k == 0){
            if(m.find(arr[i])!=m.end() && m[arr[i]] == 1)
                count += 1;
        }
        else{
            if(m.find(k + arr[i]) != m.end()) count += 1;
            if(m.find(arr[i] - k) != m.end()) count += 1;
        }
        if(m.find(arr[i]) != m.end()) m[arr[i]] = 2;
        else m[arr[i]] = 1;
    }
    return count;
}

int main() {
	int t, n, *arr, k;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cin>>k;
	    cout<<findDiffPairs(arr, n, k)<<"\n";
	    delete []arr;
	}
	return 0;
}
