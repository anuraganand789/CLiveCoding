#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define null NULL

struct Node {
    int data;
    struct Node *next;
};

//Destruction
extern void freeLinkedList(struct Node *node);

//Search
 extern struct Node *search(struct Node *node, int *data);

//modification
 extern struct Node *createNode(int *data);
 extern bool insert(struct Node *node, int *data);
 extern struct Node *deleteByData(struct Node *node, int *data);
 extern struct Node *reverseLinkedList(struct Node *node);


