/*
*   Pairwise swap the nodes of a linked list
*/

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
} Node;

void push(Node** head, int data){
    Node* node = new Node;
    node->data = data;
    node->next = *head;
    *head = node;
}

void printList(Node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

void pairSwap(Node** head){
    if(!(*head) || !(*head)->next)return;
    Node* prev = *head;
    Node* cur = (*head)->next;
    *head = cur;
    while (true){
        Node* temp = cur->next;
        cur->next = prev;
        if(!temp || !temp->next){
            prev->next = temp;
            return;
        }
        prev->next = temp->next;
        prev = temp;
        cur = temp->next;
    }
}

int main(int argc, char* argv[])
{
    Node* head = NULL;
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    push(&head, 9);
    printList(head);
    pairSwap(&head);
    printList(head);
    return 0;
}
