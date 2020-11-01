#include "InfixToPostfix.h"

void main(int argc, char **argv){
    if(argc < 2) {
        printf("Please provide Infix expression.\n");
	return;
    }

    char *expression = *++argv;
    printf("%s -> ", expression);

    uint_least8_t noOfOperators = 0;

    while(*expression != '\0') if(precedence(expression++) > 0) ++noOfOperators;

    char *stackOfOperators = (char *) calloc(noOfOperators, sizeof(char));
    int_least8_t top = -1;

    expression = *argv;
    while(*expression != '\0'){
        if(precedence(expression) < 0) { printf("%c", *expression); }
	else{
	   while(top != -1 && precedence(stackOfOperators + top) > precedence(expression)) 
	       { printf("%c", *(stackOfOperators + top--)); }

	   *(stackOfOperators + ++top) = *expression;
	}
	++expression;
    }

    while(top != -1) printf("%c", *(stackOfOperators + top--));

    printf("\n");
    free(stackOfOperators);
}


int_least8_t precedence(char *operator){
    switch(*operator){
    case '-': case '+': return 1;
    case '*': case '/': return 2;
    default : return -1;
    }
}
