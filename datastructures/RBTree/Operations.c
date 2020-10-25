#include "RB.h" 

static struct RBNode * createNode(int const value){
    struct RBNode * newNode = (struct RBNode *) malloc(sizeof(struct RBNode));
    newNode->data = value;
    newNode->color = RED;
    newNode->parent = newNode->left = newNode->right = NULL;
    return newNode;
}

static struct RBNode * organizeTreeAfterInsertion(struct RBNode * rbNode){
   struct RBNode * parent = parentOf(rbNode);
   if(rbNode && !(parent && parent->color == BLACK)){
       if(!parent) { rbNode->color = BLACK; } 
       else {
           //check uncle
	   struct RBNode * uncle = uncleOf(rbNode);
	   struct RBNode * grandParent = grandParentOf(rbNode);
	   if(uncle && uncle->color == RED){
	       parent->color = BLACK;
	       uncle->color  = BLACK;
	       grandParent->color = RED;
	       organizeTreeAfterInsertion(grandParent);
	   }else{
	       //As per normal coding practice these will be called double rotations -- but I have achieved the same effect in one go.
	       if(rbNode == parent->right && parent == grandParent->left) 
	           parent = rightGrandChildReplacesTheGrandParent(rbNode);  
	       else if(rbNode == parent->left && parent == grandParent->right) 
	           parent = leftGrandChildReplacesTheGrandParent(rbNode);
	       else if(rbNode == parent->left && parent == grandParent->left)  
	           parent = leftChildParentReplacesTheGrandParent(rbNode);
	       else 
	           parent = rightChildParentReplacesTheGrandParent(rbNode);

	       parent->color = BLACK;
	       grandParent->color = RED;
	       return parent;
	   }
       }
   }

   return rbNode;
}

struct RBNode *insertRBNode(struct RBNode * const root, int const insertValue){
    struct RBNode * newNode = createNode(insertValue);
    if(root){
	struct RBNode * previousNode = NULL;
        struct RBNode * currentNode  = root;
        
	while(currentNode) {
	   //value is already there
	   if(currentNode->data == insertValue) return root;

	   previousNode = currentNode;
	   currentNode  = currentNode->data > insertValue ? currentNode->left : currentNode->right;
	}
        
	if(previousNode->data > insertValue) 
	    previousNode->left = newNode;
	else 
	    previousNode->right = newNode;
	
	newNode->parent = previousNode;

	organizeTreeAfterInsertion(newNode);
	return root;
    }

    return organizeTreeAfterInsertion(newNode);
}

struct RBNode *deleteRBNode(struct RBNode * const root, int const value){
    return NULL;
}
