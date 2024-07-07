#ifndef myBST_Tree
#define myBST_Tree

typedef struct{
    int day, month, year;
}Date;

typedef struct{
    Date expDate;
    char prodName[20];
    float prodPrice;
    int prodQty;
}Product;

typedef struct node{
    Product item;
    struct node *left;
    struct node *right;
}NodeType, *BST;


BST insert(BST root, Product newProduct);
BST createNode(Product newProduct);
BST deleteNode(BST root, Product delProduct);
BST findSuccessor(BST root);
void inOrder(BST root);
void preOrder(BST root);
void postOrder(BST root);
void bfs(BST root);

#endif
