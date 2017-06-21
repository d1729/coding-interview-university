/*
 This program fnds the minimum and maximum values in the array in 3(n - 1) / 2 for odd number of values
 and in 3n/2 - 2 comparisons for even number of elements
 */
#include<iostream>
using namespace std;

typedef struct pair1{
    int min, max;
}pair1;

pair1 findMinMax(int arr[], int size){
    int i;
    pair1 minmax;
    if(size % 2){
        minmax.max = arr[0];
        minmax.min = arr[1];
        i = 1;
    } else{
        minmax.min = arr[0] <= arr[1] ? arr[0] : arr[1];
        minmax.max = arr[0] >= arr[1] ? arr[0] : arr[1];
        i = 2;
    }

    while (i < size){
        minmax.min = arr[i] > arr[i + 1] ? arr[i + 1] < minmax.min ? arr[i + 1] : minmax.min : arr[i] < minmax.min ? arr[i] : minmax.min;
        minmax.max = arr[i] > arr[i + 1] ? arr[i] > minmax.max ? arr[i] : minmax.max : arr[i + 1] > minmax.max ? arr[i + 1] : minmax.max;
        i += 2;
    }
    return minmax;
}

int main(){
    int arr[] = {1000, 11, 445, 1, 330, 3000};
    int size = sizeof(arr) / sizeof(int);
    pair1 minmax = findMinMax(arr, size);
    cout<<minmax.min << " "<<minmax.max <<"\n";
    return 0;
}