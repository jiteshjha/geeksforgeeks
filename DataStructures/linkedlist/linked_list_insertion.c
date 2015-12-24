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

void insertAfter(NODEPTR prev, int data) {
  if(prev == NULL) {
    printf("The given previous node cannot be null");
    return;
  }
  NODEPTR temp = newNode(data);
  temp -> next = prev -> next;
  prev -> next = temp;
}

NODEPTR append(NODEPTR head, int data) {
  NODEPTR temp = newNode(data);

  if(head == NULL)
    return temp;
  NODEPTR traverse = head;
  while(traverse -> next != NULL)
    traverse = traverse -> next;
  traverse -> next = temp;
  return head;
}
int main() {
  NODEPTR head = NULL;
  head = push(head, 2);
  head = push(head, 3);
  insertAfter(head, 4);
  head = append(head, 5);
  display(head);
  return 0;
}
