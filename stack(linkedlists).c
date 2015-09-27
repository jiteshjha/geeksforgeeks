#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node *next;
}*top, *temp, *top1;

void create() {
	top = NULL;
}
void push(int info) {
	if(top == NULL) {
		top = (struct node *)malloc(sizeof(struct node));
		top -> next = NULL;
		top -> data = info;
	}
	else {
		temp = (struct node *)malloc(sizeof(struct node));
		temp -> next = top;
		temp -> data = info;
		top = temp;
	}
}

void display() {
	top1 = top;
	if(top1 == NULL) {
		printf("Stack is empty");
	}
	else {
		while(top1 != NULL) {
			printf("%d ", top1 -> data);
			top1 = top1 -> next;
		}
	}
	printf("\n");
}

void pop() {
	top1 = top;

	if(top1 == NULL) {
		printf("Stack is empty");
	}
	else {
		top1 = top1 -> next;
		printf("\nPopped value: %d\n", top -> data);
		free(top);
		top = top1;
	}
}

int main() {
	create();
	int choice, item;
	for(;;) {
		printf("Press 1 for push, 2 for pop\n3 for display, 4 to Exit:\n>");
		scanf("%d", &choice);
		if(choice == 1) {
			printf("Enter item:\n>");
			scanf("%d", &item);
			push(item);
		}
		else if(choice == 2) {
			pop();
		}
		else if(choice == 3) {
			display();
		}
		else {
			printf("Exiting...");
			exit(EXIT_SUCCESS);
		}
	}
	return 0;
}
