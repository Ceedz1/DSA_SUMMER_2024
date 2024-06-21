#include <stdio.h>
#include <stdlib.h>
#include "setArray.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
    SET A, B, unsortU, sortedU, diff, intersect;
    initSet(&A);
    initSet(&B);

    populateSet(&A, (int[]){1,2,3,5,6},5);
    populateSet(&B, (int[]){2,3,4,5,8},5);

    printf("\nSet A: ");
    display(A);
    printf("\nSet B: ");
    display(B);

    unsortU = unionUnsorted(A, B);
    printf("\nUnion Unsorted: ");
    display(unsortU);

    sortedU = unionSorted(A,B);
    printf("\nUnion Sorted: ");
    display(sortedU);

    diff = getDiff(A, B);
    printf("\nDifference: ");
    // visualize(diff.data, diff.count);
    display(diff);
    // intersect = getIntersect(A, B);
    // printf("\nIntersection: ");
    // display(intersect);

    return 0;
} 

