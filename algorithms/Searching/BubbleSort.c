#include<stdio.h>
#include<stdbool.h>

void swap(int *data, int const firstIndex, int const secondIndex) {
    int const swapValue =  data[firstIndex];
    data[firstIndex]    =  data[secondIndex];
    data[secondIndex]   =  swapValue;
}

void bubblesort(int *data, int const sizeOfArray) {
    
    int j;
    int i = 0;
    bool swapped = false;
    int const innerLoopEnds = sizeOfArray - 1;

    while(i < sizeOfArray) {

	j = 0;
        while(j < innerLoopEnds) {
	    if(data[j] > data[j + 1]) {
	        swap(data, j, j + 1);
	        swapped = true;
	    }
	    ++j;
	}

        //if swapped is false then array is sorted, so return
	if(!swapped) return;

	//we need more iterations
	swapped = false;
	++i;
    }
}

void printIntArray(int *data, int const sizeOfArray) {
    for(int i = 0; i < sizeOfArray; ++i) printf("%d ", data[i]);
    printf("\n");
}
void main() {
    int data[]            =  { 12, 6, 3, 0, -1};
    int const sizeOfArray =  sizeof(data)/sizeof(int);
    
    printf("Unsorted Array -> ");
    printIntArray(data, sizeOfArray); 

    bubblesort(data, sizeOfArray);

    printf("Sorted Array -> ");
    printIntArray(data, sizeOfArray);
}


