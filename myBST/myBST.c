#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myBST.h">

void INIT(BST *T) {
    *T = NULL;
}

void INSERT(BST *T, Product elem) {
    BST trav = *T, temp;
    while (trav != NULL && strcmp(trav->item.prodName, elem.prodName) != 0) {
        trav = (strcmp(trav->item.prodName, elem.prodName) < 0) ? trav->RC : trav->LC;
    }
    if (trav == NULL) {
        temp = (BST)malloc(sizeof(struct node));
        if (temp != NULL) {
            temp->item = elem;
            temp->LC = temp->RC = NULL;
            *T = temp;
        }
    }
}

void PREORDER(BST T) {
    if (T != NULL) {
        printf("%-20s ", T->item.prodName);
        PREORDER(T->LC);
        PREORDER(T->RC);
    }
}

void INORDER(BST T) {
    if (T != NULL) {
        INORDER(T->LC);
        printf("%-20s ", T->item.prodName);
        INORDER(T->RC);
    }
}

void POSTORDER(BST T) {
    if (T != NULL) {
        POSTORDER(T->LC);
        POSTORDER(T->RC);
        printf("%-20s ", T->item.prodName);
    }
}

void BFS(BST T) {
    Queue q;
    q.front = q.rear = NULL;

    if (T != NULL) {
        enqueue(&q, T);
    }

    while (!isQueueEmpty(&q)) {
        BST current = dequeue(&q);
        printf("%-20s ", current->item.prodName);

        if (current->LC != NULL) {
            enqueue(&q, current->LC);
        }
        if (current->RC != NULL) {
            enqueue(&q, current->RC);
        }
    }
}

// Queue functions for BFS
void enqueue(Queue *q, BST treeNode) {
    QueueNode *newNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->treeNode = treeNode;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

BST dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        fprintf(stderr, "Queue is empty\n");
        exit(EXIT_FAILURE);
    }

    QueueNode *temp = q->front;
    BST treeNode = temp->treeNode;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return treeNode;
}

int isQueueEmpty(Queue *q) {
    return (q->front == NULL);
}

BST DELETE(BST T, char *prodName) {
    if (T == NULL) {
        return NULL;
    }

    // Search for the node to delete
    if (strcmp(T->item.prodName, prodName) < 0) {
        T->RC = DELETE(T->RC, prodName);
    } else if (strcmp(T->item.prodName, prodName) > 0) {
        T->LC = DELETE(T->LC, prodName);
    } else {
        // Node to be deleted found
        BST temp;

        // Case 1: No child or one child
        if (T->LC == NULL) {
            temp = T->RC;
            free(T);
            return temp;
        } else if (T->RC == NULL) {
            temp = T->LC;
            free(T);
            return temp;
        }

        // Case 2: Two children
        // Find the minimum node in the right subtree (successor)
        temp = T->RC;
        while (temp->LC != NULL) {
            temp = temp->LC;
        }

        // Copy the successor's data to this node
        T->item = temp->item;

        // Delete the successor node
        T->RC = DELETE(T->RC, temp->item.prodName);
    }

    return T;
}
