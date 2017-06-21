#include <iostream>
using namespace std;
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void segregate(int arr[], int size){
    int lo = 0, mid = 0, hi = size - 1;
    while (mid <= hi){
        switch (arr[mid]){
            case 0:
                swap(&arr[lo++], &arr[mid++]);
                break;
            case 1:
                ++mid;
                break;
            case 2:
                swap(&arr[mid], &arr[hi--]);
                break;
        }
    }
    for (int i = 0; i < size; ++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    segregate(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}