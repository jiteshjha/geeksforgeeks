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

NODEPTR insert(NODEPTR head, int data) {
  NODEPTR temp = newNode(data);
  if(head == NULL) {
    head = temp;
    head -> next = head;
    return head;
  }
  NODEPTR curr = head -> next;
  while(curr -> next != head)
    curr = curr -> next;
  curr -> next = temp;
  temp -> next = head;
  return head;
}

void display(NODEPTR head) {
  if(head == NULL) {
    printf("Empty list!\n");
    return;
  }
  NODEPTR curr = head;
  do {
    printf("%d\t", curr -> data);
    curr = curr -> next;
  }while(curr != head);

  printf("\n");
}
void split(NODEPTR head, NODEPTR * a, NODEPTR * b) {
  NODEPTR slow = head;
  NODEPTR fast = head;

  if(head == NULL || head -> next == head)
    return;

  while(fast -> next != head && fast -> next -> next != head) {
    slow = slow-> next;
    fast = fast -> next -> next;
  }

  if(fast -> next -> next == head)
    fast = fast -> next;

  * a = head;

  * b = slow -> next;
  fast -> next = slow -> next;

  slow -> next = head;
}
int main() {
  NODEPTR head1 = NULL, a = NULL, b = NULL;

  head1 = insert(head1, 1);
  head1 = insert(head1, 2);
  head1 = insert(head1, 3);
  head1 = insert(head1, 4);
  head1 = insert(head1, 5);
  split(head1, &a ,&b);
  display(b);
  return 0;
}
