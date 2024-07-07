#include <stdio.h>
#include <stdlib.h>
#include "myBST.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
    BST root = NULL;

    Product p1 = {{1, 4, 2024}, "Cadbury", 15.90, 10};
    Product p2 = {{2, 5, 2024}, "M&M", 250.90, 20};
    Product p3 = {{12, 12, 2024}, "Hershey's", 90.30, 200};
    Product p4 = {{15, 12, 2024}, "Toblerone", 150.90, 20};
    Product p5 = {{15, 2, 2024}, "Ghirardelli", 300.60, 5};
    Product p6 = {{10, 3, 2024}, "Godiva", 160.50, 15};
    Product p7 = {{7, 1, 2025}, "Kit kat", 200.00, 10};
    Product p8 = {{22, 8, 2024}, "Mars", 180.75, 8};
    Product p9 = {{30, 7, 2024}, "Snickers", 250.90, 5};
    Product p10 = {{19, 11, 2024}, "Milka", 300.60, 7};
    Product p11 = {{5, 5, 2024}, "Nestle Crunch", 400.00, 12};
    Product p12 = {{16, 6, 2024}, "Ritter Sport", 110.00, 25};
    Product p13 = {{25, 12, 2024}, "Bounty", 130.20, 22};
    Product p14 = {{1, 9, 2024}, "Galaxy", 220.40, 18};
    Product p15 = {{3, 10, 2024}, "Reese's", 140.00, 30};
    Product p16 = {{12, 11, 2024}, "Twix", 150.00, 25};
    Product p17 = {{20, 2, 2024}, "Butterfinger", 125.75, 20};
    Product p18 = {{11, 4, 2024}, "Baby Ruth", 170.50, 15};
    Product p19 = {{8, 7, 2024}, "Lindt Swiss", 130.90, 10};
    Product p20 = {{13, 8, 2024}, "Bar Nuts", 90.30, 12};

    root = insert(root, p1);
    root = insert(root, p2);
    root = insert(root, p3);
    root = insert(root, p4);
    root = insert(root, p5);
    // root = insert(root, p6);
    // root = insert(root, p7);
    // root = insert(root, p8);
    // root = insert(root, p9);
    // root = insert(root, p10);
    // root = insert(root, p11);
    // root = insert(root, p12);
    // root = insert(root, p13);
    // root = insert(root, p14);
    // root = insert(root, p15);
    // root = insert(root, p16);
    // root = insert(root, p17);
    // root = insert(root, p18);
    // root = insert(root, p19);
    // root = insert(root, p20);

    printf("\nIn-Order Traversal: \n");
    inOrder(root);
    printf("\nPre-Order Traversal: \n");
    preOrder(root);
    printf("\nPost-Order Traversal: \n");
    postOrder(root);

    printf("\nBFS Traversal: \n");
    bfs(root);

    printf("\n\n Deleted: P4\n");
    root = deleteNode(root, p4);

    printf("\nIn-Order Traversal: \n");
    inOrder(root);
    printf("\nPre-Order Traversal: \n");
    preOrder(root);
    printf("\nPost-Order Traversal: \n");
    postOrder(root);

    printf("\nBFS Traversal: \n");
    bfs(root);
    return 0;
}
