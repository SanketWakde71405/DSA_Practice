#include<stdio.h>
#include<stdlib.h>

struct stack{
     int size;
     int top;
     int *arr;

};

int isFull(struct stack* sp){
    if(sp->top==sp->size-1) return 1;

    return 0;
}

int isEmpty(struct stack* sp){
    if(sp->top==-1) return 1;

    return 0;
}

void push(struct stack* sp, int val){
    if(isFull(sp)){
        printf("Stack overflow\n");
        printf("The value %d cannot be pushed into the stack\n",val);
    }

    sp->top++;
    sp->arr[sp->top]=val;
}

int pop(struct stack* sp){
    if(isEmpty(sp)){
        printf("Stack underflow! There is no element in stack to pop\n");
        return -1; // Considering stack contains only positive numbers
    }

    int val=sp->arr[sp->top];
    sp->top--;

    return val;

}

int peek(struct stack* sp, int pos){

    int ind= (sp->top)-pos+1;

    if(ind<0){
        printf("Invalid position\n");
        return -1; // Considering all the numbers in stack are positive
    }

    return sp->arr[ind];

}

int stackTop(struct stack* sp){
    if(isEmpty(sp)){
        printf("Stack underflow\n");
        return -1;
    }

    return sp->arr[sp->top];
}

int stackBottom(struct stack* sp){
    if (isEmpty(sp))
    {
        printf("Stack underflow\n");
        return -1;
    }

    return sp->arr[0];
}



int main(){
   struct stack* s= (struct stack*)malloc(sizeof(struct stack)); 
   s->size=10;
   s->top=-1;
   s->arr=(int*)malloc(s->size*sizeof(int));

   printf("The value of empty function before pushing any element %d\n",isEmpty(s));
   printf("The value of full function before pushing any element %d\n",isFull(s));

   push(s,76);
   push(s,49);
   push(s,59);
   push(s,13);
   push(s,97);
   push(s,43);
   push(s,46);
   push(s,733);
   push(s,346);
   push(s,8);
//    push(s,95); // Can't push Stack overflow 



//    for(int j=0;j<s->top;j++){
//         printf("%d position: %d\n",j+1, peek(s,j+1));
//    }

   // Visualizing stack

   printf("+-------+\n");
   for (int j = 0; j <= s->top; j++)
   {
       printf("| %5d |\n", peek(s, j + 1));
       printf("+-------+\n");
   }


   printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)

/*Added to check whether pop gives stack underflow error or not */
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)
//    printf("\nAfter popping top %d\n",pop(s)); // Last In First Out (LIFO)

   
//    printf("+-------+\n");
//    for (int j = 0; j <= s->top; j++)
//    {
//        printf("| %5d |\n", peek(s, j + 1));
//        printf("+-------+\n");
//    }

   printf("The value of empty function after pushing any element %d\n", isEmpty(s));
   printf("The value of full function after pushing any element %d\n", isFull(s));

   printf("The topmost element of stack is %d\n",stackTop(s));
   printf("The bottom element of stack is %d\n",stackBottom(s));
   return 0;
}