#include <iostream>
#include "binaryTree.cpp"
using namespace std;

void moris(Node* root){
    while(root){
        if(!root->left){
            cout<<root->data<<" ";
            root = root->right;
        }
        else{
            Node* cur = root->left;
            while(cur->right && cur->right != root)
                cur = cur->right;
            if(!cur->right){
                cur->right = root;
                cout<<root->data<<" ";
                root = root->left;
            }
            else{
                cur->right = NULL;
                root = root->right;
            }
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
    moris(root);
    return 0;
}
