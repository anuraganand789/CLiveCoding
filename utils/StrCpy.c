#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char * strcpyImpl_1(char * restrict destinationString, char * restrict sourceString){
    if(destinationString && sourceString){
        int const destinationStringLength = strlen(destinationString);
        int const sourceStringLength      = strlen(sourceString);

	if(destinationStringLength >= sourceStringLength){
            char * newString = (char *) malloc(sizeof(char) * (destinationStringLength + 1));
            int i = 0;
            //Copy source string
            for(;i < destinationStringLength && i < sourceStringLength; ++i) 
                newString[i] = sourceString[i];

            --i;

            //Copy remanis of destination string
            while(destinationStringLength > i){
                newString[i] = destinationString[i++];
            }

            newString[destinationStringLength] = '\0';

            return newString;
	}
        
    }

    return NULL;
}

char * strcpyImpl_2(char * restrict destinationString, char * restrict sourceString){
    if(destinationString && sourceString){
        int const destinationStringLength = strlen(destinationString);
        int const sourceStringLength      = strlen(sourceString);

	if(destinationStringLength >= sourceStringLength) {
            char * newString = (char *) malloc(sizeof(char) * (destinationStringLength + 1));
            
            char * charIterator = newString;
            while((*charIterator++ = *sourceString++));

            for(int i = sourceStringLength; i < destinationStringLength; ++i){ newString[i] = destinationString[i]; }

            newString[destinationStringLength] = '\0';

            return newString;
	}
        
    }
    return NULL;
}

char * strcpyImpl_3(char * restrict destinationString, char * restrict sourceString){
    if(destinationString && sourceString){
        int const destinationStringLength = strlen(destinationString);
        int const sourceStringLength      = strlen(sourceString);

	if(destinationStringLength >= sourceStringLength) {
            char * newString = (char *) malloc(sizeof(char) * (destinationStringLength + 1));
            char * charIterator = newString;
            //copy the destination string
            while((*charIterator++ = *destinationString++));

            charIterator = newString;
            //copy the source string
            while((*charIterator++ = *sourceString++));
            
            //remove null value put by source string
            if(destinationStringLength > sourceStringLength) newString[sourceStringLength] = destinationString[sourceStringLength];

            return newString;
	}
    }
    return NULL;
}

int main(int argc, char ** const argv){
    char * firstName = "My First name";
    printf("1. First Name Variable :- %s\n", firstName);
    firstName        = strcpyImpl_3(firstName, "My Last ");
    //firstName        = strcpyImpl_2(firstName, "My Last ");
    //firstName        = strcpyImpl_1(firstName, "My Last ");
    printf("2. First Name Variable :- %s\n", firstName);
    printf("Length of new string %d\n", (int) strlen(firstName));
    if(NULL != firstName && *firstName != '\0') free(firstName);
    return 0;
}
