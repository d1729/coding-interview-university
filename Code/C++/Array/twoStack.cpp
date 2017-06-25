#include <iostream>
using namespace std;

class TwoStack
{
    int stackSize, *arr;
    int top1, top2;
public:
    TwoStack(int n){
            stackSize = n;
            arr = new int[n];
            top1 = -1;
            top2 = n;
    }

    ~TwoStack(){
        if(arr)
            delete []arr;
    }

    void push1(int x){
        if(top1 + 1 < top2)
            arr[++top1] = x;
        else
            throw "Stack Overflow\n";
    }

    void push2(int x){
        if(top1 + 1 < top2)
            arr[--top2] = x;
        else
            throw "Stack Overflow\n";
    }

    int pop1(){
        if(top1 < 0)
            throw "Stack underflow\n";
        else{
            --top1;
            return arr[top1 + 1];
        }
    }

    int pop2(){
        if(top2 >= stackSize)
            throw "Stack underflow\n";
        else{
            ++top2;
            return arr[top2 - 1];
        }
    }

};

int main(int argc, char const *argv[]) {
    TwoStack ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1();
    ts.push2(40);
    cout << "\nPopped element from stack2 is " << ts.pop2();
    return 0;
}
