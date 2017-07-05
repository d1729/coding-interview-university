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

int getNthFromEnd(Node* head, int n){
    Node* ptr = head;
    int count = 0;
    while(count < n){
        if(!head)return -1;
        head = head->next;
        ++count;
    }
    while (head) {
        head = head->next;
        ptr = ptr->next;
    }
    return ptr->data;
}

int main()
{
  Node* head = NULL;
  push(&head, 20);
  push(&head, 4);
  push(&head, 15);
  push(&head, 35);
  cout<<getNthFromEnd(head, 4)<<"\n";
}
