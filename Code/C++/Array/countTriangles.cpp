#include <iostream>
#include <algorithm>
using namespace std;

int countTriangles(int arr[], int n){
    sort(arr, arr + n);
    int count = 0;
    for(int i = n - 1; i > 1; --i){
        int j = i - 1;
        int k = 0;
        while(j > k){
            if(arr[k] + arr[j] > arr[i]){
                count += j - k;
                --j;
            }
            else
                ++k;
        }
    }
    return count;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int [n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cout<<countTriangles(arr, n)<<"\n";
	    delete []arr;
	}
	return 0;
}
