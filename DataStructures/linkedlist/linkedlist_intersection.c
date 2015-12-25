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
int length(NODEPTR head) {
  int c = 0;
  NODEPTR temp = head;
  while(temp != NULL) {
    c++;
    temp = temp -> next;
  }
  return c;
}
void intersection(NODEPTR head1, NODEPTR head2) {
  int x = length(head1);
  int y = length(head2);
  int diff, choice = 1;
  diff = x>y ? x-y : y-x;
  NODEPTR largest = x>y ? head1 : head2;
  NODEPTR smallest = x>y ? head2 : head1;
  while(diff > 0) {
    largest = largest -> next;
    diff--;
  }
  while(largest != NULL && smallest != NULL) {
    if(largest == smallest) {
      printf("Intersection!, value : %d\n", largest -> data);
      return;
    }
    largest = largest -> next;
    smallest = smallest -> next;
  }
  printf("No Intersection!\n");
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 6);
  head = push(head, 5);
  head = push(head, 4);
  head = push(head, 5);
  head = push(head, 6);
  NODEPTR head1 = NULL;
  head1 = push(head1, 7);
  head1 = push(head1, 8);
  head1 -> next -> next = head -> next -> next;
  intersection(head, head1);
  display(head1);

  return 0;
}
