#include<iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
	struct node* arb;
} Node;

void push(Node** head_ref, int data){
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	new_node->arb = NULL;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

Node* create(int data){
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	new_node->arb = NULL;
	return new_node;
}

Node* clone(Node* head){
	if(!head)return NULL;
	Node* cur = head->next;
	head->next = cur->next;
	cur->next = clone(cur->next);
	return cur;
}

Node* copyList(Node* head){
	if(!head)return head;
	Node* cur = head;
	while (cur){
		Node* node = create(cur->data);
		node->next = cur->next;
		cur->next = node;
		cur = node->next;
	}
	cur = head;
	while(cur){
		if(cur->arb)
			cur->next->arb = cur->arb->next;
		cur = cur->next->next;
	}
	return clone(head);
}

void printList(Node* head){
	while (head)
	{
		cout<<"Current vale: "<<head->data;
		if(head->arb)
			cout<<" arbitrary value: "<<head->arb->data;
		cout<<"\n";
		head = head->next;
	}
}

int main(){
	Node* head = NULL;
	push(&head, 5);
	push(&head, 3);
	push(&head, 4);
	push(&head, 1);
	push(&head, 2);
	head->arb = head->next->next;
	head->next->next->arb = head->next->next->next;
	head->next->arb = head;
	head->next->next->next->next->arb = head;
	printList(head);
	cout<<"\n\nAfter cloning the list:\n";
	head = copyList(head);
	printList(head);
	return 0;
}
