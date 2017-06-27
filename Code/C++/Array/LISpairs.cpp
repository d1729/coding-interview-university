#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct val{
    int first;
    int second;
};

int maxChainLen(struct val p[],int n)
{
    sort(p, p + n, [](struct val &p1, struct val &p2){
        if(p1.first == p2.first)return p1.second < p2.second;
        return p1.first < p2.first;
    });
    vector<int>v(n, 1);
    for(int i = 1; i < n; ++i)
        for(int j = i - 1; j >= 0; --j)
            if(p[j].second < p[i].first)
                v[i] = max(v[i], 1 + v[j]);
    return *max_element(v.begin(), v.end());
}

int main(int argc, char const *argv[]) {
    int t, n, x, y;
    struct val *arr;
    cin>>t;
    while(t--){
        cin>>n;
        arr = new struct val[n];
        for(int i = 0; i < n; i++){
            cin>>arr[i].first>>arr[i].second;
        }
        cout<<maxChainLen(arr, n);
        delete [] arr;
    }
    return 0;
}
