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
  struct RBNode * const rootParent = parentOf(root);
  return notNull(rootParent) ? parentOf(rootParent) : NULL;
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
  return notNull(root) ? root->left  : NULL;
}

struct RBNode *rightChildOf(struct RBNode *root){
  return notNull(root) ? root->right : NULL;
}
