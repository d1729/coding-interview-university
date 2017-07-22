#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
    struct node* prev;
} Node;

void push(Node** head, int x){
    Node* new_node = new Node;
    new_node->data = x;
    new_node->prev = NULL;
    new_node->next = NULL;
    if(*head){
        (*head)->prev = new_node;
        new_node->next = *head;
    }
    *head = new_node;
}

Node* lastNode(Node* head){
    while (head && head->next)
    {
        head = head->next;
    }
    return head;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

Node* partition(Node* l, Node* h){
    int x = h->data;
    Node* i = l->prev;
    for(Node* j = l; j != h; j = j->next){
        if(j->data <= x){
            i = i == NULL ? l : i->next;
            swap(j->data, i->data);
        }
    }
    i = i == NULL ? l : i->next;
    swap(i->data, h->data);
    return i;
}

void _quickSort(Node* l, Node* h){
    if(l && h && l != h && l != h->next){
        Node* p = partition(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}

void quickSort(Node* head){
    Node* h = lastNode(head);
    _quickSort(head, h);
}

void printList(Node* head){
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}

int main(int argc, char* argv[])
{
    Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
    cout << "Linked List before sorting \n";
    printList(a);

    quickSort(a);

    cout << "Linked List after sorting \n";
    printList(a);
    return 0;
}
