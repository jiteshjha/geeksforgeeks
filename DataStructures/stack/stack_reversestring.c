#include<stdio.h>
#include<stdlib.h>

typedef struct {
  char * arr;
  unsigned capacity;
  int top;
}STACK;

typedef STACK * STACKPTR;

STACKPTR createStack(unsigned capacity) {
  STACKPTR temp = (STACKPTR)malloc(sizeof(capacity));
  temp -> capacity = capacity;
  temp -> top = -1;
  temp -> arr = (char *)calloc(capacity, sizeof(char));
  return temp;
}

int isFull(STACKPTR stack) {
  return stack -> top == stack -> capacity - 1;
}

int isEmpty(STACKPTR stack) {
  return stack -> top == -1;
}

void push(STACKPTR stack, char data) {
  if(isFull(stack)) {
    printf("Stack full!\n");
    return;
  }
  stack -> arr[++stack -> top] = data;
}
int strlength(char * str) {
  int i = 0;
  while(str[i] != '\0') {
    i++;
  }
  return i;
}
char pop(STACKPTR stack) {
  if(isEmpty(stack)) {
    printf("Stack empty!\n");
    return '\0';
  }
  return stack -> arr[stack -> top--];
}


void reverseString(char * str) {
  int len = strlength(str);

  STACKPTR stack = createStack(len);
  int i;
  for(i = 0; i < len; i++) {
    push(stack, str[i]);
  }

  for(i = 0; i < len; i++) {
    str[i] = pop(stack);
  }

}

int main() {
  char  str[] = "hey";
  reverseString(str);
  printf("%s\n", str);
}
