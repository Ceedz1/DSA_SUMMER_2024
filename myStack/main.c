#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

int main(int argc, char *argv[]){
  
  StackArrayList s;
  
  initStack(&s);
  
  stack_push(&s, 1);
  stack_push(&s, 2);
  stack_push(&s, 3);
  stack_push(&s, 4);
  
  int peekData = stack_peek(s);
  
  printf("\nTop: %d\n\n", peekData);
  
  displayStack(s);
  printf("\n");
  
  visualize(s);
  
  int popData = stack_pop(&s);
  if(popData != -1){
    printf("\nPop: %d\n\n", popData);           
  }
  
  visualize(s);
  return 0;
}
