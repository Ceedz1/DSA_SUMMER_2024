#ifndef Queue_Array
#define Queue_Array
#define MAX 10

typedef struct{
	int data[MAX];
	int front;
	int rear;
}Queue;

void initQ(Queue *Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void EnQ(Queue *Q, int newData);
void DeQ(Queue *Q);
void displayQueue(Queue Q);

#endif
