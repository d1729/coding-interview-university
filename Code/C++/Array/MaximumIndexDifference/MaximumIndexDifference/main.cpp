/*
 * Find the maximum value of j - i such that A[j] > A[i]
 */
#include <iostream>
#include <algorithm>
using namespace std;

int maxDiff(int *arr, int n){
    int i, j, difference = -1;
    int *Lmin = (int *) malloc(sizeof(int *) * n);
    int *RMax = (int *) malloc(sizeof(int *) * n);
    Lmin[0] = arr[0];
    for (i = 1; i < n; ++i)
        Lmin[i] = min(Lmin[i - 1], arr[i]);
    RMax[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; --i)
        RMax[i] = max(arr[i], RMax[i + 1]);
    i = 0, j = 0;
    while(i < n && j < n){
        if(Lmin[i] < RMax[j]){
            difference = max(difference, j - i);
            ++j;
        }
        else
            ++i;
    }
    free(Lmin);
    free(RMax);
    return difference;
}

int main(int argc, const char * argv[]) {
    int arr[] ={1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<maxDiff(arr, size)<<"\n";
    return 0;
}
