#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n, *arr, *dp;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    dp = new int[n];
	    for(int i = 0; i < n; ++i){
	        cin>>arr[i];
	        dp[i] = arr[i];
	    }
	    for(int i = 1; i < n; ++i){
	        for(int j = i - 1; j >= 0; --j){
	            if(arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
	                dp[i] = arr[i] + dp[j];
	        }
	    }

	    cout<<*max_element(dp, dp + n)<<"\n";
	    delete []arr;
	    delete []dp;
	}
	return 0;
}
