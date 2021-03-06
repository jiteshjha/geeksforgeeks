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

NODEPTR sortedInsert(NODEPTR head, int data) {
  if(head == NULL)
    return newNode(data);
  NODEPTR curr = head;
  if(data < head -> data) {
    head = push(head, data);
    return head;
  }
  while(curr -> next != NULL && data < curr -> next -> data)
    curr = curr -> next;
  NODEPTR temp = newNode(data);
  temp -> next = curr -> next;
  curr -> next = temp;

  return head;
}
int main() {
  NODEPTR head = NULL, head1  = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 7);


  //display(head);
  head = sortedInsert(head, 1);
  display(head);
  return 0;
}
