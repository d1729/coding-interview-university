#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    int start;
    int end;
};

bool isOverlapping(struct interval p1, struct interval p2){
    return p2.start > p1.end;
}

void printPairs(struct interval p[], int n){
    sort(p, p + n, [](struct interval& p1, struct interval& p2){
        return p1.start < p2.start;
    });
    struct interval p1;
    p1 = p[0];
    for(int i = 1; i < n; ++i){
        if(isOverlapping(p1, p[i])){
            cout<<p1.start<<" "<<p1.end<<" ";
            p1 = p[i];
        }
        else
            p1.end = max(p1.end, p[i].end);
    }
    cout<<p1.start<<" "<<p1.end<<"\n";
}

int main() {
	int t, n;
	struct interval* p;
	cin>>t;
	while(t--){
	    cin>>n;
	    p = new interval[n];
	    for(int i = 0; i < n; ++i)cin>>p[i].start>>p[i].end;
	    printPairs(p, n);
	    delete []p;
	}
	return 0;
}
