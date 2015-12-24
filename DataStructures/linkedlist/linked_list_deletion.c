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

NODEPTR deleteNode(NODEPTR head, int key) {
  if(head == NULL) {
    printf("Linked list empty!");
    return head;
  }
  if(head -> data == key) {
    NODEPTR temp = head -> next;
    free(head);
    return temp;
  }
  NODEPTR traverse = head -> next, prev = NULL;
  while((traverse != NULL) && traverse -> data != key) {
    prev = traverse;
    traverse = traverse -> next;
  }
  if(traverse == NULL) {
    printf("Not found!");
    return head;
  }
  prev -> next = traverse -> next;
  free(traverse);
  return head;
}
NODEPTR deleteNodePosition(NODEPTR head, int pos) {
  if(head == NULL) {
    printf("Linked list empty!");
    return head;
  }
  if(pos == 0) {
    NODEPTR temp = head -> next;
    free(head);
    return temp;
  }
  NODEPTR traverse = head -> next, prev = NULL;
  int i = 0;
  while((traverse != NULL) && (i != pos)) {
    prev = traverse;
    traverse = traverse -> next;
    i++;
  }
  if(traverse == NULL) {
    printf("Position not found!\n");
    return head;
  }
  prev -> next = traverse -> next;
  free(traverse);
  return head;

}
int main() {
  NODEPTR head = NULL;
  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = deleteNode(head, 5);
  display(head);
  head = deleteNodePosition(head, 1);
  display(head);
  return 0;
}
