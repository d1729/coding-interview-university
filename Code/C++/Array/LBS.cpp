#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxBitonicSubsequence(int arr[], int n){
    vector<int>left(n, 0);
    vector<int>right(n, 0);
    for(int i = 1; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(arr[j] < arr[i] && left[i] < left[j] + 1)
                left[i] = 1 + left[j];
        }
    }
    for(int i = n - 2; i >= 0; --i){
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[i] && right[i] < right[j] + 1)
                right[i] = 1 + right[j];
        }
    }
    int max_val = left[0] + right[0];
    for(size_t i = 1; i < n; ++i)
        max_val = max(max_val, left[i] + right[i]);
    return max_val + 1;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(size_t i = 0; i < n; ++i)cin>>arr[i];
	    cout<<maxBitonicSubsequence(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
