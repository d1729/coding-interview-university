#include <iostream>
#include <algorithm>
using namespace std;

int findMinDistance(int arr[], int n, int x, int y){
    if (x == y)
        return 0;
    int pos = -1, i, mindist = INT_MAX;
    for (i = 0; i < n; ++i) {
        if(arr[i] == x || arr[i] == y){
            if (pos == -1)
                pos = i;
            else if (arr[i] != arr[pos]){
                mindist = min(mindist, i - pos);
                pos = i;
            }
            else
                pos = i;
        }
    }
    if(mindist == INT_MAX)
        return -1;
    return mindist;
}

int main(int argc, const char * argv[]) {
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3, y = 6;
    cout<<findMinDistance(arr, size, x, y)<<"\n";
    return 0;
}
