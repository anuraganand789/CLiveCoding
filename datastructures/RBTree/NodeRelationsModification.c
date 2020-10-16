#include "RB.h"

//         P                                       C
//       /  \                                    /   \
//      C   RP      ===========>               LC     P
//    /   \                                         /  \
//  LC     RC                                      RC  RP

struct RBNode *leftNodeReplacesTheParent(struct RBNode * const rbNode){
  struct RBNode * parent;

  if(notNull(rbNode) && notNull(parent = parentOf(rbNode))) {
    //We can also use siblingOf function over here , but we already know
    // that the current child is the left child of it's parent
    // so, we can easily get it's sibling by just getting the right child of it's parent
    struct RBNode * const sibling      = rightChildOf(parent);
    struct RBNode * const grandParent  = parentOf(parent);

    struct RBNode * const rightChildOfCurrNode = rightChildOf(rbNode);
    
    if(notNull(grandParent)) {
      if(isLeftChildOf(grandParent, parent)) makeLeftChildOf(grandParent, rbNode);
      else makeRightChildOf(grandParent, rbNode);
    }

    makeParentOf(rbNode, grandParent);
    makeParentOf(parent, rbNode);

    makeLeftChildOf(parent, rightChildOfCurrNode);
    makeRightChildOf(rbNode, parent);
  }
  return rbNode;
}


//         P                         C
//	  / \                      /   \
//       S   C       ====>        P    RC
//	    / \                  / \
//	   LC RC                S  LC
//

struct RBNode *rightNodeReplacesTheParent(struct RBNode * const rbNode){
  struct RBNode * parent;
  if(notNull(rbNode) && notNull(parent = parentOf(rbNode))){

    //We can also use siblingOf function over here , but we already know
    // that the current child is the right child of it's parent
    // so, we can easily get it's sibling by just getting the left child of it's parent
    struct RBNode * const sibling     = leftChildOf(parent);
    struct RBNode * const grandParent = parentOf(parent);
    
    struct RBNode * const leftChildOfCurrentNode = leftChildOf(rbNode);
    
    if(notNull(grandParent)){
      if(isLeftChildOf(grandParent, parent)) makeLeftChildOf(grandParent, rbNode);
      else makeRightChildOf(grandParent, rbNode);
    }

    makeParentOf(rbNode, grandParent);
    makeParentOf(parent, rbNode);

    makeLeftChildOf(rbNode, parent);
    makeRightChildOf(parent, leftChildOfCurrentNode);
  }
  return rbNode;
}



//extern struct RBNode *leftNodeReplacesTheGrandParent(struct RBNode * const rbNode);
//extern struct RBNode *rightNodeReplacesTheGrandParent(struct RBNode * const rbNode);



