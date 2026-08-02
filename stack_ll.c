#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;
int count = 0;
const int MAX = 10;

int isEmpty()
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull(){
    return count==MAX;
}



struct Node* push(int val){

    if(isFull()){
        printf("Stack overflow\n");
        printf("The value %d cannot be pushed into the stack\n",val);
        return top;
    }

    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
    count++;
    return top;
}


int pop(){
    if(isEmpty()){
        printf("Stack underflow! There is no element in stack.\n");
        return -1;
    }

    struct Node* ptr=top;
    top=top->next;
    int val=ptr->data;
    free(ptr);
    count--;
    return val;
}

int peek(int pos){
    if(isEmpty()){
        printf("Stack underflow! There is no element in stack.\n");
        return -1;
    }

    struct Node* ptr=top;

    for(int i=0;i<pos-1 && ptr!=NULL;i++){
        ptr=ptr->next;
    }

    if(ptr==NULL){
        printf("Invalid position\n");
        return -1;
    }
     
    return ptr->data;
}

int stackEnd(){
    if(isEmpty()){
        printf("Stack underflow! There is no element in stack.\n");
        return -1;
    }

    struct Node* ptr=top;

    while(ptr->next!=NULL){
        ptr=ptr->next;
    }

    return ptr->data;
}

int stackTop(){
    if(isEmpty()){
        printf("Stack underflow! There is no element in stack.\n");
        return -1;
    }

    return top->data;
}



int main(){
   top=push(76);  
   top=push(49);
   top=push(32);
   top=push(95);
//    top=push(46);
//    top=push(68);
//    top=push(73);
//    top=push(15);
//    top=push(96);
//    top=push(39);
//    top=push(58); // Stack oveflow 
   
   
   struct Node* temp=top;

   while(temp!=NULL){
       printf("%d\n",temp->data);
       temp=temp->next;
   }

   printf("The value of popped element is: %d\n", pop());
//    printf("The value of popped element is: %d\n", pop());
//    printf("The value of popped element is: %d\n", pop());
//    printf("The value of popped element is: %d\n", pop());
//    printf("The value of popped element is: %d\n", pop()); -> Stack goes underflow


   printf("The value of peeked element at position 2 is: %d\n", peek(2));
//    printf("The value of peeked element at position 11 is: %d\n", peek(11)); // Invalid position 
    

   printf("The value of last element in stack is %d\n",stackEnd());
   printf("The value of top element in stack is %d\n",stackTop());

   return 0;
}