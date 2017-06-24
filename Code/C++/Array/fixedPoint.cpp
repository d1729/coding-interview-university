#include <iostream>
using namespace std;

int findFixedPoint(int arr[], int left, int right){
    if(left <= right){
        int mid = left + (right - left) / 2;
        if(arr[mid] == mid)
            return mid;
        else if(arr[mid] < mid)
            return findFixedPoint(arr, mid + 1, right);
        else
            return findFixedPoint(arr, left, mid - 1);
    }
    return -1;
}

int main() {
	int arr[] = {-10, -1, 0, 3, 10, 11, 30, 50, 100};
	int siz= sizeof(arr) / sizeof(arr[0]);
	cout << findFixedPoint(arr, 0, siz - 1) << endl;
	return 0;
}
