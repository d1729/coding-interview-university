/*
*   segregate even and odd nodes keeping their order intact
*/
#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

void segregate(Node** head_ref){
    if(!(*head_ref) || !((*head_ref)->next))return;
    Node *prev = NULL, *cur = *head_ref, *tail = *head_ref;
    while(tail->next)tail = tail->next;
    Node* tail2 = tail;
    while(cur != tail2){
        if(cur->data % 2 == 0){
            prev = cur;
            cur = cur->next;
        }
        else{
            if(*head_ref == cur)
                *head_ref = cur->next;
            else
                prev->next = cur->next;
            Node* temp = cur;
            cur = cur->next;
            temp->next = NULL;
            tail->next = temp;
            tail = temp;
        }
    }
    if(cur->data % 2 == 1){
        if(tail != cur){
            if(*head_ref == cur)*head_ref = cur->next;
            if(prev)
                prev->next = cur->next;
            cur->next = NULL;
            tail->next = cur;
        }
    }
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

void insert(Node** head, int arr[], int n){
    for(int i = 0; i < n; ++i){
        Node* new_node = (Node*)malloc(sizeof(Node));
        Node *cur;
        new_node->data = arr[i];
        new_node->next = NULL;
        if(*head == NULL){
            *head = new_node;
        }
        else{
            cur->next = new_node;
        }
        cur = new_node;
    }
}

int main() {
    int t, n, *arr;
    cin>>t;
    while(t--){
        Node* head = NULL;
        cin>>n;
        arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin>>arr[i];
        }
        insert(&head, arr, n);
        segregate(&head);
        printList(head);
        cout<<"\n";
    }
	return 0;
}
