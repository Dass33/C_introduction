#include <stdio.h>
#include <stdlib.h> // Include standard library for calloc
#include <ctype.h>

#define MAX_SIZE 2048
#define ASCII_MAX 128
#define ASCII_Start_Alphabet 96
#define ASCII_End_Alphabet 123

char* sort(char* input, int SizeInput);

int main()
{
    char input[] = "Ahoj Nomade, jak pak se mas? :)";
    int SizeInput = sizeof(input) - 1; // Subtract 1 to exclude the null terminator
    if (MAX_SIZE < SizeInput || SizeInput < 1)
    {
        return -1;
    }

    char* sortedOutput = sort(input, SizeInput);
    if (sortedOutput != NULL) {
        printf("sorted by ASCII chart: %s", sortedOutput);
        free(sortedOutput); // Free the allocated memory
    }

    return 0;
}

char* sort(char* input, int SizeInput)
{
    char* output;
    output = (char*)calloc(SizeInput +1, sizeof(char));
    
    
    if (output == NULL) {
        return NULL; // Return NULL in case of memory allocation failure
    }

    int OutputNum = 0;

    for (int ASCII_NUM = 0; ASCII_NUM < ASCII_MAX; ASCII_NUM++)
    {
        for (int inputNum = 0; inputNum < SizeInput; inputNum++)
        {
            if (input[inputNum] == ASCII_NUM && ASCII_Start_Alphabet < tolower(input[inputNum]) && tolower(input[inputNum]) < ASCII_End_Alphabet)
            {
                output[OutputNum] = tolower(input[inputNum]);
                OutputNum++;
            }
        }
    }

    output[OutputNum] = '\0'; // Null-terminate the output string

    return output;
}