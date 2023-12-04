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
            } else {
                switch(*pointer){
                    case 'o':
                        if ( *(pointer+1) == 'n' && *(pointer+2) == 'e') {
                            if (start == 0) {
                                firstNumber = '1';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '1';
                            }
                        }
                        break;
                    case 't':
                        if ( *(pointer+1) == 'w' && *(pointer+2) == 'o') {
                            if (start == 0) {
                                firstNumber = '2';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '2';
                            }
                        } else if ( *(pointer+1) == 'h' && *(pointer+2) == 'r' && *(pointer+3) == 'e' && *(pointer+4) == 'e') {
                            if (start == 0) {
                                firstNumber = '3';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '3';
                            }
                        } 
                        break;
                    case 'f':
                        if ( *(pointer+1) == 'o' && *(pointer+2) == 'u' && *(pointer+3) == 'r') {
                            if (start == 0) {
                                firstNumber = '4';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '4';
                            }
                        } else if ( *(pointer+1) == 'i' && *(pointer+2) == 'v' && *(pointer+3) == 'e') {
                            if (start == 0) {
                                // printf("FIVEEEEE");
                                firstNumber = '5';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                // printf("LAST FIVEEEEE");
                                lastNumber = '5';
                            }
                        }
                        break;
                    case 's':
                        if ( *(pointer+1) == 'i' && *(pointer+2) == 'x') {
                            if (start == 0) {
                                firstNumber = '6';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '6';
                            }
                        } else if ( *(pointer+1) == 'e' && *(pointer+2) == 'v' && *(pointer+3) == 'e' && *(pointer+4) == 'n') {
                            if (start == 0) {
                                firstNumber = '7';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '7';
                            }
                        }
                        break;
                    case 'e':
                        if ( *(pointer+1) == 'i' && *(pointer+2) == 'g' && *(pointer+3) == 'h' && *(pointer+4) == 't') {
                            if (start == 0) {
                                firstNumber = '8';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '8';
                            }
                        }
                        break;
                    case 'n':
                        if ( *(pointer+1) == 'i' && *(pointer+2) == 'n' && *(pointer+3) == 'e') {
                            if (start == 0) {
                                firstNumber = '9';
                            // printf("%c", firstNumber);
                                start++;
                            } else {
                                lastNumber = '9';
                            }
                        }
                        break;
                }
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
        // printf("\n%s",numberString);

        sum += atoi(numberString);
        
    }

    printf("Sum: %d", sum);

    fclose(fptr); 
    return 0;
} 