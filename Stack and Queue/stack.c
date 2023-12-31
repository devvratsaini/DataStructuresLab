#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 100

struct Stack {
	int items[MAX_SIZE];
	int top;
};

void initStack(struct Stack* stack) {
	stack->top = -1;
}

int isEmpty(struct Stack* stack) {
	return (stack->top == -1);
}

int isFull(struct Stack* stack) {
	return (stack->top == MAX_SIZE - 1);
}

void push(struct Stack* stack, int value) {
	if(isFull(stack)) {
		printf("Stack is full. Cannot push %d.\n", value);
		return;
	}
	else {
		stack->items[++stack->top] = value;
	}
}

int pop(struct Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty. Cannot pop.\n");
		return -1;
	}
	else {
		return stack->items[stack->top--];
	}
}

int peek(struct Stack* stack) {
	if(isEmpty(stack)) {
		printf("Stack is empty. Cannot peek.\n");
		return -1;
	}
	else {
		return stack->items[stack->top];
	}
}

int main() {
	struct Stack stack;
	initStack(&stack);
	
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	
	printf("Top element: %d\n", peek(&stack));

  printf("Popped element: %d\n", pop(&stack));
  printf("Popped element: %d\n", pop(&stack));
  
  printf("Is the stack empty? %s\n", isEmpty(&stack) ? "Yes" : "No");
	
	return 0;
}
