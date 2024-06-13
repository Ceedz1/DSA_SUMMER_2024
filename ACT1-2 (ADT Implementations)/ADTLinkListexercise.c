#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct{
    char name[20];
    int idNum;
    int age;
}info;

typedef struct node{
    info data;
    struct node *next;
}node, *nodePtr;

void displayList(nodePtr List);
void insertFirst(nodePtr *List, info newStud);
void insertLast(nodePtr *List, info newStud);
void insertIndex(nodePtr *List, int Pos, info newStud);
void insertSorted(nodePtr *List, info newStud);
void deleteFirst(nodePtr *List);
void deleteLast(nodePtr *List);
void deleteIndex(nodePtr *List, int Pos);
info initStudInfo();

int main(){
    nodePtr List = NULL;

    int Pos;
    int choose = 0;

    do{
        printf("\n.....Operations.....\n");
        printf("\n[1] Insert First\n");
        printf("[2] Insert Last\n");
        printf("[3] Insert Index\n");
        printf("[4] Insert Sorted\n");
        printf("[5] Delete First\n");
        printf("[6] Delete Last\n");
        printf("[7] Delete Index\n");
        printf("[9] Display List\n");

        printf("\n\nEnter Operation: ");
        scanf("%d", &choose);
        fflush(stdin);
        switch(choose){
            case 1:
                insertFirst(&List, initStudInfo());
                getch();
                system("cls");
                break;
            case 2:
                insertLast(&List, initStudInfo());
                getch();
                system("cls");
                break;
            case 3:
                printf("\nPosition to insert: ");
                scanf("%d", &Pos);
                fflush(stdin);
                insertIndex(&List, Pos, initStudInfo());
                getch();
                system("cls");
                break;
            case 4:
                insertSorted(&List, initStudInfo());
                getch();
                system("cls");
                break;
            case 5:
                deleteFirst(&List);
                getch();
                system("cls");
                break;
            case 6: 
                deleteLast(&List);
                getch();
                system("cls");
                break;
            case 7:
                printf("\nPosition to delete: ");
                scanf("%d", &Pos);
                fflush(stdin);
                deleteIndex(&List, Pos);
                getch();
                system("cls");
                break;
            case 9:
                displayList(List);
                getch();
                system("cls");
                break;
            default:
                printf("\nPlease Select from the List.\n");
                getch();
                system("cls");
                break;
        }
    }while(choose != 0);
    return 0;
}



info initStudInfo(){
    info newStud;

    printf("\n.....Student Form.....\n");
    printf("Name: ");
    gets(newStud.name);
    fflush(stdin);

    printf("ID: ");
    scanf("%d", &newStud.idNum);
    printf("Age: ");
    scanf("%d", &newStud.age);

    return newStud;
}

void insertFirst(nodePtr *List, info newStud){
    nodePtr temp = malloc(sizeof(node));
    if(temp != NULL){
        temp->data = newStud;
        temp->next = *List;
        *List = temp;
    }
}

void insertLast(nodePtr *List, info newStud){
    nodePtr trav, temp = malloc(sizeof(node));
    if(temp != NULL){
        temp->data = newStud;
        temp->next = NULL;

        if(*List != NULL){
            for(trav = *List; trav->next != NULL; trav = trav->next){}
            trav->next = temp;
        }else{
            *List = temp;
        }
    }
}

void insertIndex(nodePtr *List, int Pos, info newStud){
    nodePtr trav, temp = malloc(sizeof(node));
    int count = 0;

    if(temp != NULL){
        temp->data = newStud;
        temp->next = NULL;

        if(Pos != 0){
            for(trav = *List; trav != NULL && count != Pos-1; trav = trav->next){
                count++;
            }
            temp->next = trav->next;
            trav->next = temp;
        }else{
            temp->next = *List;
            *List = temp;
        }
    }
}

void insertSorted(nodePtr *List, info newStud){
    nodePtr trav, temp = malloc(sizeof(node));

    if(temp != NULL){
        temp->data = newStud;
        temp->next = NULL;


        if(*List != NULL){
            if((*List)->data.age > temp->data.age){
                temp->next = *List;
                *List = temp;
            }else{
                for(trav = *List; trav->next != NULL && trav->next->data.age <= temp->data.age; trav = trav->next){}
                temp->next = trav->next;
                trav->next = temp;
            }   
        }else{
            *List = temp;
        }
    }
}

void deleteFirst(nodePtr *List){
    nodePtr temp;
    
    if(*List != NULL){  
        temp = *List;
        *List = (*List)->next;
        free(temp);
    }
}
    
void deleteLast(nodePtr *List){
    nodePtr trav, temp;

    if(*List != NULL){
        for(trav = *List; trav->next->next != NULL; trav = trav->next){}
        temp = trav->next->next;
        trav->next = NULL;
        free(temp);

    }

}

void deleteIndex(nodePtr *List, int Pos){
    nodePtr trav, temp;
    int count = 0;

    if(*List != NULL){
        //---Check if Position is out of bounds (not working yet)---
        // if(trav == NULL || trav->next == NULL){
        //     printf("\nInvalid Position!\n");
        // }
        if(Pos != 0){
            for(trav = *List; trav->next != NULL && count != Pos-1; trav = trav->next){
                count++;
            }
            temp = trav->next;
            trav->next = temp->next;
        }else{
            temp = *List;
            *List = (*List)->next;
        }
        free(temp);
    }
}

void displayList(nodePtr List){
    nodePtr trav;

    printf("\n.....Student Info.....\n");

    if(List != NULL){
        for(trav = List; trav != NULL; trav = trav->next){
            printf("\nName: %s", trav->data.name);
            printf("\nID: %d", trav->data.idNum);
            printf("\nAge: %d", trav->data.age);
            printf("\n");
        }
    }else{
        printf("\nList is Empty!");
    } 
}