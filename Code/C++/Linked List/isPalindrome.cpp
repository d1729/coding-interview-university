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

void reverse(Node** head){
    if(!(*head))return;
    Node* first = *head;
    Node* last = first->next;
    if(!last)return;
    reverse(&last);
    first->next->next = first;
    first->next = NULL;
    *head = last;
}

Node* middle(Node* head){
    Node *fast = head, *slow = head;
    while(slow && fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->next;
}

bool isPalindrome(Node *head)
{
    if(!head || !(head->next))return true;
    Node* mid = middle(head);
    reverse(&mid);
    while(mid){
        if(mid->data != head->data)return false;
        mid = mid->next;
        head = head->next;
    }
    return true;
}

/* Drier program to test above function*/
int main()
{
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 1);
    push(&head, 8);
    push(&head, 8);
    push(&head, 1);

    cout<<isPalindrome(head)<<"\n";

    return 0;
}
