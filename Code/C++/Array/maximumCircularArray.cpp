#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int kadane(int arr[], int n){
    int max_ending = arr[0];
    int max_val = max_ending;
    for(int i = 1; i < n; ++i){
        max_ending = (arr[i] < arr[i] + max_ending) ? arr[i] + max_ending : arr[i];
        max_val = max(max_val, max_ending);
    }
    return max_val;
}

int maxCircularSum(int arr[], int n){
    int max_straight = kadane(arr, n);
    for(int i = 0; i < n; ++i) arr[i] = -arr[i];
    int max_reverse = (-accumulate(arr, arr + n, 0)) + kadane(arr, n);
    return (max_straight > max_reverse) ? max_straight : max_reverse;
}

int main() {
	int t, n, *arr, flag = 0;
	cin>>t;
	while(t--){
	    flag = 0;
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i){
	        cin>>arr[i];
	        if(arr[i] >= 0)flag = 1;
	    }
	    if(flag == 0)cout<<kadane(arr, n)<<"\n";
	    else cout<<maxCircularSum(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
