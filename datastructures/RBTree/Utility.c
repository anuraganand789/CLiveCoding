#include "RB.h"


bool isLeftChildOf(struct RBNode * const parentNode, struct RBNode * const childNode) { 
  return notNull(parentNode) && leftChildOf(parentNode) == childNode; 
}

bool isRightChildOf(struct RBNode * const parentNode, struct RBNode * const childNode){
  return notNull(parentNode) && rightChildOf(parentNode) == childNode;
}


char *nodeColorAsString(struct RBNode * const rbNode){
  if(notNull(rbNode)) {
    return (rbNode->color == RED) 
           ? "RED"
           : "BLACK";
  }
  return "NULL";
}
//***************************************Inlined functions in RB.h*******************************//
bool null(struct RBNode * const rbNode); 
bool notNull(struct RBNode * const rbNode);

bool itIsARedNode(struct RBNode *rbNode);
bool itIsABlackNode(struct RBNode * rbNode);

bool hasLeftChild(struct RBNode * const rbNode);
bool hasRightChild(struct RBNode * const rbNode);
bool hasParent(struct RBNode * const rbNode);

int dataOf(struct RBNode * const rbNode); 
