#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

long long int getDifference(long long int *numbers, int size){
    long long int differences[size-1];

    // printf("Size: %d\n",size-1);
    for (int i = 0; i < size-1; i++)
    {
        // printf("Difference: %lld - %lld = %lld\n",numbers[i+1], numbers[i], numbers[i+1] - numbers[i]);
        differences[i] = numbers[i+1] - numbers[i];
    }

    if (differences[0] == differences[size-2] && differences[0] == differences[size/2]){
        printf("EQUAL: %lld\n",differences[0]);
        return differences[0];
    }

    long long int sum = getDifference(differences, size-1);

    return differences[0] - sum;
}

int main() {
    fptr = fopen("puzzle9_input.txt", "r"); 

    int historyNumber = 21;
    long long int historyNumbers[historyNumber]; 

    long long int sum = 0;

    char history[300];
    int i=0;
    while (fgets(history, 300, fptr))
    {
        i=0;
        if(history[strlen(history)-1] == '\n'){
            history[strlen(history)-1] = '\0';
        }
    
        printf("History: %s\n",history);

        char *stateHistory = NULL;
        char *historyNumberStr = strtok_r(history, " ", &stateHistory);
        
        // Get history's numbers
        while (historyNumberStr != NULL)
        {
            // int number = atoi(historyNumberStr);
            char *historyPtr;
            long long int number = strtoll(historyNumberStr, &historyPtr, 10);
            historyNumbers[i] = number;
            // printf("Number: %lld\n",number);

            i++;
            historyNumberStr = strtok_r(NULL, " ", &stateHistory);
        }

        // Get Prediction
        long long int prediction = historyNumbers[0]-getDifference(historyNumbers, historyNumber);
        
        sum += prediction;
        printf("Prediction: %lld\n",prediction);
    }
    
    printf("SUm: %lld\n",sum);

    fclose(fptr);
}