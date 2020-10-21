#include "LinkedList.h"

//View
 void display(struct Node *head){
    while(head){
        printf("%d ", head->data);
        head  =  head->next;
    }
    printf("\n");
}

//Deletion
 void freeLinkedList(struct Node *node){
    if(node){
        struct Node *next; 
        struct Node *curr;

	for(curr = node; 
	    curr; 
	    next = curr->next, curr = next) 
	    { 
	        free(curr); 
            }
    }
}

//Search 
 struct Node *search(struct Node *node, int *data){
    while(node && node->data != *data && (node = node->next));
    return node;
}

//modification
 struct Node *createNode(int *data){
   struct Node *node = (struct Node *) malloc(sizeof(struct Node));
   node->data = *data;
   node->next = NULL;
   return node;
}

 bool insert(struct Node *node, int *data){
   if(node) while(node->next) node = node->next;

   node->next  = createNode(data);
}

 struct Node *deleteByData(struct Node *node, int *data){
   struct Node *prev = NULL;
   struct Node *curr = node;

   if(curr){
       while(curr && curr->data != *data){
           curr = (prev = curr)->next;
       }

       if(prev)
           prev->next = curr->next;
       else
           prev = curr->next;
       
       free(curr);
    }

    //either node argument value is NULL or data is not present in the Linked List
   return prev;
}

 struct Node *reverseLinkedList(struct Node *node){
     struct Node *me          = node;
     struct Node *behindMe    = NULL;
     struct Node *inFrontOfMe = NULL;

     while(me){
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










