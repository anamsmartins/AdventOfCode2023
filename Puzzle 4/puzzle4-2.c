#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *fptr;

int main() {
    //1 - recolher cada game
    fptr = fopen("puzzle4_input.txt", "r"); 

    char phrase[120]; 
    int sum=0;
    int numberOfTheCard=0; // 0 -> 212
    int winningNumbers[10], myNumbers[25];
    int cardNumbers[213];
    

    // Start all the counting at 0
    memset(cardNumbers, 0, sizeof(cardNumbers));

    while (fgets(phrase, 120, fptr)) {
        cardNumbers[numberOfTheCard] +=1;

        char copyPhrase[120];
        strcpy(copyPhrase, phrase);

        // Get the game's winning numbers
        char* winningPhrase = copyPhrase + 10;
        char *winningNumbersStr = strtok(winningPhrase, "|");
        printf("Winning numbers: %s\n",winningNumbersStr);
        memset(winningNumbers, 0, 10);

        char *stateOuter = NULL;
        char *winningNumbersDivided = strtok_r(winningNumbersStr, " ", &stateOuter);
        int i = 0;
        while (winningNumbersDivided != NULL) {
            int wn = atoi(winningNumbersDivided);
            // printf("Wiinning numberrrr: %d, i=%d\n",wn,i);
            winningNumbers[i] = wn;
            i++;
            winningNumbersDivided = strtok_r(NULL, " ", &stateOuter);
        }

        // Get the numbers you have
        char* myPhrase = phrase;
        char *myNumbersStr = strstr(myPhrase, "|") +2;
        printf("My Numbers: %s\n",myNumbersStr);
        memset(myNumbers, 0, 25);

        char *stateOuter2 = NULL;
        char *winningNumbersDivided2 = strtok_r(myNumbersStr, " ", &stateOuter2);
        i = 0;
        while (winningNumbersDivided2 != NULL) {
            int mn = atoi(winningNumbersDivided2);
            // printf("My numberrrr: %d, i=%d\n",mn,i);
            myNumbers[i] = mn;
            i++;
            winningNumbersDivided2 = strtok_r(NULL, " ", &stateOuter2);
        }

        int matchingNumbers = 0;

        // For each my number
        for (int i=0; i<25; i++)
        {
            // verify if is winning number
            for (int j=0; j<10; j++) {
                if (winningNumbers[j] == myNumbers[i]) {
                    // printf("Winning number!! %d\n",myNumbers[i]);
                    matchingNumbers++;
                }
            }
        }

        for (int n=1; n<=matchingNumbers; n++){
            cardNumbers[numberOfTheCard+n] += cardNumbers[numberOfTheCard]*1;
        }

        numberOfTheCard++;
    }

    for(int a=0; a<213; a++){
        printf("Number #%d card: %d\n",a,cardNumbers[a]);
        sum += cardNumbers[a];
    }

    printf("\nSum!!! %d\n",sum);

    fclose(fptr);

    return 0;
}