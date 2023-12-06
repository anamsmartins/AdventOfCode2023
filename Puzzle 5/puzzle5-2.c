#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

long long int calculateValue(long long int value, long long int *arraySrcs, long long int *arrayDsts, long long int *arrayLnts, int size){
    for(int i=0; i<size; i++){
        // printf("Rule: %lld %lld %lld\n",arrayDsts[i],arraySrcs[i], arrayLnts[i]);

        if((arraySrcs[i] <= value) && (value < arraySrcs[i] + arrayLnts[i])){
            // printf("SourceStart %lld <= value %lld <= sourceStart+lenght %lld\n",arraySrcs[i], value, arraySrcs[i]+arrayLnts[i]);
            // printf("New value: %lld\n",arrayDsts[i] + (value - arraySrcs[i]));
            return arrayDsts[i] + (value - arraySrcs[i]); //new value
        }
    }

    return value;
}

void fillArrays(long long int arraySrcs[], long long int arraysDts[], long long int arrayLnts[], FILE** fptr){
    char number[100];
    // printf("Line 1: %s\n",number);
    fgets(number, 100, *fptr); // e.g. seed-to-soil map:
    // printf("Line 2: %s\n",number);

    int i=0;

    while(fgets(number, 100, *fptr) && strcmp(number,"\n") != 0){
        
        // printf("NUmmmm %s\n",number);
        char *stateNumber = NULL;

        // 2.1. Get destination start
        char *destptr;
        char *destinationStartStr =  strtok_r(number, " ", &stateNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);

        // 2.2. Get source start
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);

        // 2.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);

        // printf("Fill: %d %d %d\n",destinationStart,sourceStart, length);
        arraysDts[i] = destinationStart;
        arraySrcs[i] = sourceStart;
        arrayLnts[i] = length;
        i++;
    }
}

