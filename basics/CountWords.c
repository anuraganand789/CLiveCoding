#include<stdio.h>

static char isWhiteSpace(int *readChar);

void main(){
    //Stores current count of words
    int countWords = 0;
    //Stores current character
    int readChar;
    //Store last character
    int prevReadChar = 0;

    while((readChar = getchar()) != EOF) {
	if(isWhiteSpace(&readChar) == 1 && isWhiteSpace(&prevReadChar) == 0) ++countWords;
	//Update with current character
	prevReadChar = readChar;
    }
    
    printf("Total Words :- %d.\n", countWords);
}

static char isWhiteSpace(int *readChar) {
    return (*readChar == ' ' || *readChar == '\t' || *readChar == '\n') ? 1 : 0;
}
