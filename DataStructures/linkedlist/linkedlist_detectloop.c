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

int detectLoop(NODEPTR head) {
  NODEPTR slow = head, fast = head;
  while(fast != NULL && fast -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;
    if(fast == slow)
      return 1;
  }
  return 0;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);

  head = push(head, 5);
  head = push(head, 6);
  head->next->next->next->next = head;
  display(head);
  printf("%d", detectLoop(head));
  return 0;
}
