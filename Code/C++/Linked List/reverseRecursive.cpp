#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
} Node;

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void printList(struct Node *head)
{
    struct Node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

Node* reverse(Node* head){
    if(!head)return head;
    Node *first = head, *rest = head->next;
    if(!rest)return first;
    Node* temp = reverse(rest);
    first->next->next = first;
    first->next = NULL;
    return temp;
}

int main()
{
    struct Node* head = NULL;

     push(&head, 20);
     push(&head, 4);
     push(&head, 15);
     push(&head, 85);
     printf("Given linked list\n");
     printList(head);
     Node* cur = reverse(head);
     printf("\nReversed Linked list \n");
     printList(cur);
}
