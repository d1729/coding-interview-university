#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node *prev, *next;
} Node;

void push(Node** head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    if(*head)(*head)->prev = new_node;
    *head = new_node;
}

void printList(Node *head){
    cout<<"Forward Traversal:\n";
    Node* prev = NULL;
    while(head){
        cout<<head->data<<" ";
        prev = head;
        head = head->next;
    }
    cout<<"\nBackward Traversal:\n";
        while(prev){
        cout<<prev->data<<" ";
        prev = prev->prev;
    }
    cout<<"\n";
}

Node *splitList(struct node *head)
{
    if(!head || !head->next)return NULL;
    struct node *slow = head, *fast = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    struct node* second = slow->next;
    slow->next = NULL;
    second->prev = NULL;
    return second;
}

Node *merge(struct node *first, struct node *second)
{
    if(!first)return second;
    if(!second)return first;
    Node* head;
    if(first->data < second->data){
        head = first;
        head->next = merge(first->next, second);
    }
    else{
        head = second;
        head->next = merge(first, second->next);
    }
    if(head->next)head->next->prev = head;
    return head;
}

Node *mergeSort(struct node *head)
{
    if (!head || !head->next)
        return head;
    Node *second = splitList(head);
    head = mergeSort(head);
    second = mergeSort(second);
    return merge(head, second);
}

int main(int argc, char* argv[])
{
    Node* head = NULL;
    push(&head, 4);
    push(&head, 5);
    push(&head, 2);
    push(&head, 1);
    push(&head, 3);
    head = mergeSort(head);
    printList(head);
    return 0;
}
