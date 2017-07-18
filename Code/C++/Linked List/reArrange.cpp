#include<iostream>
// this header file is to use all header file at once
#define ll long long
using namespace std;

struct Node {
	// the data structure
	int data;
	Node *next;
};


// this is the recursive function I used
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

// this function is to start the rearrangement
// this is just to specify things properly
// you can start rearrangement in main function also
Node* Rearrange(Node *start) {
    if(!start || !start->next || !start->next->next)return start;
	Node* c = rer(start,start->next);
	c->next = start->next;
	start->next = c;
	return start;
}

// to display the list
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

// To create the list
Node* create()
{
	Node *curr = NULL,*start = NULL;
	// the curr node is just to point the last node
	// so that I will not be needed to traverse every time
	int i=1;
	// here I created the list directly and sequentially
	//but you can edit the create function
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

	}while(i!=9); // this is the counter to end the list
	//cout<<"list is created\n";
	return start;
}

int main() {

	Node *start = create();
	display(start);
	start = Rearrange(start);
	display(start);
}
