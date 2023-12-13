#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

#define MATRIX_SIZE 140

struct Galaxy{
    int x;
    int y;
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
            for (int l = 0; l < lines; l++) {
                space[l] = (char *)realloc(space[l], (columns + 1 + 1) * sizeof(char));
                
                // Shift columns to the right starting from the end
                for (int k = columns; k >= i; k--) {
                    space[l][k + 1] = space[l][k];
                }

                space[l][i] = '.';
            }

            columns += 1;  // Increase the total number of columns
            i += 1;        // Skip the newly added columns
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
            lines++;
            space = (char **)realloc(space, lines * sizeof(char *));
            space[lines-1] = (char *)malloc((columns + 1) * sizeof(char)); 
            
            // Shift lines from bottom to this line
            for (int k = lines-1; k > i; k--) {
                    
                // printf("Lines: %d; k=%d, i=%d\n",lines,k,i);
                strcpy(space[k], space[k-1]);
                // printf("Lineee %s\n",space[k]);
                
            }

            // Initialize the new line with dots
            for (int c = 0; c < columns-1; c++) {
                space[i][c] = '.';
            }
            space[i][columns-1] = '\0';

            i++;
        }
    }

    // for (int i = 0; i < lines; i++)
    // {
    //     printf("Space #%d: %s\n",i,space[i]);
    // }

    // Get galaxies
    int numberOfGalaxies = 0;
    int numberPairs = 0;
    struct Galaxy *galaxies = (struct Galaxy *)malloc(sizeof(struct Galaxy));

    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if(space[i][j] == '#'){
                if(numberOfGalaxies != 0){
                    galaxies = realloc(galaxies, (numberOfGalaxies+1)*sizeof(galaxies));
                }
                galaxies[numberOfGalaxies].x = i;
                galaxies[numberOfGalaxies].y = j;
                numberOfGalaxies++;
                numberPairs += numberOfGalaxies;
            }
        }
    }
    
    numberPairs -= numberOfGalaxies;
    printf("Number of pairs: %d; number of galaxies:%d \n",numberPairs, numberOfGalaxies);

    int sum = 0;
    for (int n = 0; n < numberOfGalaxies-1; n++)
    {
        for (int m = n+1; m < numberOfGalaxies; m++)
        {
            int horizontalSteps = abs(galaxies[m].x - galaxies[n].x);
            int verticalSteps = abs(galaxies[m].y - galaxies[n].y);

            printf("From (%d, %d) to (%d, %d): %d\n",galaxies[n].x,galaxies[n].y,galaxies[m].x,galaxies[m].y,horizontalSteps + verticalSteps);
            sum += horizontalSteps + verticalSteps;
        }
       
    }

    printf("Sum: %d\n",sum);

    fclose(fptr);
}