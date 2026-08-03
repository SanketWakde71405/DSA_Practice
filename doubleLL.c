#include <stdio.h>
#include <stdlib.h>

// Doubly linked list Node structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// Linked list traversal function
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;

    printf("NULL<-->");
    while (ptr != NULL)
    {
        printf("| %d |<-->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

// Doubly linked list reverse traversal function
void reverseTraversal(struct Node *end)
{
    struct Node *ptr = end;

    printf("NULL<-->");
    while (ptr != NULL)
    {
        printf("| %d |<-->", ptr->data);
        ptr = ptr->prev;
    }
    printf("NULL\n");
}

// Insert at first position in doubly linked list
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
    return head;
}

// Insert at last position in linked list 
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}

// Insert After node 
struct Node *insertAfterNode(struct Node *head, struct Node *p, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = p->next;
    p->next = ptr;
    ptr->prev = p;
    ptr->next->prev = ptr;

    return head;
}

// Insert between two nodes - similar to Insert After
struct Node *insertInBetween(struct Node *head, struct Node *p, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *q = p->next;
    ptr->data = data;

    p->next = ptr;
    ptr->prev = p;
    ptr->next = q;
    q->prev = ptr;

    return head;
}

// Insert Node at given position
struct Node* insertAtPosition(struct Node* head,int data,int position){

    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=data;

    if(position==1){
        newNode->next=head;
        newNode->prev=NULL;
        if(head!=NULL){
            head->prev=newNode;
        }

        head=newNode;
        return head;
    }

    int x=1;
    struct Node* ptr=head;

    while(x<position-1 && ptr!=NULL){
        ptr=ptr->next;
        x++;
    }

    if(ptr==NULL){
        printf("Invalid position\n");
        return head;
    }

    newNode->next=ptr->next;
    newNode->prev=ptr;
    if(ptr->next!=NULL){
        ptr->next->prev=newNode;
    }
    ptr->next=newNode;

    return head;
}

// Deleting head of the doubly linked list 
struct Node* deleteHead(struct Node* head){
    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    struct Node* temp=head;
    head=head->next;
    head->prev=NULL;
    free(temp);
    return head;
}

// Delete last node of the doubly linked list
struct Node* deleteEnd(struct Node* head){

    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    struct Node* ptr=head;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    if(ptr->prev!=NULL){
        ptr->prev->next=NULL;
    }

    free(ptr);
    return head;
}

// Delete a specific node in doubly linked list
struct Node* deleteNode(struct Node* head, struct Node* deleteNode){

    if(head==NULL || deleteNode==NULL){
        printf("List is empty or node to delete is NULL\n");
        return head;
    }

    if(head==deleteNode){
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(deleteNode);
        return head;
    }

    struct Node* ptr=head;

    struct Node* p=deleteNode->prev;
    struct Node* q=deleteNode->next;

    p->next=q;
    if(q!=NULL){
        q->prev=p;
    }

    free(deleteNode);
    return head;
}

// Delete the node at given position
struct Node* deleteAtPosition(struct Node* head,int position){

    if(head==NULL){
        printf("List is empty\n");
        return NULL;
    }

    if(position==1){
        struct Node* temp=head;
        head=head->next;
        if(head!=NULL){
            head->prev=NULL;
        }
        free(temp);
        return head;
    }

    int x=1;

    struct Node* ptr=head;

    while(x<position && ptr!=NULL){
        ptr=ptr->next;
        x++;
    }

    if(ptr==NULL){
        printf("Invalid position\n");
        return head;
    }
    
    struct Node* q=ptr->prev;

    if(q!=NULL){
        q->next = ptr->next;
    }
  
    
    if(ptr->next!=NULL){
        ptr->next->prev=q;
    }

    free(ptr);
    
    return head;


}

// Delete the node if the value is matched
struct Node* deleteByValue(struct Node* head,int val){

    if(head==NULL){
        printf("List is empty. Cannot delete value\n");
        return NULL;
    }

    struct Node* p=head;

    while(p!=NULL && p->data!=val){
        p=p->next;
    }

    if(p==NULL){
        printf("Value %d not found in the list.\n",val);
    }

    struct Node* q= p->prev;
    if(q!=NULL){
        q->next=p->next;
    }
    if(p->next!=NULL){
        p->next->prev=q;
    }

    free(p);
    return head;

}

// Main function
int main()
{

    // First five nodes of doubly linked list declaration and  initialization
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 10;
    head->next = first;
    head->prev = NULL;

    first->data = 20;
    first->next = second;
    first->prev = head;

    second->data = 30;
    second->next = third;
    second->prev = first;

    third->data = 40;
    third->next = fourth;
    third->prev = second;

    fourth->data = 50;
    fourth->next = NULL;
    fourth->prev = third;

    // Printing the doubly linked list by traversing it from front to back
    linkedListTraversal(head);

    // Printing the doubly linked list by traversing it from back to front
    reverseTraversal(fourth);

    // Inserting a new node at the beginning of the doubly linked list
    head = insertAtFirst(head, 5);
    printf("After inserting a new node at the beginning:\n");
    linkedListTraversal(head);

    // Inserting a new node at the end of the doubly linked list
    head = insertAtEnd(head, 60);
    printf("After inserting a new node at the end:\n");
    linkedListTraversal(head);
    

    // Inserting a new node in between two nodes
    head = insertAfterNode(head, first, 25);
    printf("After inserting a new node after the first node:\n");
    linkedListTraversal(head);

    // Inserting a new node in between two nodes
    head = insertInBetween(head, second, 35);
    printf("After inserting a new node in between:\n");
    linkedListTraversal(head);

    // Inserting a new node at a specific position
    head = insertAtPosition(head, 15, 3);
    printf("After inserting a new node at position 3:\n");
    linkedListTraversal(head);

    // Deleting the head node of the doubly linked list
    head= deleteHead(head);
    printf("After deleting the head node:\n");
    linkedListTraversal(head);

    // Deleting the last node of the doubly linked list
    head= deleteEnd(head);
    printf("After deleting the last node:\n");
    linkedListTraversal(head);

    // Deleting a specific node of the doubly linked list
    head= deleteNode(head,second);
    printf("After deleting the second node:\n");
    linkedListTraversal(head);

    // Deleting a node at specific position
    head=deleteAtPosition(head,5);
    printf("After deleting the node at 5th position\n");
    linkedListTraversal(head);

    head=deleteByValue(head,40);
    printf("After deleting the node with value 40\n");
    linkedListTraversal(head);

    printf("Reverse traversal ensuring the nodes are linked using prev correctly\n");
    reverseTraversal(fourth);

    return 0;
}