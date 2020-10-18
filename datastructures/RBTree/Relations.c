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


//************************inlined functions -> defined in RB.h***********************************//

//These functions modify the parent child relations
void makeLeftChildOf(struct RBNode * const parentNode, struct RBNode * const leftChild);
void makeRightChildOf(struct RBNode * const parentNode, struct RBNode * const rightChild);
void makeParentOf(struct RBNode * const childNode, struct RBNode * const parentNode);

struct RBNode *leftChildOf(struct RBNode *root);
struct RBNode *rightChildOf(struct RBNode *root);
struct RBNode *parentOf(struct RBNode * const root);
struct RBNode *grandParentOf(struct RBNode * const root);
