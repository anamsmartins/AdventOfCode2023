#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

struct Hand {
    char cards[6];
    int bidding;
    int handValues[13]; // 2 3 4 5 6 7 8 9 T J K Q A
    int type; // 0K 2K 2K2K 3K 3K2K 4K 5K | 0 -> 6
};

int compareHands(const void *a, const void *b) {
    struct Hand *handA = (struct Hand *)a;
    struct Hand *handB = (struct Hand *)b;

    // First, compare by type
    if (handA->type != handB->type) {
        return handA->type - handB->type;
    }

    // If types are equal, compare by handOrdered value
    char order[] = "J23456789TQKA";

    for (int i = 0; i < 5; i++) {

        int index1 = strchr(order, handA->cards[i]) - order;
        int index2 = strchr(order, handB->cards[i]) - order;

        // Compare the positions
        if (index1 < index2) {
            return -1;
        } else if (index1 > index2) {
            return 1;
        }
    }
}

int main() {
    fptr = fopen("puzzle7_input.txt", "r"); 

    int handsNumber = 0;
    int cardsPerHand = 5;
    
    struct Hand *hands = (struct Hand *)malloc(sizeof(struct Hand));
    memset(hands[0].handValues, 0 , sizeof(hands[0].handValues));

    // Get Hands, Biddings and Types
    char phrase[20];
    char phraseCopy[20];
    while(fgets(phrase, 20, fptr)){
        strcpy(phraseCopy, phrase);
        
        strcpy(hands[handsNumber].cards, strtok(phraseCopy, " "));

        int min_index = 0;
        // Calculate the hand type
        for (int card = 0; card<cardsPerHand; card++){
            if (isdigit(hands[handsNumber].cards[card]))
            {
                int digit = hands[handsNumber].cards[card] - '0';
                // printf("CARD: %c is digit, handValues[%d] +=1\n",hands[handsNumber][card],digit-2);
                hands[handsNumber].handValues[digit-1] += 1;
            } else if (hands[handsNumber].cards[card] == 'T'){
                hands[handsNumber].handValues[9] += 1;
            } else if (hands[handsNumber].cards[card] == 'J'){
                hands[handsNumber].handValues[0] += 1;
            } else if (hands[handsNumber].cards[card] == 'Q'){
                hands[handsNumber].handValues[10] += 1;
            } else if (hands[handsNumber].cards[card] == 'K'){
                hands[handsNumber].handValues[11] += 1;
            } else if (hands[handsNumber].cards[card] == 'A'){
                hands[handsNumber].handValues[12] += 1;
            }    
        }
        
        // handValues = 2 3 4 5 6 7 8 9 T J Q K A
        // type: 0 (0K); 1 (2K); 2 (2K2K); 3 (3K); 4 (3K2K); 5 (4K); 6 (5K)
        int maxValue = 0; // 0 - 5 
        int count = 0; // 0 - 5
        int maxIndex = 0;

        for (int card = 0; card < 13; card++){   //  0 - 12
            if(hands[handsNumber].handValues[card] >= maxValue){
                maxValue = hands[handsNumber].handValues[card];
                maxIndex = card;
                printf("max value! %d max Index! %d\n",maxValue,maxIndex);
            }
            if (hands[handsNumber].handValues[card] != 0){
                count++;
            }
        }

        printf("Max index: %d\n",maxIndex);
        
        // Attribute the J value
        if(hands[handsNumber].handValues[0] != 0){
            if(maxIndex != 0){
                hands[handsNumber].handValues[maxIndex] += hands[handsNumber].handValues[0];
                if(hands[handsNumber].handValues[maxIndex] > maxValue){
                    maxValue = hands[handsNumber].handValues[maxIndex];
                }
                hands[handsNumber].handValues[0] = 0;
                count -= 1;
                printf("Max value %d count %d\n",maxValue,count);
            }else{
                if(hands[handsNumber].handValues[0] == 5){
                    hands[handsNumber].handValues[12] += 5;
                    hands[handsNumber].handValues[0] = 0;
                } else {
                    // get strongest card
                    int strongestCard = 0;
                    for (int f = 1; f<13; f++){
                        if (hands[handsNumber].handValues[f] !=0 ){
                            strongestCard = f;
                        }
                    } 

                    // J value
                    hands[handsNumber].handValues[strongestCard] += hands[handsNumber].handValues[0];
                    if(hands[handsNumber].handValues[strongestCard] > maxValue){
                        maxValue = hands[handsNumber].handValues[strongestCard];
                    }
                    hands[handsNumber].handValues[0] = 0;
                    count -= 1;
                    printf("Max value %d count %d\n",maxValue,count);
                }
            }
        }

        if (count == 5){ // 1 1 1 1 1 - 0K
            hands[handsNumber].type = 0;    
        } else if (count == 4){ // 2 1 1 1 - 2K
            hands[handsNumber].type = 1;
        } else if (count == 3){ 
            if (maxValue == 2) { // 2 2 1 - 2K2K
                hands[handsNumber].type = 2;
            } else { // 3 1 1 - 3K
                hands[handsNumber].type = 3;
            }
        } else if (count == 2) {
            if (maxValue == 3){ // 3 2 - 2K3K
                hands[handsNumber].type = 4;
            } else { // 4 1 - 4K
                hands[handsNumber].type = 5;
            }
        } else { // 5 - 5K
            hands[handsNumber].type = 6;
        }

        hands[handsNumber].bidding = atoi(strstr(phrase, " "));
        
        printf("Hand: %s Bidding: %d Type: %d\n",hands[handsNumber].cards,hands[handsNumber].bidding, hands[handsNumber].type);
        handsNumber++;
        hands = realloc(hands, (handsNumber+1)*sizeof(*hands));
        memset(hands[handsNumber].handValues, 0 , sizeof(hands[handsNumber].handValues));

    }

    qsort(hands, handsNumber, sizeof(hands[0]), compareHands);

    int sum = 0;
    for (int i = 0; i < handsNumber; i++)
    {
        sum += hands[i].bidding * (i+1);
        printf("Hand Ordered: %s bidding: %d type: %d rank: %d\n",hands[i].cards,hands[i].bidding,hands[i].type,i);
    }

    printf("Summmm!! %d\n",sum);

    fclose(fptr);

    return 0;
}


