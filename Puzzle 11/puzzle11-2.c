#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

#define MATRIX_SIZE 140

struct Galaxy{
    long long int x;
    long long int y;
};

int main() {
    fptr = fopen("puzzle11_input.txt", "r"); 

    int lines= 1;
    int columns = MATRIX_SIZE+1;
    char **space = (char **)malloc(lines * sizeof(char *));
    space[0] = (char *)malloc(columns * sizeof(char));

    // Get Space Matrix
    char phrase[columns+1];
    while (fgets(phrase, columns+1, fptr))
    {
        if(lines != 1){
            space = realloc(space, lines*sizeof(space));
            space[lines-1] = (char *)malloc(columns * sizeof(char));
        }

        if(phrase[columns-1] == '\n'){
            phrase[columns-1] = '\0';
        }
        
        strcpy(space[lines-1], phrase);
        
        // printf("Line: %s a\n",space[lines-1]);

        lines++;
    }

    lines -= 1;
    printf("Lines: %d\n",lines);

        // Get galaxies
    int numberOfGalaxies = 0;
    int numberPairs = 0;
    struct Galaxy *galaxies = (struct Galaxy *)malloc(sizeof(struct Galaxy));
    struct Galaxy *copyGalaxies = (struct Galaxy *)malloc(sizeof(struct Galaxy));

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(space[i][j] == '#'){
                if(numberOfGalaxies != 0){
                    galaxies = realloc(galaxies, (numberOfGalaxies+1)*sizeof(struct Galaxy));
                    copyGalaxies = realloc(copyGalaxies, (numberOfGalaxies+1)*sizeof(struct Galaxy));
                }
                galaxies[numberOfGalaxies].x = (long long int)i;
                printf("aaa %lld\n",galaxies[numberOfGalaxies].x);
                galaxies[numberOfGalaxies].y = (long long int)j;
                printf("aaa %lld\n",galaxies[numberOfGalaxies].y);
                copyGalaxies[numberOfGalaxies].x = (long long int)i;
                copyGalaxies[numberOfGalaxies].y = (long long int)j;
                numberOfGalaxies++;
                numberPairs += numberOfGalaxies;
            }
        }
    }
    
    numberPairs -= numberOfGalaxies;
    printf("Number of pairs: %d; number of galaxies:%d \n",numberPairs, numberOfGalaxies);

    long long int skipNumber = 999999;

    // Updates column space
    int allDots = 1;
    for (int i = 0; i < columns-1; i++)
    {
        allDots = 1;
        for (int j = 0; j < lines; j++)
        {
            if(space[j][i] == '#'){
                allDots = 0;
                break;
            }
        }

        if(allDots){
            // Resize the matrix by adding two columns
            for (int g = 0; g < numberOfGalaxies; g++)
            {
                printf("Galaxy: (%lld, %lld), i=%d\n",galaxies[g].x, galaxies[g].y, i);
                if (galaxies[g].y > i)
                {
                    printf("AAAAA\n");
                    copyGalaxies[g].y += skipNumber;
                }
                
            }
        }
    }

    // Updates Lines space
    for (int i = 0; i < lines; i++)
    {
        allDots = 1;
        for (int j = 0; j < columns; j++)
        {
            if(space[i][j] == '#'){
                allDots = 0;
                break;
            }
        }

        if(allDots){
             // Resize the matrix by adding two columns
            for (int g = 0; g < numberOfGalaxies; g++)
            {
                if (galaxies[g].x > i)
                {
                    copyGalaxies[g].x += skipNumber;
                }
                
            }
        }
    }

    for (int i = 0; i < lines; i++)
    {
        printf("Space #%d: %s\n",i,space[i]);
    }

    long long int sum = 0;
    for (int n = 0; n < numberOfGalaxies-1; n++)
    {
        for (int m = n+1; m < numberOfGalaxies; m++)
        {
            long long int horizontalSteps = abs(copyGalaxies[m].x - copyGalaxies[n].x);
            long long int verticalSteps = abs(copyGalaxies[m].y - copyGalaxies[n].y);

            printf("From (%lld, %lld) to (%lld, %lld): %lld\n",copyGalaxies[n].x,copyGalaxies[n].y,copyGalaxies[m].x,copyGalaxies[m].y,horizontalSteps + verticalSteps);
            sum += horizontalSteps + verticalSteps;
        }
       
    }

    printf("Sum: %lld\n",sum);

    fclose(fptr);
}