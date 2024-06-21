#ifndef Set_Array
#define Set_Array
#define MAX 10

typedef struct{
	int data[MAX];
	int count;
}SET;

void initSet(SET *S);
void populateSet(SET *S, int arrS[], int size);
SET unionUnsorted(SET A, SET B);
SET unionSorted(SET A, SET B);
SET getDiff(SET A, SET B);
void visualize(int S[], int count);
void display(SET S);

#endif
