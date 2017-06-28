#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void randomShuffle(int arr[], int n){
    srand((int)time(0));
    for(int i = n - 1; i >= 0; --i)
        swap(arr[i], arr[rand() % (i + 1)]);
}

int main(int argc, char* argv[])
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    randomShuffle(arr, n);
    for(int i = 0; i < n; ++i)cout<<arr[i]<<" ";
    cout<<"\n";
    return 0;
}
