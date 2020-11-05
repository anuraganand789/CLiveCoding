#include<stdio.h>
#include<stdbool.h>

void main() {
    int data[] = {1 , 5, 10, 4 , 11};
    int dataLength = sizeof(data)/sizeof(int);

    int searchValue = 12;

    bool found = false; 
    for(int i = 0; i < dataLength; ++i) if(found = ( data[i] == searchValue )) break;

    if(found) printf("Value found.\n");
    else      printf("Value not found.\n");
}
