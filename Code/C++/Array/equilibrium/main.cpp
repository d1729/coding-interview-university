#include <iostream>
#include <numeric>
using namespace std;

int equilibrium(int arr[], int n){
    int sum, leftSum = 0, i;
    sum = accumulate(arr, arr + n, 0);
    for(i = 0; i < n; ++i){
        sum -= arr[i];
        if(sum == leftSum)
            return i;
        leftSum += arr[i];
    }
    return -1;
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int eql = equilibrium(arr, sizeof(arr) / sizeof(arr[0]));
    if(eql == -1)
        cout<<"No equilibrium point exists\n";
    else
        cout<<eql<<"\n";
    return 0;
}