/*
* Find the smallest subarray length whose sum is greater than given value
*/

#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

int minimumLength(int arr[], int n, int x){
    int *temp;
    temp = new int[n];
    temp[0] = arr[0];
    if(temp[0] > x)return 1;
    int maxlen = n + 1;
    for(int i = 1; i < n; i++){
        temp[i] = temp[i - 1] + arr[i];
        if(temp[i] > x){
            int tmp = temp[i] - x - 1;
            int pos = lower_bound(temp, temp + i, tmp) - temp;
            if(temp[pos] > tmp)
                maxlen = min(maxlen, i - pos + 1);
            else
                maxlen = min(maxlen, i - pos);
        }
    }
    delete [] temp;
    return maxlen;
}

int main() {
    int t, n, x, *arr;
    cin>>t;
    while(t--){
        cin>>n>>x;
        arr = new int[n];
        for(int i = 0; i < n; ++i)cin>>arr[i];
        cout<<minimumLength(arr, n, x)<<"\n";
        delete []arr;
    }
	return 0;
}
