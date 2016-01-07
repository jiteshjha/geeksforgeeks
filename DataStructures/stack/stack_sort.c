#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int * arr;
  unsigned capacity;
  int top;
}STACK;

typedef STACK * STACKPTR;

STACKPTR createStack(unsigned capacity) {
  STACKPTR temp = (STACKPTR)malloc(sizeof(capacity));
  temp -> capacity = capacity;
  temp -> top = -1;
  temp -> arr = (int *)calloc(capacity, sizeof(char));
  return temp;
}

int isFull(STACKPTR stack) {
  return stack -> top == stack -> capacity - 1;
}

int isEmpty(STACKPTR stack) {
  return stack -> top == -1;
}

void push(STACKPTR stack, int data) {
  if(isFull(stack)) {
    printf("Stack full!\n");
    return;
  }
  stack -> arr[++stack -> top] = data;
}


int pop(STACKPTR stack) {
  if(isEmpty(stack)) {
    printf("Stack empty!\n");
    return '\0';
  }
  return stack -> arr[stack -> top--];
}
int top(STACKPTR s) {
  if(!isEmpty(s))
    return s -> arr[s -> top];
  else
    return 0;
}
void SortedInsert(STACKPTR s, int item) {
  if(isEmpty(s) || item > top(s)) {
    push(s, item);
    return;
  }

  int temp = pop(s);

  SortedInsert(s, item);

  push(s, temp);
}
void Sort(STACKPTR s) {
  if(!isEmpty(s)) {
    int temp = pop(s);

    Sort(s);

    SortedInsert(s, temp);
  }
}
int main() {
  STACKPTR s = createStack(5);
  push(s, 1);
  push(s, 2);
  push(s, 3);
  push(s, 4);
  Sort(s);
  while(!isEmpty(s)) {
    printf("%d", pop(s));
  }
  return 0;
}
