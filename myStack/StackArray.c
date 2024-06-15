#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

bool isFull(StackArrayList *s){
	return s->top == MAX-1 ? true:false;
}

bool isEmpty(StackArrayList *s){
	return s->top == -1 ? true:false;
}

bool stack_push(StackArrayList *s, int elem){
	if(!isFull(s)){
		s->top++;
		s->data[s->top] = elem;
		return true;
	}else{
		printf("\nStack is Full!\n");
		return false;
	}
}

int stack_pop(StackArrayList *s){
	
	if(!isEmpty(s)){
		int temp = s->data[s->top];
		s->top--;
		return temp;
	}else{
		printf("\nStack is Empty!\n");
		return -1;
	}
}

int stack_peek(StackArrayList s){
	if(!isEmpty(&s)){
		return s.data[s.top];
	}else{
		printf("\nStack is empty!\n");
		return false;
	}
}

void displayStack(StackArrayList s){
	StackArrayList temp;


	for(temp.top = -1; s.top != -1; s.top--){
		stack_push(&temp, s.data[s.top]);
	}

	while(temp.top != -1){
		printf("%d ", temp.data[temp.top]);
		stack_pop(&temp);
	}
}

void visualize(StackArrayList s) {
	int i;
    for (i = s.top; i >= 0; i--) {
        if (i == s.top) {
            printf("[%d]: %d (TOP)\n", i, s.data[i]);
        }else{
            printf("[%d]: %d\n", i, s.data[i]);
        }
    }
}
