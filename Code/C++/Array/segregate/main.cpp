#include <iostream>
using namespace std;

void segregate(int arr[], int size){
    int left = 0, right = size - 1;
    while(left < right){
        while (arr[left] == 0 && left < right)
            ++left;
        while(arr[right] == 1 && left < right)
            --right;
        if(left < right){
            arr[left++] = 0;
            arr[right--] = 1;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    segregate(arr, sizeof(arr) / sizeof(int));
    for (int i = 0; i < sizeof(arr) / sizeof(int); ++i) {
        cout<<arr[i] <<" ";
    }
    cout<<endl;
    return 0;
}