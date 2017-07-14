/*
*   Find the sum of two linked lists(345 as 3->4->5)
*/

#include <iostream>
using namespace std;

typedef struct node{
    int data;
    struct node* next;
}Node;

Node* create(int data){
    Node* new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert(Node** head, int arr[], int n){
    Node *cur = NULL;
    for(int i = 0; i < n; ++i){
        Node* temp = create(arr[i]);
        if(!(*head))*head = temp;
        else cur->next = temp;
        cur = temp;
    }
}

void reverse(Node** head){
    if(*head == NULL)return;
    Node* first = *head;
    Node* last = first->next;
    if(!last)return;
    reverse(&last);
    first->next->next = first;
    first->next = NULL;
    *head = last;
}

Node* add(Node* head1, Node* head2){
    Node* head = NULL, *cur;
    int carry = 0;
    Node* temp;
    while(head1 && head2){
        int val = (head1->data + head2->data + carry);
        temp = create(val % 10);
        carry = val / 10;
        if(!head)head = temp;
        else cur->next = temp;
        cur = temp;
        head1 = head1->next;
        head2 = head2->next;
    }
    while(head1){
        int val = head1->data + carry;
        temp = create(val % 10);
        carry = val / 10;
        if(!head)head = temp;
        else cur->next = temp;
        cur = temp;
        head1 = head1->next;
    }
    while(head2){
        int val = head2->data + carry;
        temp = create(val % 10);
        carry = val / 10;
        if(!head)head = temp;
        else cur->next = temp;
        cur = temp;
        head2 = head2->next;
    }
    if(carry){
        temp = create(carry);
        cur->next = temp;
    }
    return head;
}

void printList(Node* head){
    if(!head)return;
    printList(head->next);
    cout<<head->data<<" ";
}

int main() {
	int t, n1, n2, *arr1, *arr2;
	cin>>t;
	while(t--){
	    Node *head1 = NULL, *head2 = NULL;
	    cin>>n1>>n2;
	    arr1 = new int[n1];
	    arr2 = new int[n2];
	    for(int i = 0; i < n1; ++i)cin>>arr1[i];
	    for(int i = 0; i < n2; ++i)cin>>arr2[i];
	    insert(&head1, arr1, n1);
	    insert(&head2, arr2, n2);
	    reverse(&head1);
	    reverse(&head2);
	    Node* sum = add(head1, head2);
	    printList(sum);
	    cout<<"\n";
	}
	return 0;
}
