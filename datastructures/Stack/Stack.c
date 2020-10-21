#include "Stack.h" //My Stack Declarations

//Creation
struct Stack *createStack(int *capacity){
    if(*capacity < 1) return NULL;
    
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    stack->top      = -1;
    stack->capacity = *capacity;
    stack->data     = (int *) malloc(sizeof(int) * *capacity);

    return stack;
}

//Deletion
int deleteStack(struct Stack *stack){
    if(stack) {
        if(stack->data) free(stack->data);
        free(stack);
    }
}

#define isStackFull(stack)     ((stack != NULL && (stack->top + 1) == stack->capacity))
#define isStackEmpty(stack)    ((stack == NULL || stack->top < 0))

//Modifications Functions
int push(struct Stack *stack, int *data){
    if(stack == NULL || isStackFull(stack)) return EOF;

    *(stack->data + ++(stack->top)) = *data;

    return *(stack->data + stack->top);
}

int pop(struct Stack *stack){
    return isStackEmpty(stack) ? EOF : *(stack->data + stack->top--);
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

