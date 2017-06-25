/*
    Find the element that occurs at least more than n/2 times in an array(n is the size of the arrray)
*/
#include <iostream>
using namespace std;

int findMajorityElement(int arr[], int size){
    int index = 0, count = 1, i;
    for(i = 1; i < size; i++){
        if(arr[i] == arr[index])count++;
        else --count;
        if(count == 0){
            index = i;
            count = 1;
        }
    }
    return arr[index];
}

int main(int argc, char const *argv[]) {
    int *arr, size, count = 0;
    cin>>size;
    arr = new int[size];
    for(int i = 0; i < size; i++)
        cin>>arr[i];
    int val = findMajorityElement(arr, size);
    for(int i = 0; i < size; ++i)
        if(arr[i] == val)
            ++count;
    if(count > size / 2)
        cout<<val<<"\n";
    else
        cout<<"No majority element is present\n";
    return 0;
}
