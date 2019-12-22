#ifndef STACK_H
#define STACK_H

#define STACK_SIZE 1500

typedef struct {
	int top;
	char* items[STACK_SIZE];
}Stack;

//Stack functions
Stack* createStack();
int push(Stack* stack, char* x);
int pop(Stack* stack, char** x);
int peek(Stack* stack, char** x);
int _isEmpty(Stack* stack);
int _isFull(Stack* stack);
int printStack(Stack* stack);
int resetStack(Stack* stack);

#endif // !STACK_H