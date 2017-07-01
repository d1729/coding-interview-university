#include <iostream>
#include <algorithm>
using namespace std;

void Combinations(int arr[], int data[], int start, int end, int index, int r){
    if(index == r){
        for(int i = 0; i < r; ++i)
            cout<<data[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i = start; i < end && end - i + 1 >= r - index; ++i){
        data[index] = arr[i];
        Combinations(arr, data, i + 1, end, index + 1, r);
        while (i < end && arr[i] == arr[i + 1])
            ++i;
    }
}

void printArray(int arr[], int r, int n){
    sort(arr, arr + n);
    int *data = new int[r];
    Combinations(arr, data, 0, n, 0, r);
    delete [] data;
}

int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, r, n);
    return 0;
}
