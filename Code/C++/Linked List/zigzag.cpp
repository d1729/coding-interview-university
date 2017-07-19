/*
*   Zigzag a linked list (a<b>c<d>....)maintaining order(Use 3 elements at one go)
*/
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

// This function distributes the Node in zigzag fashion
Node *zigZagList(Node* head)
{
    int flag = 0;
    Node* cur = head;
    while(head && head->next && head->next->next){
        if(flag == 0){
            if(head->data > head->next->data){
                int temp = head->next->data;
                head->next->data = head->data;
                head->data = temp;
            }
            if(head->next->next->data > head->next->next->data){
                int temp = head->next->data;
                head->next->data = head->next->next->data;
                head->next->next->data = temp;
            }
        }
        else{
            if(head->data < head->next->data){
                int temp = head->next->data;
                head->next->data = head->data;
                head->data = temp;
            }
            if(head->next->next->data < head->next->data){
                int temp = head->next->data;
                head->next->data = head->next->next->data;
                head->next->next->data = temp;
            }
        }
        flag = 1 - flag;
        head = head->next;
    }
    if(head && head->next){
        if(flag == 0){
            if(head->data > head->next->data){
                int temp = head->next->data;
                head->next->data = head->data;
                head->data = temp;
            }
        }
        else{
            if(head->data < head->next->data){
                int temp = head->next->data;
                head->next->data = head->data;
                head->data = temp;
            }
        }
    }
    return cur;
}

/* UTILITY FUNCTIONS */
/* Function to push a Node */
void push(Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = new Node;

    /* put in the data  */
    new_Node->data  = new_data;

    /* link the old list off the new Node */
    new_Node->next = (*head_ref);

    /* move the head to point to the new Node */
    (*head_ref)    = new_Node;
}

/* Function to print linked list */
void printList(struct Node *Node)
{
    while (Node != NULL)
    {
        printf("%d->", Node->data);
        Node = Node->next;
    }
    printf("NULL");
}

/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    struct Node* head = NULL;

    // create a list 4 -> 3 -> 7 -> 8 -> 6 -> 2 -> 1
    // answer should be -> 3  7  4  8  2  6  1
    push(&head, 1);
    push(&head, 2);
    push(&head, 6);
    push(&head, 8);
    push(&head, 7);
    push(&head, 3);
    push(&head, 4);

    printf("Given linked list \n");
    printList(head);

    head = zigZagList(head);

    printf("\nZig Zag Linked list \n");
    printList(head);

    return (0);
}
