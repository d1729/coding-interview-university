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

int length(Node* head){
    int count = 0;
    while(head){
        head = head->next;
        ++count;
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    int len1 = length(head1);
    int len2 = length(head2);
    if(len1 > len2)
        for(int i = 0; i < len1 - len2; ++i)
            head1 = head1->next;
    else if(len2 > len1)
        for(int i = 0; i < len2 - len1; ++i)
            head2 = head2->next;
    while(head1){
        if(head1 == head2)return head1->data;
        head1 = head1->next;
        head2 = head2->next;
    }
    return -1;
}

/* Drier program to test above function*/
int main()
{
    struct Node* newNode;
  struct Node* head1 =
            (struct Node*) malloc(sizeof(struct Node));
  head1->data  = 10;

  struct Node* head2 =
            (struct Node*) malloc(sizeof(struct Node));
  head2->data  = 3;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 6;
  head2->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 9;
  head2->next->next = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = (struct Node*) malloc (sizeof(struct Node));
  newNode->data = 30;
  head1->next->next= newNode;

  head1->next->next->next = NULL;

  cout<<intersectPoint(head1, head2)<<"\n";

  return 0;
}
