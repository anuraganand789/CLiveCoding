#include "RB.h"

bool itIsARedNode(struct RBNode * rbNode){ return notNull(rbNode) && rbNode->color == Color.RED; }

bool itIsABlackNode(struct RBNode * rbNode){ return null(rbNode) || rbNode->color == Color.BLACK; }

bool isLeftChildOf(struct RBNode * const rootNode, 
                   struct RBNode * const rbNode) { 
  return notNull(rootNode) && isLeftChildOf(rootNode, rbNode); 
}

bool isRightChildOf(struct RBNode * const rootNode, 
                    struct RBNode * const rbNode){
  return noNull(rootNode) && isRightChildOf(rootNode, rbNode);
}

bool null(struct RBNode * const rbNode) { return rbNode == NULL; }

bool notNull(struct RBNode * const rbNode) { return rbNode != NULL; }

bool hasLeftChild(struct RBNode * const rbNode) { return notNull(rbNode->left); }

bool hasRightChild(struct RbNode * const rbNode) { return notNull(rbNode->right); }

bool hasParent(struct RBNode * const rbNode) { return notNull(parentOf(roo)); }

char *nodeColorAsString(struct RBNode * const rbNode){
  if(notNull(rbNode)) {
    return (rbNode->color == COLOR.RED) 
           ? "RED"
           : "BLACK";
  }
  return "NULL";
}
int dataOf(struct RBNode * const rbNode){ return notNull(rbNode) ? rbNode->data : EOF; }
