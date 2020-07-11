#include "Stack.h" //My Stack Declarations
#include<stdio.h>  //Input Output Operations
#include<stdlib.h> //malloc and free functions

//Creation
extern struct Stack *createStack(int *capacity){
    if(*capacity < 1) return NULL;
    
    struct Stack *stack = (struct Stack *) 
                                   malloc(sizeof(struct Stack));
    stack->top      = -1;
    stack->capacity = *capacity;
    stack->data     = (int *) malloc(sizeof(int) * *capacity);

    return stack;
}

//Deletion
int deleteStack(struct Stack *stack){
    if(stack == NULL) return EOF;

    if(stack->data != NULL) free(stack->data);

    free(stack);
}

//Status Check
int isStackFull(struct Stack *stack){
    if(stack == NULL) return EOF;
    return stack->top + 1 == stack->capacity ? 1 : 0;
}

int isStackEmpty(struct Stack *stack){
    if(stack == NULL) return EOF;
    return stack->top < 0 ? 1 : 0;
}

//Modifications Functions
int push(struct Stack *stack, int *data){
    if(stack == NULL) return EOF;
    if(isStackFull(stack)) return EOF;

    *(stack->data + ++(stack->top)) = *data;

    return *(stack->data + stack->top);
}

int pop(struct Stack *stack){
    return stack == NULL || isStackEmpty(stack) == 1 ? EOF : *(stack->data + stack->top--);
}

void main(){
    int capacity = 3;
    struct Stack *stack = createStack(&capacity);

    if(stack != NULL) printf("Stack memory successfully allocated.\n");
    int data = 100;
    int pushStatus = push(stack, &data);
    if(EOF == pushStatus) printf("Stack can not accept %d.\n", data);

    data = 101;
    pushStatus = push(stack, &data);
    if(EOF == pushStatus) printf("Stack can not accept %d.\n", data);

    data = 102;
    pushStatus = push(stack, &data);
    if(EOF == pushStatus) printf("Stack can not accept %d.\n", data);

    data = 103;
    pushStatus = push(stack, &data);
    if(EOF == pushStatus) printf("Stack can not accept %d.\n", data);

    int value = pop(stack);
    if(EOF == value) printf("Stack is EMPTY, because top is %d.\n", stack->top);

    value = pop(stack);
    if(EOF == value) printf("Stack is EMPTY, because top is %d.\n", stack->top);

    value = pop(stack);
    if(EOF == value) printf("Stack is EMPTY, because top is %d.\n", stack->top);

    value = pop(stack);
    if(EOF == value) printf("Stack is EMPTY, because top is %d.\n", stack->top);

    printf("Stack top %d. \n", stack->top);

    deleteStack(stack);
}

