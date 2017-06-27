#include <iostream>
#include <vector>
using namespace std;

vector<int> find3Numbers(vector<int> A, int N)
{
   vector<int>v(3, 0);
   vector<int>smaller(N, -1);
   vector<int>greater(N, -1);
   int smallest = A[0];
   int greatest = A[N - 1];
   for(int i = 1; i < N; ++i){
       if(A[i] > smallest)smaller[i] = smallest;
       else smallest = min(smallest, A[i]);
   }
   for(int i = N - 2; i >= 0; --i){
       if(A[i] < greatest)greater[i] = greatest;
       else greatest = max(greatest, A[i]);
   }
   for(int i = 0; i < N; ++i){
       if(smaller[i] != -1 && greater[i] != -1){
           v[0] = smaller[i];
           v[1] = A[i];
           v[2] = greater[i];
           return v;
       }
   }
   v.clear();
   return v;
}

int main(int argc, char const *argv[]) {
    int t, n;
    cin>>t;
    while (t--) {
        cin>>n;
        vector<int>A(n);
        for(int i = 0; i < n; ++i)cin>>A[i];
        vector<int>v =  find3Numbers(A, n);
        if(v.empty())cout<<"No 3 consecutive elements found\n";
        else{
            for(int i = 0; i < 3; ++i)cout<<v[i]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
