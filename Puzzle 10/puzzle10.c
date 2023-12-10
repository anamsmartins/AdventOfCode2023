#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

#define MATRIX_SIZE 140

int getSteps(char previousMovement, int linePosition, int columnPosition, char field[MATRIX_SIZE][MATRIX_SIZE+1], int numberOfSteps){
    // printf("Movemnt: %c, %d %d\n",previousMovement,linePosition,columnPosition);
    
    char symbol = field[linePosition][columnPosition];

    if (symbol == 'S'){
        return numberOfSteps++;
    }

    if(previousMovement == 't'){
        if(symbol == '|'){
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1);
        }

        if(symbol == '7'){
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1);
        }

        if(symbol == 'F'){
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1);
        }
    }

    if(previousMovement == 'd'){
        if(symbol == '|'){
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1);
        }

        if(symbol == 'L'){
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1);
        }

        if(symbol == 'J'){
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1);
        }
    }

    if(previousMovement == 'l'){
        if(symbol == '-'){
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1);
        }

        if(symbol == 'L'){
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1);
        }

        if(symbol == 'F'){
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1);
        }
    }

    if(previousMovement == 'r'){
        if(symbol == '-'){
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1);
        }

        if(symbol == 'J'){
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1);
        }

        if(symbol == '7'){
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1);
        }
    }
    
    
    return 1;
}

int main() {
    fptr = fopen("puzzle10_input.txt", "r"); 

    int lines= MATRIX_SIZE;
    int columns = MATRIX_SIZE;
    char field[lines][columns+1]; 

    int sLinePosition, sColumnPosition = 0;
    int furthestPosition = 0;

    // Get field matrix
    int i = 0;
    char phrase[columns+2];
    while (fgets(phrase, columns+2, fptr))
    {
        if(phrase[columns] == '\n'){
            phrase[columns] = '\0';
        }
        
        strcpy(field[i], phrase);
        
        if(strstr(phrase, "S") != NULL){
            sLinePosition = i;
            for (int j = 0; j < strlen(phrase); j++)
            {
                if(phrase[j] == 'S'){
                    sColumnPosition = j;
                    // printf("S position: %d %d\n",sLinePosition, sColumnPosition);
                    break;
                }
            }
        }
        // printf("S: %s\n",field[i]);

        i++;
    }

    int nextLine = sLinePosition;
    int nextColumn = sColumnPosition; 
    char movement; // t - top; d - down; l - left, r - right
    // Check positions
    if(sLinePosition!=0 && (field[sLinePosition-1][sColumnPosition] == '|' || field[sLinePosition-1][sColumnPosition] == '7' || field[sLinePosition-1][sColumnPosition] == 'F')){
        nextLine -= 1; // Top position
        movement = 't';
    } else if(sLinePosition!=lines-1 && (field[sLinePosition+1][sColumnPosition] == '|' || field[sLinePosition+1][sColumnPosition] == 'L' || field[sLinePosition-1][sColumnPosition] == 'J')){
        nextLine += 1; // Down position
        movement = 'd';
    } else if(sColumnPosition!=0 && (field[sLinePosition][sColumnPosition-1] == '-' || field[sLinePosition][sColumnPosition-1] == 'L' || field[sLinePosition][sColumnPosition-1] == 'F')){
        nextColumn -= 1; // Left position
        movement = 'l';
    } else if(sColumnPosition!=columns-1 && (field[sLinePosition][sColumnPosition+1] == '-' || field[sLinePosition][sColumnPosition+1] == 'J' || field[sLinePosition][sColumnPosition+1] == '7')){
        nextColumn += 1; // Right position
        movement = 'r';
    }

    furthestPosition = getSteps(movement, nextLine, nextColumn, field, 1)/2;

    
    printf("Furthest Position: %d\n",furthestPosition);

    fclose(fptr);
}