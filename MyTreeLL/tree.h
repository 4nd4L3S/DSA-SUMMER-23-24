#ifndef treeLL
#define treeLL

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date expDate;
    char prodName[20];
    float prodPrice;
    int prodQty;
} Product;

typedef struct node {
    Product item;
    struct node *left;
    struct node *right;
} NodeType, *NodePtr;

NodePtr createNode(Product item);
NodePtr insert(NodePtr root, Product item);
NodePtr deleteNode(NodePtr root, char *prodName);

void inorder(NodePtr root);
void preorder(NodePtr root);
void postorder(NodePtr root);
void breadthFirst(NodePtr root);
void freeTree(NodePtr root);
#endif
