#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isOperator(char *ch){
    return *ch == '/' || *ch == '*' || *ch == '-' || *ch == '+';
}

int precedence(char *ch){
    switch(*ch){
        default : return -1;
	case '-':
	case '+': return 1;
	case '/':
	case '*': return 2;
    }
}

void main(int argc, char **argv){
    char *expression = *(++argv);
    printf("%s ->", expression);

    unsigned char expressionLength = -1;
    unsigned char countOfOperators = 0;
    for(; *expression != '\0'; ++expression) {
       ++expressionLength;
       if(isOperator(expression)) ++countOfOperators;
    }
    
    //reverse the expression
    char tempCharHolder = '\0';
    unsigned char leftChar = 0;
    unsigned char rightChar = expressionLength;

    expression = *argv;
    while(leftChar < rightChar){
        tempCharHolder = *(expression + leftChar);
	*(expression + leftChar) = *(expression + rightChar);
	*(expression + rightChar) = tempCharHolder;
	++leftChar;
	--rightChar;
    }

    char *stackOfOperators = (char *) calloc(countOfOperators, sizeof(char));
    char topOfStack = -1;

    char *prefix = (char *) calloc(expressionLength + 1, sizeof(char));
    char prefixLocation = expressionLength;

    for(; *expression != '\0'; ++expression){
        if(!isOperator(expression)) *(prefix + prefixLocation--) = *expression;
	else{
	    while(topOfStack > -1 
	        && precedence(expression) <= precedence(stackOfOperators + topOfStack))
	            *(prefix + prefixLocation--) = *(stackOfOperators + topOfStack--);
	    
	    *(stackOfOperators + ++topOfStack) = *expression;
	}
    }

    while(topOfStack > -1) *(prefix + prefixLocation--) = *(stackOfOperators + topOfStack--);

    printf(" %s.\n", prefix);
}
