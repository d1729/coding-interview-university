#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void rotate(int arr[], int n, int d){
    //n -> size of the array
    //d -> rotate element to the left
    d = d % n;
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}
int main(int argc, char const *argv[]) {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(int);
    rotate(arr, sizeof(arr) / sizeof(int), 2);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
