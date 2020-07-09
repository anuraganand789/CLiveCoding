#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define null NULL

struct Node {
    int data;
    struct Node *next;
};

//Creation
static struct Node *allocateNode();
//Destruction
static void freeNode(struct Node *node);
static void freeLinkedList(struct Node *node);

//Search
static struct Node *search(struct Node *node, int *data);

//modification
static struct Node *createNode(int *data);
static bool insert(struct Node *node, int *data);
static struct Node *deleteByData(struct Node *node, int *data);
static struct Node *reverseLinkedList(struct Node *node);

//View
static void display(struct Node *head){
    while(head != null){
        printf("%d ", head->data);
        head  =  head->next;
    }
    printf("\n");
}
//Creation
static struct Node *allocateNode(){
    return (struct Node *) malloc(sizeof(struct Node));
}

//Destruction
static void freeNode(struct Node *node){
    if(node != NULL) free(node);
}

static void freeLinkedList(struct Node *node){
    if(node == NULL) return;
    struct Node *next = NULL; 
    struct Node *curr = node;

    while(curr != NULL) {
        next = curr->next;
	freeNode(curr);
	curr = next;
    }
}

//Search 
static struct Node *search(struct Node *node, int *data){
    while(node != NULL && node->data != *data) node = node->next;
    return node;
}

//modification
static struct Node *createNode(int *data){
   struct Node *node = allocateNode();
   node->data = *data;
   return node;
}

static bool insert(struct Node *node, int *data){
   if(node == NULL) return false;
   while(node->next != NULL) node = node->next;
   //we are the last node 
   node->next  = createNode(data);
}

static struct Node *deleteByData(struct Node *node, int *data){
   if(node == NULL) return NULL;
   struct Node *prev = NULL;
   //If linked list head needs to be deleted
   if(node->data == *data){
      prev = node->next;
      node-> next = NULL;
      freeNode(node);
      return prev;
   }
   prev = node;
   node = node->next;
   while(node != NULL && node->data != *data){
       prev = node;
       node = node->next;
   }

   if(node == NULL) return NULL;
   prev->next = node->next;
   node->next = NULL;
   freeNode(node);
   return NULL;
}

static struct Node *reverseLinkedList(struct Node *node){
     if(node == NULL) return node;
     struct Node *me       = node;
     struct Node *behindMe = NULL;
     struct Node *inFrontOfMe = NULL;

     while(me != NULL){
         inFrontOfMe = me->next;    
	 me->next = behindMe;
	 behindMe = me;
	 me = inFrontOfMe;
     }

     return behindMe;
}

void main(){
   int data = 200;
   struct Node *head = createNode(&data);
   data = 201;
   insert(head, &data);
   data = 202;
   insert(head, &data);
   data = 203;
   insert(head, &data);
   data = 204;
   insert(head, &data);
   display(head);
   data = 200;
   head = deleteByData(head, &data);
   display(reverseLinkedList(head));
}










