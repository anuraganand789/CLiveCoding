#include "RB.h"


void printRBNode(struct RBNode * root){
  if(notNull(root)) printf("{Data : %d, 
                            Color : %s, 
			    LeftChild : %d, 
			    RightChild : %d, 
			    Parent : %d}", 
                            dataOf(root),
                            nodeColorAsString(root),
			    dataOf(leftChidlOf(root)),
			    dataOf(rightChildOf(root)),
			    dataOf(parentOf(root)));
}

void printRBTree(struct RBNode * root, int const noOfRepeats, char const indentChar){
  if(notNull(root){
    printRBTree(root->left, noOfRepeats + 2, indentChar);

    for(int i = noOfRepeats; i > -1; --i) { printf("%c", indentChar); }
    printRBNode(root);

    printRBTree(root->right, noOfRepeats + 2, indentChar);
  }
}

void *debugMalloc(size_t sizeOfMalloc){
  static int count = 0;
  printf("Memory allocated %d times", ++count);
  return malloc(sizeOfMalloc);
}
void debugFree(void *pointer){
  static int count = 0;
  printf("Memory De-allocated %d times", ++count);
  free(pointer);
}
