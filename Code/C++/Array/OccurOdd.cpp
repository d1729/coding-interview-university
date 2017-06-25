#include <iostream>
using namespace std;

int main(){
    int *arr;
    int size, val;
    cin>>size;
    arr = new int[size];
    for(int i = 0; i < size; i ++)
        cin>>arr[i];
    val = arr[0];
    for(int i = 1; i < size; ++i)
        val ^= arr[i];
    cout<<val<<"\n";
    return 0;
}
