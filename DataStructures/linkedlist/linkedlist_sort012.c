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

NODEPTR sort(NODEPTR head) {
  int c0 = 0, c1 = 0, c2 = 0;
  NODEPTR curr = head;
  while(curr != NULL) {
    if(curr -> data == 0)
      c0++;
    else if(curr -> data == 1)
      c1++;
    else
      c2++;
    curr = curr -> next;
  }
  curr = head;
  while(c0 > 0) {
    curr -> data = 0;
    curr = curr -> next;
    c0--;
  }
  while(c1 > 0) {
    curr -> data = 1;
    curr = curr -> next;
    c1--;
  }
  while(c2 > 0) {
    curr -> data = 2;
    curr = curr -> next;
    c2--;
  }
  return head;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 0);
  head = push(head, 1);
  head = push(head, 2);
  head = push(head, 0);
  head = push(head, 1);
  head = sort(head);
  display(head);
  return 0;
}
