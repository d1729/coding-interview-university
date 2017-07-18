/*
*   Given a linked list of co-ordinates where adjacent points either form
*   a vertical line or a horizontal line. Delete points from the linked list
*   which are in the middle of a horizontal or vertical line.
*/
#include <iostream>
using namespace std;

typedef struct node{
    int x;
    int y;
    struct node* next;
} Node;

void push(Node** head, int x, int y){
    Node* node = new Node;
    node->x = x;
    node->y = y;
    node->next = *head;
    *head = node;
}

void printList(Node* head){
    while(head->next){
        cout<<"("<<head->x<<", "<<head->y<<")->";
        head = head->next;
    }
    cout<<"("<<head->x<<", "<<head->y<<")->NULL\n";
}

void removeMiddleNode(Node* head){
    if(!head || !head->next)return;
    int flag = -1;
    Node *start = head, *prev = start, *cur = head->next;
    while (cur){
        if(cur->y == prev->y){
            if(flag == 1){
                Node* temp = prev;
                start->next = cur;
                delete temp;
            }
            else{
                flag = 1;
                start = prev;
            }
        }
        else{
            if(flag == 0){
                Node* temp = prev;
                start->next = cur;
                delete temp;
            }
            else{
                flag = 0;
                start = prev;
            }
        }
        prev = cur;
        cur = cur->next;
    }
}

int main(int argc, char* argv[])
{
    Node* head = NULL;
    int n, x, y;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>x>>y;
        push(&head, x, y);
    }
    cout<<"Before removing the middle points\n";
    printList(head);
    cout<<"After removing the middle Points\n";
    removeMiddleNode(head);
    printList(head);
    return 0;
}
