#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	NodePtr root = NULL;
	
	Product chocolate1 = {{1, 1, 2025}, "Snickers", 2.5, 50};
    Product chocolate2 = {{1, 1, 2024}, "Milky Way", 3.0, 30};
    Product chocolate3 = {{1, 1, 2023}, "Mars", 2.0, 40};
    Product chocolate4 = {{1, 1, 2025}, "Twix", 2.5, 50};
    Product chocolate5 = {{1, 1, 2024}, "Crunch", 3.0, 30};
    Product chocolate6 = {{1, 1, 2023}, "Oreo", 2.0, 40};
    Product chocolate7 = {{1, 1, 2025}, "MnM", 2.5, 50};
    Product chocolate8 = {{1, 1, 2024}, "KitKat", 3.0, 30};
    Product chocolate9 = {{1, 1, 2023}, "ButterFinger", 2.0, 40};

    root = insert(root, chocolate1);
    root = insert(root, chocolate2);
    root = insert(root, chocolate3);
    root = insert(root, chocolate4);
    root = insert(root, chocolate5);
    root = insert(root, chocolate6);
    root = insert(root, chocolate7);
    root = insert(root, chocolate8);
    root = insert(root, chocolate9);


    printf("DFS Inorder traversal:\n");
    inorder(root);
    
    printf("\n\nDFS Preorder traversal:\n");
    preorder(root);

    printf("\n\nDFS Postorder traversal:\n");
    postorder(root);

    printf("\n\nBreadth-first traversal:\n");
    breadthFirst(root);


    char deleteProductName[20];
    printf("\n\nEnter the product name to delete: ");
    scanf("%s", deleteProductName);
    root = deleteNode(root, deleteProductName);


    printf("\n\nInorder traversal after deletion:\n");
    inorder(root);
    printf("\n\nPreorder traversal after deletion:\n");
    preorder(root);
    printf("\n\nPostorder traversal after deletion:\n");
    postorder(root);
    printf("\n\nBreadth-first traversal after deletion:\n");
    breadthFirst(root);


    freeTree(root);
	return 0;
}
