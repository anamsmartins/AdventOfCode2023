#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
FILE *fptr;

struct Instruction
{
    char designation[4]; // AAA
    char left[4]; // BBB
    char right[4]; // ZZZ
};


// TODO - fazer função - getInstructionByDesignation
struct Instruction getInstructionByDesignation(char *designation, int instructionsNumber, struct Instruction *instructions){
    for (int i = 0; i< instructionsNumber; i++){
        if(strcmp(designation, instructions[i].designation) == 0){
            // printf("%s = %s\n",designation, instructions[i].designation);
            return instructions[i];
        }
    }

    struct Instruction instructionNULL;
    return instructionNULL; // Error
}

int main() {
    fptr = fopen("puzzle8_input.txt", "r"); 

    // Get rule
    char rule[300];
    fgets(rule, 300, fptr); // LLR
    rule[strlen(rule)-1] = '\0';
    printf("RUle: %s length: %ld\n",rule, strlen(rule));

    // Get instructions
    struct Instruction *instructions = (struct Instruction *)malloc(sizeof(struct Instruction));
    
    char phrase[20];
    char designationPhrase[20];
    char leftPhrase[20];
    char rightPhrase[20];
    fgets(phrase, 20, fptr); // enter

    int instructionsNumber = 0;
    while (fgets(phrase, 20, fptr))
    {
        // Get designation
        strcpy(designationPhrase, phrase);
        strcpy(instructions[instructionsNumber].designation, strtok(designationPhrase, " ="));
        // printf("Designation: %s\n",instructions[instructionsNumber].designation);

        char *instructionsPhrase = strstr(phrase, "(")+1;
        // printf("instructions phrase: %s\n",instructionsPhrase); 
        
        // Get left following instruction
        strcpy(leftPhrase, instructionsPhrase);
        strcpy(instructions[instructionsNumber].left, strtok(leftPhrase, ","));
        // printf("Left: %s\n",instructions[instructionsNumber].left);

        // Get right following instruction
        strcpy(rightPhrase, instructionsPhrase);
        char *leftPhraseStr = strstr(rightPhrase, ",")+2;
        leftPhraseStr[3] = '\0';
        strcpy(instructions[instructionsNumber].right, leftPhraseStr);
        // printf("Right: %s\n",instructions[instructionsNumber].right);

        instructionsNumber++;
        instructions = realloc(instructions, (instructionsNumber+1)*sizeof(*instructions));
    }

    int hasArrived = 0;
    int count = 0;
    struct Instruction currentInstruction = getInstructionByDesignation("AAA",instructionsNumber,instructions);
    // printf("Current instruction: %s\n",instructions[0].designation);

    while(!hasArrived){
        printf("New set of rules, current steps: %d\n",count);
        // Follow the rules
        for (int i=0; i<strlen(rule);i++){
            // printf("Rule: %c\n",rule[i]);
            if(rule[i] == 'L'){ //left
                // printf("Current Instruction %s\n",currentInstruction.designation);
                currentInstruction = getInstructionByDesignation(currentInstruction.left,instructionsNumber,instructions);
                // printf("Current Instruction %s\n",currentInstruction.designation);
            } else { // right
                currentInstruction = getInstructionByDesignation(currentInstruction.right,instructionsNumber,instructions);
            }
        }

        if(strcmp(currentInstruction.designation, "ZZZ") == 0){
            hasArrived = 1;
        } 
        count+=strlen(rule);
        
    }

    printf("Number of steps: %d\n",count);

    
    fclose(fptr);

    return 0;
}
