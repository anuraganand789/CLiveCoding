#include<stdio.h>
#include<stddef.h>

//Implementation 1
int strlenImpl_1(char * restrict string){
    if(NULL == string) return -1;
    int length = 0; 
    while('\0' != *string++) ++length;
    return length;
}

//Implementation 2
ptrdiff_t strlenImpl_2(char * const restrict string){
    if(NULL == string ) return -1;
    char * charIterator = string;
    while(*charIterator++ != '\0');
    return charIterator - string - 1;
}

int main(int const argc, char **argv){
    char *firstName = "Anurag";
    printf("Length Of FirstName %d \n", strlenImpl_1(firstName));
    printf("Length Of FirstName %ld \n", strlenImpl_2(firstName));
    return 0;
}
