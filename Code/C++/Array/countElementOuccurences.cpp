/*
*Given an array of size n, find all elements in array that appear more than n/k times.
*/

#include <iostream>
using namespace std;

struct eleCount
{
    long long int e;  // Element
    long long int c;  // Count
};

void moreThanNdK(long long int arr[], long long int n, long long int k)
{
    if(k < 2)return;
    struct eleCount temp[k - 1];
    int i;
    for(i = 0; i < k - 1; ++i){
        temp[i].c = 0;
        temp[i].e = -32000;
    }
    for(i = 0; i < n; ++i){
        int j = 0;
        for(j = 0; j < k - 1; ++j){
            if(temp[j].e == arr[i]){
                temp[j].c++;
                break;
            }
        }
        if(j == k - 1){
            int p = 0;
            for(p = 0; p < k - 1; ++p){
                if(temp[p].c == 0){
                    temp[p].e = arr[i];
                    temp[p].c = 1;
                    break;
                }
            }
            if(p == k - 1)
                for(p = 0; p < k - 1; ++p)
                    temp[p].c -= 1;
        }
    }
    int count = 0;
    for(i = 0; i < k - 1; ++i){
        int cnt = 0;
        for(int j = 0; j < n; ++j)
            if(arr[j] == temp[i].e)
                ++cnt;
        if(cnt > n / k)++count;
    }
    cout<<count<<"\n";
}

int main(int argc, char const *argv[]) {
    int t, n, *arr, k;
    cin>>t;
    while(t--){
        cin>>n;
        arr = new int[n];
        for(int i = 0; i < n; ++i)cin>>arr[i];
        cin>>k;
        moreThanNdK(arr, n, k);
        delete [] arr;
    }
    return 0;
}
