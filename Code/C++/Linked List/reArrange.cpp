/*
*	Rearrange a linked list A0->A1->A2->A3->......->An-1->An becomes
*	A0->An->A1->An-1->A2->An-2->.....
*/
#include<iostream>
#define ll long long
using namespace std;

struct Node {
	// the data structure
	int data;
	Node *next;
};


Node* rer(Node *a, Node *b) {

	if(b->next!=NULL) {
		if(b->next->next!=NULL) {
			a = a->next;
			b = b->next->next;
			if(b->next == NULL) {
				// this b will be the last node;
				// number of nodes are even
				Node *c = a->next->next;
				a->next->next = NULL;
				return c;
			}
			b = rer(a,b);
		}
		else {
			a = a->next;
			// this a will be the last Node;
			// number of nodes are odd
			Node *node = a->next;
			a->next = NULL;
			//node->next = a;
			return node;
		}
	}


	Node *c = b->next;
	b->next = a->next;
	a->next = b;
	return c;
}

Node* Rearrange(Node *start) {
    if(!start || !start->next || !start->next->next)return start;
	Node* c = rer(start,start->next);
	c->next = start->next;
	start->next = c;
	return start;
}

void display(Node *start)
{
	struct Node *newnode=start;
	while(newnode->next!=NULL)
	{
		cout<<newnode->data<<"-> ";
		newnode=newnode->next;
	}
	cout<<newnode->data<<endl;

}

Node* create()
{
	Node *curr = NULL,*start = NULL;
	int i=1;
	do {
		struct Node *newnode = new Node;
		newnode->next = NULL;
		newnode->data = i++;
		if(start==NULL) {
			start=newnode; curr=newnode;
		}
		else {
			curr->next = newnode;
			curr = newnode;
		}

	}while(i!=9);
	return start;
}

int main() {

	Node *start = create();
	display(start);
	start = Rearrange(start);
	display(start);
}
