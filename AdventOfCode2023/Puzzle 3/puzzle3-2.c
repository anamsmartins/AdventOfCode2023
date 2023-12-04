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

    char matrix[140][141];
    int nLeft, nLeftSecond;
    // char* fullNumberstr;
    int fullNumber, fullSecondNumber;

    memset(phrase, 0, sizeof(phrase));
    // 1. Preencher a matriz
    while (fgets(phrase, sizeof(phrase), fptr) && numberOfPhrase<142) {
        phrase[strlen(phrase)] = '\0';
        strcpy(matrix[numberOfPhrase], phrase);
        // printf("\n%s,\n Number of phrase: %d\n", matrix[numberOfPhrase],numberOfPhrase);
        memset(phrase, 0, sizeof(phrase));
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
                        if (matrix[i][k+1] == '*'){
                            printf("\nFOUND *!\n");

                            int l = k+1;
                            // * position: [i][l]

                            // Check right position 124*abc
                            if(l!=139){
                                if(isdigit(matrix[i][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i][l+1];

                                    while(l+1+nLeftSecond!=140 && isdigit(matrix[i][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            // Check left position abc*124
                            // if(l!=0){
                            //     if(isdigit(matrix[i][l-1])) {
                            //         // Get full number
                            //         nLeftSecond = 2;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i][l-1];

                                    // while(l-nLeftSecond!=-1 && isdigit(matrix[i][l-nLeftSecond])){
                                    //     for(int m = nLeftSecond-1; m > -1; m--){
                                    //         // 0 -> 1; 1 -> 2
                                    //         // m = 1
                                    //         fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                    //     } 
                                    //     fullSecondNumberStr[0] = matrix[i][l-nLeftSecond];
                                    //     nLeftSecond++;
                                    // }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // Check up left corner position 
                            // if(i!=0 && l!=0){
                            //     if(isdigit(matrix[i-1][l-1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l-1];
                                    
                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l-1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l-1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }

                            //         int nRemove = nLeftSecond;
                            //         while(l-1-nRemove!=-1 && isdigit(matrix[i-1][l-1-nRemove])){
                            //             for(int m = nRemove-1; m > -1; m--){
                            //                 // 0 -> 1; 1 -> 2
                            //                 // m = 1
                            //                 fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                            //             } 
                            //             fullSecondNumberStr[0] = matrix[i-1][l-1-nRemove];
                            //             nRemove++;
                            //         }

                                    
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up position 
                            // if(i!=0){
                            //     if(isdigit(matrix[i-1][l])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up right corner position 
                            // if(i!=0 && l!=139){
                            //     if(isdigit(matrix[i-1][l+1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l+1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // Check down left corner position 
                            if(i!=139 && l!=0){
                                if(isdigit(matrix[i+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l-1];

                                    while(l-1+nLeftSecond!=140 && isdigit(matrix[i+1][l-1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l-1+nLeftSecond];
                                        nLeftSecond++;
                                    }

                                    int nRemove;
                                    if (nLeftSecond == 2){
                                        nRemove = nLeftSecond-1;
                                    }else{
                                        nRemove = nLeftSecond;
                                    }
                                    while(l-1-nRemove!=-1 && isdigit(matrix[i+1][l-1-nRemove])){
                                        for(int m = nRemove+1; m > -1; m--){
                                            // 0 -> 1; 1 -> 2
                                            // m = 1
                                            fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                        } 
                                        fullSecondNumberStr[0] = matrix[i+1][l-1-nRemove];
                                        nRemove++;
                                    }

                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down position 
                            if(i!=139){
                                if(isdigit(matrix[i+1][l])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1][l+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down right corner position 
                            if(i!=139 && l!=139){
                                if(isdigit(matrix[i+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l+1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                        }
                    }

                    // Check left position
                    if(k!=0){
                        if (matrix[i][k-1] == '*'){
                            printf("\nFOUND ONE!\n");

                            int l = k-1;
                    //         // * position: [i][l]

                    //         // Check right position 124*abc
                    //         // if(l!=139){
                    //         //     if(isdigit(matrix[i][l+1])) {
                    //         //         // Get full number
                    //         //         nLeftSecond = 1;
                    //         //         char fullSecondNumberStr[140];
                    //         //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                    //         //         fullSecondNumberStr[0] = matrix[i][l+1];

                    //         //         while(l+nLeftSecond!=140 && isdigit(matrix[i][l+1+nLeftSecond])){
                    //         //             fullSecondNumberStr[nLeftSecond-1] = matrix[i][l+1+nLeftSecond];
                    //         //             nLeftSecond++;
                    //         //         }
                    //         //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                    //         //         fullSecondNumber = atoi(fullSecondNumberStr);

                    //         //         sum += fullNumber * fullSecondNumber;
                    //         //         break;
                    //         //     }
                    //         // }
                            
                    //         // Check left position abc*124
                    //         if(l!=0){
                    //             if(isdigit(matrix[i][l-1])) {
                    //                 // Get full number
                    //                 nLeftSecond = 2;
                    //                 char fullSecondNumberStr[140];
                    //                 memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                    //                 fullSecondNumberStr[0] = matrix[i][l-1];

                    //                 while(l-nLeftSecond!=-1 && isdigit(matrix[i][l-nLeftSecond])){
                    //                     for(int m = nLeftSecond-1; m > -1; m--){
                    //                         // 0 -> 1; 1 -> 2
                    //                         // m = 1
                    //                         fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                    //                     } 
                    //                     fullSecondNumberStr[0] = matrix[i][l-nLeftSecond];
                    //                     nLeftSecond++;
                    //                 }
                    //                 printf("Full Second Number str: %s\n",fullSecondNumberStr);
                    //                 fullSecondNumber = atoi(fullSecondNumberStr);

                    //                 sum += fullNumber * fullSecondNumber;
                    //                 break;
                    //             }
                    //         }

                    //         // Check up left corner position 
                    //         // if(i!=0 && l!=0){
                    //         //     if(isdigit(matrix[i-1][l-1])) {
                    //         //         // Get full number
                    //         //         nLeftSecond = 1;
                    //         //         char fullSecondNumberStr[140];
                    //         //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                    //         //         fullSecondNumberStr[0] = matrix[i-1][l-1];

                    //         //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l-1+nLeftSecond])){
                    //         //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l-1+nLeftSecond];
                    //         //             nLeftSecond++;
                    //         //         }

                    //         //         int nRemove = nLeftSecond;
                    //         //         while(l-1-nRemove!=-1 && isdigit(matrix[i-1][l-1-nRemove])){
                    //         //             for(int m = nRemove-1; m > -1; m--){
                    //         //                 // 0 -> 1; 1 -> 2
                    //         //                 // m = 1
                    //         //                 fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                    //         //             } 
                    //         //             fullSecondNumberStr[0] = matrix[i-1][l-1-nRemove];
                    //         //             nRemove++;
                    //         //         }

                    //         //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                    //         //         fullSecondNumber = atoi(fullSecondNumberStr);

                    //         //         sum += fullNumber * fullSecondNumber;
                    //         //         break;
                    //         //     }
                    //         // }

                    //         // // Check up position 
                    //         // if(i!=0){
                    //         //     if(isdigit(matrix[i-1][l])) {
                    //         //         // Get full number
                    //         //         nLeftSecond = 1;
                    //         //         char fullSecondNumberStr[140];
                    //         //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                    //         //         fullSecondNumberStr[0] = matrix[i-1][l];

                    //         //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+nLeftSecond])){
                    //         //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+nLeftSecond];
                    //         //             nLeftSecond++;
                    //         //         }
                    //         //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                    //         //         fullSecondNumber = atoi(fullSecondNumberStr);

                    //         //         sum += fullNumber * fullSecondNumber;
                    //         //         break;
                    //         //     }
                    //         // }

                    //         // // Check up right corner position 
                    //         // if(i!=0 && l!=139){
                    //         //     if(isdigit(matrix[i-1][l+1])) {
                    //         //         // Get full number
                    //         //         nLeftSecond = 1;
                    //         //         char fullSecondNumberStr[140];
                    //         //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                    //         //         fullSecondNumberStr[0] = matrix[i-1][l+1];

                    //         //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+1+nLeftSecond])){
                    //         //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+1+nLeftSecond];
                    //         //             nLeftSecond++;
                    //         //         }
                    //         //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                    //         //         fullSecondNumber = atoi(fullSecondNumberStr);

                    //         //         sum += fullNumber * fullSecondNumber;
                    //         //         break;
                    //         //     }
                    //         // }

                            // Check down left corner position 
                            if(i!=139 && l!=0){
                                if(isdigit(matrix[i+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l-1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1][l-1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l-1+nLeftSecond];
                                        nLeftSecond++;
                                    }

                                    if(isdigit(matrix[i+1][l-1-1])){
                                        int nRemove;
                                        if (nLeftSecond == 2){
                                            nRemove = nLeftSecond-1;
                                        }else{
                                            nRemove = nLeftSecond;
                                        }
                                        while(l-1-nRemove!=-1 && isdigit(matrix[i+1][l-1-nRemove])){
                                            for(int m = nRemove+1; m > -1; m--){
                                                // 0 -> 1; 1 -> 2
                                                // m = 1
                                                fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                            } 
                                            fullSecondNumberStr[0] = matrix[i+1][l-1-nRemove];
                                            nRemove++;
                                        }
                                    }

                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down position 
                            if(i!=139){
                                if(isdigit(matrix[i+1][l])) {
                                    printf("HEREEEE\n");
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1][l+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down right corner position 
                            if(i!=139 && l!=139){
                                if(isdigit(matrix[i+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l+1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            
                        }
                    }

                    // Check up right corner position
                    if(i!=0 && k!=139){
                        if (matrix[i-1][k+1] == '*'){
                            printf("\nFOUND ONE!\n");

                            int l = k+1;

                            if(matrix[i][l] == '.' && isdigit(matrix[i][l+1])){
                               
                                // Get full number
                                nLeftSecond = 1;
                                char fullSecondNumberStr[140];
                                memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                fullSecondNumberStr[0] = matrix[i][l+1];

                                while(l+nLeftSecond!=140 && isdigit(matrix[i][l+1+nLeftSecond])){
                                    fullSecondNumberStr[nLeftSecond] = matrix[i][l+1+nLeftSecond];
                                    nLeftSecond++;
                                }
                                printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                fullSecondNumber = atoi(fullSecondNumberStr);

                                sum += (fullNumber * fullSecondNumber);
                                break;
                            }
                        }
                    }

                    // Check down position
                    if(i!=139){
                        if (matrix[i+1][k] == '*'){
                            printf("\nFOUND ONE!\n");
                            
                            int l = k;
                            // * position: [i][l]

                            // Check right position 124*abc
                            if(l!=139){
                                if(isdigit(matrix[i+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l+1];

                                    while(l+1+nLeftSecond!=140 && isdigit(matrix[i+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            // Check left position abc*124
                            if(l!=0){
                                if(isdigit(matrix[i+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 2;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l-1];

                                    while(l-nLeftSecond!=-1 && isdigit(matrix[i+1][l-nLeftSecond])){
                                        for(int m = nLeftSecond-1; m > -1; m--){
                                            // 0 -> 1; 1 -> 2
                                            // m = 1
                                            fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                        } 
                                        fullSecondNumberStr[0] = matrix[i+1][l-nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check up left corner position 
                            // if(i!=0 && l!=0){
                            //     if(isdigit(matrix[i-1][l-1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l-1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l-1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l-1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up position 
                            // if(i!=0){
                            //     if(isdigit(matrix[i-1][l])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up right corner position 
                            // if(i!=0 && l!=139){
                            //     if(isdigit(matrix[i-1][l+1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l+1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // Check down left corner position 
                            if(i!=139 && l!=0){
                                if(isdigit(matrix[i+1+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l-1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l-1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l-1+nLeftSecond];
                                        nLeftSecond++;
                                    }

                                    if(isdigit(matrix[i+1+1][l-1-1])){
                                        int nRemove;
                                        if (nLeftSecond == 2){
                                            nRemove = nLeftSecond-1;
                                        }else{
                                            nRemove = nLeftSecond;
                                        }
                                        while(l-1-nRemove!=-1 && isdigit(matrix[i+1+1][l-1-nRemove])){
                                            for(int m = nRemove+1; m > -1; m--){
                                                // 0 -> 1; 1 -> 2
                                                // m = 1
                                                fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                            } 
                                            fullSecondNumberStr[0] = matrix[i+1+1][l-1-nRemove];
                                            nRemove++;
                                        }
                                    }

                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down position 
                            if(i!=139){
                                if(isdigit(matrix[i+1+1][l])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down right corner position 
                            if(i!=139 && l!=139){
                                if(isdigit(matrix[i+1+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l+1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                        }
                    }

                    
                    // Check bottom left corner position
                    if(i!=139 && k!=0){
                        if (matrix[i+1][k-1] == '*'){
                            printf("\nFOUND ONE!\n");
                            
                            int l = k-1;
                            // * position: [i][l]

                            // Check right position 124*abc
                            if(l!=139){
                                if(isdigit(matrix[i+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l+1];

                                    while(l+1+nLeftSecond!=140 && isdigit(matrix[i+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            // Check left position abc*124
                            if(l!=0){
                                if(isdigit(matrix[i+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 2;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l-1];

                                    while(l-nLeftSecond!=-1 && isdigit(matrix[i+1][l-nLeftSecond])){
                                        for(int m = nLeftSecond-1; m > -1; m--){
                                            // 0 -> 1; 1 -> 2
                                            // m = 1
                                            fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                        } 
                                        fullSecondNumberStr[0] = matrix[i+1][l-nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check up left corner position 
                            // if(i!=0 && l!=0){
                            //     if(isdigit(matrix[i-1][l-1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l-1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l-1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l-1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up position 
                            // if(i!=0){
                            //     if(isdigit(matrix[i-1][l])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up right corner position 
                            // if(i!=0 && l!=139){
                            //     if(isdigit(matrix[i-1][l+1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l+1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // Check down left corner position 
                            if(i!=139 && l!=0){
                                if(isdigit(matrix[i+1+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l-1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l-1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l-1+nLeftSecond];
                                        nLeftSecond++;
                                    }

                                    if(isdigit(matrix[i+1+1][l-1-1])){
                                        int nRemove;
                                        if (nLeftSecond == 2){
                                            nRemove = nLeftSecond-1;
                                        }else{
                                            nRemove = nLeftSecond;
                                        }
                                        while(l-1-nRemove!=-1 && isdigit(matrix[i+1+1][l-1-nRemove])){
                                            for(int m = nRemove+1; m > -1; m--){
                                                // 0 -> 1; 1 -> 2
                                                // m = 1
                                                fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                            } 
                                            fullSecondNumberStr[0] = matrix[i+1+1][l-1-nRemove];
                                            nRemove++;
                                        }
                                    }

                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down position 
                            if(i!=139){
                                if(isdigit(matrix[i+1+1][l])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down right corner position 
                            if(i!=139 && l!=139){
                                if(isdigit(matrix[i+1+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l+1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            
                        }
                    }

                     // Check bottom right corner position
                    if(i!=139 && k!=139){
                        if (matrix[i+1][k+1] == '*'){
                            printf("\nFOUND ONE AHHH!\n");
                            
                            int l = k+1;
                            // * position: [i][l]

                            // Check right position 124*abc
                            if(l!=139){
                                if(isdigit(matrix[i+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l+1];

                                    while(l+1+nLeftSecond!=140 && isdigit(matrix[i+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
                            // Check left position abc*124
                            if(l!=0){
                                if(isdigit(matrix[i+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 2;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1][l-1];

                                    while(l-nLeftSecond!=-1 && isdigit(matrix[i+1][l-nLeftSecond])){
                                        for(int m = nLeftSecond-1; m > -1; m--){
                                            // 0 -> 1; 1 -> 2
                                            // m = 1
                                            fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                        } 
                                        fullSecondNumberStr[0] = matrix[i+1][l-nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check up left corner position 
                            // if(i!=0 && l!=0){
                            //     if(isdigit(matrix[i-1][l-1])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l-1];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l-1+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l-1+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // // Check up position 
                            // if(i!=0){
                            //     if(isdigit(matrix[i-1][l])) {
                            //         // Get full number
                            //         nLeftSecond = 1;
                            //         char fullSecondNumberStr[140];
                            //         memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                            //         fullSecondNumberStr[0] = matrix[i-1][l];

                            //         while(l+nLeftSecond!=140 && isdigit(matrix[i-1][l+nLeftSecond])){
                            //             fullSecondNumberStr[nLeftSecond] = matrix[i-1][l+nLeftSecond];
                            //             nLeftSecond++;
                            //         }
                            //         printf("Full Second Number str: %s\n",fullSecondNumberStr);
                            //         fullSecondNumber = atoi(fullSecondNumberStr);

                            //         sum += fullNumber * fullSecondNumber;
                            //         break;
                            //     }
                            // }

                            // Check up right corner position 
                            if(i!=0 && l!=139){
                                
                                if(isdigit(matrix[i][l+1]) && !isdigit(matrix[i][l])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i][l+1];

                                    while(l+1+nLeftSecond!=140 && isdigit(matrix[i][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down left corner position 
                            if(i!=139 && l!=0){
                                if(isdigit(matrix[i+1+1][l-1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l-1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l-1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l-1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    
                                    if(isdigit(matrix[i+1+1][l-1-1])){
                                        int nRemove;
                                        if (nLeftSecond == 2){
                                            nRemove = nLeftSecond-1;
                                        }else{
                                            nRemove = nLeftSecond;
                                        }
                                        while(l-1-nRemove!=-1 && isdigit(matrix[i+1+1][l-1-nRemove])){
                                            for(int m = nRemove+1; m > -1; m--){
                                                // 0 -> 1; 1 -> 2
                                                // m = 1
                                                fullSecondNumberStr[m] = fullSecondNumberStr[m-1];
                                            } 
                                            fullSecondNumberStr[0] = matrix[i+1+1][l-1-nRemove];
                                            nRemove++;
                                        }
                                    }

                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down position 
                            if(i!=139){
                                if(isdigit(matrix[i+1+1][l])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }

                            // Check down right corner position 
                            if(i!=139 && l!=139){
                                if(isdigit(matrix[i+1+1][l+1])) {
                                    // Get full number
                                    nLeftSecond = 1;
                                    char fullSecondNumberStr[140];
                                    memset(fullSecondNumberStr, 0, sizeof(fullSecondNumberStr));
                                    fullSecondNumberStr[0] = matrix[i+1+1][l+1];

                                    while(l+nLeftSecond!=140 && isdigit(matrix[i+1+1][l+1+nLeftSecond])){
                                        fullSecondNumberStr[nLeftSecond] = matrix[i+1+1][l+1+nLeftSecond];
                                        nLeftSecond++;
                                    }
                                    printf("Full Second Number str: %s\n",fullSecondNumberStr);
                                    fullSecondNumber = atoi(fullSecondNumberStr);

                                    sum += fullNumber * fullSecondNumber;
                                    break;
                                }
                            }
                            
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