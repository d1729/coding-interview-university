#include <iostream>
using namespace std;

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    int x = 0, y = 0, xor1 = arr[0];
	    for(size_t i = 1; i < n; ++i){
	        xor1 ^= arr[i];
	    }
	    int set_bit_no = xor1 & ~(xor1 - 1);
	    for(size_t i = 0; i < n; ++i){
	        if(set_bit_no & arr[i])
	            x ^= arr[i];
	        else
	            y ^= arr[i];
	    }
	    if(x > y)cout<<x<<" "<<y<<"\n";
	    else cout<<y<<" "<<x<<"\n";
	    delete []arr;
	}
	return 0;
}
