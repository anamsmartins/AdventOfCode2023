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
    int period;
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

int gcd(long long int a, int b) // Greatest Common Diviser
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long int lcm(struct Instruction *instructions, int numberOfInstructions){  // Least Common Multiplier
    long long int result = instructions[0].period;
    // printf("Result: %d\n",instructions[0].period);
    for (int i = 1; i < numberOfInstructions; i++) {
        // printf("GCD: %d\n",gcd(result, instructions[i].period));
        result = (result * instructions[i].period) / gcd(result, instructions[i].period);
    }

    return result;
}

int main() {
    fptr = fopen("puzzle8_input.txt", "r"); 

    // Get rule
    char rule[300];
    fgets(rule, 300, fptr); // LLR
    rule[strlen(rule)-1] = '\0';
    printf("RUle: %s \n",rule);

    // Get instructions
    struct Instruction *instructions = (struct Instruction *)malloc(sizeof(struct Instruction));
    struct Instruction *currentInstructions = (struct Instruction *)malloc(sizeof(struct Instruction));
    
    char phrase[20];
    char designationPhrase[20];
    char leftPhrase[20];
    char rightPhrase[20];
    fgets(phrase, 20, fptr); // enter

    int instructionsNumber = 0;
    int currentInstructionsNumber = 0;
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

        // Get the instructions ending with A
        if(instructions[instructionsNumber].designation[2] == 'A'){
            currentInstructions[currentInstructionsNumber] = instructions[instructionsNumber];
            currentInstructionsNumber++;
            currentInstructions = realloc(currentInstructions, (currentInstructionsNumber+1)*sizeof(*currentInstructions));
        }

        instructionsNumber++;
        instructions = realloc(instructions, (instructionsNumber+1)*sizeof(*instructions));
    }

    // Get the period for each one
    int won;
    int count;
    for (int i = 0; i < currentInstructionsNumber; i++)
    {
        count = 0;
        won = 0;
        struct Instruction copyInstruction = currentInstructions[i];
        // printf("%s - (%s, %s)\n",copyInstruction.designation, copyInstruction.left, copyInstruction.right);
        while(!won){
            for (int j=0; j<strlen(rule);j++){
                count++;
                // printf("Rule: %c\n",rule[i]);
                if(rule[j] == 'L'){ //left
                    copyInstruction = getInstructionByDesignation(copyInstruction.left,instructionsNumber,instructions);
                    if (copyInstruction.designation[2] == 'Z'){
                        // printf("%s == Z\n", copyInstruction.designation);
                        won = 1;
                        currentInstructions[i].period = count;
                        // printf("Periodddd: %d\n",currentInstructions[i].period);
                        break;
                    }
                    // printf("Current Instruction %s\n",currentInstruction.designation);
                } else { // right
                    copyInstruction = getInstructionByDesignation(copyInstruction.right,instructionsNumber,instructions);
                    if (copyInstruction.designation[2] == 'Z'){
                        // printf("%s == Z\n", copyInstruction.designation);
                        won = 1;
                        currentInstructions[i].period = count;
                        // printf("Period: %d\n",currentInstructions[i].period);
                        break;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < currentInstructionsNumber; i++)
    // {
    //     printf("Period: %d\n",currentInstructions[i].period);
    // }
    
    long long int numberOfSteps = lcm(currentInstructions, currentInstructionsNumber);

    printf("Number of steps: %lld\n",numberOfSteps);
    
    fclose(fptr);

    return 0;
}
