/*
 *Given an array and an integer k, find the maximum for each and every contiguous subarray of size k
 */
#include <iostream>
#include <deque>
using namespace std;

void printMax(int arr[], int n, int k){
    deque<int>Qi(k);
    int i;
    for (i = 0; i < k; ++i) {
        while (!Qi.empty() && arr[i] >= arr[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    for (; i < n; ++i) {
        cout<<arr[Qi.front()]<<" ";
        while (!Qi.empty() && Qi.front() <= i - k)
            Qi.pop_front();
        while (!Qi.empty() && arr[Qi.back()] <= arr[i])
            Qi.pop_back();
        Qi.push_back(i);
    }
    cout<<arr[Qi.front()]<<"\n";
}

int main(int argc, const char * argv[]) {
    int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    printMax(arr, n, k);
    return 0;
}
