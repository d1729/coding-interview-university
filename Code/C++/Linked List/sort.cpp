/*
*   Sort a linked list that is sorted by absolute values
*/

#include <iostream>
using namespace std;

// Linked List Node
struct Node
{
    Node* next;
    int data;
};

// Utility function to insert a node at the
// beginning
void push(Node** head, int data)
{
    Node* newNode = new Node;
    newNode->next = (*head);
    newNode->data = data;
    (*head) = newNode;
}

// Utility function to print a linked list
void printList(Node* head)
{
    while (head != NULL)
    {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout<<endl;
}

void sortList(Node** head)
{
    if(!(*head) || !(*head)->next)return;
    Node *cur = (*head)->next, *prev = *head;
    while(cur){
        if(cur->data < 0){
            prev->next = cur->next;
            cur->next = *head;
            *head = cur;
            cur = prev->next;
        }
        else{
            prev = cur;
            cur = cur->next;
        }
    }
}
// Driver code
int main()
{
    Node* head = NULL;
    push(&head, -5);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, -2);
    push(&head, 1);
    push(&head, 0);

    cout << "Original list :\n";
    printList(head);

    sortList(&head);

    cout << "\nSorted list :\n";
    printList(head);

    return 0;
}
