#include <iostream>
#include <algorithm>
using namespace std;

struct pairSum{
    int first, second, sum;
};

bool noCommons(struct pairSum a, struct pairSum b){
    if((a.first == b.second) || (a.first == b.first) || (a.second == b.first) || (a.second ==b.second))
        return false;
    return true;
}

void findFourElements(int arr[], int n, int Sum){
    int i, j, k = 0;
    sort(arr, arr + n);
    int size = n * ( n - 1) / 2;
    struct pairSum aux[size];
    for(i = 0; i < n - 1; ++i){
        for(j = i + 1; j < n; ++j){
            aux[k].first = i;
            aux[k].second = j;
            aux[k].sum = arr[i] + arr[j];
            k++;
        }
    }
    sort(aux, aux + size, [](struct pairSum& p1, struct pairSum& p2){
        return p1.sum < p2.sum;
    });
    i = 0, j = size - 1;
    while(i < size && j >= 0){
        if((aux[i].sum + aux[j].sum == Sum) && (noCommons(aux[i], aux[j]))){
            cout<<arr[aux[i].first]<<" "<<arr[aux[i].second]<<" "<<arr[aux[j].first]<<" "<<arr[aux[j].second]<<"\n";
            return;
        }
        else if (aux[i].sum + aux[j].sum < Sum)
            i++;
        else
            j--;
    }

}

int main() {
	int t, n, *arr, sum;
	cin>>t;
	while(t--){
	    cin>>n>>sum;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    findFourElements(arr, n, sum);
	    delete []arr;
	}
	return 0;
}
