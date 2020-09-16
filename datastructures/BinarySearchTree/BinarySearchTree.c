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
    if(NULL == head) return;

    inorder(head->left, noOfSeparator + 2); 
    printf("\n");
    for(int i = 0; i < noOfSeparator; ++i) printf("-");
    printf("%d", head->data);
    inorder(head->right, noOfSeparator + 2);
}

struct BTreeNode *newNode(int const data){
    struct BTreeNode *node = (struct BTreeNode *) malloc(sizeof(struct BTreeNode));
    node->data = data;
    node->right = node->left = NULL;
    return node;
}

//recursive function
struct BTreeNode *insertInBTree(struct BTreeNode *root, int const data){
    if(NULL == root) return newNode(data);

    if(data == root->data) return root;

    if(data > root->data) root->right = insertInBTree(root->right, data);
    else                  root->left  = insertInBTree(root->left,  data);

    return root;
}

void insert(struct BTreeNode * const head, int const data){
    if(NULL == head) return;

    bool nodeAddedToRight         = false;
    struct BTreeNode *currNode    = head;
    struct BTreeNode *prevNode    = head;

    while(NULL != currNode){
        if(data == currNode->data) return;
	prevNode = currNode;
	if(data > currNode->data) {
	    nodeAddedToRight = true;
	    currNode = currNode->right;
	} else {
	    nodeAddedToRight = false;
	    currNode = currNode->left;
	}
    }
    
    struct BTreeNode *nodeNew  = newNode(data);
    if(nodeAddedToRight) prevNode->right = nodeNew;
    else                 prevNode->left  = nodeNew;

}

struct BTreeNode *search(struct BTreeNode * const head, int const data){
    if(NULL == head || data == head->data) return head;

    struct BTreeNode *currNode = head;
    while(NULL != currNode && data != currNode->data){
        currNode = data < currNode->data ? currNode->left : currNode->right;
    }

    return currNode;
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
}
