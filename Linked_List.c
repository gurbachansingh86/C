/********** Link List ********/
/**
	Definition : Like arrays, Linked List is a linear data structure.
Unlike arrays, linked list elements are not stored at contiguous location,
the elements are linked using pointers.
	
	1. It is linear data structure and non continous memory storage.
	2. Element is linked with pointer.

	Improvement over array :
	 a. Dynamic memory allocation.
	 b. Esaily insertion/deletion operation perform.
	
	Drawback :
	 a. we dnt't access directly location we use always node head to bottom.
	 b. Extra memory for next pointer location.
	 c. Inhere we dont use binary search like array use.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This is used to declare and define  structure
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
struct node {
	int data;
	struct node *pointer;	
};

/**
 * This function is used to print list
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
void printList (struct node *n)
{
	while(n != NULL) {
		printf(" Data : %d And Address : %p\n", n->data, n->pointer);
		n = n->pointer;
	}
}

/**
 * This function is used to push at front
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
void push (struct node **head, int data)
{
	struct node* new_head = (struct node*) malloc(sizeof(struct node));
	new_head->data=data;
	new_head->pointer=*head;
	(*head) = new_head;
}

/**
 * This function is used to delete first occurence node only
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
void deleteNodeOnlyFirstOccurence(struct node **head, int key)
{
	struct node* tmp = *head, *prev;

	if (*head == NULL) {
		return;
	}

	if ((*head)->data == key && (*head)->pointer == NULL) {
		free(*head);
		*head = NULL;
		return;
	} 	

 	while (tmp->pointer != NULL && tmp->data != key) {
		prev = tmp;
		tmp  = tmp->pointer;		
 	}

 	if (tmp == NULL ) return;
 	
 	prev->pointer = tmp->pointer;
 	
 	free(tmp);
}

/**
 * This function is used to append node at end of list
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
void append(struct node **head, int data)
{
	struct node* new_head = (struct node*) malloc(sizeof(struct node));
	new_head->data = data;
	new_head->pointer = NULL;
	struct node* last = *head;
	if ((*head) ==  NULL) {
		(*head) = new_head;
		return;	
	}
	while ( last->pointer != NULL) {
		last = last->pointer;
	}
	last->pointer = new_head;
}

/**
 * This function is used to delete all occurence node in list
 *
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
void deleteAllNodeOccurence(struct node **head, int key)
{
	struct node *tmp = *head, *prev;
	
	if (tmp == NULL) {
		return;
	}
	if (tmp->pointer == NULL && tmp->data == key) {
		free(tmp);
		return;	
	}
	while(tmp != NULL) {
		if (tmp->data == key) {
			if (tmp == (*head)) {
				*head = prev = tmp->pointer;
			} else {
				prev->pointer = tmp->pointer;
			}
			free(tmp); // Free memory
			tmp = prev; 
		} else {
			prev = tmp;
			tmp = tmp->pointer;
		}
		
	}	
}

/**
 * This function to get count of link list node
 * 
 * @param struct node instance
 * @return int counter
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
int getCount(struct node *head)
{
	int counter = 0;
	while (head != NULL) {
		counter++;
		head = head->pointer;
	}
	return counter;
}

/**
 * This function is use to search key in link list
 *
 * @param struct node instance
 * @return boolean true | false
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
bool searchKey(struct node *head, int key)
{
  while(head != NULL){
  	if (head->data == key) {
  		return true;
  	}
  	head = head->pointer;
  }
  return false;
}

/**
 * Default function of program 
 *
 * param void
 * retun int
 * @author Gurbachan Singh <gurbachansingh86@gmail.com>
 */
int main(void)
{
	struct node *head = NULL;
	append(&head, 1);
	append(&head, 2);
	append(&head, 3);
	append(&head, 4);
	printList(head);
	printf("Count of link list node : %d\n", getCount(head));
	if(searchKey(head, 6)) {
		puts("Key found in list");
	} else {
		puts("Key not foud in list");
	}
	return 0;
}