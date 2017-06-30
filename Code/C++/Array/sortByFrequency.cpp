#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

void sortByFrequency(int arr[], int n){
    map<int, int>m;
    vector<pair<int, int>>v;
    for(int i = 0; i < n; ++i){
        if(m.find(arr[i]) != m.end())m[arr[i]]++;
        else m[arr[i]] = 1;
    }
    map<int, int>::iterator it;
    for(it = m.begin(); it != m.end(); ++it)
        v.push_back(make_pair(it->first, it->second));
    sort(v.begin(), v.end(), [](pair<int, int>& p1, pair<int, int>& p2){
        if(p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second > p2.second;
    });
    int j = 0;
    for(auto it = v.begin(); it != v.end(); ++it)
        for(int i = 0; i < it->second; ++i)
            arr[j++] = it->first;
    for(int i = 0; i < n; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
        sortByFrequency(arr, n);
	    delete []arr;
	}
	return 0;
}
