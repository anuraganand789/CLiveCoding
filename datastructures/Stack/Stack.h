struct Stack{
    int top;
    int capacity;
    int *data;
};

//Creation
struct Stack *createStack(int *capacity);

//Deletion
int deleteStack(struct Stack *stack);

//Status Checks
int isStackFull(struct Stack *stack);
int isStackEmpty(struct Stack *stack);

//Modification Functions
int push(struct Stack *stack, int *data);
int pop(struct Stack *stack);
