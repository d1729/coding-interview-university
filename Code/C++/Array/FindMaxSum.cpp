#include <iostream>
#include <algorithm>
using namespace std;

int findMaxSum(int arr[], int size){
    int incl = arr[0];
    int excl = 0, excl_new;
    for(int i = 1; i < size; ++i){
        excl_new = max(incl, excl);
        incl = excl + arr[i];
        excl = excl_new;
    }
    return max(incl, excl);
}

int main(){
    int arr[] = {5, 5, 10, 100, 10, 5};
    cout<<findMaxSum(arr, sizeof(arr) / sizeof(int))<<"\n";
    return 0;
}