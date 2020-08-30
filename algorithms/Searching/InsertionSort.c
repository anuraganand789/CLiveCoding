#include<stdio.h>

void swap(int *data, int const firstIndex, int const secondIndex) {
    int const tempValue  = data[firstIndex];
    data[firstIndex ]    = data[secondIndex];
    data[secondIndex]    = tempValue;
}

void insertionSort(int *data, int const sizeOfArray) {
    int j;

    for(int i = 1; i < sizeOfArray; ++i) {

        j = i;
	while(j > 0 && data[j] < data[j - 1]) {
	    swap(data, j, j - 1);
	    --j;
	}

    }
}

void printIntArray(int *data, int const  sizeOfArray) {
   for(int i = 0; i < sizeOfArray; ++i) printf("%d ", data[i]);
   printf("\n");
}

void main() {
               int data[] = {9, 5, 10, 1, 6, 12, 0};
    int const sizeOfArray = sizeof(data)/sizeof(int);

    printf("Unsorted Array -> ");
    printIntArray(data, sizeOfArray);
    
    insertionSort(data, sizeOfArray);

    printf("Sorted Array -> ");
    printIntArray(data, sizeOfArray);
}
