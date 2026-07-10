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

// Deletion of head node in linked list Time complexity O(1)
struct Node *deleteHead(struct Node *ptr){
    if(ptr==NULL){
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp=ptr;
    ptr=ptr->next;
    free(temp);

    return ptr;
}

// Deletion of last node in linked list Time complexity O(n)
struct Node *deleteEnd(struct Node *head){
    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    struct Node* p=head;
    struct Node* q=head->next;

    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }

    p->next=NULL;
    free(q);

    return head;
}

// Deletion of a specific node in linked list Time complexity O(n)
struct Node *deleteNode(struct Node *head, struct Node *nodeToDelete){
    if(head==NULL || nodeToDelete==NULL){
        printf("List is empty or node to delete is NULL\n");
        return head;
    }

    if(head==nodeToDelete){
        struct Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }

    struct Node* p=head;

    while(p->next!=NULL && p->next!=nodeToDelete){
        p=p->next;
    }

    if(p->next==NULL){
        printf("Node to delete not found in the list\n");
        return head;
    }

    p->next=nodeToDelete->next;
    free(nodeToDelete);

    return head;
}

// Deleting a node at a specific index in linked list Time complexity O(n)
struct Node *deleteAtIndex(struct Node *head,int index){
    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    int i=0;
    struct Node* p=head;
    struct Node* q=head->next;

    while(i!=index-1 && q->next!=NULL){
        p=p->next;
        q=q->next;
        i++;
    }

    if(i!=index-1){
        printf("Index out of bounds\n");
        return head;
    }

    p->next=q->next;
    free(q);

    return head;
}

// Deleting a node by value in linked list Time complexity O(n)
struct Node *deleteByValue(struct Node *head, int value){
    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    struct Node* p=head;
    struct Node* q=head->next;

    if(p->data==value){
        head=head->next;
        free(p);
        return head;
    }

    while(q!=NULL && q->data!=value){
        p=p->next;
        q=q->next;
    }

    if(q==NULL){
        printf("Value not found in the list\n");
        return head;
    }

    p->next=q->next;
    free(q);
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

    // Deleting the head node of linked list 
    head=deleteHead(head);

    // Displaying linked list after dletion of head node
    printf("\nLinked list after deletion of head node\n");
    linkedListTraversal(head);

    // Deleting the last node of linked list
    head=deleteEnd(head);

    // Displaying linked list after deletion of last node
    printf("\nLinked list after deletion of last node\n");
    linkedListTraversal(head);

    // Deleting a specific node of linked list
    head=deleteNode(head,third);

    // Displaying linked list after deletion of a specific node
    printf("\nLinked list after deletion of a specific node\n");
    linkedListTraversal(head);

    // Deleting a node at a specific index in linked list 
    head=deleteAtIndex(head,2);

    // Displaying linked list after deletion of a node at a specific index
    printf("\nLinked list after deletion of a node at a specified index\n");
    linkedListTraversal(head);

    // Deleting a node by value in linked list
    head=deleteByValue(head,90);

    // Displaying linked list after deletion of a node by value
    printf("\nLinked list after deletion of a node by value\n");
    linkedListTraversal(head);
    








    return 0;
}