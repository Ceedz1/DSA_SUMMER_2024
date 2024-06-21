#include <stdio.h>
#include <stdlib.h>
#include "setArray.h"

void initSet(SET *S){
    S->count = 0;
}

void populateSet(SET *S, int arrS[], int size){
    int x;

    if(S->count + size <= MAX){ 
        for(x = 0; x < size; x++){
            S->data[S->count++] = arrS[x];
        }
    }
}

SET unionUnsorted(SET A, SET B){
    SET C;
    int x,y;
    initSet(&C);

    //insert all elem of Set A to Set C
    for(x = 0; x < A.count; x++){
        C.data[C.count] = A.data[x];
        C.count++;
    }

    //insert all unique elem of B to C
    for(x = 0; x < B.count; x++){
        for(y = 0; y < C.count; y++){
            if(B.data[x] == C.data[y]){
                break;
            }
        }
        if(y == C.count){
            C.data[C.count] = B.data[x];
            C.count++;
        }
    }
    return C;
}

SET unionSorted(SET A, SET B){
    SET C;
    int ctrA, ctrB;
    ctrA = ctrB = 0;
    
    initSet(&C);

    //loop to compare elements from Sets A and B
    while(ctrA < A.count && ctrB < B.count){
        //if element in A is smaller, insert it to C
        if(A.data[ctrA] < B.data[ctrB]){
            C.data[C.count] = A.data[ctrA];
            C.count++;
            ctrA++;
        }else{
            //if elements are equal, skip the duplicate in A
            if(A.data[ctrA] == B.data[ctrB]){
                ctrA++;
            }
            //then we add elements from B to C
            C.data[C.count] = B.data[ctrB];
            C.count++;
            ctrB++;
        }
    }

    //if there are elements remaining in Set B copy it to A and
    //update counters
    if(ctrB < B.count){
        A = B;
        ctrA = ctrB;
    }

    //add any remaining elem from Set A to C
    while(ctrA < A.count){
        C.data[C.count++] = A.data[ctrA++];
    }
    return C;
}

SET getDiff(SET A, SET B){
//    SET C;
//    int x, y;
//    initSet(&C);
//
//    for(x = 0; x < A.count; x++){
//        for(y = 0; y < B.count && A.data[x] != B.data[y]; y++){
//            if(y == B.count || A.data[x] != B.data[y]){
//                C.data[C.count++] = A.data[x];
//            }
//        }
//    }


int ctrA, ctrB;
	SET C;
	C.count = 0;
	
	for (ctrA = ctrB = 0; ctrA < A.count && ctrB < B.count;) {
		if (A.data[ctrA] == B.data[ctrB]) {
			C.data[C.count++] = A.data[ctrA++];
			ctrB++;
 		} else {
 			if (A.data[ctrA] < B.data[ctrB]) {
    			ctrA++;
			} else {
   			 ctrB++;
			}
		 }
	}
    return C;
}

void visualize(int S[], int count){
    int i;

    for(i = 0; i < count; i++){
        printf("%d ", S[i]);
    }
}

void display(SET S){
    int x;

    for(x = 0; x < S.count; x++){
        printf("%d ", S.data[x]);
    }
}



