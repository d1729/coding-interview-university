/*
*       Sort an array according to the order defined by another array
*/

#include <iostream>
#include <algorithm>
using namespace std;

void relativeSort(int *A1, int *A2, int n, int m){
    int *temp;
    bool *isVisited;
    temp = new int[n];
    isVisited = new bool[n];
    for(int i = 0; i < n; ++i){
        temp[i] = A1[i];
        isVisited[i] = false;
    }
    sort(temp, temp + n);
    int pos = 0;
    for(int i = 0; i < m; ++i){
        if(binary_search(temp, temp + n, A2[i])){
            int count = upper_bound(temp, temp + n, A2[i]) - lower_bound(temp, temp + n, A2[i]);
            for(int j = pos; j < pos + count; ++j)A1[j] = A2[i];
            pos += count;
            for(int j = lower_bound(temp, temp + n, A2[i]) - temp; j < upper_bound(temp, temp + n, A2[i]) - temp; ++j)
                isVisited[j] = true;
        }
    }
    int k = pos;
    for(int i = 0; i < n; ++i)
        if(!isVisited[i])
            A1[k++] = temp[i];
    sort(A1 + pos, A1 + n);
    for(int i = 0; i < n; ++i)cout<<A1[i]<<" ";
    cout<<"\n";
}

int main() {
	int t, n, m, *A1, *A2;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    A1 = new int[n];
	    A2 = new int[m];
	    for(int i = 0; i < n; i++)cin>>A1[i];
	    for(int i = 0; i < m; ++i)cin>>A2[i];
	    relativeSort(A1, A2, n, m);
	    delete []A1;
	    delete []A2;
	}
	return 0;
}
