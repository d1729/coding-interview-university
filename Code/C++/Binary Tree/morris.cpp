#include <iostream>
#include "binaryTree.cpp"
using namespace std;

void MorrisTreaversal(Node* root){
    Node *cur, *pre;
    cur = root;
    while (cur)
    {
        if(!cur->left){
            cout<<cur->data<<" ";
            cur = cur->right;
        }
        else{
            pre = cur->left;
            while (pre->right && pre->right != cur)
                pre = pre->right;
            if(!pre->right){
                pre->right = cur;
                cur = cur->left;
            }
            else{
                pre->right = NULL;
                cout<<cur->data<<" ";
                cur = cur->right;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    MorrisTreaversal(root);
    cout<<"\n";
    return 0;
}
