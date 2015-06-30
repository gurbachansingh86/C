// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sckkAr
{
	int capacity;
	int pointer;
	int *data;
};

bool isEmpty(struct sckkAr* root) {
	return (root->pointer == -1);
}

bool isFull(struct sckkAr* root) {
	return (root->pointer == (root->capacity-1));	
}

void push (struct sckkAr* root, int item) {
	if (!isFull(root)) {
		root->pointer = ++root->pointer;
		root->data[root->pointer] = item;
		printf("%d item is successful pushed in stack \n", item);
	} else {
		puts("Stack is full");
	}
}

void pop (struct sckkAr* root) {
	if (!isEmpty(root)) {
		printf("%d item is successful popped from stack \n", root->data[root->pointer]);
		root->pointer = --(root->pointer);
	} else {
		puts("Stack is empty");
	}
}

void peek (struct sckkAr* root) {
	if (!isEmpty(root)) {
		printf("%d item is top most in stack \n", root->data[root->pointer]);
	} else {
		puts("Stack is empty");
	}
}

struct sckkAr* createStack(int capacity)
{
	struct sckkAr* stackAr = (struct sckkAr*) malloc(sizeof(struct sckkAr));
	stackAr->capacity = capacity;
	stackAr->pointer = -1;
	stackAr->data = (int *) malloc(sizeof(int) * capacity);
}

int main (void) 
{
	struct sckkAr *root = createStack(5);	
	push(root, 3);
	push(root, 4);
	push(root, 5);
	push(root, 6);
	push(root, 7);
	push(root, 8);
	push(root, 9);
	push(root, 10);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
	pop(root);
	peek(root);
}