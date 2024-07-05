#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "tree.h"


NodePtr createNode(Product item) {
    NodePtr newNode = (NodePtr) malloc(sizeof(NodeType));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


NodePtr insert(NodePtr root, Product item) {
    if (root == NULL) {
        return createNode(item);
    } else {
        // Insert recursively based on product name (alphabetical order)
        if (strcmp(item.prodName, root->item.prodName) < 0) {
            root->left = insert(root->left, item);
        } else {
            root->right = insert(root->right, item);
        }
        return root;
    }
}


NodePtr deleteNode(NodePtr root, char *prodName) {
    if (root == NULL) {
        return root;
    }

    // Find the node to be deleted
    if (strcmp(prodName, root->item.prodName) < 0) {
        root->left = deleteNode(root->left, prodName);
    } else if (strcmp(prodName, root->item.prodName) > 0) {
        root->right = deleteNode(root->right, prodName);
    } else { // Node found, delete it
        //Node has no children or only one child
        if (root->left == NULL) {
            NodePtr temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            NodePtr temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        // Find the minin the right subtree or max in left subtree
        NodePtr minNode = root->right;
        while (minNode->left != NULL) {
            minNode = minNode->left;
        }

        // Copy the inorder successors
        root->item = minNode->item;

        // Delete the inorder successor
        root->right = deleteNode(root->right, minNode->item.prodName);
    }
    return root;
}


void inorder(NodePtr root) {
    if (root != NULL) {
        inorder(root->left);
        printf("[%s]  ", root->item.prodName); 
        inorder(root->right);
    }
}

void preorder(NodePtr root) {
    if (root != NULL) {
        printf("[%s]  ", root->item.prodName); 
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(NodePtr root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("[%s]  ", root->item.prodName); 
    }
}


void breadthFirst(NodePtr root) {
    if (root == NULL) {
        return;
    }
    
    NodePtr queue[100]; 
    int front = 0, rear = 0;
    
    queue[rear++] = root;
    
    while (front < rear) {
        NodePtr current = queue[front++];
        printf("[%s]  ", current->item.prodName); 
        
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

void freeTree(NodePtr root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
