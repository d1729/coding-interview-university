/*
*   Reverse the linked list in chunks of k
*/
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

struct Node* reverse(struct Node* head, int k){
    int count = 0;
    struct Node *prev = NULL, *cur = head, *temp;
    while (cur && count < k)
    {
        temp = cur->next;
        cur->next = prev;
        prev = cur;
        cur = temp;
        count++;
    }
    if(cur)
        head->next = reverse(cur, k);
    return prev;
}

void printList(struct Node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    cout<<"Normal Linked List:\n";
    printList(head);
    head = reverse(head, 4);
    cout<<"\nReversed Linked List:\n";
    printList(head);
    cout<<"\n";

    return 0;
}
