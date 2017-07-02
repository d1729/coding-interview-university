/*
* Check if the array has a subarray of sum 0
*/

#include <iostream>
#include <unordered_map>
using namespace std;

bool zeroSumArray(int *arr, int n){
    unordered_map<int, bool>m;
    int sum = 0;
    for(int i = 0; i < n; ++i){
        sum += arr[i];
        if(sum == 0 || m.find(sum) != m.end())return true;
        m[sum] = true;
    }
    return false;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    if(zeroSumArray(arr, n))cout<<"Yes\n";
	    else cout<<"No\n";
	    delete []arr;
	}
	return 0;
}
