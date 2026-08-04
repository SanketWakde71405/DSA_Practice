#include<stdio.h>
#include<stdlib.h>

// In circular linked list any node can be head node
// Role of head node is only for traversal through linked list and does not imply the starting of the list.

// Linked list Node structure
struct Node{
    int data;
    struct Node* next;
};

// Circular linked list traversal function
void linkedListTraversal(struct Node* head){

    struct Node* ptr=head;
    do
    {
        printf("| %d |-->",ptr->data);
        ptr=ptr->next;
    } while (ptr!=head);
    
    printf("| %d | The last node is head itself\n", ptr->data);
}

// Insertion of new head 
struct Node* insertAtFirst(struct Node* head, int val){
    struct Node* ptr= (struct Node*) malloc(sizeof(struct Node));
    ptr->data=val;

    struct Node* q=head;

    while(q->next!=head){
        q=q->next;
    }

    q->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;
}

// Inserting a new node before head node 
struct Node* insertAtEnd(struct Node* head,int data){
    struct Node* ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    
    struct Node*q=head;

    while(q->next!=head){
        q=q->next;
    }

    ptr->next=q->next;
    q->next=ptr;

    return head;
}
// Insert node after a particular node
struct Node* insertAfterNode(struct Node* head,struct Node* node, int val){
    struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
    ptr->data=val;

    ptr->next=node->next;
    node->next=ptr;
    return head;
}

// Insert a node at particular position w.r.t head
struct Node* insertAtPos(struct Node* head, int data, int pos){
     struct Node* p=(struct Node*)malloc(sizeof(struct Node));
     p->data=data;

     struct Node* q=head;
     if(pos==1){
        while(q->next!=head){
            q=q->next;
        }

        q->next=p;
        p->next=head;
        head=p;
        return head;
     }

     int x=1;

     do
     {
        q=q->next;
        x++;
     } while (x<pos-1 && q!=head);
     

     if(q==head){
        printf("Invalid position\n");
        return head;
     }

     p->next=q->next;
     q->next=p;
     return head;
}

// Deleting a node and returning a previous node of head as New head
struct Node* deleteHead(struct Node* head){
    struct Node* p=head;
    
    do{
        p=p->next;
    }while(p->next!=head);

    if(p==head){
        free(head);
        printf("List has now become empty.");
        return NULL;
    }
    
    p->next=head->next;
    free(head);
    return p;
}

// Deleting a specific node 
struct Node* deleteNode(struct Node* head, struct Node* deletionNode){
    if(deletionNode==head){
        if(head->next==head){
            free(head);
            printf("List has become empty!\n");
            return NULL;
        }
        head=head->next;
        free(deletionNode);
        return head;
    }

    struct Node*p=head;

    while(p->next!=deletionNode){
        p=p->next;
    }

    p->next=deletionNode->next;
    free(deletionNode);
    return head;
}

// Deleting a node with given value
struct Node* deleteByValue(struct Node* head, int val){

    if(head->data==val){
        if(head->next==head){
            free(head);
            printf("List has become empty!\n");
            return NULL;
        }
        struct Node* p=head;
        head=head->next;
        free(p);
        return head;
    }

    struct Node* ptr=head;

    do
    {
        ptr=ptr->next;
    } while (ptr!=head && ptr->data!=val);
    

    if(ptr==head){
        printf("Value Not found\n");
        return head;
    }

    struct Node* q=head;

    while(q->next!=ptr){
        q=q->next;
    }

    q->next=ptr->next;
    free(ptr);

    return head;

}

// Deleting a node at specific position w.r.t head
struct Node* deleteAtPosition(struct Node* head, int pos){
    if(pos==1){
        if(head->next==head){
            free(head);
            printf("List has become empty!\n");
            return NULL;
        }
        
        struct Node* p=head;
        while (p->next!=head)
        {
            p=p->next;
        }

        p->next=head->next;
        free(head);
        return p;
        
           
    }

    int x=1;
    struct Node* q=head;

    do
    {
        q=q->next;
        x++;
    } while (q!=head && x < pos);
    
    
    struct Node* r=head;

    while (r->next!=q)
    {
        r=r->next;
    }

    r->next=q->next;
    free(q);
    return head;
}

// Deleting end node
struct Node* deleteEnd(struct Node* head){

    if(head->next==head){
        free(head);
        printf("List has now become empty!\n");
        return NULL;
    }

    struct Node* p=head;
    struct Node*q=head->next;

    while(q->next!=head){
        p=p->next;
        q=q->next;
    }

    p->next=q->next;
    free(q);

    return p->next;

}

int main(){
  
   struct Node* head = (struct Node*)malloc(sizeof(struct Node)); 
   struct Node* second = (struct Node*)malloc(sizeof(struct Node)); 
   struct Node* third = (struct Node*)malloc(sizeof(struct Node)); 
   struct Node* fourth = (struct Node*)malloc(sizeof(struct Node)); 

   head->data=78;
   head->next=second;

   second->data=94;
   second->next=third;

   third->data=63;
   third->next=fourth;

   fourth->data=49;
   fourth->next=head;

   linkedListTraversal(head);

   // Inserting a node to the first position or last position
   head=insertAtFirst(head,56);
   printf("After inserting a new node as head:\n");
   linkedListTraversal(head);

   head=insertAtEnd(head,971);
   printf("After inserting a new node as end node:\n");
   linkedListTraversal(head);

   // Inserting a node after the provided node
   head=insertAfterNode(head,second,99);
   printf("After inserting a node after 2nd node:\n");
   linkedListTraversal(head);

   head=insertAtPos(head,123,3);
   printf("After inserting a node at 3rd position\n");
   linkedListTraversal(head);

   head=deleteHead(head);
   printf("After deleting head\n");
   linkedListTraversal(head);

   head= deleteNode(head,second);
   printf("After deleting the given node\n");
   linkedListTraversal(head);

   head=deleteByValue(head,123);
   printf("After deleting the value 123:\n");
   linkedListTraversal(head);

   head= deleteAtPosition(head,2);
   printf("After deleting node at 2nd position\n");
   linkedListTraversal(head);

   head=deleteEnd(head);
   printf("After deleting end node\n");
   linkedListTraversal(head);


   return 0;
}