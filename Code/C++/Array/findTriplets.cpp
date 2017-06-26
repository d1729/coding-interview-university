#include <iostream>
#include <algorithm>
using namespace std;

bool isTriplets(int arr[], int n, int x){
    sort(arr, arr + n);
    for(size_t i = 0; i < n; ++i){
        int sum = x - arr[i];
        int left = i + 1, right = n - 1;
        while(left < right){
            int val = arr[left] + arr[right];
            if(val == sum)return true;
            else if(val < sum) ++left;
            else --right;
        }
    }
    return false;
}

int main() {
	int t, n, x, *arr;
	cin>>t;
	while(t--){
	    cin>>n>>x;
	    arr = new int[n];
	    for(size_t i = 0; i < n; ++i)
	        cin>>arr[i];
	    if(isTriplets(arr, n, x))cout<<1<<"\n";
	    else cout<<0<<"\n";
	    delete []arr;
	}
	return 0;
}
