#include <iostream>
#include <stack>
using namespace std;

int* nextGreaterElment(int* arr, int size){
    int *result = new int[size];
    stack<int>s;
    for(int i = size - 1; i >= 0; --i){
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
        if(s.empty())
            result[i] = -1;
        else
            result[i] = s.top();
        s.push(arr[i]);
    }
    return result;
}

int main() {
    int arr[] = {13, 7, 6, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int* result = nextGreaterElment(arr, size);
    for (int i = 0; i < size; ++i)
        cout<<result[i]<<" ";
    cout<<"\n";
    return 0;
}