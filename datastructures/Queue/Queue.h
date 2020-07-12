#include<stdio.h>
#include<stdlib.h> //malloc and free
#include<stdbool.h> // we get bool and true and false
#include<stdint.h> 

//First In First Out
struct Queue {
    int_least8_t frontIndex;
    int_least8_t rearIndex;
    uint_least8_t maxCapacity;
    int           data[];
};

//Create Stack - Allocate Memory for stack
extern struct Queue *createQueue(int *capacity);

//Free Memory - Delete Queue from memory
extern void deleteQueue(struct Queue *queue);

//Status Check functions
extern int numberOfItemsInQueue(struct Queue *queue);
extern bool isQueueFull(struct Queue *queue);
extern bool isQueueEmpty(struct Queue *queue);

//Data modification functions
extern int  putInQueue(struct Queue *queue, int *data);
extern int  removeFromQueue(struct Queue *queue);
