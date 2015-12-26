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
NODEPTR merge(NODEPTR a, NODEPTR b) {
  if(a == NULL)
    return b;
  else if(b == NULL)
    return a;

  NODEPTR result = NULL, first = a, second = b;

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
NODEPTR mergeSort(NODEPTR head) {

  if(head == NULL || head -> next == NULL) {
    return head;
  }

  //Front back split
  NODEPTR a = NULL, b = NULL;
  NODEPTR fastptr = head, slowptr = head;
  while(fastptr != NULL && fastptr -> next != NULL) {
    fastptr = fastptr -> next -> next;
    slowptr = slowptr -> next;
  }
  a = head;
  b = slowptr -> next;
  slowptr -> next = NULL;

  a = mergeSort(a);
  b = mergeSort(b);
  head = merge(a, b);

  return head;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  display(head);
  head = mergeSort(head);
  display(head);
  return 0;
}
