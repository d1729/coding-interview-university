#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestIncreasingSubsequence(int arr[], int n){
    if(n == 0)return 0;
    vector<int>tail(n, 0);
    int length = 1;
    tail[0] = arr[0];
    for(size_t i = 1; i < n; ++i){
        if(arr[i] < tail[0])
            tail[0] = arr[i];
        else if(arr[i] > tail[length - 1])
            tail[length++] = arr[i];
        else
            tail[lower_bound(tail.begin(), tail.begin() + length - 1, arr[i]) - tail.begin()] = arr[i];
    }
    return length;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)
	        cin>>arr[i];
	    cout<<largestIncreasingSubsequence(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
