#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

enum COLOR { RED, BLACK };

struct RBNode {
  int data;
  enum COLOR color;
  struct RBNode *parent;
  struct RBNode *left;
  struct RBNode *right;
};

//Conditionals 
inline bool null(struct RBNode * const rbNode)       { return rbNode == NULL; }
inline bool notNull(struct RBNode * const rbNode)    { return rbNode != NULL; }

//Relations 
inline struct RBNode *parentOf(struct RBNode * const root) { 
    return root ? root->parent : NULL; 
}
inline struct RBNode *grandParentOf(struct RBNode * const root) { 
    return parentOf(parentOf(root)); 
}
inline struct RBNode *leftChildOf(struct RBNode *root) { 
    return notNull(root) ? root->left  : NULL; 
} 
inline struct RBNode *rightChildOf(struct RBNode *root) { 
    return notNull(root) ? root->right : NULL; 
}
// Conditional Functions
extern bool isLeftChildOf(struct RBNode *rootNode, struct RBNode *rbNode);
extern bool isRightChildOf(struct RBNode *rootNode, struct RBNode *rbNode);

inline bool itIsARedNode(struct RBNode * rbNode)     { return notNull(rbNode) && rbNode->color == RED; }
inline bool itIsABlackNode(struct RBNode * rbNode)   { return null(rbNode) || rbNode->color == BLACK;  }
inline int dataOf(struct RBNode * const rbNode)      { return notNull(rbNode) ? rbNode->data : EOF;    }

inline bool hasLeftChild(struct RBNode * const rbNode) { return notNull(leftChildOf(rbNode)); }
inline bool hasRightChild(struct RBNode * const rbNode) { return notNull(rightChildOf(rbNode)); }
inline bool hasParent(struct RBNode * const rbNode) { return notNull(parentOf(rbNode)); }

extern char *nodeColorAsString(struct RBNode * const rbNode);

// For Debug purposes
extern void printRBNode(struct RBNode * const root);
extern void printRBTree(struct RBNode * const root, int const noOfRepeats, char const indentChar);

extern void *debugMalloc(size_t const sizeOfMalloc);
extern void debugFree(void * const pointer);

//Relations
extern struct RBNode *uncleOf(struct RBNode * const root);
extern struct RBNode *siblingOf(struct RBNode * const root);

//Set Relations

inline void makeParentOf(struct RBNode * const childNode, struct RBNode * const parentNode){
  if(childNode) childNode->parent = parentNode;
}

//These functions modify the parent child relations
inline void makeLeftChildOf(struct RBNode * const parentNode, struct RBNode * const leftChild){
  if(parentNode) parentNode->left = leftChild;
}

inline void makeRightChildOf(struct RBNode * const parentNode, struct RBNode * const rightChild){
  if(parentNode) parentNode->right = rightChild;
}

//Rotations or Node Relation Modification
extern struct RBNode *leftGrandChildReplacesTheGrandParent(struct RBNode * const rbNode);
extern struct RBNode *rightGrandChildReplacesTheGrandParent(struct RBNode * const rbNode);

extern struct RBNode *leftChildReplacesTheParent(struct RBNode * const rbNode);
extern struct RBNode *rightChildReplacesTheParent(struct RBNode * const rbNode);

extern struct RBNode *leftChildParentReplacesTheGrandParent(struct RBNode * const rbNode);
extern struct RBNode *rightChildParentReplacesTheGrandParent(struct RBNode * const rbNode);

//Operations On Nodes
extern struct RBNode *insertRBNode(struct RBNode * const root, int const value);
extern struct RBNode *deleteRBNode(struct RBNode * const root, int const value);

