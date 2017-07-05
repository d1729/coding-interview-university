#include <iostream>
using namespace std;

typedef struct Node{
    int data;
    Node* next;
}Node;

int getMiddle(Node *head)
{
    if(!head)return -1;
    Node *fast = head, *slow = head;
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }
    if(fast->next)
        slow = slow->next;
    return slow->data;
}

void push(struct Node** head_ref, int new_data)
{
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

int main(int argc, char const *argv[]) {
    struct Node* head = NULL;
    int i;

    for (i=5; i>0; i--)
    {
        push(&head, i);
        cout<<getMiddle(head)<<"\n";
    }
    return 0;
}
