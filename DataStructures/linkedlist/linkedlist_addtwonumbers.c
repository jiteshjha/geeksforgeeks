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

NODEPTR add(NODEPTR a, NODEPTR b) {
  NODEPTR aa = reverse(a);
  NODEPTR bb = reverse(b);
  NODEPTR aR = aa, bR = bb;
  NODEPTR result = NULL;
  int sum = 0, carry = 0;
  while(aR != NULL && bR != NULL) {
    sum = aR -> data + bR -> data + carry;
    carry = sum/10;
    result = push(result, sum%10);
    aR = aR -> next;
    bR = bR -> next;
  }
  while(aR != NULL) {
    sum = aR -> data + carry;
    carry = sum/10;
    result = push(result, sum%10);
    aR = aR -> next;
  }
  while(bR != NULL) {
    sum = bR -> data + carry;
    carry = sum/10;
    result = push(result, sum%10);
    bR = bR -> next;
  }
  if(carry != 0)
    result = push(result, carry);

  result = reverse(result);
  return result;
}
int main() {
  NODEPTR head = NULL;

  head = push(head, 2);
  head = push(head, 3);
  head = push(head, 4);
  display(head);
  NODEPTR head1 = NULL;
  head1 = push(head1, 9);
  head1 = push(head1, 3);
  head1 = push(head1, 4);
  NODEPTR result = add(head, head1);
  display(result);
  return 0;
}
