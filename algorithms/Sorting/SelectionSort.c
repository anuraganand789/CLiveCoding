#include<stdio.h>

int min(int data[], int startIndex, int endIndex) {
    int minValueIndex = startIndex;

    for(int currIndex = startIndex + 1; currIndex <= endIndex; ++currIndex) {
        if(data[minValueIndex] > data[currIndex]) minValueIndex = currIndex;
    }
   
   return minValueIndex;
}


void printIntArray(int data[], int sizeOfArray){
    for(int index = 0; index < sizeOfArray; ++index) printf("%d ", data[index]);

    printf("\n");
}

void swap(int data[], int firstIndex, int secondIndex) {
    int temp            = data[firstIndex];
    data[firstIndex]    = data[secondIndex];
    data[secondIndex]   = temp;
}
void selectionSort(int data[], int sizeOfArray) {
    int endIndex = sizeOfArray - 1;
    for(int currIndex = 0; currIndex < endIndex; ++currIndex) {
        int minIndex = min(data, currIndex,  endIndex);
	if(minIndex != currIndex) swap(data, currIndex, minIndex);
    }
}

void main() {
    int data[] = {11, 5, 6, 22, 21, 7};
    int sizeOfArray = sizeof(data)/ sizeof(int);
   
   printf("Unsorted Array => ");
   printIntArray(data, sizeOfArray);
   
   selectionSort(data, sizeOfArray);

   printf("Sorted Array   => ");
   printIntArray(data, sizeOfArray);

}
