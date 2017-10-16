#include <stdio.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;

void ListPrint(Node *head)
{
    Node *p = head;
    while(p) {
        printf("%d,", p->data);
        p = p->next;
    }
    printf("\b\n");
}

void ListReverse(Node *head)
{
    Node *p = head->next;
    head->next = NULL;
    Node *t = NULL;
    while(p) {
        t = p->next;
        p->next = head->next;
        head->next = p;
        p = t;
    }
}

int main()
{
    Node head;
    Node n1;
    Node n2;
    Node n3;
    Node n4;
    Node n5;
    Node n6;
    head.data = -1;
    head.next = &n1;
    n1.data = 1;
    n1.next = &n2;
    n2.data = 2;
    n2.next = &n3;
    n3.data = 3;
    n3.next = &n4;
    n4.data = 4;
    n4.next = &n5;
    n5.data = 5;
    n5.next = &n6;
    n6.data = 6;
    n6.next = NULL;
    ListPrint(&head);
    ListReverse(&head);
    ListPrint(&head);
    return 0;
}

