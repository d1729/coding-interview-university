#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
} Node;

void push(Node** head, int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

void printList(Node* head){
    while (head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int countNodes(Node* head){
    int count = 0;
    while (head){
        ++count;
        head = head->next;
    }
    return count;
}
void swapKth(Node** head, int k){
    int n = countNodes(*head);
    if(k > n)return;
    if(2 * k - 1 == n)return;
    Node *x = *head, *x_prev = NULL;
    for(int i = 1; i < k; ++i){
        x_prev = x;
        x = x->next;
    }
    Node *y = *head, *y_prev = NULL;
    for(int i = 1; i < n - k + 1; ++i){
        y_prev = y;
        y = y->next;
    }
    if(x_prev)x_prev->next = y;
    if(y_prev)y_prev->next = x;

    Node *temp = x->next;
    x->next = y->next;
    y->next = temp;

    if(k == 1) *head = y;
    if(k == n) *head = x;
}

int main(int argc, char* argv[])
{
    Node *head = NULL;
    for (int i = 8; i >= 1; i--)
       push(&head, i);

    cout << "Original Linked List: ";
    printList(head);

    for (int k = 1; k < 9; k++)
    {
        swapKth(&head, k);
        cout << "\nModified List for k = " << k << endl;
        printList(head);
    }
    return 0;
}
