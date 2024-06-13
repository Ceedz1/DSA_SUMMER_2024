#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
}

StackArrayList createStack(){
	StackArrayList s;
	s.top = -1;
	return s;
}

bool isFull(StackArrayList *s){
	return s->top == MAX-1 ? true:false;
}

bool isEmpty(StackArrayList *s){
	return s->top == -1 ? true:false;
}

bool stack_push(StackArrayList *s, int elem){
	if(isFull(&s)){
		printf("\nStack is Full!\n");
		return false;		
	}else{
		s->top++;
		s->data[s->top] = elem;
		
		return true;
	}
}

bool stack_pop(StackArrayList *s){
	if(isEmpty(&s)){
		printf("\nStack is Empty!\n");
		return true;
	}else{
		s->top--;
		return false;
	}
}

int stack_peek(StackArrayList s){
	if(isEmpty(&s)){
		printf("\nStack is Empty!\n");
		return 1;
	}else{
		printf("TOP: %d", s.data[s.top]);
		return 0;
	}
}

void display(StackArrayList s){
	StackArrayList temp;
	
	for(temp.top = -1; s.top != -1; s.top--){
		stack_push(&temp, s.data[s.top]);
	}
	while(temp.top != -1){
		printf("%d ", temp.data[temp.top]);
		stack_pop(&temp);
	}
}



void visualize(StackArrayList s){
    if(isEmpty(s)){
        printf("\nStack is Empty!\n");
        return;
    }

    printf("Stack Visualization:\n");
    for(int i = 0; i <= s->top; i++){
        if(i == s->top){
            printf("TOP: ");
        }
        printf("[%d]: %d\n", i, s->data[i]);
    }
}
