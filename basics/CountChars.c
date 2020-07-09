#include<stdio.h>

void main() {
    int wordCount = 0;
    int charRead;

    while((charRead = getchar()) != EOF) ++wordCount;

    printf("Total Characters = %d.\n", wordCount);
}
