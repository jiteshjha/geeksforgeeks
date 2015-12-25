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

NODEPTR duplicateSorted(NODEPTR head) {
  NODEPTR curr = head, temp;
  while(curr -> next != NULL) {
    if(curr -> data == curr -> next -> data) {
      temp = curr -> next;
      curr -> next = temp -> next;
      free(temp);
    }
    else
      curr = curr -> next;
  }
  return head;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 6);
  head = push(head, 6);
  display(head);
  head = duplicateSorted(head);
  display(head);
  return 0;
}
