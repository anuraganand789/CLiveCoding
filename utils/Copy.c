#include<stdio.h>
void main(){
    int characterRead;
    while((characterRead = getchar()) != EOF) putchar(characterRead);
}
