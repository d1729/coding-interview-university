#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

void sortKsortedArray(int arr[], int n, int k){
    priority_queue<int, vector<int>, greater<int>>q;
    int i;
    for(i = 0; i < k; ++i)
        q.push(arr[i]);
    for(i = k; i < n; ++i){
        arr[i - k] = q.top();
        q.pop();
        q.push(arr[i]);
    }
    i = n - k;
    while(!q.empty()){
        arr[i++] = q.top();
        q.pop();
    }
    for(int i = 0; i < n; ++i)cout<<arr[i]<<" ";
}

int main() {
	int t, n, k, *arr;
	cin>>t;
	while(t--){
	    cin>>n>>k;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    sortKsortedArray(arr, n, k);
	    cout<<"\n";
	    delete []arr;
	}
	return 0;
}
