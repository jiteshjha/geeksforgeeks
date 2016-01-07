#include<stdio.h>
#include<stdlib.h>

typedef struct {
  int * arr, *next, *top;
  int free;

}STACK;

typedef STACK * STACKPTR;

STACKPTR createStack(int n, int k) {
  STACKPTR s = (STACKPTR)malloc(sizeof(STACK));
  s -> arr = (int *)calloc(n, sizeof(int));
  s -> next = (int *)calloc(n, sizeof(int));
  s -> top = (int *)calloc(k, sizeof(int));
  s -> free = 0;

  int i;
  for(i = 0; i < k; i++)
    s -> top[i] = -1;
  for(i = 0; i < n - 1; i++)
    s -> next[i] = i + 1;
  s -> next[n - 1] = -1;
  return s;
}

int isFull(STACKPTR s) {
  return s -> free == -1;
}

int isEmpty(STACKPTR s, int sn) {
  return s -> top[sn] == -1;
}
void push(STACKPTR s, int sn, int item) {

  if(isFull(s))
    {
        printf("\nStack Overflow\n");
        //return;
    }

    int i = s -> free;
    //printf("free0%d\n", s -> free);
    s -> free = s -> next[i];
    //printf("free %d\n", s -> free);
    s -> next[i] = s -> top[sn];
    s -> top[sn] = i;

    s -> arr[i] = item;
}

int pop(STACKPTR s, int sn) {
  if(isEmpty(s, sn)) {
    printf("\nStack Underflow\n");
    return -1;
  }

  int i = s -> top[sn];

  s -> top[sn] = s -> next[i];

  s -> next[i] = s -> free;
  s -> free = i;

  return s -> arr[i];

}
int main() {
  STACKPTR s = createStack(9, 3);
  push(s, 0, 3);
  push(s, 1, 2);
  push(s, 0, 4);
  push(s, 1, 1);
  printf("%d\n", pop(s, 1));
  printf("%d\n", pop(s, 1));
  printf("%d\n", pop(s, 0));
  printf("%d\n", pop(s, 0));
  return 0;
}
