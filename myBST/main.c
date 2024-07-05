#include <stdio.h>
#include <stdlib.h>
#include "myBST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
    printf("\n - - Initialize BST Tree - - \n");
    BST T;
    INIT(&T);

    Product p1 = {{1, 4, 2024}, "DeepCool", 150.90, 20};
    Product p2 = {{2, 5, 2024}, "Cooler Master", 5.49, 100};
    Product p3 = {{15, 5, 2024}, "NZXT", 8.75, 30};
    Product p4 = {{23, 1, 2023}, "Corsair", 10.75, 27};
    Product p5 = {{2, 5, 2023}, "Gigabyte", 111.75, 15};

    INSERT(&T, p1);
    INSERT(&T, p2);
    INSERT(&T, p3);
    INSERT(&T, p4);
    INSERT(&T, p5);

    printf("\n - - Display Traversals - - \n");
    printf("\nPREORDER : ");
    PREORDER(T);
    printf("\nINORDER : ");
    INORDER(T);
    printf("\nPOSTORDER : ");
    POSTORDER(T);
    printf("\nBREADTH-FIRST SEARCH : ");
    BFS(T);

    char deleteProductName[20];
    printf("\nEnter Product Name to delete: ");
    scanf("%s", deleteProductName);
    T = DELETE(T, deleteProductName);

    printf("\n - - After Deletion - - \n");
    printf("\nINORDER : ");
    INORDER(T);

    return 0;
}
