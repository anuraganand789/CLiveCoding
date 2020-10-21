#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define null NULL

struct Node {
    int data;
    struct Node *next;
};

//Destruction
 void freeLinkedList(struct Node *node);

//Search
 struct Node *search(struct Node *node, int *data);

//modification
 struct Node *createNode(int *data);
 bool insert(struct Node *node, int *data);
 struct Node *deleteByData(struct Node *node, int *data);
 struct Node *reverseLinkedList(struct Node *node);


