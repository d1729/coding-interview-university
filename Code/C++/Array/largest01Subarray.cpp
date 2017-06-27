#include <iostream>
#include <vector>
using namespace std;

int maxLen(int arr[], int n)
{
    int count = 0, len = 0;
    vector<int>zeros(n, -1);
    vector<int>ones(n, -1);
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            ++count;
            if(count > 0 && zeros[count - 1] == -1) zeros[count - 1] = i;
        }
        else{
            --count;
            if(count < 0 && ones[abs(count) - 1] == -1) ones[abs(count) - 1] = i;
        }
        if(count > 0) len = max(len, i - zeros[count - 1]);
        else if(count < 0) len = max(len, i - ones[abs(count) - 1]);
        else len = i + 1;
    }
    return len;
}

int main(int argc, char const *argv[]) {
    int t, n, *arr;
    cin>>t;
    while(t--){
        cin>>n;
        arr= new int[n];
        for(int i = 0; i < n; ++i)cin>>arr[i];
        cout<<maxLen(arr, n)<<"\n";
        delete [] arr;
    }
    return 0;
}
