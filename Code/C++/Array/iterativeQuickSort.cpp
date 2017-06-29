#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int l, int h){
    int i = l - 1;
    for(int j = l; j < h; ++j)
        if(arr[j] <= arr[h])
            swap(arr[i], arr[j]);
    swap(arr[i + 1], arr[h]);
    return (i + 1);
}

void quickSort(int arr[], int l, int h){
    int stack[h - l + 1];
    int top = l - 1;
    stack[++top] = l;
    stack[++top] = h;
    while (top >= 0){
        h = stack[top--];
        l = stack[top--];
        int p = partition(arr, l, h);
        if(p - 1 > l){
            stack[++top] = l;
            stack[++top] = p - 1;
        }
        if(p + 1 < h){
            stack[++top] = p + 1;
            stack[++top] = h;
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[] = {4, 3, 5, 2, 1, 3, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; ++i)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
