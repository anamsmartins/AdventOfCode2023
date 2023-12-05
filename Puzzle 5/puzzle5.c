#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

int main() {
    fptr = fopen("puzzle5_input.txt", "r"); 

    int initialSeedsNumber = 20;
    long long int seedsNumbers[initialSeedsNumber];
    long long int soilNumbers[initialSeedsNumber];
    long long int fertilizerNumbers[initialSeedsNumber];
    long long int waterNumbers[initialSeedsNumber];
    long long int lightNumbers[initialSeedsNumber];
    long long int temperatureNumbers[initialSeedsNumber];
    long long int humidityNumbers[initialSeedsNumber];
    long long int locationNumbers[initialSeedsNumber];

    char phrase[220];

    fgets(phrase, 220, fptr);
    char *seedsStr = strstr(phrase, ":") + 2;
    printf("Initial Numbers: %s\n",seedsStr);
    
    char *stateSeeds = NULL;
    char *seedsNumberStr = strtok_r(seedsStr, " ", &stateSeeds);
    int i=0;

    // 1. Initialize all arrays (seeds, soil, fertilizer, water, light, temperature, humidity, and location)
    while (seedsNumberStr != NULL) {
        // Place the '\0' in the end
        int seedLStrLength = strlen(seedsNumberStr);
        char* seedsNumberStrWithEnd = malloc(seedLStrLength + 1);
        strcpy(seedsNumberStrWithEnd, seedsNumberStr);
        seedsNumberStrWithEnd[seedLStrLength] = '\0';
        
        // printf("Seed number string: %s a\n",seedsNumberStrWithEnd);
        char *endptr;
        long long int seedNumber = strtoll(seedsNumberStrWithEnd, &endptr, 10);

        // printf("Number: i=%d ; %lld\n",i,seedNumber);

        seedsNumbers[i] = seedNumber;
        // printf("Seed number ; %lld\n",seedsNumbers[i]);
        soilNumbers[i] = seedNumber;
        fertilizerNumbers[i] = seedNumber;
        waterNumbers[i] = seedNumber;
        lightNumbers[i] = seedNumber;
        temperatureNumbers[i] = seedNumber;
        humidityNumbers[i] = seedNumber;
        locationNumbers[i] = seedNumber;

        i++;
        seedsNumberStr = strtok_r(NULL, " ", &stateSeeds);
    }

    // 2. Get the soil numbers
    char soilNumber[100];
    fgets(soilNumber, 100, fptr); // enter
    fgets(soilNumber, 100, fptr); // seed-to-soil map:

    while(fgets(soilNumber, 100, fptr) && strcmp(soilNumber,"\n") != 0){
        printf("\nSoil strucutre: %s",soilNumber);

        char *stateSoilNumber = NULL;

        // 2.1. Get destination start aka soil number
        char *destptr;
        char *destinationStartStr =  strtok_r(soilNumber, " ", &stateSoilNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 2.2. Get source start aka seed
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateSoilNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 2.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateSoilNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 2.4. iterate through all initial seeds to see if it is necesary
        for (int seed = 0; seed < initialSeedsNumber; seed++)
        {
            long long int seedValue = seedsNumbers[seed];
            if((sourceStart <= seedValue) && (seedValue <= sourceStart + length)){
                printf("SourceStart %lld <= seedValue %lld <= sourceStart+lenght %lld\n",sourceStart, seedValue, sourceStart+length);
                soilNumbers[seed] = destinationStart + (seedValue - sourceStart);
                printf("Solid number seed = %lld\n", soilNumbers[seed]);
                fertilizerNumbers[seed] = soilNumbers[seed];
                waterNumbers[seed] = soilNumbers[seed];
                lightNumbers[seed] = soilNumbers[seed];
                temperatureNumbers[seed] = soilNumbers[seed];
                humidityNumbers[seed] = soilNumbers[seed];
                locationNumbers[seed] = soilNumbers[seed];
            }
        }
    }

    // 3. Get the fertilizer numbers
    char fertilizerNumber[100];
    fgets(fertilizerNumber, 100, fptr); // soil-to-fertilizer map:

    while(fgets(fertilizerNumber, 100, fptr) && strcmp(fertilizerNumber,"\n") != 0){
        printf("\nFertilizer strucutre: %s",fertilizerNumber);

        char *stateFertilizerNumber = NULL;

        // 3.1. Get destination start aka fertilizer number
        char *destptr;
        char *destinationStartStr =  strtok_r(fertilizerNumber, " ", &stateFertilizerNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 3.2. Get source start aka soil number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateFertilizerNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 3.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateFertilizerNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 3.4. iterate through all soil numbers to see if it is necesary
        for (int soil = 0; soil < initialSeedsNumber; soil++)
        {
            long long int soilValue = soilNumbers[soil];
            if((sourceStart <= soilValue) && (soilValue <= sourceStart + length)){
                printf("SourceStart %lld <= soilValue %lld <= sourceStart+lenght %lld\n",sourceStart, soilValue, sourceStart+length);
                fertilizerNumbers[soil] = destinationStart + (soilValue - sourceStart);
                printf("Fertelizer number soil = %lld\n", fertilizerNumbers[soil]);

                waterNumbers[soil] = fertilizerNumbers[soil];
                lightNumbers[soil] = fertilizerNumbers[soil];
                temperatureNumbers[soil] = fertilizerNumbers[soil];
                humidityNumbers[soil] = fertilizerNumbers[soil];
                locationNumbers[soil] = fertilizerNumbers[soil];
            }
        }
    }
    
    // 4. Get the water numbers
    char waterNumber[100];
    fgets(waterNumber, 100, fptr); // fertilizer-to-water map:

    while(fgets(waterNumber, 100, fptr) && strcmp(waterNumber,"\n") != 0){
        printf("\nWater number strucutre: %s",waterNumber);

        char *stateWaterNumber = NULL;

        // 4.1. Get destination start aka water number
        char *destptr;
        char *destinationStartStr =  strtok_r(waterNumber, " ", &stateWaterNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 4.2. Get source start aka fertilizer number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateWaterNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 4.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateWaterNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 4.4. iterate through all fertilizer numbers to see if it is necesary
        for (int fertilizer = 0; fertilizer < initialSeedsNumber; fertilizer++)
        {
            long long int fertilizerValue = fertilizerNumbers[fertilizer];
            if((sourceStart <= fertilizerValue) && (fertilizerValue <= sourceStart + length)){
                printf("SourceStart %lld <= fertilizerValue %lld <= sourceStart+lenght %lld\n",sourceStart, fertilizerValue, sourceStart+length);
                waterNumbers[fertilizer] = destinationStart + (fertilizerValue - sourceStart);
                printf("Water number fertilizer = %lld\n", waterNumbers[fertilizer]);

                lightNumbers[fertilizer] = waterNumbers[fertilizer];
                temperatureNumbers[fertilizer] = waterNumbers[fertilizer];
                humidityNumbers[fertilizer] = waterNumbers[fertilizer];
                locationNumbers[fertilizer] = waterNumbers[fertilizer];
            }
        }
    }
    
    // 5. Get the light numbers
    char lightNumber[100];
    fgets(lightNumber, 100, fptr); // water-to-light map:

    while(fgets(lightNumber, 100, fptr) && strcmp(lightNumber,"\n") != 0){
        printf("\nLight number strucutre: %s",lightNumber);

        char *stateLightNumber = NULL;

        // 5.1. Get destination start aka light number
        char *destptr;
        char *destinationStartStr =  strtok_r(lightNumber, " ", &stateLightNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 5.2. Get source start aka water number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateLightNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 5.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateLightNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 5.4. iterate through all water numbers to see if it is necesary
        for (int water = 0; water < initialSeedsNumber; water++)
        {
            long long int waterValue = waterNumbers[water];
            if((sourceStart <= waterValue) && (waterValue <= sourceStart + length)){
                printf("SourceStart %lld <= waterValue %lld <= sourceStart+lenght %lld\n",sourceStart, waterValue, sourceStart+length);
                lightNumbers[water] = destinationStart + (waterValue - sourceStart);
                printf("Light number water = %lld\n", lightNumbers[water]);

                temperatureNumbers[water] = lightNumbers[water];
                humidityNumbers[water] = lightNumbers[water];
                locationNumbers[water] = lightNumbers[water];
            }
        }
    }
    
    // 6. Get the temperature numbers
    char temperatureNumber[100];
    fgets(temperatureNumber, 100, fptr); // light-to-temperature map:

    while(fgets(temperatureNumber, 100, fptr) && strcmp(temperatureNumber,"\n") != 0){
        printf("\nTemperature number strucutre: %s",temperatureNumber);

        char *stateTemperatureNumber = NULL;

        // 6.1. Get destination start aka temperature number
        char *destptr;
        char *destinationStartStr =  strtok_r(temperatureNumber, " ", &stateTemperatureNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 6.2. Get source start aka light number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateTemperatureNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 6.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateTemperatureNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 6.4. iterate through all light numbers to see if it is necesary
        for (int light = 0; light < initialSeedsNumber; light++)
        {
            long long int lightValue = lightNumbers[light];
            if((sourceStart <= lightValue) && (lightValue <= sourceStart + length)){
                printf("SourceStart %lld <= lightValue %lld <= sourceStart+lenght %lld\n",sourceStart, lightValue, sourceStart+length);
                temperatureNumbers[light] = destinationStart + (lightValue - sourceStart);
                printf("Temperature number light = %lld\n", temperatureNumbers[light]);

                humidityNumbers[light] = temperatureNumbers[light];
                locationNumbers[light] = temperatureNumbers[light];
            }
        }
    }
    
    // 7. Get the humidity numbers
    char humidityNumber[100];
    fgets(humidityNumber, 100, fptr); // temperature-to-humidity map:

    while(fgets(humidityNumber, 100, fptr) && strcmp(humidityNumber,"\n") != 0){
        printf("\nHumidity number strucutre: %s",humidityNumber);

        char *stateHumidityNumber = NULL;

        // 7.1. Get destination start aka humidity number
        char *destptr;
        char *destinationStartStr =  strtok_r(humidityNumber, " ", &stateHumidityNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 7.2. Get source start aka temperature number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateHumidityNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 7.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateHumidityNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 7.4. iterate through all temperature numbers to see if it is necesary
        for (int temperature = 0; temperature < initialSeedsNumber; temperature++)
        {
            long long int temperatureValue = temperatureNumbers[temperature];
            if((sourceStart <= temperatureValue) && (temperatureValue <= sourceStart + length)){
                printf("SourceStart %lld <= temperatureValue %lld <= sourceStart+lenght %lld\n",sourceStart, temperatureValue, sourceStart+length);
                humidityNumbers[temperature] = destinationStart + (temperatureValue - sourceStart);
                printf("Humidity number light = %lld\n", humidityNumbers[temperature]);
                
                locationNumbers[temperature] = humidityNumbers[temperature];
            }
        }
    }
    
    // 8. Get the location numbers
    char locationNumber[100];
    fgets(locationNumber, 100, fptr); // humidity-to-location map:

    while(fgets(locationNumber, 100, fptr) && strcmp(locationNumber,"\n") != 0){
        printf("\nLocation number strucutre: %s",locationNumber);

        char *stateLocationNumber = NULL;

        // 8.1. Get destination start aka location number
        char *destptr;
        char *destinationStartStr =  strtok_r(locationNumber, " ", &stateLocationNumber);
        long long int destinationStart = strtoll(destinationStartStr, &destptr, 10);
        // printf("Destination start: %lld\n", destinationStart);

        // 8.2. Get source start aka humidity number
        char *sourceptr;
        char *sourceStartStr =  strtok_r(NULL, " ", &stateLocationNumber);
        long long int sourceStart = strtoll(sourceStartStr, &sourceptr, 10);
        // printf("Source start: %lld\n", sourceStart);

        // 8.3. Get length
        char *lengthptr;
        char *lengthStr =  strtok_r(NULL, " ", &stateLocationNumber);
        long long int length = strtoll(lengthStr, &lengthptr, 10);
        // printf("Length: %lld\n", length);

        // 8.4. iterate through all humidity numbers to see if it is necesary
        for (int humidity = 0; humidity < initialSeedsNumber; humidity++)
        {
            long long int humidityValue = humidityNumbers[humidity];
            if((sourceStart <= humidityValue) && (humidityValue <= sourceStart + length)){
                printf("SourceStart %lld <= humidityValue %lld <= sourceStart+lenght %lld\n",sourceStart, humidityValue, sourceStart+length);
                locationNumbers[humidity] = destinationStart + (humidityValue - sourceStart);
                printf("Location number light = %lld\n", locationNumbers[humidity]);
            }
        }
    }
   
    for (int m = 0; m < initialSeedsNumber; m++)
    {
        printf("\nSeed %lld, soil %lld, fertilizer %lld, water %lld, light %lld, temperature %lld, humidity %lld, location %lld.\n",
        seedsNumbers[m], soilNumbers[m], fertilizerNumbers[m], waterNumbers[m], lightNumbers[m], humidityNumbers[m], locationNumbers[m]);
    }
    

    // 9. Find the lowest location in the array
    long long int lowestLocation = __INT64_MAX__;

    for (int k = 0; k < initialSeedsNumber; k++)
    {
        if(locationNumbers[k] < lowestLocation) {
            printf("location Number: %lld\n",locationNumbers[k]);
            lowestLocation = locationNumbers[k];
        }
    }

    printf("\nLowest location!!! %lld\n",lowestLocation);

    fclose(fptr);

    return 0;
}

