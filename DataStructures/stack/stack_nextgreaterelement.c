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

void printNGE(int * arr, int len) {
  STACKPTR s = createStack(len);
  int i = 0, element, next;

  push(s, arr[0]);

  for(i = 0; i < len; i++) {

    next = arr[i];
    if(isEmpty(s) == 0) {
      element = pop(s);

      while(element < next) {
        printf("%d --> %d\n", element, next);
        if(isEmpty(s) == 1)
          break;
        element = pop(s);
      }

      if(element > next)
        push(s, element);
    }

    push(s, next);
  }

  while(isEmpty(s) == 0) {
    element = pop(s);
    next = -1;
    printf("%d --> %d\n", element, next);
  }
}

int main() {
  int arr[] = {4, 5, 2, 25, 7, 50};
  int len = sizeof(arr)/sizeof(arr[0]);
  printNGE(arr, len);
  return 0;
}
