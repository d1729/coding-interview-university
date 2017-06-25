#include<iostream>
#include<unordered_map>
using namespace std;

void findSubArray(int arr[], int n, int val){
    int i, sum = 0;
    unordered_map<int, int>m;
    for(i = 0; i < n; ++i){
        sum += arr[i];
        if(sum == val){
            cout<<"Sum found between 0 and "<<i<<"\n";
            return;
        }
        if(m.find(sum - val) != m.end()){
            cout<<"Sum found between "<<m[sum - val] + 1<<" and "<<i<<"\n";
            return;
        }
        m[sum] = i;
    }
    cout<<"The given value is not found\n";
}

int main(int argc, char const *argv[]) {
    int arr[] = {10, 2, -2, -20, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    findSubArray(arr, n, 0);
    return 0;
}
