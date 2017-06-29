#include <iostream>
#include <algorithm>
using namespace std;

int remainder(int x){
    int rem = 10;
    while(x / rem > 0)
        rem *= 10;
    return rem;
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    sort(arr, arr + n, [](int& x, int& y){
	        return x * remainder(y) + y > y * remainder(x) + x;
	    });
	    if(arr[0] == 0)cout<<0<<"\n";
	    else{
	        for(int i = 0; i < n; ++i)cout<<arr[i];
	        cout<<"\n";
	    }
	    delete []arr;
	}
	return 0;
}
