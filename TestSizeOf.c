#include<stdio.h>

void main(){
    char msg[] = "My name is anurag anand";
    printf("sizeof msg array %ld\n", sizeof(msg) * 8);
    char *ptrToMsg = msg;
    printf("sizeof ptrToMsg %ld\n", sizeof(ptrToMsg) * 8);
}
