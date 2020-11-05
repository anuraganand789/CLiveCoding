#include<stdio.h>

void swap(const int data[], int const firstIndex, int const secondIndex) {
    int const temp    = data[firstIndex];
    data[firstIndex]  = data[secondIndex];
    data[secondIndex] = temp;
}

void printIntArray(int const data[], int const arrayEndsIndex) {
    for(int i = 0; i <= arrayEndsIndex; ++i) printf("%d ", data[i]);
    printf("\n");
}
void makeMaxValueTheParent(int const data[], int const parent, int const arrayEnds) {
    int root, leftChild, rightChild;

    root = parent;
    leftChild = 2 * root + 1;
    rightChild = leftChild + 1;

    int maxIndex = root; 

    while(leftChild <= arrayEnds) {
        if(data[maxIndex] < data[leftChild])  maxIndex = leftChild;

        if(rightChild <= arrayEnds && data[maxIndex] < data[rightChild]) maxIndex = rightChild;
    
	if(maxIndex == root) return;

        swap(data, root, maxIndex);
        
	root = maxIndex;
	leftChild = 2 * root + 1;
        rightChild = leftChild + 1;
    }
}

void buildHeap(int data[], int const arrayEndsIndex) {
    int const lastParent = arrayEndsIndex/ 2;
    for(int i = lastParent; i > -1; --i) 
        makeMaxValueTheParent(data, i, arrayEndsIndex);

    int swapIndex = arrayEndsIndex;

    while(swapIndex > 0) {
        swap(data, 0, swapIndex);
	--swapIndex;
	makeMaxValueTheParent(data, 0, swapIndex);
    }
}

void main() {
    int data[] = {-12, -14, 5, 11};
    int sizeOfArray = sizeof(data)/sizeof(int);

    printf("Unsorted Array :- ");
    printIntArray(data, sizeOfArray - 1);

    buildHeap(data, sizeOfArray - 1);
    
    printf("Sorted Array :- ");
    printIntArray(data, sizeOfArray - 1);
}
