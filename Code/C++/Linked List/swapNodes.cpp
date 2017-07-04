#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

typedef struct Node Node;

void push(Node** head_ref, int data){
    Node *temp = new Node;
    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void swapNodes(Node** head_ref, int x, int y){
    Node *node1 = NULL, *node2 = NULL, *cur = *head_ref, *prev=NULL, *prev1 = NULL, *prev2 = NULL;
    while (cur) {
        if(cur->data == x){
            node1 = cur;
            prev1 = prev;
        }
        if(cur->data == y){
            node2 = cur;
            prev2 = prev;
        }
        prev = cur;
        cur = cur->next;
    }
    if(!node1 || !node2)return;
    if(prev1)
        prev1->next = node2;
    else
        *head_ref = node2;

    if(prev2)
        prev2->next = node1;
    else
        *head_ref = node1;

    Node *temp = node2->next;
    node2->next = node1->next;
    node1->next = temp;
}

int main(int argc, char const *argv[]) {
    Node* start = NULL;
    int n, x, y;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>x;
        push(&start, x);
    }
    printList(start);
    cin>>x>>y;
    swapNodes(&start, x, y);
    printList(start);
    return 0;
}
