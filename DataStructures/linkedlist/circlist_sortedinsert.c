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

NODEPTR insert(NODEPTR head, int data) {
  NODEPTR temp = newNode(data);
  if(head == NULL) {
    head = temp;
    head -> next = head;
    return head;
  }
  NODEPTR curr = head -> next;
  while(curr -> next != head)
    curr = curr -> next;
  curr -> next = temp;
  temp -> next = head;
  return head;
}

void display(NODEPTR head) {
  if(head == NULL) {
    printf("Empty list!\n");
    return;
  }
  NODEPTR curr = head;
  do {
    printf("%d\t", curr -> data);
    curr = curr -> next;
  }while(curr != head);

  printf("\n");
}
NODEPTR sortedInsert(NODEPTR head, int data) {
  if(head == NULL) {
    head = insert(head, data);
    return head;
  }
  NODEPTR curr = NULL;
  NODEPTR temp = newNode(data);
  if(head -> data > data) {
    curr = head;
    while(curr -> next != head)
      curr = curr -> next;
    temp -> next = head;
    head = temp;
    curr -> next = head;
  }
  else {
    curr = head;
    while(curr -> next -> data < data && curr -> next != head)
      curr = curr -> next;

    temp -> next = curr -> next;
    curr -> next = temp;

  }

  return head;
}
int main() {
  NODEPTR head1 = NULL;

  head1 = insert(head1, 1);
  head1 = insert(head1, 2);
  head1 = insert(head1, 3);
  head1 = insert(head1, 4);
  head1 = insert(head1, 7);
  head1 = sortedInsert(head1, 1);
  display(head1);
  return 0;
}
