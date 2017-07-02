/*
*   Find the number of pairs (x, y) for which x ^ y > y ^ x;
*/

#include <iostream>
#include <algorithm>
using namespace std;

int countPairs(int *x, int *y, int m, int n){
    int count = 0, pos;
    sort(y, y + n);
    int onez = 0;
    if(binary_search(y, y + n, 1))onez = upper_bound(y, y + n, 1) - y;
    for(int i = 0; i < m; ++i){
        if(x[i] <= 1)continue;
        else{
            if(x[i] == 2)
                pos = upper_bound(y, y + n, 4) - y;
            else{
                if(x[i] == 3)
                    count += upper_bound(y, y + n, 2) - lower_bound(y, y + n, 2);
                pos = upper_bound(y , y + n, x[i]) - y;
            }
            count += onez + n - pos;
        }
    }
    return count;
}

int main() {
	int t, m, n, *x, *y;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    x = new int[m];
	    y = new int[n];
	    for(int i = 0; i < m; ++i)cin>>x[i];
	    for(int i = 0; i < n; ++i)cin>>y[i];
	    cout<<countPairs(x, y, m, n)<<"\n";
	    delete []x;
	    delete []y;
	}
	return 0;
}
