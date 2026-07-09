#include <stdio.h>
#include <stdlib.h>

// Linked list as ADT
struct Node{
    int data;
    struct Node *next;
};

// Traversal of linked list Time complexity O(n)
void linkedListTraversal(struct Node *ptr){

    while (ptr != NULL)
    {
        printf("|%d|->", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL\n");
}

// Insertion at the end of linked list Time complexity O(n)
struct Node *insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Insertion at the start of linked list Time complexity O(1)
struct Node *insertAtStart(struct Node *head, int data){
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;

    head = ptr;
    return head;
}

// Insertion after a specific node in linked list Time complexity O(1)
struct Node *insertAfterNode(struct Node * head, struct Node *afterNode, int data){
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data =data;

    ptr->next=afterNode->next;
    afterNode->next=ptr;

    return head;
}

// Insertion at a specific index in linked list Time complexity O(n)
struct Node *insertAtIndex(struct Node *head,int index, int data){

    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data= data;

    struct Node* p=head;

    int i=0;
    while(i!=index-1 && p!=NULL){
        p=p->next;
        i++;
    }

    if(p==NULL){
        printf("Index out of bounds\n");
        free(ptr);
        return head;
    }

    ptr->next=p->next;
    p->next=ptr;

    return head;
}

// Main function
int main()
{
    // Creating nodes of linked list in heap memory
    struct Node *head = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;
    struct Node *fourth = NULL;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 85;
    head->next = second;

    second->data = 76;
    second->next = third;

    third->data = 98;
    third->next = fourth;

    fourth->data = 105;
    fourth->next = NULL;

    linkedListTraversal(head);

    // Inserting a node at the end of linked list
    head = insertAtEnd(head, 120);

    // Displaying linked list after insertion at end
    printf("\nLinked list after insertion at end\n");
    linkedListTraversal(head);

    // Inserting a node at the start of linked list 
    head= insertAtStart(head,45);

    // Displaying linked list after insertion at start
    printf("\nLinked list after insertion at start\n");
    linkedListTraversal(head);

    // Inserting a node after a specific node in linked list 
    head= insertAfterNode(head, second, 90);

    // Displaying linked list after insertion after a specific node 
    printf("\nLinked list after insertion after a specific node\n");
    linkedListTraversal(head);

    // Inserting a node at a specific index in linked list 
    head =insertAtIndex(head,3,200);

    // Displaying linked list after insertion at a specific index 
    printf("\nLinked list after insertion at a specific index\n");
    linkedListTraversal(head);

    return 0;
}