#ifndef FCFS_QueueArray
#define FCFS_QueueArray
#define MAX 20

//typedef struct{
//	int averageWT;
//	int averageTT;
//}compute;

typedef struct{
//	compute Average;
	
    char processID;
    int ArrivalTime;
    int BurstTime;
    int CompletionTime;
    int WaitingTime;
    int TurnAroundTime;
}Process;

typedef struct{
    Process array[MAX];
    int front;
    int rear;
}Queue;



void initQ(Queue *Q);
void enQ(Queue *Q, Process pData);
void displayQ(Process solveVal[], int NProcess);
void solveWtTt(Queue *Q, Process solveVal[], int NProcess);
void ganttChart(Process solveVal[], int NProcess);
void solveAverage(Process solveVal[], int NProcess);


#endif
