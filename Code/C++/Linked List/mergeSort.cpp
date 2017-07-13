/*
*   Merge Sort for linked list
*/
#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void push(struct node** head_ref, int key){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = key;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void splitList(struct node* head, struct node** a, struct node** b){
    if(!head || !(head->next)){
        *a = NULL;
        *b = head;
    }
    else{
        struct node* fast = head;
        struct node* slow = head;
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        *a = head;
        *b = slow->next;
        slow->next = NULL;
    }
}

struct node* mergeList(struct node* a, struct node* b){
    struct node* head = NULL;
    if(!a)return b;
    if(!b)return a;
    if(a->data < b->data){
        head = a;
        head->next = mergeList(a->next, b);
    }
    else{
        head = b;
        head->next = mergeList(a, b->next);
    }
    return head;
}

void mergeSort(struct node** head){
    if (*head == NULL || (*head)->next == NULL)
        return;
    struct node *a = NULL, *b = NULL;
    splitList(*head, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head = mergeList(a, b);
}

void printList(struct node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
}

int main(int argc, char* argv[])
{
    struct node* a = NULL;
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);
    mergeSort(&a);
    printList(a);
    cout<<"\n";
    return 0;
}
