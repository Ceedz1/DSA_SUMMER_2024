#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "QueueArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Queue Q;
	
	initQ(&Q);
	int newData, choose = 0;

	do{
		printf("\n---Operations---\n");
		printf("[1] EnQ");
		printf("\n[2] DeQ");
		printf("\n[3] Display");
		
		printf("\n\nEnter Operation: ");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
				printf("\nEnter Data to insert: ");
				scanf("%d", &newData);
				EnQ(&Q, newData);
				getch();
				system("cls");
				break;
			case 2:
				DeQ(&Q);
				getch();
				system("cls");
				break;
			case 3:
				displayQueue(Q);
				getch();
				system("cls");
				break;
			default:
				printf("\nPlease Select from the list!\n");
				getch();
				system("cls");
				break;
		}
	}while(choose != 0);
	return 0;
}
