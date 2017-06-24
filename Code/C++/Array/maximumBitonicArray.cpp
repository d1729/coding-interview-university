#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int *arr;
	int t, n;
	cin>>t;
	while(t--){
	    int maxlen = 1;
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)
	        cin>>arr[i];
	    int *min_arr = new int[n];
	    int *max_arr = new int[n];
	    min_arr[0] = 1;
	    max_arr[n - 1] = 0;
	    for(int i = 1; i < n; i++)
	        min_arr[i] = arr[i] > arr[i - 1] ? 1 + min_arr[i - 1] : 1;
	    for(int i = n - 2; i >= 0; --i)
	        max_arr[i] = arr[i] > arr[i + 1] ? 1 + max_arr[i + 1] : 0;
	    for(int i = 0; i < n; ++i){
	        maxlen = max(maxlen, max_arr[i] + min_arr[i]);
	    }
	    cout<<maxlen<<"\n";
	    delete []min_arr;
	    delete []max_arr;
	}
	return 0;
}
