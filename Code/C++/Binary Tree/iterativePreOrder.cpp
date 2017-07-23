#include <iostream>
#include "binaryTree.cpp"
#include <stack>
using namespace std;

void preOrder2(Node* root){
    stack<Node*>s;
    if(root)
        s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        cout<<temp->data<<" ";
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
}

int main(int argc, char* argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right= newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    preOrder2(root);
    return 0;
}
