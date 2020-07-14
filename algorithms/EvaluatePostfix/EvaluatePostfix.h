#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef unsigned short Word;
typedef unsigned char  Byte;

bool isOperand(char *);
Word performOperation(char *, Word *, Word *);
Word alphaToInt(char *);
