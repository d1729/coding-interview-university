#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int maxProduct(int arr[], int n){
    if(n == 1)return arr[0];
    int max_ending = 0, min_ending = 0, max_val = INT_MIN;
    for(int i = 0; i < n; ++i){
        if(max_ending == 0 && min_ending ==0){
            if(arr[i] > 0){
                max_ending = arr[i];
                min_ending = 1;
            }
            else if(arr[i] == 0){
                max_ending = 0;
                min_ending = 0;
            }
            else{
                max_ending = 0;
                min_ending = arr[i];
            }
        }
        else{
            if(arr[i] == 0){
                max_ending = 0;
                min_ending = 0;
            }
            else if(arr[i] > 0){
                max_ending = max(max_ending * arr[i], arr[i]);
                min_ending = min(min_ending * arr[i], arr[i]);
            }
            else{
                int temp = max_ending;
                max_ending = max(min_ending * arr[i], arr[i]);
                min_ending = min(temp * arr[i], arr[i]);
            }
        }
        max_val = max(max_val, max_ending);
    }
    return max_val;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cout<<maxProduct(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
