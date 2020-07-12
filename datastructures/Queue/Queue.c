#include "Queue.h"

//Creation is done
struct Queue *createQueue(int *capacity){
    struct Queue *queue;
    queue = (struct Queue *) malloc((sizeof *queue) + (sizeof(int) * *capacity));

    if(queue != NULL) {
       queue->frontIndex = queue->rearIndex = -1; 
       queue->maxCapacity = *capacity; 
    }

    return queue;
}

//Deletion of Queue
void deleteQueue(struct Queue *queue){
    if(queue == NULL) return;
    free(queue);
}

int numberOfItemsInQueue(struct Queue *queue){
    if(queue->frontIndex < 0) return 0;
    if(queue->frontIndex <= queue->rearIndex)  return (queue->rearIndex - queue->frontIndex) + 1;
    
    //when front Index is greater than rear index
    return (queue->maxCapacity - queue->frontIndex) + queue-> rearIndex + 1;
}
//Check Status
bool isQueueFull(struct Queue *queue){
    return queue == NULL || numberOfItemsInQueue(queue) == queue->maxCapacity;
}

bool isQueueEmpty(struct Queue *queue){
    return queue == NULL || queue->frontIndex < 0;
}

//Data modifications
int putInQueue(struct Queue *queue, int *data){
    if(isQueueFull(queue)) return EOF;
    
    ++queue->rearIndex;

    if(queue->frontIndex < 0) queue->frontIndex = queue->rearIndex;
    else if(queue->rearIndex == queue->maxCapacity) queue->rearIndex = 0;

    queue->data[queue->rearIndex] = *data;
    return queue->data[queue->rearIndex];
}

int removeFromQueue(struct Queue *queue){
   if(isQueueEmpty(queue)) return EOF;

   int data = queue->data[queue->frontIndex];

   if(queue->frontIndex == queue->rearIndex) queue->frontIndex = queue->rearIndex = -1;
   else if(queue->frontIndex + 1 == queue->maxCapacity) queue->frontIndex = 0;
   else ++queue->frontIndex;

   return data;
}

void printIndices(struct Queue *queue){
    if(queue != NULL) printf("Front Index %d, Rear Index %d.\n", queue->frontIndex, queue->rearIndex);
}

void printQueue(struct Queue *queue){
      if(isQueueEmpty(queue)) return;
      if(queue->frontIndex < queue->rearIndex) {
          int index = queue->frontIndex;
	  while(index <= queue->rearIndex) printf("%d ", queue->data[index++]); 
      } else if(queue->frontIndex > queue->rearIndex) {
          int index = queue->frontIndex;
	  int endIndex = queue->maxCapacity - 1;
	  while(index <= endIndex) printf("%d ", queue->data[index++]); 

	  index = 0;
	  endIndex = queue->rearIndex;
	  while(index <= endIndex) printf("%d ", queue->data[index++]); 
      } else {
            printf("%d ", queue->data[queue->frontIndex]);
      }
      printf("\n");
}

void main(){
    int capacity = 4;
    struct Queue *queue = createQueue(&capacity);
    if(queue != NULL) printf("Queue Created.\n");
     
     printIndices(queue);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));
     int data = 11;
     putInQueue(queue,  &data);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));

     data = 14;
     putInQueue(queue,  &data);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));
     data = 12;
     putInQueue(queue,  &data);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));
     data = 13;
     putInQueue(queue,  &data);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));
    printQueue(queue);
    removeFromQueue(queue);
     printf("Number Of Items in Queue %d.\n", numberOfItemsInQueue(queue));
    printQueue(queue);
    deleteQueue(queue);
    queue = NULL;
}
