#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

int main() {
    fptr = fopen("puzzle6_input.txt", "r"); 

    int sum=1;

    int numOfRaces = 1;
    long long int maxTime;
    long long int minDist;

    // Get max Times
    char phrase[220];
    fgets(phrase, 220, fptr);
    char *maxTimeStr = strstr(phrase, ":") + 6;
    printf("Max Time: %s\n",maxTimeStr);

    // Remove spaces
    char *maxTimeState = NULL;
    char maxTimeWithoutSpacesStr[100] = "";

    char *maxTimePtr = strtok_r(maxTimeStr, " ", &maxTimeState);
    while (maxTimePtr != NULL) {
        strcat(maxTimeWithoutSpacesStr, maxTimePtr);

        maxTimePtr = strtok_r(NULL, " ", &maxTimeState);
    }
    char *endTimeptr;
    maxTime = strtoll(maxTimeWithoutSpacesStr, &endTimeptr, 10);
    // maxTime = atoi(maxTimeWithoutSpacesStr);
    printf("Max time: %d\n",maxTime);
    
    // Get min Dists
    fgets(phrase, 220, fptr);
    char *minDistStr = strstr(phrase, ":") + 2;
    printf("Min Dist: %s\n",minDistStr);

    // Remove spaces
    char *minDistState = NULL;
    char minDistWithoutSpacesStr[100] = "";

    char *minDistPtr = strtok_r(minDistStr, " ", &minDistState);
    while (minDistPtr != NULL) {
        strcat(minDistWithoutSpacesStr, minDistPtr);

        minDistPtr = strtok_r(NULL, " ", &minDistState);
    }
    printf("Min dist str: %s\n",minDistWithoutSpacesStr);
    char *endDistptr;
    minDist = strtoll(minDistWithoutSpacesStr, &endDistptr, 10);
    // minDist = atoi(minDistWithoutSpacesStr);
    printf("Min Dist: %lld\n",minDist);

    long long int count = 0;

    for (long long int j = 0; j < maxTime; j++)
    {
        // printf("%d t = %d t x %d speed = %d",j,maxTime-j,j, (maxTime-j)*j);
        if ( (maxTime - j)*j > minDist){
            count++;
        }
    }

    printf("Count: %lld\n",count);

    sum*=count;
    

    printf("\nMultiplication!!! %lld\n",sum);

    fclose(fptr);

    return 0;
}


