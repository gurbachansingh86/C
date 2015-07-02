/* Implementation of queue using array */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct myArray
{
  int capacity;
  int pointer;
  int *arrayData;
  int front;
  int rear;
};

bool isFull (struct myArray* root)
{
	return ((root->capacity - 1) == (root->pointer)); 
}

bool isEmpty (struct myArray* root)
{
	return root->pointer == -1; 
}

struct myArray* createHelperArray(int capacity )
{
	struct myArray* node = (struct myArray*) malloc(sizeof(struct myArray));
	node->capacity = capacity;
	node->pointer  = node->front = 0;
	node->rear = capacity -1;
	node->arrayData = (int *) malloc(sizeof(int) * capacity);
	return node;
}

void enQueue(struct myArray* root, int item)
{
	if (isFull(root)) {
 		puts("Queue is full");
		return;
	}	
	root->rear = (root->rear+1) % root->capacity;
	root->arrayData[root->rear] = item;
	root->pointer = root->pointer + 1;
	
	printf("%d successfully insert in queue \n", item);
}

void deQueue(struct myArray* root)
{
	if (isEmpty(root)) {
 		puts("Queue is full");
		return;
	}
	
	int item = root->arrayData[root->front];
	root->front = (root->front + 1) % root->capacity;
	root->pointer = root->pointer - 1;
	printf("%d successfully deQueue from queue \n", item);
}

void front(struct myArray* root)
{
	if (isEmpty(root)) {
		puts("Empty queue");
		return;
	}
	printf("%d font in queue\n",root->arrayData[root->front]);
}

void rear(struct myArray* root)
{
	if (isEmpty(root)) {
		puts("Empty queue");
		return;
	}
	printf("%d rear in queue\n",root->arrayData[root->rear]);
}

int main ()
{
	struct myArray* node = createHelperArray(5);
	enQueue(node, 1);
	enQueue(node, 2);
	front(node);
	rear(node);
	deQueue(node);
	front(node);
	rear(node);
 	return 0;
}