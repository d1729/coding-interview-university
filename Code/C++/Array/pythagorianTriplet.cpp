#include <iostream>
#include <algorithm>
using namespace std;

bool isPyth(int arr[], int n){
    for(int i = 0; i < n; ++i)arr[i] *= arr[i];
    sort(arr, arr + n);
    for(int i = n - 1; i >= 2; --i){
        int j = 0, k = i - 1;
        while(j < k){
            if(arr[j] + arr[k] == arr[i])return true;
            else if(arr[j] + arr[k] < arr[i]) ++j;
            else --k;
        }
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
	    if(isPyth(arr, n))cout<<"Yes\n";
	    else cout<<"No\n";
	    delete []arr;
	}
	return 0;
}
