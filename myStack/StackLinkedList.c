#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
    s = NULL;
}

bool isEmpty(StackArrayList *s){
   return (s == NULL) ? true:false; 
}

bool isFull(StackArrayList *s){
    return (s != NULL) ? true:false;
}

int stack_peek(StackArrayList s){
    return (s!=NULL) ? s->data:-1;
}

void stack_push(StackArrayList *s, int data){
    StackArrayList temp = malloc(sizeof(node));

    if(temp != NULL){
        temp->data = data;
        temp->next = *s;
        *s = temp;
    }
}


int stack_pop(StackArrayList *s){
    StackArrayList temp;
    int popData;

    if(isEmpty(s) != -1){
        temp = *s;
        popData = temp->data;
        *s = (*s)->next;
        free(temp);
    }
    return popData;
}

void displayStack(StackArrayList s){
    StackArrayList trav;
    int count = 0;
    for(trav = s; trav != NULL; trav = trav->next){
        printf("\n[%d]:%d", count, trav->data); 
        count++;
    }
}

void visualize(StackArrayList s) {
    StackArrayList trav = s;
    int index = 0;

    if (trav == NULL) {
        printf("The stack is empty.\n");
        return;
    }

    while (trav != NULL) {
        if (index == 0) {
            printf("[%d]: %d (TOP)\n", index, trav->data);
        } else {
            printf("[%d]: %d\n", index, trav->data);
        }
        trav = trav->next;
        index++;
    }
}

