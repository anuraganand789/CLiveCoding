#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct BTreeNode{
    int data;
    struct BTreeNode *left;
    struct BTreeNode *right;
};

struct BTree{
    struct BTreeNode *head;
};

void inorder(struct BTreeNode *head, int const noOfSeparator){
    if(head){
        inorder(head->left, noOfSeparator + 2); 

        printf("\n");
        for(int i = 0; i < noOfSeparator; ++i) printf("-");
        printf("%d", head->data);

        inorder(head->right, noOfSeparator + 2);
    }

}

struct BTreeNode *newNode(int const data){
    struct BTreeNode *node = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

//recursive function
struct BTreeNode *insertInBTree(struct BTreeNode *root, int const data){
    if(root) {
	if(root->data > data)
	    root->left = insertInBTree(root->left, data);
        else if(root->data < data)
	    root->right = insertInBTree(root->right, data);
	
	return root;
    } 
    return newNode(data); 
}

void insert(struct BTreeNode * const head, int const data){
    if(head){
        struct BTreeNode *currNode    = head;
        struct BTreeNode *prevNode    = NULL;

        while(currNode && currNode->data != data){

            prevNode = currNode;

            if(data > currNode->data) {
                currNode = currNode->right;
            } else if(data < currNode->data){
                currNode = currNode->left;
            }
        }
        
        //we are trying to add duplicate data
        if(currNode != NULL) return;

        struct BTreeNode *nodeNew  = newNode(data);
        if(!prevNode->left)
	    prevNode->left  = nodeNew;
        else
            prevNode->right = nodeNew;

    }
}

struct BTreeNode *search(struct BTreeNode * const head, int const data){
    struct BTreeNode *foundNode;
    if(foundNode = head){
	while(foundNode && foundNode->data != data) 
	    foundNode = foundNode->data > data ? foundNode->left : foundNode->right;
    }
    return foundNode;
}

struct BTreeNode *maxValueInTheLeftTree(struct BTreeNode * const root){
    struct BTreeNode * maxNode;
    if((maxNode = root) && (maxNode = root->left))
        while(maxNode->right) maxNode = maxNode->right;
    
    return maxNode;
}

struct BTreeNode *minValueInTheRightTree(struct BTreeNode * const root){
    struct BTreeNode *nodeIterator;
    if((nodeIterator = root) && (nodeIterator = root->right)) {
        while(nodeIterator && (nodeIterator = nodeIterator->left));
    }

    return nodeIterator;
}
void delete(struct BTreeNode *root, int const data){
    if(NULL == root) return;

    if(data == root->data) {
        free(root);
	return; 
    }

    struct BTreeNode *parent = NULL;
    struct BTreeNode *currNode = root;
    
    while(NULL != currNode && data != currNode->data) {
        parent = currNode;
	currNode = data > currNode->data ? currNode->right : currNode->left;
    }

    //Value does not exist
    if(NULL == currNode) return;

    //Delete a leaf
    if(NULL == currNode->left && NULL == currNode->right) {
        if(NULL != parent){
	    //Detach the current Node
	    if(currNode == parent->left) 
	        parent->left = NULL;
	    else
	        parent->right = NULL;
	}
	free(currNode);
	return;
    }
     
    struct BTreeNode *replacementNode = maxValueInTheLeftTree(currNode);
    if(NULL == replacementNode) 
        replacementNode = minValueInTheRightTree(currNode);

    int const replacementValue = replacementNode->data;
    
    delete(currNode, replacementValue);
    currNode->data = replacementValue;
}

void main(){
    struct BTreeNode *head = newNode(19);

    struct BTree     *tree = (struct BTree *) malloc(sizeof(struct BTree));
    tree->head = head;

    insert(tree->head, 20);
    insert(tree->head, 21);
    insert(tree->head, 17);
    insert(tree->head, 25);
    insert(tree->head, 25);

    inorder(tree->head, 0);
    printf("\n");

    int const itemWeAreLookingFor = 17;
    struct BTreeNode *searchItem = search(tree->head, itemWeAreLookingFor);
    if(NULL == searchItem) printf("%d Item Not Found.\n", itemWeAreLookingFor);
    else                   printf("%d is found.\n", searchItem->data);

    delete(tree->head, 17);
    inorder(tree->head, 0);

    delete(tree->head, 21);
    inorder(tree->head, 0);
    printf("\n");
}
