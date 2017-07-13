#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printReverse(Node* head){
    if(!head)return;
    printReverse(head->next);
    cout<<head->data<<" ";
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    Node* head = NULL;

    push(&head, 1);
    push(&head, 7);
    push(&head, 4);
    push(&head, 5);

    printReverse(head);
    cout<<"\n";

    return 0;
}
