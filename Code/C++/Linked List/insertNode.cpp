#include <cstdio>
#include <iostream>

/* Name: Given a linked list which is sorted, how will you insert in sorted way
 * Link: geeksforgeeks.org/given-a-linked-list-which-is-sorted-how-will-you-insert-in-sorted-way/
 * Genre: Linked list
 * Description:
 *  *
 * */

typedef struct list_node {
    int n;
    list_node *next;
} list_node;

list_node *new_node(int n)
{
    list_node *tmp = new list_node;
    if (tmp == NULL) return NULL;
    tmp->n    = n;
    tmp->next = NULL;
    return tmp;
}

void free_list(list_node **l)
{
    if (l == NULL) return ;
    list_node *next;
    while (*l != NULL) {
        next = (*l)->next;
        delete *l;
        *l   = next;
    }
}

void print_list(const list_node *l)
{
    if (l == NULL) return ;
    while (l != NULL) {
        printf("%d", l->n);
        l = l->next;
        putchar(l ? ' ' : '\n');
    }
}

list_node *build_list(const int *arr, unsigned n)
{
    if (arr == NULL) return NULL;
    unsigned i;
    list_node *head = NULL, *tmp;
    for (i = n-1; i != (unsigned) -1; i--) {
        tmp = new_node(n);
        if (tmp == NULL) break;
        tmp->n    = arr[i];
        tmp->next = head;
        head      = tmp;
    }
    return head;
}

/* memory-efficient solution */
void sorted_insert(list_node **head_ref, list_node *new_node)
{
    if (head_ref == NULL || new_node == NULL) return ;
    list_node* ls;
    list_node **cursor = head_ref;
    //printf("%p\n", &new_node);
    while (*cursor && (*cursor)->n < new_node->n){
        cursor = &((*cursor)->next);
    }
    new_node->next = *cursor;
    *cursor = new_node;
}

int main(void)
{
    int arr[] = {1, 2, 3, 5, 8};
    unsigned len = sizeof(arr) >> 2;
    list_node *l = build_list(arr, len);
    print_list(l);

    list_node *n1;

    /*n1 = new_node(0);
    sorted_insert(&l, n1);
    print_list(l);*/

    n1 = new_node(7);
    sorted_insert(&l, n1);
    print_list(l);

    /*n1 = new_node(9);
    sorted_insert(&l, n1);
    print_list(l);*/

    free_list(&l);
    return 0;
}
