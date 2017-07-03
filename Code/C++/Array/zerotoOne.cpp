#include <iostream>
using namespace std;

int maxIndex(int *arr, int n){
    int index = -1, max_len = 0;
    int curr = 0, prev = -1, pre_prev = -1;
    while (curr < n) {
        if(arr[curr] == 0){
            int len = curr - pre_prev;
            if(len > max_len){
                index = curr;
                max_len = len;
            }
            pre_prev = prev;
            prev = curr;
        }
        ++curr;
    }
    if(n - pre_prev > max_len)
        index  = prev;
    return index;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxIndex(arr, n)<<"\n";
    return 0;
}
