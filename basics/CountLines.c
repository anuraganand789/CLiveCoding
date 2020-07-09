#include<stdio.h>

void main(){
     int countLines = 0;
     int readChar;

     while((readChar = getchar()) != EOF) if(readChar == '\n') ++countLines;

     printf("Number of lines %d.\n", countLines);
}
