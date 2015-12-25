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

NODEPTR reverse(NODEPTR head) {
  if(head == NULL) {
    printf("List empty!\n");
    return head;
  }
  NODEPTR prev = NULL, curr = head, next;
  while(curr != NULL) {
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
  return head;
}
NODEPTR middle(NODEPTR head) {
  NODEPTR fastptr = head, slowptr = head;

  while(fastptr != NULL && fastptr -> next != NULL) {
    fastptr = fastptr -> next -> next;
    slowptr = slowptr -> next;
  }
  if(fastptr != NULL)
    slowptr = slowptr -> next;
  return slowptr;
}
int palindrome(NODEPTR head) {
  if(head == NULL) {
    printf("List empty!\n");
    return 0;
  }
  NODEPTR mid = middle(head);
  mid = reverse(head);
  NODEPTR curr = head;
  while(mid != NULL && curr != NULL) {
    if(mid -> data != curr -> data)
      return 0;
    mid = mid -> next;
    curr = curr -> next;
  }
  return 1;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 6);
  head = push(head, 5);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  display(head);
  printf("%d", palindrome(head));
  return 0;
}
