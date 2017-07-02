/*
*   Merge K sorted arrays
*/
#include <iostream>
#include <queue>
using namespace std;
#define n 2

typedef pair<int, pair<int, int>>p;
class Compare{
public:
    bool operator()(p& p1, p& p2){
        return p1.first > p2.first;
    }
};
int* mergeKArrays(int arr[][n], int k)
{
    int *result = new int[k * k];
    priority_queue<p, vector<p>, Compare>q;
    for(int i = 0; i < k; ++i)
        q.push(make_pair(arr[i][0], make_pair(i, 0)));
    int l = 0;
    while(!q.empty()){
         p p1 = q.top();
         q.pop();
         int i = p1.second.first;
         int j = p1.second.second;
         result[l++] = p1.first;
         if(j < k - 1)
            q.push(make_pair(arr[i][j + 1], make_pair(i, j + 1)));
    }
    return result;
}

int main(int argc, char const *argv[]) {
    int arr[][2] =  {{68, 200},{63, 71}};
    int* results = mergeKArrays(arr, 2);
    for(int i = 0; i < n * n; ++i)cout<<results[i]<<" ";
    cout<<"\n";
    return 0;
}
