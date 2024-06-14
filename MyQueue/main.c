#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
	int data;
	struct node *next;
}node, *nodePtr;

typedef struct{
	nodePtr head, tail;
}Queue;

void initQueue(Queue *Q);
void enQueue(Queue *Q, int newData);
void deQueue(Queue *Q);
void displayQueue(Queue Q);
bool isEmpty(Queue Q);

int main(){
	Queue Q;
	
	initQueue(&Q);
	
	enQueue(&Q, 1);
	enQueue(&Q, 2);
	enQueue(&Q, 3);
	enQueue(&Q, 4);	
	
	printf("\nQueue: ");
	displayQueue(Q);
	
	printf("\nAfter DeQueue: ");
	deQueue(&Q);
	displayQueue(Q);
	printf("\nAfter DeQueue: ");
	deQueue(&Q);
	displayQueue(Q);
	printf("\nAfter DeQueue: ");
	deQueue(&Q);
	displayQueue(Q);
	
	return 0;
}

bool isEmpty(Queue Q){
	return(Q.tail == NULL) ? true:false;
}

void initQueue(Queue *Q){
	Q->head = NULL;
	Q->tail = NULL;
}

void displayQueue(Queue Q){
	nodePtr trav;
	
	for(trav = Q.head; trav != NULL; trav=trav->next){
		printf("%d ", trav->data);
	}
}

void enQueue(Queue *Q, int newData){
	nodePtr temp = malloc(sizeof(node));
	
	if(temp != NULL){
		temp->data = newData;
		temp->next = NULL;
		
		if(Q->head != NULL){
			Q->tail->next = temp;
			Q->tail = temp;
		}else{
			Q->head = Q->tail = temp;
		}
	}
}

void deQueue(Queue *Q){
	nodePtr temp;
	
	if(!isEmpty(*Q)){
		temp = Q->head;
		
		if(Q->head == Q->tail){
			Q->tail = temp->next;
		}
		Q->head = temp->next;
		free(temp);
	}else{
		printf("Queue Is Empty!");
	}
}




