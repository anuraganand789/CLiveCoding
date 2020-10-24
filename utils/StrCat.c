#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcatImpl_1(char * restrict firstString, char * restrict secondString){
    int const noOfCharsInFirstString  = firstString  ? strlen(firstString)  : 0;
    int const noOfCharsInSecondString = secondString ? strlen(secondString) : 0;
    
    if(noOfCharsInFirstString && noOfCharsInSecondString) {
        char * const newString = (char *) 
                                  (
				    !noOfCharsInFirstString 
				    ? malloc(sizeof(char) * (noOfCharsInSecondString + 1))
            		            : !noOfCharsInSecondString 
				        ? malloc(sizeof(char) * (noOfCharsInFirstString + 1))
            		                : malloc(sizeof(char) * (noOfCharsInFirstString + noOfCharsInSecondString + 1))
            		          );

        char * iterator = newString;
        if(noOfCharsInFirstString) { 
            while((*iterator++ = *firstString++)); 
	    //move one block back to start adding new chars from second string by overwriting the null char
            if(noOfCharsInSecondString) --iterator;
        }
        
        if(noOfCharsInSecondString) { while((*iterator++ = *secondString++)); }
        return newString;
    }

    return NULL;

}

int main(int argc, char** argv){
    char * const slogan = strcatImpl_1("Jai!!!", "Shree Ram");
    printf("=> %s \n", slogan);
    if(slogan && *slogan) free(slogan);
    return 0;
}
