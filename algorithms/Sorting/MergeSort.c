#include <stdio.h>


void printIntArrayOverRange(int const data[], int const startIndex, int const endIndex) {
    for(int i = startIndex; i <= endIndex; ++i) printf("%d ", data[i]);
    printf("\n");
}

void merge(int data[], int const left, int const middle, int const right){
    int startIndexSubArray_1  = left;
    int endIndexSubArray_1    = middle;
    
    int startIndexSubArray_2  = middle + 1;
    int endIndexSubArray_2    = right;

    int const auxArraySize = right - left + 1;
    int aux[auxArraySize];
    
    int startIndexAuxArray    = 0;
    int endIndexAuxArray      = auxArraySize - 1;
    
    while(startIndexSubArray_1 <= endIndexSubArray_1 && startIndexSubArray_2 <= endIndexSubArray_2)
	    aux[startIndexAuxArray++] = data[startIndexSubArray_1] <= data[startIndexSubArray_2] 
	                                                              ? data[startIndexSubArray_1++] 
	                                                              : data[startIndexSubArray_2++];

    while(startIndexSubArray_1 <= endIndexSubArray_1) aux[startIndexAuxArray++] = data[startIndexSubArray_1++];
    while(startIndexSubArray_2 <= endIndexSubArray_2) aux[startIndexAuxArray++] = data[startIndexSubArray_2++];
    
    startIndexAuxArray   = 0;
    startIndexSubArray_1 = left;
    
    while(startIndexAuxArray <= right) data[startIndexSubArray_1++] = aux[startIndexAuxArray++];
}

void mergesort(int data[], int const left, int const right) {
   if(left < right){
       int const middleIndex = left + (right - left) / 2;
       mergesort(data, left,            middleIndex);
       mergesort(data, middleIndex + 1, right);
       merge(data, left, middleIndex,   right);
   }
}

void printIntArray(int const data[], int dataSizeOfArray) {
    for(int i = 0; i < dataSizeOfArray; ++i) printf("%d ", data[i]);
    printf("\n");
}


int main()
{
    int data[] = {2, 5, 1, -12};
    int const dataArraySize = sizeof(data)/sizeof(int);
    int const lastValidIndex = dataArraySize - 1;

    printf("UnsortedArray :- ");
    printIntArray(data, dataArraySize);

    mergesort(data, 0, lastValidIndex);

    printf("Sorted Array :- ");
    printIntArray(data, dataArraySize);
    
    return 0;
}
