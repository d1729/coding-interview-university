#include <iostream>
#include <numeric>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    if(accumulate(p, p + n, 0, [](int sum, petrolPump& p1){
        return sum + p1.petrol - p1.distance;
    }) < 0) return -1;
    int start = 0, max_ending = p[0].petrol - p[0].distance;
    for(int i = 1; i < n; ++i){
        int temp = p[i].petrol - p[i].distance;
        if(max_ending < 0){
            start = i;
            max_ending = temp;
        }
        else
            max_ending += temp;
   }
   return start;
}

int main(int argc, char* argv[])
{
    int t, n;
    struct petrolPump *p;
    cin>>t;
    while(t--){
        cin>>n;
        p = new petrolPump[n];
        for(int i = 0; i < n; ++i)cin>>p[i].petrol>>p[i].distance;
        cout<<tour(p, n);
        delete [] p;
    }
    return 0;
}
