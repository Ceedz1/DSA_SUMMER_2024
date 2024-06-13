//insertSorted (sort by age)

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct{
	char fName[MAX];
	char Lname[MAX]; 
}studName;

typedef struct{
	int month;
	int year;
}bDay;

typedef struct{
	studName name;
	bDay birthDate;
	int age;
	int idNum;
}studentInfo;

typedef struct{
	studentInfo studList[MAX];
	int studCount;
}classRec;


void initList(classRec *R);
void insertFront(classRec *R, studentInfo newStud);
studentInfo initStudRec();
void insertLast(classRec *R, studentInfo newStud);
void insertPos(classRec *R, studentInfo newStud);
void insertSorted(classRec *R, studentInfo newStud);
void displayRec(classRec R);
void deletePos(classRec *R);
void deleteFirst(classRec *R);
void deleteLast(classRec *R);

int main(){
	classRec R;
	initList(&R);
	
    studentInfo newStud;
    
	int choose = 0;
    
    do{
    	printf("\n---Operations---\n");
	    printf("[1] Insert First\n");
	    printf("[2] Insert Last\n");
	    printf("[3] Insert Position\n");
	    printf("[4] Insert Sorted\n");
	    printf("[5] Delete First\n");
	    printf("[6] Delete Last\n");
	    printf("[7] Delete Position\n");
	    printf("[8] Display List\n");
	    printf("[0] Exit\n");
	    
	    printf("\nEnter Operation: ");
	    scanf("%d", &choose);
	    fflush(stdin);
	    printf("\n");
    	
    	
    	switch(choose){
	    	case 1:
	    		newStud = initStudRec();
	    		insertFront(&R, newStud);
	    		getch();
				system("cls");
				break;
			case 2: 
				newStud = initStudRec();
				insertLast(&R, newStud);
				getch();
				system("cls");
				break;
			case 3:
				newStud = initStudRec();
				insertPos(&R, newStud);
				getch();
				system("cls");
				break;
			case 4:
				newStud = initStudRec();
				insertSorted(&R, newStud);
				getch();
				system("cls");
				break;
			case 5:
				deleteFirst(&R);
				getch();
				system("cls");
				break;
			case 6:
				deleteLast(&R);
				getch();
				system("cls");
				break;
			case 7:
				deletePos(&R);	
				getch();
				system("cls");
				break;
			case 8:
				displayRec(R);
				getch();
				system("cls");
				break;
		}
	}while(choose != 0);  
	return 0;
}


void initList(classRec *R){
	R->studCount = 0;
}

void displayRec(classRec R){
	int x;
	
	printf("\n\n---Student Records---\n\n");
	if(R.studCount != 0){
		for(x = 0; x < R.studCount; x++){
			printf("\nFirst Name: %s", R.studList[x].name.fName);
			printf("\nLast Name: %s", R.studList[x].name.Lname);
			printf("\nBirth Month: %d", R.studList[x].birthDate.month);
			printf("\nBirth Year: %d", R.studList[x].birthDate.year);
			printf("\nAge: %d", R.studList[x].age);
			printf("\nID: %d", R.studList[x].idNum);
			printf("\n");
		}
	}else{
		printf("\nList is Empty!\n");
	}
}

studentInfo initStudRec(){
	studentInfo newStud;
	
	printf("\n---Enter StudentInfo---\n");
	
	printf("Enter First Name: ");
	scanf("%[^\n]s ", newStud.name.fName);
	fflush(stdin);
	printf("Enter Last Name: ");
	scanf("%[^\n]s ", newStud.name.Lname);
	fflush(stdin);
	printf("Enter Brith Month: ");
	scanf("%d", &newStud.birthDate.month);
	fflush(stdin);
	printf("Enter Birth Year: ");
	scanf("%d", &newStud.birthDate.year);
	fflush(stdin);
	printf("Enter Age: ");
	scanf("%d", &newStud.age);
	fflush(stdin);
	printf("Enter ID Number: ");
	scanf("%d", &newStud.idNum);
	fflush(stdin);
	return newStud;
}

void insertFront(classRec *R, studentInfo newStud ){
	int x;
	
	if(R->studCount < MAX){
		for(x = R->studCount; x > 0; x--){
			R->studList[x] = R->studList[x-1];
		}
		R->studList[x] = newStud;
		R->studCount++;
	}
}

void insertLast(classRec *R, studentInfo newStud){
	if(R->studCount < MAX){
		R->studList[R->studCount] = newStud;
		R->studCount++;
	}
}

void insertPos(classRec *R, studentInfo newStud){
	int x;
	int Pos;
	
	printf("\nEnter Position: ");
	scanf("%d", &Pos);
	
	if(R->studCount < MAX){
		for(x = R->studCount; x > Pos; x--){
			R->studList[x] = R->studList[x-1];
		}
		R->studList[x] = newStud;
		R->studCount++;
	}
}

void insertSorted(classRec *R, studentInfo newStud){
	int x; 
	
	if(R->studCount < MAX){
		for(x = R->studCount-1; x >= 0 && R->studList[x].age > newStud.age ; x--){
			R->studList[x+1] = R->studList[x];
		}
		R->studList[x+1] = newStud;
		R->studCount++;
	}
}

void deleteFirst(classRec *R){
	int x;
	
	if(R->studCount != 0){
		for(x = 0; x < R->studCount; x++){
			R->studList[x] = R->studList[x+1];
		}
		R->studCount--;
	}
}

void deleteLast(classRec *R){
	if(R->studCount != 0){
		R->studCount--;
	}
}

void deletePos(classRec *R){
	int x, Pos;
	
	printf("\nEnter Position to delete: ");
	scanf("%d", &Pos);
	
	if(Pos < R->studCount){
		for(x = Pos; x < R->studCount; x++){
			R->studList[x] = R->studList[x+1];
		}
		R->studCount--;
	}	
}



