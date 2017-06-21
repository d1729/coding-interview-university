#include <iostream>
using namespace std;

void printArray(int arr[], int size){
    int min_index = size - 1, max_index = 0, left = -1, right = size, i;
    for(i = 1; i < size; ++i){
        if(arr[i] < arr[max_index])
            right = i;
        else
            max_index = i;
    }
    for(i = size - 2; i >= 0; --i){
        if(arr[i] > arr[min_index])
            left = i;
        else
            min_index = i;
    }
    if(left == -1 or right == size )
        cout<<"The array is already sorted\n";
    else
        cout<<left<<" "<<right<<"\n";
}

int main() {
    int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    return 0;
}