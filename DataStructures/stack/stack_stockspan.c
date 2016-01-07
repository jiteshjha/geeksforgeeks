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
void stockspan(int * price, int * st, int n) {
  STACKPTR s = createStack(n);

  push(s, 0);

  st[0] = 1;
  int i, j;
  for(i = 1; i < n; i++) {
    while(!isEmpty(s) && price[top(s)] <= price[i])
      pop(s);

    if(isEmpty(s))
      st[i] = i + 1;
    else
      st[i] = i - top(s);

    push(s, i);
  }
}
int main() {
  int price[] = {100, 80, 60, 70, 60, 75, 85};
  int n = sizeof(price)/sizeof(price[0]);
  int s[n];
  stockspan(price, s, n);
  int i;
  for(i = 0; i < n; i++)
    printf("%d\t", s[i]);
  return 0;
}
