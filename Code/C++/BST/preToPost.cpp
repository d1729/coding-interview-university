#include <iostream>
#include <stack>
using namespace std;

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* newNode(int data){
    Node *new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* entry(Node* root, int data){
    if(!root)return newNode(data);
    if(data < root->data)
        root->left = entry(root->left, data);
    else
        root->right = entry(root->right, data);
    return root;
}

Node* createTree(int arr[], int n){
    Node *root = NULL;
    for(int i = 0; i < n; ++i)
        root = entry(root, arr[i]);
    return root;
}

void preOrder(Node* root, int arr2[], int n){
	if(!root)return;
    stack<Node*>s;
    int i = 0;
    s.push(root);
    while(!s.empty()){
        Node* temp = s.top();
        s.pop();
        arr2[i++] = temp->data;
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
}

bool isValid(Node *root, int arr[], int n){
    int *arr2;
    arr2 = new int[n];
    preOrder(root, arr2, n);
    for(int i = 0; i < n; ++i)
        if(arr[i] != arr2[i])
        	return false;
    return true;
}

void printPostOrder(Node* root){
    if(!root)return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout<<root->data<<" ";
}

void postOrder(int arr[], int n){
    Node* root = createTree(arr, n);
    if(!isValid(root, arr, n)){
        cout<<"NO\n";
        return;
    }
    printPostOrder(root);
    cout<<"\n";
}

int main() {
	int t, n, *arr;
	cin>>t;
	while(t--){
	    cin>>n;
	    arr = new int[n];
	    for(int i = 0; i < n; ++i)cin>>arr[i];
	    postOrder(arr, n);
	    delete []arr;
	}
	return 0;
}
