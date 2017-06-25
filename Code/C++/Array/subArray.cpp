#include <iostream>
using namespace std;

typedef struct ans{
    int left, right;
}ans;

ans subarray(int arr[], int n, int val){
    int left = 0, right = 0;
    int sum = arr[0];
    ans ans1;
    ans1.left = -1;
    ans1.right = -1;
    while(left < n && right < n){
        if(val == sum){
            ans1.left = left;
            ans1.right = right;
            return ans1;
        }
        else if(sum < val){
            if(right == n - 1)
                return ans1;
            sum += arr[++right];
        }
        else{
            if(left == n - 1)
                return ans1;
            sum -= arr[left++];
            if(left > right)
                sum += arr[++right];
        }
    }
    return ans1;
}

int main() {
	int t, n, *arr, val;
	cin>>t;
	while(t--){
	    cin>>n>>val;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)
	        cin>>arr[i];
	    ans ans1 = subarray(arr, n, val);
	    delete []arr;
	    if(ans1.left == -1 )cout<<-1<<"\n";
	    else
	        cout<<ans1.left + 1<<" "<<ans1.right + 1<<"\n";
	}
	return 0;
}
