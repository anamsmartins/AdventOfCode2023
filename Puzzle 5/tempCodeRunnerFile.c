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

        long long int soil = calculateValue(seedValue,soilSrcs,soilDsts,soilLnts,nSoil);
        printf("soil = %lld\n",soil);
        long long int fertilizer = calculateValue(soil, fertilizerSrcs, fertilizerDsts, fertilizerLnts,nFertilizer);
        printf("fertilizer = %lld\n",fertilizer);
        long long int water = calculateValue(fertilizer, waterSrcs, waterDsts, waterLnts,nWater);
        printf("water = %lld\n",water);
        long long int light = calculateValue(water,lightSrcs,lightDsts,lightLnts,nLight);
        printf("light = %lld\n",light);
        long long int temperature = calculateValue(light,temperatureSrcs, temperatureDsts, temperatureLnts,nTemperature);
        printf("temperature = %lld\n",temperature);
        long long int humidity = calculateValue(temperature,humiditySrcs,humidityDsts,humidityLnts,nHumidity);
        printf("humidity = %lld\n",humidity);
        long long int location = calculateValue(humidity,locationSrcs,locationDsts,locationLnts,nLocation);
        printf("location = %lld\n\n",location);

        if(location < lowestLocation){
            lowestLocation = location;
        }        

        seedsNumberStr = strtok_r(NULL, " ", &stateSeeds);
    }

    printf("\