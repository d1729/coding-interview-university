#include <iostream>
using namespace std;
#define NA -1

void mergeArr(int mPlusN[], int N[], int size1, int size2){
    int i = size2, j = 0, k = 0;
    while(k < (size1 + size2)){
        if((i < (size1 + size2) && mPlusN[i] <= N[j]) || j == size2){
            mPlusN[k] = mPlusN[i];
            ++i;
        }
        else{
            mPlusN[k] = N[j];
            ++j;
        }
        ++k;
    }
}

void moveToEnd(int mPlusN[], int size){
    int i = size - 1;
    for(int j = size - 1; j >= 0; --j){
        if(mPlusN[j] != NA){
            mPlusN[i] = mPlusN[j];
            --i;
        }
    }
}

int main(int argc, char const *argv[]) {
    int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
    int N[] = {5, 7, 9, 25};
    int size1 = sizeof(mPlusN) / sizeof(int);
    int size2 = sizeof(N) / sizeof(int);
    moveToEnd(mPlusN, size1);
    mergeArr(mPlusN, N, size1 - size2, size2);
    for(int i = 0; i < size1; ++i)
        cout<<mPlusN[i]<<" ";
    return 0;
}
