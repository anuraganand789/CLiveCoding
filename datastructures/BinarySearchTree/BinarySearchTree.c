#include<stdio.h>
#include<stdlib.h>

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

void main(){
    struct BTreeNode *head = newNode(24);

    struct BTree     *tree = (struct BTree *) malloc(sizeof(struct BTree));
    tree->head = head;

    insertInBTree(tree->head, 20);
    insertInBTree(tree->head, 21);
    insertInBTree(tree->head, 17);
    insertInBTree(tree->head, 25);

    inorder(tree->head, 0);
    printf("\n");
}
