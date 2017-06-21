#include <iostream>
using namespace std;
int binMap[100000];

void printPairs(int *arr, int arr_size, int sum){
    int temp;
    for(int i = 0; i < 100000; ++i)binMap[i] = 0;
    for(int i = 0; i < arr_size; ++i){
        temp = sum - arr[i];
            if(temp >= 0 && binMap[temp] == 1)
            cout<<arr[i]<<" "<<temp<<"\n";
        binMap[arr[i]] = 1;
    }
}

int main(int argc, char const *argv[]) {
    int n, sum;
    int *arr;
    cin>>sum;
    cin>>n;
    arr = new int[n];
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    printPairs(arr, n, sum);
    return 0;
}
