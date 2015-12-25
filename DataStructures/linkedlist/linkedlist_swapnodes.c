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

NODEPTR swap(NODEPTR head, int x, int y) {
  if(head == NULL) {
    printf("Empty list!\n");
    return head;
  }
  NODEPTR prevx = NULL, traversex = head;
  while(traversex != NULL && traversex -> data != x) {
    prevx = traversex;
    traversex = traversex -> next;
  }

  NODEPTR prevy = NULL, traversey = head;
  while (traversey != NULL && traversey -> data != y ) {
    prevy = traversey;
    traversey = traversey -> next;
  }
  if(traversex == NULL || traversey == NULL) {
    printf("Nodes not found!\n" );
    return head;
  }
  if(prevx != NULL)
    prevx -> next = traversey;
  else
    head = traversey;

  if(prevy != NULL)
    prevy -> next = traversex;
  else
    head = traversex;

  NODEPTR temp = traversex -> next;
  traversex -> next = traversey -> next;
  traversey -> next = temp;

  return head;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  display(head);
  head = swap(head, 5, 2);
  display(head);
  return 0;
}
