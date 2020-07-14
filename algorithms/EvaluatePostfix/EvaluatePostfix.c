#include "EvaluatePostfix.h"

void main(int argCount, char **arguments){
    
    char *postfixExpression = *++arguments;
    printf("%s -> ", postfixExpression);

    Byte noOfOperands = 0;

    for(; *postfixExpression != '\0'; ++postfixExpression) if(isOperand(postfixExpression)) ++noOfOperands;

    Word *stackOfOperands = (Word *) calloc(noOfOperands, sizeof(Word));
    char            topOfStack = -1;

    for(postfixExpression = *arguments; *postfixExpression != '\0'; ++postfixExpression){
        if(isOperand(postfixExpression)) *(stackOfOperands + ++topOfStack) = alphaToInt(postfixExpression);
	else {
	    Word *operand1 = (stackOfOperands + topOfStack--);
	    Word *operand2 = (stackOfOperands + topOfStack--);
	    *(stackOfOperands + ++topOfStack) = performOperation(postfixExpression, operand1, operand2);
	}
    }

    printf("%d\n", *(stackOfOperands + topOfStack));

    free(stackOfOperands);
}

Word alphaToInt(char *operand){
    switch(*operand){
        default : return EOF;
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
    }
}

Word performOperation(char *operator, Word *operand1, Word *operand2){
    switch(*operator){
        default : return -1;
	case '-' : return *operand1 - *operand2;
	case '+' : return *operand1 + *operand2;
	case '*' : return *operand1 * *operand2;
	case '/' : return *operand1 / *operand2;
    }
}

bool isOperand(char *charachter) {
    return *charachter >= '0' && *charachter <= '9';
}
