#include <iostream>
#include <algorithm>
using namespace std;

bool isConsecutive(int *arr, int size){
    int min_val = *min_element(arr, arr + size);
    int max_val = *max_element(arr, arr + size) + 1;
    int i;
    if(max_val - min_val != size)
        return false;
    for(i = 0; i < size; ++i){
        if (arr[i] % max_val - min_val >= size)
            return false;
        arr[arr[i] % max_val - min_val] += max_val;
    }
    for(i = 0; i < size; ++i)
        if (arr[i] / max_val != 1)
            return false;
    return true;
}

int main() {
    int arr[] = {7, 6, 5, 5, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    if(isConsecutive(arr, size))
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
    return 0;
}