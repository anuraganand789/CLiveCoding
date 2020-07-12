#include "LinkedList.h"

//View
 void display(struct Node *head){
    while(head != null){
        printf("%d ", head->data);
        head  =  head->next;
    }
    printf("\n");
}

//Creation
 struct Node *allocateNode(){
    return (struct Node *) malloc(sizeof(struct Node));
}

//Deletion
 void freeLinkedList(struct Node *node){
    if(node == NULL) return;
    struct Node *next = NULL; 
    struct Node *curr = node;

    while(curr != NULL) {
        next = curr->next;
	free(curr);
	curr = next;
    }
}

//Search 
 struct Node *search(struct Node *node, int *data){
    while(node != NULL && node->data != *data) node = node->next;
    return node;
}

//modification
 struct Node *createNode(int *data){
   struct Node *node = allocateNode();
   node->data = *data;
   node->next = NULL;
   return node;
}

 bool insert(struct Node *node, int *data){
   if(node == NULL) return false;
   //Find The last node
   while(node->next != NULL) node = node->next;
   //we are the last node 
   node->next  = createNode(data);
}

 struct Node *deleteByData(struct Node *node, int *data){
   if(node == NULL) return NULL;

   //stores links to nodes - used for changing node->next link
   //After the node is found and deleted
   struct Node *temp = NULL;
   //find the matching node
   while(node != NULL && node->data != *data){
       temp = node;
       node = node->next;
   }

   //data not found
   if(node == NULL) return NULL;

   //Store the node next to the node getting deleted 
   if(temp != NULL) temp->next = node->next;
   //check NULL - case where data occurs as the first node
   else temp = node->next;

   node->next = NULL;
   free(node);

   return temp;
}

 struct Node *reverseLinkedList(struct Node *node){
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

     //now this node is the head of the reversed node
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










