#ifndef myBST_Tree
#define myBST_Tree

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    Date expDate;
    char prodName[20];
    float prodPrice;
    int prodQty;
} Product;

typedef struct node {
    Product item;
    struct node *LC;
    struct node *RC;
} NodeType, *BST;



// Queue structure for BFS
typedef struct queueNode {
    BST treeNode;
    struct queueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front, *rear;
} Queue;


void INIT(BST *T);
void INSERT(BST *T, Product elem);
BST DELETE(BST T, char *prodName);
int ISMEMBER(BST T, Product elem);
int MIN(BST T);
int MAX(BST T);

void PREORDER(BST T);
void INORDER(BST T);
void POSTORDER(BST T);
void BFS(BST T);

// Queue functions for BFS
void enqueue(Queue *q, BST treeNode);
BST dequeue(Queue *q);
int isQueueEmpty(Queue *q);

#endif
