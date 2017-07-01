/*
*Put all the zeroes in the end
*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    int pos = 0;
	    for(int i = 0; i < n; i++)
	        if(arr[i] != 0)swap(arr[i], arr[pos++]);
	    for(; pos < n; ++pos)arr[pos] = 0;
	    for(int i = 0; i < n; ++i)cout<<arr[i]<<" ";
	    cout<<"\n";
	    delete []arr;
	}
	return 0;
}
