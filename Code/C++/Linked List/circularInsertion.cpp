#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
} Node;

void printList(Node* head){
    Node* cur = head;
    do{
        cout<<cur->data<<" ";
        cur = cur->next;
    }while(cur != head);
    cout<<"\n";
}

void sortedInsert(Node** head_ref, int x)
{
    Node *new_node = new  Node;
    new_node->data = x;
    new_node->next = NULL;
    if(!*head_ref){
        *head_ref = new_node;
        (*head_ref)->next = *head_ref;
        return;
    }
    int flag = 0;
    Node *cur = *head_ref, *prev = *head_ref;
    while(prev->next != cur)prev = prev->next;
    if(x < (*head_ref)->data){
        prev->next = new_node;
        new_node->next = cur;
        *head_ref = new_node;
        return;
    }
    do{
        if(x < cur->data){
            prev->next = new_node;
            new_node->next = cur;
            flag = 1;
            break;
        }
        prev = prev->next;
        cur = cur->next;
    }while(cur != *head_ref && x >= cur->data);
    if(flag == 0){
        prev->next = new_node;
        new_node->next = cur;
    }
}

int main(int argc, char* argv[])
{
    Node *head = NULL;
    sortedInsert(&head, 1);
    sortedInsert(&head, 4);
    sortedInsert(&head, 2);
    sortedInsert(&head, 2);
    sortedInsert(&head, 0);
    printList(head);
    return 0;
}
