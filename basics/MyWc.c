#include<stdio.h>

static int isWhiteSpace(const int *readChar);

void main(){
    int currentReadChar;
    int previousReadChar = 0;
    
    //counts 
    int countCharacters = 0;
    int countWords      = 0;
    int countLines      = 0;
    
    while((currentReadChar = getchar()) != EOF) {
         ++countCharacters;
	 if(currentReadChar == '\n') ++countLines;
	 if(isWhiteSpace(&currentReadChar) == 1 && isWhiteSpace(&previousReadChar) == 0)
	     ++countWords;

	 //Update the last read character
	 previousReadChar = currentReadChar;
    }

    printf("Lines %d, Words %d, Characters %d.\n", countLines, countWords, countCharacters);


}

static int isWhiteSpace(const int *readChar){
    return (*readChar == ' ' || *readChar == '\t' || *readChar == '\n') ? 1 : 0;
}
