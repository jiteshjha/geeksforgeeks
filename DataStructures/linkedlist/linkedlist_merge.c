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
  if(head == NULL)
    return temp;
  NODEPTR curr = head;
  while(curr -> next != NULL)
    curr = curr -> next;
  curr -> next = temp;
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

NODEPTR merge(NODEPTR a, NODEPTR b) {
  NODEPTR first = a, second = b;
  NODEPTR result = NULL;
  while(first != NULL && second != NULL) {
    if(first -> data <= second -> data) {
      result = push(result, first -> data);
      first = first -> next;
    }
    else {
      result = push(result, second -> data);
      second = second -> next;
    }
  }

  while(first != NULL) {
    result = push(result, first -> data);
    first = first -> next;
  }
  while(second != NULL) {
    result = push(result, second -> data);
    second = second -> next;
  }
  return result;
}


int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 4);
  head = push(head, 9);

  NODEPTR head1 = NULL;
  head1 = push(head1, 3);
  head1 = push(head1, 5);
  head1 = push(head1, 6);
  NODEPTR result = merge(head, head1);
  display(result);
  return 0;
}
