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
  NODEPTR temp = head;
  while(temp != NULL) {
    printf("%d\n", temp -> data);
    temp = temp -> next;
  }
}

void middle(NODEPTR head) {
  NODEPTR fastptr = head, slowptr = head;

  while(fastptr != NULL && fastptr -> next != NULL) {
    fastptr = fastptr -> next -> next;
    slowptr = slowptr -> next;
  }
  printf("Middle: %d\n", slowptr -> data);
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  display(head);
  middle(head);
  return 0;
}
