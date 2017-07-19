/*
*   Add 1 to a linked list (1->9->9 becomes 2->0->0)
*/
#include<iostream>
using namespace std;

/* Linked list node */
struct Node
{
    int data;
    Node* next;
};

int carry = 0;

/* Function to create a new node with given data */
Node *newNode(int data)
{
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node* addOneUtil(Node* head){
    if(!head->next){
        int sum = head->data + carry + 1;
        head->data = sum % 10;
        carry = sum / 10;
        return head;
    }
    head->next = addOneUtil(head->next);
    int sum = head->data + carry;
    head->data = sum % 10;
    carry = sum / 10;
    return head;
}

Node *addOne(Node *head)
{
    carry = 0;
    if(!head)return head;
    head = addOneUtil(head);
    if(carry != 0){
        Node* new_node = newNode(carry);
        new_node->next = head;
        head = new_node;
    }
    return head;
}

// A utility function to print a linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Driver program to test above function */
int main(void)
{
    Node *head = newNode(1);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);

    printf("List is ");
    printList(head);

    head = addOne(head);

    printf("\nResultant list is ");
    printList(head);

    return 0;
}
