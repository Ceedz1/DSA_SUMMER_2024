#ifndef STACK_ARRAY
#define STACK_ARRAY
#define MAX 5

typedef struct{
	int data[MAX];
	int top;
} StackArrayList;

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
int stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

void displayStack(StackArrayList s);
void visualize(StackArrayList s);


bool isFull(StackArrayList *s);
bool isEmpty(StackArrayList *s);

#endif
