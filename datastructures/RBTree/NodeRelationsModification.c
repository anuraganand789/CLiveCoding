#include "RB.h"

//         P                                       C
//       /  \                                    /   \
//      C   RP      ===========>               LC     P
//    /   \                                         /  \
//  LC     RC                                      RC  RP

struct RBNode *leftChildReplacesTheParent(struct RBNode * const rbNode){
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

struct RBNode *rightChildReplacesTheParent(struct RBNode * const rbNode){
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
//         Great Grand Parent             Great Grand Parent
//              |                               |                     <----------- Check that the grandparent was left child or right Child
//              G                               C
//	       / \                            /   \
//	      P   RG                         P     G
//	     / \               =>           / \    / \
//          LP  C                          LP  LC RC  RG
//             / \
//	      LC  RC
//

struct RBNode *rightGrandChildReplacesTheGrandParent(struct RBNode * const root){
    if(notNull(root)){
        struct RBNode * leftChild  = leftChildOf(root);
	struct RBNode * rightChild = rightChildOf(root);
        
	struct RBNode * parent      = parentOf(root);
	struct RBNode * grandParent = grandParentOf(root);
	struct RBNode * greatGrandParent = parentOf(grandParent); 

	makeParentOf(root,        greatGrandParent);
	if(isLeftChildOf(greatGrandParent, grandParent)) 
	    makeLeftChildOf(greatGrandParent, root);
	else 
	    makeRightChildOf(greatGrandParent, root);

	makeParentOf(grandParent,  root);
	makeRightChildOf(root,     grandParent);

	makeParentOf(parent,      root);
	makeLeftChildOf(root,     parent);

	makeLeftChildOf(grandParent,  rightChild);
	makeParentOf(rightChild,      grandParent);

	makeRightChildOf(parent,    leftChild);
	makeParentOf(leftChild,     parent);
    }
}

//
//         Great Grand Parent             Great Grand Parent
//             |                                 |                      <----------- Check that the grandparent was left child or right Child
//             G                                 C
//           /  \                              /   \
//          LG   P            =>              G     P
//              /  \                         / \    / \
//             C    RP                      LG LC  RC  RP
//            / \
//           LC  RC
//
//

struct RBNode *leftGrandChildReplacesTheGrandParent(struct RBNode * const root){
    if(notNull(root)){
        struct RBNode * leftChild  = leftChildOf(root);
	struct RBNode * rightChild = rightChildOf(root);
        
	struct RBNode * parent      = parentOf(root);
	struct RBNode * grandParent = grandParentOf(root);
	struct RBNode * greatGrandParent = parentOf(grandParent); 

	makeParentOf(root,        greatGrandParent);
	if(isLeftChildOf(greatGrandParent, grandParent)) 
	    makeLeftChildOf(greatGrandParent, root);
	else 
	    makeRightChildOf(greatGrandParent, root);

	makeParentOf(grandParent, root);
	makeLeftChildOf(root,     grandParent);

	makeParentOf(parent,      root);
	makeRightChildOf(root,    parent);

	makeRightChildOf(grandParent, leftChild);
	makeParentOf(leftChild,       grandParent);

	makeLeftChildOf(parent,       rightChild);
	makeParentOf(rightChild,      parent);
    }
}