int main() {
    fptr = fopen("puzzle5_input.txt", "r"); 

    char phrase[220];
    fgets(phrase, 220, fptr);
    char *seedsStr = strstr(phrase, ":") + 2;
    printf("Initial Numbers: %s\n",seedsStr);

    char number[100];
    fgets(number, 100, fptr); // enter

    int nSoil = 16;
    long long int soilSrcs[nSoil];
    long long int soilDsts[nSoil];
    long long int soilLnts[nSoil];
    fillArrays(soilSrcs, soilDsts, soilLnts, &fptr);
    // for (int i = 0; i < nSoil; i++)
    // {
    //     printf("Soil: %lld %lld %lld\n",soilDsts[i],soilSrcs[i],soilLnts[i]);
    // }
    

    int nFertilizer = 33;
    long long int fertilizerSrcs[nFertilizer];
    long long int fertilizerDsts[nFertilizer];
    long long int fertilizerLnts[nFertilizer];
    fillArrays(fertilizerSrcs, fertilizerDsts, fertilizerLnts, &fptr);
    // for (int i = 0; i < nFertilizer; i++)
    // {
    //     printf("Fertilizer: %lld %lld %lld\n",fertilizerDsts[i],fertilizerSrcs[i],fertilizerLnts[i]);
    // }

    int nWater = 26;
    long long int waterSrcs[nWater];
    long long int waterDsts[nWater];
    long long int waterLnts[nWater];
    fillArrays(waterSrcs, waterDsts, waterLnts, &fptr);
    // for (int i = 0; i < nWater; i++)
    // {
    //     printf("Water: %lld %lld %lld\n",waterDsts[i],waterSrcs[i],waterLnts[i]);
    // }

    int nLight = 38; 
    long long int lightSrcs[nLight];
    long long int lightDsts[nLight];
    long long int lightLnts[nLight];
    fillArrays(lightSrcs, lightDsts, lightLnts, &fptr);
    // for (int i = 0; i < nLight; i++)
    // {
    //     printf("Light: %lld %lld %lld\n",lightDsts[i],lightSrcs[i],lightLnts[i]);
    // }

    int nTemperature = 10;
    long long int temperatureSrcs[nTemperature];
    long long int temperatureDsts[nTemperature];
    long long int temperatureLnts[nTemperature];
    fillArrays(temperatureSrcs, temperatureDsts, temperatureLnts, &fptr);
    // for (int i = 0; i < nTemperature; i++)
    // {
    //     printf("Temperature: %lld %lld %lld\n",temperatureDsts[i],temperatureSrcs[i],temperatureLnts[i]);
    // }

    int nHumidity = 37;
    long long int humiditySrcs[nHumidity];
    long long int humidityDsts[nHumidity];
    long long int humidityLnts[nHumidity];
    fillArrays(humiditySrcs, humidityDsts, humidityLnts, &fptr);
    // for (int i = 0; i < nHumidity; i++)
    // {
    //     printf("Humidity: %lld %lld %lld\n",humidityDsts[i],humiditySrcs[i],humidityLnts[i]);
    // }

    int nLocation = 22;
    long long int locationSrcs[nLocation];
    long long int locationDsts[nLocation];
    long long int locationLnts[nLocation];
    fillArrays(locationSrcs, locationDsts, locationLnts, &fptr);
    // for (int i = 0; i < nLocation; i++)
    // {
    //     printf("Location: %lld %lld %lld\n",locationDsts[i],locationSrcs[i],locationLnts[i]);
    // }

    long long int lowestLocation = __INT64_MAX__;

    char *stateSeeds = NULL;
    char *seedsNumberStr = strtok_r(seedsStr, " ", &stateSeeds);
    while (seedsNumberStr != NULL) {
        // 1.1. Get seed value
        // Place the '\0' in the end
        int seedValueLStrLength = strlen(seedsNumberStr);
        char* seedsValueStrWithEnd = malloc(seedValueLStrLength + 1);
        strcpy(seedsValueStrWithEnd, seedsNumberStr);
        seedsValueStrWithEnd[seedValueLStrLength] = '\0';

        char *endValueptr;
        long long int seedValue = strtoll(seedsValueStrWithEnd, &endValueptr, 10);
        printf("Seed value: %lld\n",seedValue);

        // 1.2. Get seed quantity
        seedsNumberStr = strtok_r(NULL, " ", &stateSeeds); // seed qtd

        // Place the '\0' in the end
        int seedQtdLStrLength = strlen(seedsNumberStr);
        char* seedsQtdStrWithEnd = malloc(seedQtdLStrLength + 1);
        strcpy(seedsQtdStrWithEnd, seedsNumberStr);
        seedsQtdStrWithEnd[seedQtdLStrLength] = '\0';

        char *endqtdptr;
        long long int seedQuantity = strtoll(seedsQtdStrWithEnd, &endqtdptr, 10);
        printf("Seed Quantity: %lld\n",seedQuantity);

        printf("NEW SEED starting at: %lld with quantity: %lld\n",seedValue,seedQuantity);

        for (int v = 0; v < seedQuantity; v++)
        {

            long long int soil = calculateValue(seedValue,soilSrcs,soilDsts,soilLnts,nSoil);
            // printf("soil = %lld\n",soil);
            long long int fertilizer = calculateValue(soil, fertilizerSrcs, fertilizerDsts, fertilizerLnts,nFertilizer);
            // printf("fertilizer = %lld\n",fertilizer);
            long long int water = calculateValue(fertilizer, waterSrcs, waterDsts, waterLnts,nWater);
            // printf("water = %lld\n",water);
            long long int light = calculateValue(water,lightSrcs,lightDsts,lightLnts,nLight);
            // printf("light = %lld\n",light);
            long long int temperature = calculateValue(light,temperatureSrcs, temperatureDsts, temperatureLnts,nTemperature);
            // printf("temperature = %lld\n",temperature);
            long long int humidity = calculateValue(temperature,humiditySrcs,humidityDsts,humidityLnts,nHumidity);
            // printf("humidity = %lld\n",humidity);
            long long int location = calculateValue(humidity,locationSrcs,locationDsts,locationLnts,nLocation);
            // printf("location = %lld\n\n",location);

            if(location < lowestLocation){
                printf("Seed %lld lowest location %lld\n",seedValue, location);
                lowestLocation = location;
            }     
            
            seedValue++;
        }

        seedsNumberStr = strtok_r(NULL, " ", &stateSeeds);
    }

    printf("\nLowest location!!! %lld\n",lowestLocation);

    fclose(fptr);

    return 0;
}