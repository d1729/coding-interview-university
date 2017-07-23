#include "binaryTree.cpp"
#include <stack>
#include <iostream>
using namespace std;

void inOrder1(Node* root){
    stack<Node*>s;
    Node* cur = root;
    bool done = false;
    while(!done){
        if(cur){
            s.push(cur);
            cur = cur->left;
        }
        else{
            if(!s.empty()){
                cur = s.top();
                s.pop();
                cout<<cur->data<<" ";
                cur = cur->right;
            }
            else
                done = true;
        }
    }
}

int main(int argc, char* argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right= newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    inOrder1(root);
    return 0;
}
