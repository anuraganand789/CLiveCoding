#include "RB.h"

bool itIsARedNode(struct RBNode * rbNode){ return notNull(rbNode) && rbNode->color == RED; }

bool itIsABlackNode(struct RBNode * rbNode){ return null(rbNode) || rbNode->color == BLACK; }

bool isLeftChildOf(struct RBNode * const parentNode, struct RBNode * const childNode) { 
  return notNull(parentNode) && leftChildOf(parentNode) == childNode; 
}

bool isRightChildOf(struct RBNode * const parentNode, struct RBNode * const childNode){
  return notNull(parentNode) && rightChildOf(parentNode) == childNode;
}

bool null(struct RBNode * const rbNode) { return rbNode == NULL; }

bool notNull(struct RBNode * const rbNode) { return rbNode != NULL; }

bool hasLeftChild(struct RBNode * const rbNode) { return notNull(leftChildOf(rbNode)); }

bool hasRightChild(struct RBNode * const rbNode) { return notNull(rightChildOf(rbNode)); }

bool hasParent(struct RBNode * const rbNode) { return notNull(parentOf(rbNode)); }

char *nodeColorAsString(struct RBNode * const rbNode){
  if(notNull(rbNode)) {
    return (rbNode->color == RED) 
           ? "RED"
           : "BLACK";
  }
  return "NULL";
}
int dataOf(struct RBNode * const rbNode){ return notNull(rbNode) ? rbNode->data : EOF; }
