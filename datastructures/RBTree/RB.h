#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct RBNode {
  int data;
  enum COLOR color;
  struct RBNode *parent;
  struct RBNode *leftChild;
  struct RBNode *rightChild;
};

enum Color { RED, BLACK };

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
extern int dataOf(struct RBNode * const rbNode);
