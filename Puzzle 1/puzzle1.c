#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *fptr;

int main() {
    fptr = fopen("puzzle1_input.txt", "r"); 

    char phrase[100]; 
    int sum = 0;

    while (fgets(phrase, 100, fptr)) {
        printf("\n%s length: %lu\n", phrase, strlen(phrase));

        char *pointer = phrase;
        // printf("\n%c\n", *pointer);
        int start = 0, firstNumber, lastNumber;

        while (*pointer) {
            // printf("\n%c", *pointer);

            if ( isdigit(*pointer)) {
                // printf("I am a number!");
                if (start == 0) {
                    firstNumber = *pointer;
                    // printf("%c", firstNumber);
                    start++;
                }

                lastNumber = *pointer;
            }

            pointer++;
        }
       
        printf("\nFirst Number: %c; Last Number: %c", firstNumber, lastNumber);
        
        char sFirstNumber[2], sLastNumber[2];
        sprintf(sFirstNumber, "%c", firstNumber);
        printf("\nFirst Number: %s", sFirstNumber);

        sprintf(sLastNumber, "%c", lastNumber);
        printf("\nLast Number: %s", sLastNumber);

        char numberString[3];
        strcpy(numberString, strcat(sFirstNumber, sLastNumber));
        printf("\n%s",numberString);

        sum += atoi(numberString);
        
    }

    printf("Sum: %d", sum);

    fclose(fptr); 
    return 0;
} 