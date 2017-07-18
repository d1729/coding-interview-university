/*
*   Rearran a linked list such that all the odd placed and even placed elements
*   occur together.
*/

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
} Node;

void push(Node** head_ref, int data){
    Node* node = new Node;
    node->data = data;
    node->next = *head_ref;
    *head_ref = node;
}

Node *rearrangeEvenOdd(Node *head)
{
    Node *l1 = NULL, *l2 = NULL, *cur1 = NULL, *cur2 = NULL;
    int flag = 0;
    while(head){
        if(flag == 0){
            if(!l1){
                l1 = head;
                cur1 = head;
            }
            else{
                cur1->next = head;
                cur1 = head;
            }
        }
        else{
            if(!l2){
                l2 = head;
                cur2 = head;
            }
            else{
                cur2->next = head;
                cur2 = head;
            }
        }
        head = head->next;
        flag = 1 - flag;
    }
    if(cur2)cur2->next = NULL;
    if(cur1)
        cur1->next = l2;
    return l1;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main(int argc, char* argv[]){
    Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    cout<<"Before reArrange:\n";
    printList(head);
    cout << "\n";
    rearrangeEvenOdd(head);
    cout<<"After reArrange:\n";
    printList(head);
    cout<<"\n\n";

    return 0;
}
