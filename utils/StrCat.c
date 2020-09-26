#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcatImpl_1(char * restrict firstString, char * restrict secondString){
    int const noOfCharsInFirstString = firstString == NULL ? 0 : strlen(firstString);
    int const noOfCharsInSecondString = secondString == NULL ? 0 : strlen(secondString);
    
    if(0 == noOfCharsInFirstString && 0 == noOfCharsInSecondString) return NULL;

    char * const newString = (char *) 
                              (noOfCharsInFirstString == 0
                                 ? malloc(sizeof(char) * (noOfCharsInSecondString + 1))
			         : noOfCharsInSecondString == 0 
			         ? malloc(sizeof(char) * (noOfCharsInFirstString + 1))
			         : malloc(sizeof(char) * (noOfCharsInFirstString + noOfCharsInSecondString + 1))
			      );

    if(NULL == newString) return NULL;

    char * iterator = newString;
    if(0 != noOfCharsInFirstString) { 
        while((*iterator++ = *firstString++) != '\0'); 
        if(0 != noOfCharsInSecondString) --iterator;
    }
    
    if(0 != noOfCharsInSecondString) { while((*iterator++ = *secondString++) != '\0'); }

    return newString;
}

int main(int argc, char** argv){
    char* const slogan = strcatImpl_1("Jai!!!", "Shree Ram");
    printf("=> %s \n", slogan);
    if(NULL != slogan && '\0' != *slogan) free(slogan);
    return 0;
}
