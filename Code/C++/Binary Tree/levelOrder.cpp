/*
*   LEVEL ORDER TREE TRAVERSAL
*/
#include <iostream>
#include "binaryTree.cpp"
using namespace std;

void printLevelOrder(Node* root, int level){
    if(!root)return;
    if(level == 1)
        cout<<root->data<<" ";
    else{
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level - 1);
    }
}

void levelOrder(Node* node)
{
    int h = height(node);
    for(int i = 1; i <= h; ++i)
        printLevelOrder(node, i);
    cout<<"\n";
}

int main(int argc, char* argv[])
{
    Node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    levelOrder(root);
    return 0;
}
