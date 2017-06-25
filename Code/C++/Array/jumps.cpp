#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
	int t, n;
	int *arr, *dp;
	cin>>t;
	while(t--){
	    cin>>n;
	    dp = new int[n];
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)
	        cin>>arr[i];
	    dp[0] = 0;
	    for(int i = 1; i < n; ++i)
	        dp[i] = INT_MAX;
	    for(int i = 0; i < n - 1; ++i)
	        if(dp[i] != INT_MAX)
	            for(int j = 1; j <= arr[i] && (i + j) < n; ++j)
	                dp[i + j] = min(dp[i + j], 1 + dp[i]);

	    if(dp[n -1] == INT_MAX)
	        dp[n-1] = -1;
	    cout<<dp[n -1]<<"\n";
	    delete []arr;
	    delete []dp;
	}
	return 0;
}
