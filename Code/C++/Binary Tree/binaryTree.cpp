#include <cstdio>
#include <algorithm>
#include "binaryTree.h"

Node* newNode(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void inOrder(Node* root)
{
    if(!root)return;
    inOrder(root->left);
    printf("%d ",root->data);
    inOrder(root->right);
}

void preOrder(Node* root)
{
    if(!root)return;
    printf("%d ",root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root)
{
    if(!root)return;
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ",root->data);
}

int height(Node* node)
{
   if(!node)return 0;
   int lheight = height(node->left);
   int rheight = height(node->right);
   return 1 + std::max(lheight, rheight);
}
