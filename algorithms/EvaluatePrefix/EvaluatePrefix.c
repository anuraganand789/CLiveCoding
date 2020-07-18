#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isOperator(char *ch){
    return *ch == '-' || *ch == '/' || *ch == '*' || *ch == '+';
}

int alphaToInt(char *ch) {
    switch(*ch){
        default : return EOF;
	case '0' : return 0;
	case '1' : return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6' : return 6;
	case '7' : return 7;
	case '8' : return 8;
	case '9' : return 9;
    }
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
