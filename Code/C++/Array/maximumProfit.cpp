#include <iostream>
using namespace std;

int maxProfit(int arr[], int n){
    int smallest = 0, flag = 0;
    for(int i = 1; i < n; ++i){
        if(arr[i] <= arr[i - 1]){
            if(smallest != i - 1){
                cout<<"("<<smallest<<" "<<i - 1<<") ";
                flag = 1;
            }
            smallest = i;
        }
    }
    if(smallest != n - 1){
        cout<<"("<<smallest<<" "<<n - 1<<") ";
        flag = 1;
    }
    if(flag == 0)cout<<"No Profit";
    cout<<"\n";
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    maxProfit(arr, n);
	    delete []arr;
	}
	return 0;
}
