#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *fptr;

int main() {
    //1 - recolher cada game
    fptr = fopen("puzzle3_input.txt", "r"); 

    char phrase[142]; 
    int sum = 0;
    int numberOfPhrase = 0;

    char matrix[140][140];
    int nLeft;
    // char* fullNumberstr;
    int fullNumber;

    // 1. Preencher a matriz
    while (fgets(phrase, 142, fptr) && numberOfPhrase<140) {
        // printf("%s, Number of phrase: %d", matrix[numberOfPhrase],numberOfPhrase);
        phrase[strlen(phrase)-1] = '\0';
        strcpy(matrix[numberOfPhrase], phrase);
        // printf("\n%s,\n Number of phrase: %d\n", matrix[numberOfPhrase],numberOfPhrase);
        numberOfPhrase++;
    }

    int i, j;
    for(i=0; i<140; i++){
        printf("Lineeeeee: %s\n",matrix[i]);
        for(j=0; j<140; j++){
            // Se for um número
            if(isdigit(matrix[i][j])){
                // Get full number
                nLeft = 1;
                char fullNumberStr[140];
                memset(fullNumberStr, 0, sizeof(fullNumberStr));
                fullNumberStr[0] = matrix[i][j];

                while(j+nLeft!=140 && isdigit(matrix[i][j+nLeft])){
                    fullNumberStr[nLeft] = matrix[i][j+nLeft];
                    nLeft++;
                }
                printf("Full Number str: %s\n",fullNumberStr);
                fullNumber = atoi(fullNumberStr);

                // For each digit of the number
                for(int k=j; k<j+nLeft; k++){
                    // Check right position
                    if(k!=139){
                        if (!isdigit(matrix[i][k+1]) && matrix[i][k+1] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check left position
                    if(k!=0){
                        if (!isdigit(matrix[i][k-1]) && matrix[i][k-1] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check down position
                    if(i!=139){
                        if (!isdigit(matrix[i+1][k]) && matrix[i+1][k] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check up position
                    if(i!=0){
                        if (!isdigit(matrix[i-1][k]) && matrix[i-1][k] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check up left corner position
                    if(i!=0 && k!=0){
                        if (!isdigit(matrix[i-1][k-1]) && matrix[i-1][k-1] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check up right corner position
                    if(i!=0 && k!=139){
                        if (!isdigit(matrix[i-1][k+1]) && matrix[i-1][k+1] != '.'){
                            printf("\nFOUND ONE! %c k=%d  j=%d\n",matrix[i-1][k+1],k,j);
                            sum += fullNumber;
                            break;
                        }
                    }

                    // Check bottom left corner position
                    if(i!=139 && k!=0){
                        if (!isdigit(matrix[i+1][k-1]) && matrix[i+1][k-1] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }

                     // Check bottom right corner position
                    if(i!=139 && k!=139){
                        if (!isdigit(matrix[i+1][k+1]) && matrix[i+1][k+1] != '.'){
                            printf("\nFOUND ONE!\n");
                            sum += fullNumber;
                            break;
                        }
                    }
                }

                // advance j with the number of digits (nLeft)
                j += nLeft;
                // printf("\nNeW J: %d",j);

                
            }
        }
    }

    printf("\nSummmmmm: %d", sum);

    fclose(fptr);

    return 0;
} 