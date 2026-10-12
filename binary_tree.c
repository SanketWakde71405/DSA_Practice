#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}

void preOrderTraversal(struct node *root){

    // ROOTNODE -> LEFT SUBTREE -> RIGHT SUBTREE
    if(root!=NULL){
        printf("%d -> ",root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main(){
    
    struct node* root = createNode(4);
    struct node* leftChild = createNode(1);
    struct node* rightChild = createNode(6);

    root->left=leftChild;
    root->right=rightChild;
    leftChild->left=createNode(5);
    leftChild->right=createNode(2);

    /*  Representation of the binary tree created:
                         4                 
                        / \
                       1   6 
                      / \
                     5   2                         */

    printf("Preorder traversal of the binary tree is: \n");
    preOrderTraversal(root); 
    printf("NULL\n");



    
    
    return 0;
}