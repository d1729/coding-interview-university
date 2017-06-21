#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char const *argv[]) {
    int arr[] = {2, 5, 2, 8, 5, 6, 8, 8};
    int n = sizeof(arr) / sizeof(int);
    /*cin>>n;
    arr = new int[n];
    for(int i = 0; i < n; ++i)
        cin>>arr[i];
    */
    map<int, pair<int, int>> m;
    for(int i = 0; i < n; ++i){
        if(m.find(arr[i]) != m.end())
            ++m[arr[i]].first;
        else
            m.insert(make_pair(arr[i], make_pair(1, i)));
    }
    vector<pair<int, pair<int, int>>>v;
    map<int, pair<int, int> >::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
        v.push_back(make_pair(it->first, it->second));
    sort(v.begin(), v.end(), [](pair<int, pair<int, int>>&p1, pair<int, pair<int, int>>&p2){
        if(p1.second.first == p2.second.first)
            return p1.second.second < p2.second.second;
        return p1.second.first > p2.second.first;
    });
    int i = 0;
    for(int j = 0; j < v.size(); ++j){
        int sz = v[j].second.first;
        while (sz > 0) {
            arr[i] = v[j].first;
            --sz;
            ++i;
        }
    }
    for(i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
