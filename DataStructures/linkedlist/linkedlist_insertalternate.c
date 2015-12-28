#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node * next;
}NODE;

typedef NODE * NODEPTR;

NODEPTR newNode(int data) {
  NODEPTR temp = (NODEPTR)malloc(sizeof(NODE));
  temp -> data = data;
  temp -> next = NULL;
  return temp;
}
NODEPTR push(NODEPTR head, int data) {
  NODEPTR temp = newNode(data);
  temp -> next = head;
  head = temp;
  return head;
}

void display(NODEPTR head) {
  if(head == NULL) {
    printf("List empty!\n");
    return;
  }
  NODEPTR temp = head;
  while(temp != NULL) {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }
}

NODEPTR alternate(NODEPTR a, NODEPTR b) {
  if(b == NULL)
    return a;
  NODEPTR first = a, second = b, next = NULL;
  while(first != NULL && second != NULL) {
    next = second -> next;
    second -> next = first -> next;
    first -> next = second;
    second = next;
    first = first -> next -> next;
  }

  return a;
}
int main() {
  NODEPTR head = NULL, head1  = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);

  head1 = push(head1, 10);
  head1 = push(head1, 11);
  head1 = push(head1, 12);
  head1 = push(head1, 13);
  head1 = push(head1, 14);
  //display(head);
  head = alternate(head, head1);
  display(head);
  return 0;
}
