#include <stdio.h>
#include <string.h>
#include <ctype.h>
FILE *fptr;

int main() {

    int possibleReds = 12;
    int possibleGreens = 13;
    int possibleBlues = 14;

    //1 - recolher cada game
    fptr = fopen("puzzle2_input.txt", "r"); 

    char phrase[160]; 
    int sum = 0;
    int gameDown;
    int numberOfRounds;

    while (fgets(phrase, 160, fptr)) {
        char* copyPhrase[160];
        strcpy(copyPhrase, phrase);
        char *gameString = strtok(copyPhrase, ":");

        char* id = gameString+5;

        int numberID = atoi(id);


        printf("GAME IDDDDD: %s", id);

        char* gameWithDots = strrchr(phrase, ':');

        char *game = gameWithDots+2;

        char *state_inner = NULL, *state_outer = NULL;

        printf("\nGame: %s\n",game);

        numberOfRounds = 0;
        gameDown = 0;

        //2 - para cada game separar por ; para obter o número de jogos e o número de cada cubo
        char *rounds = strtok_r(game, ";", &state_outer);

        while (rounds != NULL) {
            // printf("%s",rounds);

            // For each cube
            char *cubes = strtok_r(rounds, ",", &state_inner);

            while (cubes != NULL) {
                
                // char* cubesTrim = cubes;

                if (cubes[0] == ' '){
                    cubes++;
                }

                printf("\n%s",cubes);
                char* color = strrchr(cubes, ' ');
                char* numberOfCubes = cubes;
                // printf("\nNUMBBBBBERR: %c", *numberOfCubes);

                int number = atoi(numberOfCubes);
                // printf("\nNUMMMMBBBBBBERRR: %d", number);
                
                if (strstr(color, "red") != NULL) {
                    printf("\nCHECK REDDD -%s", color);
                    if (number > possibleReds) {
                        printf("\n%d > %d",number,possibleReds);
                        gameDown = 1;
                        break;
                    }
                } else if (strstr(color, "blue") != NULL) {
                    printf("\nCHECK BLUEEEEE -%s", color);
                    if (number > possibleBlues) {
                        printf("\n%d > %d",number,possibleBlues);
                        gameDown = 1;
                        break;
                    }
                    
                }  else if (strstr(color, "green") != NULL) {
                    printf("\nCHECK GREEEEN -%s", color);
                    if (number > possibleGreens) {
                        printf("\n%d > %d",number, possibleGreens);
                        gameDown = 1;
                        break;
                    }

                }

                printf("\nEnd of cubes\n");
                cubes = strtok_r(NULL, ",", &state_inner);  
            }

            if (gameDown == 1) {
                printf("LEAVINGGG");
                break;
            } 

            printf("\nEnd of round %s\n", rounds);
            // numberOfRounds++;
            rounds = strtok_r(NULL, ";", &state_outer); 

            printf("\nRRRR%s\n", rounds);
        }

        // printf("\n%s\n", rounds);

        if (gameDown == 1){
            printf("\nGAME DOWN\n");
            continue;
        }

        // printf("\nNumbeEEEEEEEEEEEEEEEEEEEEEEr of rounds: %d\n",numberOfRounds);
        sum += numberID;


        //2.1 - verificar se algum dos cubos do game é superior ao possível

        //2.2. - se for possível contar, senão continuar para outra linha 

    }

    printf("\nSummmmmm: %d", sum);

    fclose(fptr);

    return 0;
} 