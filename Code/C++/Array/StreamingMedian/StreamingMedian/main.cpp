#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define MAX_HEAP_SIZE 1024

/*bool Greater(int a, int b){return a > b;}
bool Smaller(int a, int b){return a < b;}



class Heap{
protected:
    int *A;
    int heapSize;
    bool (*comp)(int, int);
    int left(int i){return (i << 1) + 1;}
    int right(int i){return (i + 1) << 1;}
    int parent(int i){return (i - 1) >> 1;}
    
public:
    Heap(int *a, bool (*c)(int, int)):A(a), comp(c){
        heapSize = 0;
    }
    
    virtual ~Heap(){
        if(A)
            delete []A;
    }
    
    int top(){
        if(heapSize == 0)
            throw "Heap is empty\n";
        return A[0];
    }
    
    int Count(){return heapSize;}
    
    void heapify(int i){
        int l = left(i);
        int r = right(i);
        int temp = i;
        if (l < heapSize && !comp(A[i], A[l]))
            temp = l;
        if (r < heapSize && !comp(A[temp], A[r]))
            temp = r;
        if(temp != i){
            swap(A[temp], A[i]);
            heapify(temp);
        }
    }
    
    int deleteTop(){
        if(heapSize == 0)
            throw "no elements in the Heap\n";
        swap(A[0], A[heapSize - 1]);
        --heapSize;
        heapify(0);
        return A[heapSize];
    }
    
    bool insertHelper(int key){
        if(heapSize == MAX_HEAP_SIZE)
            throw "Heap is full\n";
        A[heapSize++] = key;
        int i = heapSize - 1;
        while (i > 0 && !comp(A[parent(i)], A[i])) {
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
        return true;
    }
    
    virtual bool Insert(int e) = 0;
    virtual int  GetTop() = 0;
    virtual int  ExtractTop() = 0;
    virtual int  GetCount() = 0;
};

class MaxHeap : public Heap{
public:
    MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater){}
    ~MaxHeap() {}
    
    bool Insert(int e){
        return insertHelper(e);
    }
    
    int GetTop() {
        return top();
    }
    
    int ExtractTop() {
        return deleteTop();
    }
    
    int GetCount() {
        return Count();
    }
    
    
};

class MinHeap : public Heap{
public:
    MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) {}
    ~MinHeap() {}
    
    bool Insert(int e){
        return insertHelper(e);
    }
    
    int GetTop() {
        return top();
    }
    
    int ExtractTop(){
        return deleteTop();
    }
    
    int GetCount(){
        return Count();
    }
    
};

double findMedian(int e, double &m, Heap &l, Heap &r){
    int hp = biggerheap(l.GetCount(), r.GetCount());
    switch (hp) {
        case 1:
            if(e < m){
                r.Insert(l.ExtractTop());
                l.Insert(e);
            }
            else
                r.Insert(e);
            m = ((double)l.GetTop() + (double)r.GetTop()) / 2;
            break;
            
        case 0:
            if(e < m){
                l.Insert(e);
                m = (double)l.GetTop();
            }
            else{
                r.Insert(e);
                m = (double)r.GetTop();
            }
            break;
            
        case -1:
            if (e < m) {
                l.Insert(e);
            }
            else{
                l.Insert(r.ExtractTop());
                r.Insert(e);
            }
            m = ((double)l.GetTop() + (double)r.GetTop()) / 2.0;
            break;
            
        default:
            break;
    }
    return m;
}

void printMedian(int *arr, int size){
    double m = 0.0;
    Heap *left = new MaxHeap();
    Heap *right = new MinHeap();
    for(int i = 0; i < size; ++i){
        m = findMedian(arr[i], m, *left, *right);
        cout<<m<<" ";
    }
}
*/
int biggerheap(int a, int b){
    if(a == b)
        return 0;
    return a > b ? 1 : -1;
}

void printMedian(int *arr, int size){
    double m = 0;
    priority_queue<int, vector<int>, less<int>>MaxHeap;
    priority_queue<int, vector<int>, greater<int>>MinHeap;
    for (int i = 0; i < size; ++i) {
        int signal = biggerheap((int)MaxHeap.size(), (int)MinHeap.size());
        switch (signal) {
            case 1:
                if(arr[i] < m){
                    MinHeap.push(MaxHeap.top());
                    MaxHeap.pop();
                    MinHeap.push(arr[i]);
                }
                else
                    MinHeap.push(arr[i]);
                m = ((double)MaxHeap.top() + (double)MinHeap.top()) / 2;
                cout<<m<<" ";
                break;
                
            case 0:
                if(arr[i] < m){
                    MaxHeap.push(arr[i]);
                    m = MaxHeap.top();
                }
                else{
                    MinHeap.push(arr[i]);
                    m = MinHeap.top();
                }
                cout<<m<<" ";
                break;
            case -1:
                if(arr[i] < m)
                    MaxHeap.push(arr[i]);
                else{
                    MaxHeap.push(MinHeap.top());
                    MinHeap.pop();
                    MinHeap.push(arr[i]);
                }
                m = ((double)MaxHeap.top() + (double)MinHeap.top()) / 2;
                cout<<m<<" ";
                break;
            default:
                break;
        }
    }
    
}

int main(int argc, const char * argv[]) {
    int arr[] = {3, 5, 8, 9, 7, 6, 2, 11, 12, 13, 14, 15, 16, 17, 18};
    int size = sizeof(arr) / sizeof(arr[0]);
    printMedian(arr, size);
    cout<<"\n";
    return 0;
}
