#include<stdio.h>

void printIntArrayOnRange(int const data[], int const start, int const end) {
    for(int i = start; i <= end; ++i) printf("%d ", data[i]);
    printf("\n");
}

void swap(int data[], int const firstIndex, int const secondIndex){
    int const temp   = data[firstIndex];
    data[firstIndex] = data[secondIndex];
    data[secondIndex] = temp;
}

int partition(int data[], int const startIndex, int const endIndex){
    int const middle = startIndex + (endIndex - startIndex) / 2;
    int const pivot = data[middle];
    
    swap(data, middle, endIndex);

    int _startIndex = startIndex;
    int _endIndex   = endIndex - 1;
    int iterCount   = startIndex;

    while(iterCount <= _endIndex) {
        if(data[iterCount] < pivot) { swap(data, _startIndex++, iterCount); }
	
	++iterCount;
    }

    swap(data, _startIndex, endIndex);
    return _startIndex;

}

void quicksort(int data[], int const startIndex, int const endIndex){
    if(startIndex < endIndex){
        int partitionIndex = partition(data, startIndex, endIndex);
	quicksort(data, startIndex,         partitionIndex - 1);
	quicksort(data, partitionIndex + 1, endIndex);
    }
}

void printIntArray(int data[], int sizeOfArray){
    for(int i = 0; i < sizeOfArray; ++i) printf("%d ", data[i]);
    printf("\n");
}

void main() {
   int data[] = {12, 5, -12, 9}; 
   int sizeOfArray = sizeof(data) / sizeof(int);
   
   printf("Unsorted Array :-");
   printIntArray(data, sizeOfArray);

   quicksort(data, 0, sizeOfArray - 1);

   printf("Sorted Array :- ");
   printIntArray(data, sizeOfArray);
}
