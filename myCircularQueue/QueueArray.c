#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "QueueArray.h"

void initQ(Queue *Q){
	Q->front = 1;
	Q->rear = 0;
}

bool isEmpty(Queue Q){
	return ((Q.rear+1)%MAX == Q.front) ? true:false;
}

bool isFull(Queue Q){
	return ((Q.rear+2)%MAX == Q.front) ? true:false;
}

void EnQ(Queue *Q, int newData){
	if(!isFull(*Q)){
		Q->rear=(Q->rear+1)%MAX;
		Q->data[Q->rear]=newData;
	}else{
		printf("Queue is Full!");
	}
}

void DeQ(Queue *Q){
	if(!isEmpty(*Q)){
		Q->front=(Q->front+1)%MAX;
	}else {
        printf("Queue is Empty.\n");
    }
}

void displayQueue(Queue Q){
	int x;
	
	if(!isEmpty(Q)){
		printf("\nQueue Data\n");
		for(x = Q.front; x != (Q.rear+1)%MAX; x = (x+1)%MAX){
			printf(" %d", Q.data[x]);
		}
		printf("\n");
	}

//	if (isEmpty(Q)) {
//        printf("Queue is empty.\n");
//    } else {
//    	
//		int x = Q.front;
//	    
//	    printf("Queue elements: ");
//	    while (x != (Q.rear + 1)%MAX) {
//	        printf("%d ", Q.data[x]);
//	        x = (x + 1)%MAX;
//	    }
//	    printf("\n");
//	}
}
