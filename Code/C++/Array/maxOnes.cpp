#include <iostream>
#include <algorithm>
using namespace std;

int maxOnes(int **arr, int R, int C){
    int lowest = lower_bound(arr[0], arr[0] + C, 1) - arr[0];
    int ans = 0;
    for(int i = 1; i < R; ++i){
        if(lowest == 0)return ans;
        if(arr[i][lowest - 1] == 1)ans = i;
        while(lowest > 0 && arr[i][lowest - 1] == 1)
            --lowest;
    }
    return ans;
}

int main() {
	int t, r, c, **arr;
	cin>>t;
	while(t--){
	    cin>>r>>c;
	    arr = new int* [r];
	    for(int i = 0; i < r; ++i)arr[i] = new int[c];
	    for(int i = 0; i < r; ++i)
	        for(int j = 0; j < c; ++j)
	            cin>>arr[i][j];
	    cout<<maxOnes(arr, r, c)<<"\n";
	    for(int i = 0; i < r; ++i)delete [] arr[i];
	    delete []arr;
	}
	return 0;
}
