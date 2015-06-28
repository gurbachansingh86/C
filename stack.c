/** ---------------  Stack ------------------- **/
/** 
 * Stack is a linear data structure which follows a particular order
 * in which the operations are performed. The order may be 
 * LIFO(Last In First Out) or FILO(First In Last Out). Mainly the following 
 * 	three basic operations are performed in the stack:
 * Push: Adds an item in the stack. If the stack is full, 
		then it is said to be an Overflow condition.
 * Pop: Removes an item from the stack. The items are popped in the reversed order
 * 		in which they are pushed. If the stack is empty, then it is said to be
 * 		an Underflow condition.
 * Peek: Get the topmost item.
 * Stack will be implemented using Array and link list here i will show to you how using
 * link list present stack
 * -------------------- Implement Using Link List ---------------------------
 */
 // C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct stackNode
{
  int data;
  struct stackNode* next; 
};

struct stackNode* createNode(int data)
{
    struct stackNode* newNode = (struct stackNode*) malloc(sizeof(struct stackNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

bool isEmpty(struct stackNode *root)
{
    return !root;
}

void push(struct stackNode** root, int data)
{
    struct stackNode *tmp = createNode(data);
    tmp->data = data;
    tmp->next = *root;
    *root = tmp;
    printf(" %d  push in stack \n", data);
}

int peek(struct stackNode** root)
{
    if (isEmpty(*root)) {
        return printf("Empty Stack");
    }
    return (*root)->data;
}

int pop (struct stackNode** root)
{
   if (isEmpty(*root)) {
        return printf("Empty Stack");
    }
    struct stackNode* tmp = *root;
    *root = tmp->next;
    tmp->next = NULL;
    int popped = tmp->data; 
    free(tmp);
    return popped; 
}

int main(void)
{
    struct stackNode* root = NULL;
    push(&root, 1); 
    push(&root, 2);
    push(&root, 3);
    push(&root, 4);
    push(&root, 5);
    push(&root, 6);
    printf("%d pop element of stack \n", pop(&root));
    printf("%d peek element of stack \n", peek(&root)); 
    printf("%d pop element of stack \n", pop(&root));
    printf("%d peek element of stack \n", peek(&root)); 
}