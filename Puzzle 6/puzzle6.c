#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

int main() {
    fptr = fopen("puzzle6_input.txt", "r"); 

    int sum=1;

    int numOfRaces = 4;
    int maxTimes[numOfRaces];
    int minDists[numOfRaces];

    // Get max Times
    char phrase[220];
    fgets(phrase, 220, fptr);
    char *maxTimesStr = strstr(phrase, ":") + 6;
    printf("Max Times: %s\n",maxTimesStr);

    char *stateTimes = NULL;
    char *maxTimeStr = strtok_r(maxTimesStr, " ", &stateTimes);
    
    int i=0;
    while(maxTimeStr != NULL){
        maxTimes[i] = atoi(maxTimeStr);

        maxTimeStr = strtok_r(NULL, " ", &stateTimes);
        i++;
    }

    // Get min Dists
    fgets(phrase, 220, fptr);
    char *minDistsStr = strstr(phrase, ":") + 2;
    printf("Min Dists: %s\n",minDistsStr);

    char *stateDists = NULL;
    char *minDistStr = strtok_r(minDistsStr, " ", &stateDists);

    i=0;
    while(minDistStr != NULL){
        minDists[i] = atoi(minDistStr);

        minDistStr = strtok_r(NULL, " ", &stateDists);
        i++;
    }

    for (int nRace = 0; nRace < numOfRaces; nRace++){
        int maxTime = maxTimes[nRace];
        int minDist = minDists[nRace];
        int count = 0;

        printf("Max time: %d Min dist: %d\n",maxTime,minDist);

        for (int j = 0; j < maxTime; j++)
        {
            // printf("%d t = %d t x %d speed = %d",j,maxTime-j,j, (maxTime-j)*j);
            if ( (maxTime - j)*j > minDist){
                count++;
            }
        }

        printf("Count: %d\n",count);

        sum*=count;
    }
    

    printf("\nMultiplication!!! %d\n",sum);

    fclose(fptr);

    return 0;
}


