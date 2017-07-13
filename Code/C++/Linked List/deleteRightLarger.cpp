#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

void push(Node **head_ref, int new_data)
{
     Node *new_node = (Node *)malloc(sizeof(Node));
     new_node->data = new_data;
     new_node->next = *head_ref;
     *head_ref = new_node;
}

void reverse(Node** head_ref){
    if(!(*head_ref))return;
    Node* first = *head_ref;
    Node* last = first->next;
    if(!last)return;
    reverse(&last);
    first->next->next = first;
    first->next = NULL;
    *head_ref = last;
}

Node *compute(Node *head)
{
    if(!head)return head;
    int val = INT_MIN;
    reverse(&head);
    Node *prev = NULL, *cur = head;
    while(cur){
        if(cur->data < val){
            Node *temp = cur;
            prev->next = cur->next;
            cur = cur->next;
            delete temp;
        }
        else{
            prev = cur;
            val = cur->data;
            cur = cur->next;
        }
    }
    reverse(&head);
    return head;
}

void printList(Node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(int argc, char* argv[])
{
    Node *head = NULL;
    push(&head,3);
    push(&head,2);
    push(&head,6);
    push(&head,5);
    push(&head,11);
    push(&head,10);
    push(&head,15);
    push(&head,12);

    printf("Given Linked List \n");
    printList(head);

    head = compute(head);

    printf("Modified Linked List \n");
    printList(head);
    return 0;
}
