/*
*   Given the heads of two linked lists(345 is represented as 5->4->3)
*   Add where all the nodes are 0
*/
Node* createNode(int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
Node*  addTwoLists(Node* first, Node* second){
    Node *head = NULL, *cur = NULL;
    int carry = 0;
    while(first || second){
        Node* temp;
        if(!second){
            temp = createNode((first->data + carry) % 10);
            carry = (first->data + carry) / 10;
            first = first->next;
        }
        else if(!first){
            temp = createNode((second->data + carry) % 10);
            carry = (second->data + carry) / 10;
            second = second->next;
        }
        else{
            temp = createNode((first->data + second->data + carry) % 10);
            carry = (first->data + second->data + carry) / 10;
            first = first->next;
            second = second->next;
        }
        if(head == NULL)head = temp;
        else cur->next = temp;
        cur = temp;
    }
    if(carry != 0){
        Node *temp = createNode(carry);
        cur->next = temp;
    }
    return head;
}
