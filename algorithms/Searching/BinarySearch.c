#include<stdio.h>
#include<stdbool.h>

int binarySearch(int data[], int sizeOfTheArray, int searchItem) {
    
    int left  =  0;
    int right =  sizeOfTheArray - 1;

    while(left <= right) {
        int mid  =  left + ((right - left) / 2); 
	
	if(data[mid]  ==  searchItem ) return mid;

        if(data[mid] > searchItem)     right  =  mid - 1;
	else                           left   =  mid + 1;
    }

    return -1;
}

void main() {
    int data[]  =  { 1, 2, 5, 10, 15, 22};
    int sizeOfTheArray  = sizeof(data) / sizeof(int);
    int searchItem = 11;

    int indexOfSearchItem = binarySearch(data, sizeOfTheArray, searchItem);

    if(indexOfSearchItem == -1)  printf("value does not exist.\n");
    else                         printf("The values exists at the index %d.\n", indexOfSearchItem);

}
