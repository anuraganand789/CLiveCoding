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
    return (*operand >= '0' && *operand <= '9') ? *operand - '0' : EOF;
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

inline bool isOperand(char *charachter) {
    return *charachter >= '0' && *charachter <= '9';
}
