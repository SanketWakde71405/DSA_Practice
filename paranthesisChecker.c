#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack *sp)
{
    if (sp->top == sp->size - 1)
        return 1;

    return 0;
}

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
        return 1;

    return 0;
}

void push(struct stack *sp, char val)
{
    if (isFull(sp))
    {
        printf("Stack overflow\n");
        printf("The value %c cannot be pushed into the stack\n", val);
    }

    sp->top++;
    sp->arr[sp->top] = val;
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow! There is no element in stack to pop\n");
        return -1; // Considering stack contains only positive numbers
    }

    char val = sp->arr[sp->top];
    sp->top--;

    return val;
}

int peek(struct stack *sp, int pos)
{

    int ind = (sp->top) - pos + 1;

    if (ind < 0)
    {
        printf("Invalid position\n");
        return -1; // Considering all the numbers in stack are positive
    }

    return sp->arr[ind];
}

int stackTop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow\n");
        return -1;
    }

    return sp->arr[sp->top];
}

int stackBottom(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow\n");
        return -1;
    }

    return sp->arr[0];
}

int paranthesisChecker(struct stack* sp, char* str){

    int i=0;
    char ch='0';
    while(str[i]!='\0'){
        if(str[i]=='('){
            push(sp,str[i]);
        }

        if(str[i]==')'){
            if(isEmpty(sp)){
                return 0;
            }
            ch=pop(sp);
        }
        i++;
    }

    if(isEmpty(sp)) return 1;

    return 0;
}

int main(){

    char* str="(5-(4*2)/755))";
    
    struct stack* s= (struct stack*) malloc(sizeof(struct stack));
    s->top=-1;
    s->size=20;
    s->arr = (char *)malloc(s->size * sizeof(char));


    int paranthesisResult=paranthesisChecker(s,str);

    if(paranthesisResult==1){
        printf("The %s expression is valid",str);
    }else{
        printf("The %s expression is invalid",str);
    }


    return 0;
}