/** 
 * Queue : In this datastructure follow order operation perform in which first come first out or first come  
 * First server operation  like our machine in which one request server as first and follow the order.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 
 struct Queue
 {
   int data;
   struct Queue *next;   
 };
 struct QPointer
 {
    struct Queue *front, *rear;   
 };
 
 bool isEmpty(struct QPointer* root)
 {
 	return (root->front == NULL);
 }
 
 void enQueue (struct QPointer **root, int item)
 {
 	struct Queue *head = (struct Queue*) malloc(sizeof(struct Queue));
 	head->data = item;
 	head->next = NULL;
 	if ((*root)->front == NULL) {
		(*root)->front = head;
 	}
 	if ((*root)->rear != NULL) {
 		(*root)->rear->next = head;	
 	} 	
 	(*root)->rear = head;
 	printf("%d is enQueue in Queue \n", item);
 }

 void deQueue (struct QPointer **root)
 {
 	if (isEmpty(*root)) {
 		puts("Queue is empty");
 		return;
 	}
 	struct Queue *tmp = (*root)->front;
 	int data = tmp->data;
 	(*root)->front = tmp->next;
 	free(tmp);
 	printf("%d is deQueue from Queue \n", data);
 }
 
 void rear(struct QPointer *root)
 {
 	if (isEmpty(root)) {
 		puts("Queue is empty");
 		return;
 	}
 	printf("%d is end item in Queue \n", root->rear->data);
 }

 void front(struct QPointer *root)
 {
 	if (isEmpty(root)) {
 		puts("Queue is empty");
 		return;
 	}
 	printf("%d is front item in Queue \n", root->front->data);
 }

 struct QPointer* createPointer()
 {
 	struct QPointer*  node = (struct QPointer*) malloc(sizeof(struct QPointer) );
	node->front = node->rear = NULL;
 	return node;
 }

 void printList(struct Queue *root)
 {	
 	while (root != NULL) {
 		printf("Orignal Address : %p \t Data : %d \t Address : %p \n", root, root->data, root->next);
 		root = root->next;
 	}

 }

 int main (void) {
	struct QPointer* pointerHead =  createPointer();
 	enQueue(&pointerHead, 2);
 	enQueue(&pointerHead, 3);
 	enQueue(&pointerHead, 4);
	enQueue(&pointerHead, 5);
	deQueue(&pointerHead); // 2
	deQueue(&pointerHead); // 3
	deQueue(&pointerHead); // 4
 	deQueue(&pointerHead); // 5
 	front(pointerHead);
 	front(pointerHead);
 	front(pointerHead);
 	rear(pointerHead);
 	rear(pointerHead);
 	rear(pointerHead);
 }
