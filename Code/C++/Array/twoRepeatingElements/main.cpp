/* Given an array of n + 2 elements where the elements range from 1 to n, find the two repeating elements*/
#include <iostream>
using namespace std;

void printRepeating(int arr[], int size){
    int x = 0, y = 0, set_bit_no, i;
    int _xor = arr[0];
    /*
     * Calculate x ^ y in the next to for loops
     */
    for (i = 0; i < size; ++i)
        _xor ^= arr[i];
    for(i = 1; i < size - 1; ++i)
        _xor ^= i;
    set_bit_no = _xor & ~(_xor - 1); //Find the rightmost bit where the two bits differ for x and y
    for(i = 0; i < size; ++i){
        if (arr[i] & set_bit_no)
            x ^= arr[i];
        else
            y ^= arr[i];
    }
    for(i = 1; i < size - 1; ++i){
        if(i & set_bit_no)
            x ^= i;
        else
            y ^= i;
    }
    cout << x <<" " <<y <<"\n";
}

int main() {
    int arr[] = {4, 2, 4, 5, 2, 3, 1};
    printRepeating(arr, sizeof(arr) / sizeof(int));
    return 0;
}