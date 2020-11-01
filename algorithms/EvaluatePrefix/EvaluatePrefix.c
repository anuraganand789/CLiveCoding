#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isOperator(char *ch){
    return *ch == '-' || *ch == '/' || *ch == '*' || *ch == '+';
}

int alphaToInt(char *ch) {
    return (*ch >= '0' && *ch <= '9') ?  *ch - '0' : EOF;
}
short calc(char *ops, short *opd1, short *opd2) {
    switch(*ops){
        default : return -255;
	case '-' : return *opd1 - *opd2;
	case '+' : return *opd1 + *opd2;
	case '/' : return *opd1 / *opd2;
	case '*' : return *opd1 * *opd2;
    }
}

void main(int argc, char **argv){
    char *expression = *(++argv); 

    
    char expressionLength = -1;
    unsigned char noOfOperands = 0;

    for(; *expression != '\0'; ++expression) {
        if(!isOperator(expression)) ++noOfOperands;
	++expressionLength;
    }

    //reverser the prefix expression
    char leftChar = 0;
    char rightChar = expressionLength;

    char tempCharHolder = '\0';
    expression = *argv;
    while(leftChar < rightChar) {
        tempCharHolder = *(expression + leftChar);
	*(expression + leftChar) = *(expression + rightChar);
	*(expression + rightChar) = tempCharHolder;
	++leftChar;
	--rightChar;
    }

    short *stackOfOperands = (short *) calloc(noOfOperands, sizeof(short));
    char topOfStack = -1;

    for(; *expression != '\0'; ++expression) {
        if(!isOperator(expression)) *(stackOfOperands + ++topOfStack) = alphaToInt(expression);
	else {
	    short *opd1 = stackOfOperands + topOfStack--;
	    short *opd2 = stackOfOperands + topOfStack--;
            short result = calc(expression, opd1, opd2);
	    *(stackOfOperands + ++topOfStack) = result;
	}
    }

   printf(" :- %d.\n", *(stackOfOperands + topOfStack));
}
