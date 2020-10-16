#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

enum COLOR { RED, BLACK };

struct RBNode {
  int data;
  enum COLOR color;
  struct RBNode *parent;
  struct RBNode *left;
  struct RBNode *right;
};


// For Debug purposes
extern void printRBNode(struct RBNode * const root);
extern void printRBTree(struct RBNode * const root, int const noOfRepeats, char const indentChar);

extern void *debugMalloc(size_t const sizeOfMalloc);
extern void debugFree(void * const pointer);

//Relations
extern struct RBNode *uncleOf(struct RBNode * const root);
extern struct RBNode *parentOf(struct RBNode * const root);
extern struct RBNode *siblingOf(struct RBNode * const root);
extern struct RBNode *leftChildOf(struct RBNode * const root);
extern struct RBNode *rightChildOf(struct RBNode * const root);
extern struct RBNode *grandParentOf(struct RBNode * const root);

//Set Relations
extern void makeParentOf(struct RBNode * const childNode, struct RBNode * const parentNode);
extern void makeLeftChildOf(struct RBNode * const parentNode, struct RBNode * const leftChild);
extern void makeRightChildOf(struct RBNode * const parentNode, struct RBNode * const rightChild);

// Conditional Functions
extern bool itIsARedNode(struct RBNode *rbNode);
extern bool itIsABlackNode(struct RBNode *rbNode);
extern bool isLeftChildOf(struct RBNode *rootNode, struct RBNode *rbNode);
extern bool isRightChildOf(struct RBNode *rootNode, struct RBNode *rbNode);
extern bool null(struct RBNode * const rbNode);
extern bool notNull(struct RBNode * const rbNode);
extern bool hasLeftChild(struct RBNode * const rbNode);
extern bool hasRightChild(struct RBNode * const rbNode);
extern bool hasParent(struct RBNode * const rbNode);
extern char *nodeColorAsString(struct RBNode * const rbNode);
extern int  dataOf(struct RBNode * const rbNode);

//Rotations or Node Relation Modification
extern struct RBNode *leftNodeReplacesTheGrandParent(struct RBNode * const rbNode);
extern struct RBNode *rightNodeReplacesTheGrandParent(struct RBNode * const rbNode);

extern struct RBNode *leftNodeReplacesTheParent(struct RBNode * const rbNode);
extern struct RBNode *rightNodeReplacesTheParent(struct RBNode * const rbNode);
