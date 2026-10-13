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

void postOrderTraversal(struct node *root){

    // LEFT SUBTREE -> RIGHT SUBTREE -> ROOTNODE
    if(root!=NULL){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d -> ",root->data);
    }
}

void inOrderTraversal(struct node *root){

    // LEFT SUBTREE -> ROOTNODE-> RIGHT SUBTREE 
    if(root!=NULL){
         inOrderTraversal(root->left);
         printf("%d -> ",root->data);
         inOrderTraversal(root->right);
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

    printf("Postorder traversal of the binary tree is: \n");
    postOrderTraversal(root); 
    printf("NULL\n");

    printf("Inorder traversal of the binary tree is: \n");
    inOrderTraversal(root); 
    printf("NULL\n");



    
    
    return 0;
}