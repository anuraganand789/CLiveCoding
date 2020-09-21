#include<stdio.h>
#include<stdlib.h>

#include "AVL.h"

extern struct AVLNode *freeAllMemoryInAVLTree(struct AVLNode * const root){
    if(NULL == root) return NULL;

    root->left  = freeAllMemoryInAVLTree(root->left);
    root->right = freeAllMemoryInAVLTree(root->right);
    free(root);
    return NULL;
}
struct AVLNode *newAVLNode(int const data){
    struct AVLNode *newNode = (struct AVLNode *) malloc(sizeof(struct AVLNode));

    newNode->left    =  newNode->right = NULL;
    newNode->data    =  data;
    newNode->height  =  1;

    return newNode;
}

void printAVLNode(struct AVLNode *const root){
    if(NULL == root) return;

    printf("{DATA : %d, Height : %d, Balance Factor : %d}\n", root->data, root->height, balanceFactorOfAVLNode(root));
}

static void printAVLTreeWithIndentation(struct AVLNode * const root, char const seperator, char const repeater){
    if(NULL == root) return;

    printAVLTreeWithIndentation(root->left, seperator, repeater + 2);

    for(int i = 0; i < repeater; ++i) printf("%c", seperator);
    printf(">");
    printAVLNode(root);

    printAVLTreeWithIndentation(root->right, seperator, repeater + 2);

}
void printAVLTree(struct AVLNode * const root){
    printf("\n");
    printAVLTreeWithIndentation(root, '-', 0);
}

inline int heightOfAVLNode(struct AVLNode * const root){
    return NULL == root ? 0 : root->height;
}

inline int max(int const numberOne, int const numberTwo){
    return (numberOne > numberTwo) ? numberOne : numberTwo;
}

int updateHeight(struct AVLNode * const root){
    if(NULL == root) return 0;

    root->height =  1 + max(heightOfAVLNode(root->left), heightOfAVLNode(root->right));

    return root->height;
}

int balanceFactorOfAVLNode(struct AVLNode * const root){
    return (NULL == root) ? 0 : heightOfAVLNode(root->left) - heightOfAVLNode(root->right);
}
struct AVLNode *rotateRight(struct AVLNode * const root){
    if(NULL == root) return NULL;

    struct AVLNode * const leftChild        = root->left;
    struct AVLNode * const rightOfLeftChild = leftChild->right; 

    leftChild->right = root;
    root->left       = rightOfLeftChild;
    
    updateHeight(root);
    updateHeight(leftChild);

    return leftChild;
}

struct AVLNode *rotateLeft(struct AVLNode * const root){
    if(NULL == root) return NULL;
    
    struct AVLNode *rightChild         =   root->right;
    struct AVLNode *leftOfRightChild   =   rightChild->left;

    rightChild->left = root;
    root->right      = leftOfRightChild;

    //Update Sequence is important
    updateHeight(root);
    updateHeight(rightChild);
    
    return rightChild;
}
struct AVLNode *insert(struct AVLNode *root, int const data){
    if(NULL == root) return newAVLNode(data);

    if(data == root->data) return root;

    if(data < root->data) {
        root->left  = insert(root->left, data);
    } else if(data > root->data) {
        root->right = insert(root->right, data);
    }

    updateHeight(root);
    int const rootBalanceFactor = balanceFactorOfAVLNode(root);

    if(rootBalanceFactor > 1) {
        if(data > root->left->data) root->left  = rotateLeft(root->left);
	root = rotateRight(root);
    } else if (rootBalanceFactor < -1) {
        if(data < root->right->data) root->right = rotateRight(root->right);
	root = rotateLeft(root);
    }

    return root;
}

struct AVLNode *deleteAVLNode(struct AVLNode * root, int const data){
    if(NULL == root) return NULL;

    if(data < root->data){
        root->left = deleteAVLNode(root->left, data);
    }else if(data > root->data){
        root->right = deleteAVLNode(root->right, data);
    } else {
	//Leaf Node 
        if(NULL == root->left && NULL == root->right){
	    free(root);
	    return NULL;
	} else if(NULL == root->left || NULL == root->right){
	    struct AVLNode * temp = (NULL == root->right) ? root->left : root->right;
	    free(root);
	    root = temp;
	} else{
	    struct AVLNode * temp = root->left;
	    //find the maximum value in the left subtree
	    while(NULL != temp->right) temp = temp->right;

	    root->data = temp->data;
	    root->left = deleteAVLNode(root->left, temp->data);
	}
    }

    updateHeight(root);
    int balanceFactorOfRoot = balanceFactorOfAVLNode(root);

    if(1 < balanceFactorOfRoot) {
	 //if right subtree has an extra node then , right rotation will not balance the number of nodes
	 //because that extra node is present in the right of the left node
         if(0 > balanceFactorOfAVLNode(root->left)) root->left = rotateLeft(root->left);
	 root = rotateRight(root);
    } else if(-1 > balanceFactorOfRoot) {
	//If the left subtree of the right node is heavy then the extra node needs to be moved to
	//the right subtree
        if(0 < balanceFactorOfAVLNode(root->right)) root->right = rotateRight(root->right);
	root = rotateLeft(root);
    }

    return root;
}

int main(){
    struct AVLNode *head = newAVLNode(35);
    printAVLTree(head);

    head = insert(head, 37);
    printAVLTree(head);

    head = insert(head, 38);
    printAVLTree(head);

    head = insert(head, 39);
    printAVLTree(head);

    head = insert(head, 21);
    printAVLTree(head);

    head = insert(head, 37);
    printAVLTree(head);

    head = insert(head, 3);
    printAVLTree(head);

    head = insert(head, 29);
    printAVLTree(head);

    head = insert(head, 2);
    printAVLTree(head);

    head = deleteAVLNode(head, 29);
    printAVLTree(head);

    freeAllMemoryInAVLTree(head);
    return 0;
}
