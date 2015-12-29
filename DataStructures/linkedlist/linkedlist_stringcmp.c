#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  char data;
  struct node * next;
}NODE;

typedef NODE * NODEPTR;

NODEPTR newNode(char data) {
  NODEPTR temp = (NODEPTR)malloc(sizeof(NODE));
  temp -> data = data;
  temp -> next = NULL;
  return temp;
}
NODEPTR push(NODEPTR head, char data) {
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
    printf("%c\n", temp -> data);
    temp = temp -> next;
  }
}

int stringcmp(NODEPTR a, NODEPTR b) {
  NODEPTR first = a, second = b;
  while(first != NULL && second != NULL) {
    if(first -> data > second -> data)
      return 1;
    else if(second -> data > first -> data)
      return -1;
    first = first -> next;
    second = second -> next;
  }
  if(first != NULL)
    return 1;
  if(second != NULL)
    return -1;
  return 0;
}
int main() {
  NODEPTR head = NULL, head1 = NULL;

  //head = push(head, 'a');
  head = push(head, 'b');
  head = push(head, 'c');

  head1 = push(head1, 'a');
  head1 = push(head1, 'b');
  head1 = push(head1, 'c');
  printf("%d\n", stringcmp(head1, head));
  return 0;
}
