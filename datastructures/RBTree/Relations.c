#include "RB.h"

struct RBNode *uncleOf(struct RBNode * const root){
  struct RBNode * const rootParent = parentOf(root);
  if(notNull(rootParent)){
    struct RBNode * const rootGrandParent = grandParentOf(root);
    if(notNull(rootGrandParent)) {
      return isLeftChildOf(rootGrandParent, rootParent) 
             ? rightChildOf(rootGrandParent)
             : leftChildOf(rootGrandParent);
    }
  }
  return NULL;
}

struct RBNode *parentOf(struct RBNode * const root){
  return notNull(root) ? root->parent : NULL;
}

struct RBNode *grandParentOf(struct RBNode * const root){
  return parentOf(parentOf(root)); 
}

struct RBNode *siblingOf(struct RBNode * const root){
  if(notNull(root)){
    struct RBNode *rootParent = parentOf(root);
    if(notNull(rootParent)) { 
      return isLeftChildOf(rootParent, root) 
             ? rightChildOf(rootParent)
	     : leftChildOf(rootParent);
    }
  }
  return NULL;
}

struct RBNode *leftChildOf(struct RBNode *root){
  return notNull(root) ? leftChildOf(root)  : NULL;
}

struct RBNode *rightChildOf(struct RBNode *root){
  return notNull(root) ? rightChildOf(root) : NULL;
}

//These functions modify the parent child relations
void makeLeftChildOf(struct RBNode * const parentNode, struct RBNode * const leftChild){
  if(notNull(parentNode)) parentNode->left = leftChild;
}

void makeRightChildOf(struct RBNode * const parentNode, struct RBNode * const rightChild){
  if(notNull(parentNode)) parentNode->right = rightChild;
}


void makeParentOf(struct RBNode * const childNode, struct RBNode * const parentNode){
  if(notNull(childNode)) childNode->parent = parentNode;
}
