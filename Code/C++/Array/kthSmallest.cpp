#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

int partition(int arr[], int l, int r){
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] <= arr[r])
            swap(arr[j], arr[++i]);
    }
    swap(arr[++i], arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r){
    srand((int)time(0));
    int pivot = rand() % (r - l + 1);
    swap(arr[pivot + l], arr[r]);
    return partition(arr, l, r);
}

int kthSmallest(int arr[], int l, int r, int k){
    if(k > 0 && k <= r - l + 1){
        int pos = randomPartition(arr, l, r);
        if(pos - l == k - 1)
            return arr[pos];
        if(pos - l > k - 1)
            return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }
    return INT_MAX;
}

int main() {
	int t, n, k, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    cin>>k;
	    cout<<kthSmallest(arr, 0, n - 1, k)<<"\n";
	    delete []arr;
	}
	return 0;
}
