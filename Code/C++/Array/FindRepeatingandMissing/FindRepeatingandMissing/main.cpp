/*
 *Find the repeating and missing number from the array of size n where the elements range from 1 to n
 */
#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, const char * argv[]) {
    int arr[] = {1,2, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++){
        if(arr[abs(arr[i]) - 1] < 0)
            cout<<"Repeating number: "<<abs(arr[i])<<"\n";
        else
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
    }
    for (int i = 0; i < n; i ++) {
        if(arr[i] > 0){
            cout<<"Missing number: "<<i + 1<<"\n";
            break;
        }
    }
    return 0;
}
