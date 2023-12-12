#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

#define MATRIX_SIZE 140

struct Vertice{
    int x;
    int y;
};

int getSteps(char previousMovement, int linePosition, int columnPosition, char field[MATRIX_SIZE][MATRIX_SIZE+1], int numberOfSteps, struct Vertice *vertices, int *numberOfVertices){
    // printf("Movemnt: %c, %d %d\n",previousMovement,linePosition,columnPosition);
    
    char symbol = field[linePosition][columnPosition];

    if (symbol == 'S'){
        return numberOfSteps++;
    }

    if(previousMovement == 't'){
        if(symbol == '|'){
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == '7'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'F'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1, vertices, numberOfVertices);
        }
    }

    if(previousMovement == 'd'){
        if(symbol == '|'){
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'L'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'J'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1, vertices, numberOfVertices);
        }
    }

    if(previousMovement == 'l'){
        if(symbol == '-'){
            return getSteps('l', linePosition, columnPosition-1, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'L'){
           vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'F'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
        }
    }

    if(previousMovement == 'r'){
        if(symbol == '-'){
            return getSteps('r', linePosition, columnPosition+1, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == 'J'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('t', linePosition-1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
        }

        if(symbol == '7'){
            vertices = realloc(vertices, (*numberOfVertices+1)*sizeof(*vertices));
            vertices[*numberOfVertices].x = linePosition;
            vertices[*numberOfVertices].y = columnPosition;
            (*numberOfVertices)++;
            return getSteps('d', linePosition+1, columnPosition, field, numberOfSteps+1, vertices, numberOfVertices);
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

    struct Vertice *vertices = (struct Vertice *)malloc(sizeof(struct Vertice));


    vertices[0].x = sLinePosition;
    vertices[0].y = sColumnPosition;
    int numberOfVertices = 1;

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

    int loopLength = getSteps(movement, nextLine, nextColumn, field, 1, vertices, &numberOfVertices);

    printf("vertice numbers: %d\n",numberOfVertices);

    // Get loop area according to the Pick's formula
    int loopArea = 0; 
    for (int v = 0; v < numberOfVertices; v++)
    {
        int nextIndex = (v + 1) % numberOfVertices;

        int currentX = vertices[v].x;
        int currentY = vertices[v].y;
        int nextX = vertices[nextIndex].x;
        int nextY = vertices[nextIndex].y;

        loopArea += currentX * nextY - currentY * nextX;
        printf("Vertice #%d - x: %d y: %d\n",v,vertices[v].x, vertices[v].y);
        printf("Loop Area: %d\n",loopArea);
    }
    loopArea = abs(loopArea) / 2;
    printf("Loop Area: %d\n",loopArea);
    printf("Loop length %d\n",loopLength);

    // Get interior points according to the Shoelace's formula
    int interiorPointsCount = loopArea - (loopLength/2) +1;


    printf("Points Count: %d\n",interiorPointsCount);

    fclose(fptr);
}