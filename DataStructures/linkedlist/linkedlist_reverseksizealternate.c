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

NODEPTR reversek(NODEPTR head, int k) {
  if(head == NULL || head -> next == NULL || k == 1)
    return head;
  NODEPTR curr = head, prev = NULL, next;
  int i = 0;
  while(curr != NULL && i < k) {
    next = curr -> next;
    curr -> next = prev;
    prev = curr;
    curr = next;
    i++;
  }
  if(curr != NULL)
    head -> next = curr;
  i = 0;
  while(curr != NULL && i < k - 1) {
    curr = curr -> next;
    i++;
  }
  if(curr != NULL)
    curr -> next = reversek(curr -> next, k);
  return prev;

}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  head = push(head, 3);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  display(head);
  printf("\n");
  head = reversek(head, 3);
  display(head);
  return 0;
}
