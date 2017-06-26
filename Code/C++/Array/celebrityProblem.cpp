#include <iostream>
using namespace std;
#define N 8

bool  MATRIX[N][N] = {{0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};

bool knows(int a, int b){
    if(MATRIX[a][b])
        return true;
    return false;
}

int findCelebrity(int n){
    int left = 0, right = n -1;
    while (left < right) {
        if(knows(left, right))++left;
        else --right;
    }
    for(size_t i = 0; i < n; ++i){
        if(i != left && (knows(left, i) || !knows(i, left)))
            return -1;
    }
    return left;
}

int main(int argc, char const *argv[]) {
    int n = 4;
    if(findCelebrity(n) == -1)cout<<"No celebrity in the lot\n";
    else cout<<"celebrity id: "<<findCelebrity(n)<<"\n";
    return 0;
}
