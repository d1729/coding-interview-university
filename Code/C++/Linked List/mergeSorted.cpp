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

Node* SortedMerge(Node* head1,   Node* head2)
{
    Node* head = NULL;
    if(!head1)return head2;
    if(!head2)return head1;
    head = head1->data < head2->data ? head1 : head2;
    head->next = head1->data < head2->data ? SortedMerge(head1->next, head2) : SortedMerge(head1, head2->next);
    return head;
}

void printList(Node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

/* Drier program to test above function*/
int main()
{
    struct Node* res = NULL;
    struct Node* a = NULL;
    struct Node* b = NULL;

    /* Let us create two sorted linked lists to test
      the functions
       Created lists, a: 5->10->15,  b: 2->3->20 */
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);

    push(&b, 20);
    push(&b, 3);
    push(&b, 2);

    /* Remove duplicates from linked list */
    res = SortedMerge(a, b);

    printf("Merged Linked List is: \n");
    printList(res);

    return 0;
    return 0;
}
