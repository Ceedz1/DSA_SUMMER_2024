#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	StackArrayList s;
	
	initStack(&s);
	
	stack_push(&s, 1);
	stack_push(&s, 2);
	stack_push(&s, 3);
	stack_push(&s, 4);
	
	stack_peek(s);	
	printf("\n");
	display(s);
	
	visualize(s);
	return 0;
}
