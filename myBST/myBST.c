#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myBST.h">

BST insert(BST root, Product newProduct){
    if(root != NULL){
        if(strcmp(newProduct.prodName, root->item.prodName) < 0){
            root->left = insert(root->left, newProduct);
        }else if(strcmp(newProduct.prodName, root->item.prodName) > 0){
            root->right = insert(root->right, newProduct);
        }
        return root;
    }else{
        return createNode(newProduct);
    }
}

BST createNode(Product newProduct){
    BST temp = malloc(sizeof(struct node));
    if(temp != NULL){
        temp->item = newProduct;
        temp->left = temp->right = NULL;
    }
    return temp;
}

BST findSuccessor(BST root){
    BST currentRoot = root;

    while(currentRoot && currentRoot->left != NULL){
        currentRoot = currentRoot->left;
    }
    return currentRoot;
}

BST deleteNode(BST root, Product delProduct){
    BST temp = root;

    if(root != NULL){
        if(strcmp(delProduct.prodName, root->item.prodName) < 0){
            root->left = deleteNode(root->left, delProduct);
        }else if(strcmp(delProduct.prodName, root->item.prodName) > 0){
            root->right = deleteNode(root->right, delProduct);
        }else{
            if(root->left == NULL && root->right == NULL){
                free(temp);
                root = NULL;
            }else if(root->left == NULL){
                temp = root->right;
                free(temp);
            }else if(root->right == NULL){
                temp = root->left;
                free(temp);
            }else{
                temp = findSuccessor(root->right);
                root->item = temp->item;
                root->right = deleteNode(root->right, temp->item);

            }
        }
        return root;
    }
    return root;
}

void inOrder(BST root){
    if(root != NULL){
        inOrder(root->left);
        printf("%-20s %02d-%02d-%d  P%.2f  %d\n", root->item.prodName, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year, root->item.prodPrice, root->item.prodQty);
        inOrder(root->right);
    }
}

void preOrder(BST root){
    if(root != NULL){
        printf("%-20s %02d-%02d-%d  P%.2f  %d\n", root->item.prodName, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year, root->item.prodPrice, root->item.prodQty);
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(BST root){
    if(root != NULL){
        inOrder(root->left);
        inOrder(root->right);
        printf("%-20s %02d-%02d-%d  P%.2f  %d\n", root->item.prodName, root->item.expDate.day, root->item.expDate.month, root->item.expDate.year, root->item.prodPrice, root->item.prodQty);
        
    }
}

void bfs(BST root){
    if(root != NULL){
        BST queue[100];

        int front = 0, rear = 0;
        queue[rear++] = root;

        while(front < rear){
            BST current = queue[front++];

            printf("%-20s %02d-%02d-%d  P%.2f  %-20d\n", current->item.prodName, current->item.expDate, current->item.prodPrice, current->item.prodQty);

            //enqueue left child
            if(current->left != NULL){
                queue[rear++] = current->left;
            }

            //enqueue right child
            if(current->right != NULL){
                queue[rear++] = current->right;
            }
        }
    }
}
