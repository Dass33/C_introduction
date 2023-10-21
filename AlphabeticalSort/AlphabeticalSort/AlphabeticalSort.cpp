#include <stdio.h>
#include <stdlib.h> // Include standard library for calloc
#include <ctype.h>

#define MAX_SIZE 2048
#define ASCII_Start_Alphabet 96
#define ASCII_End_ALPHABET 123
//constants declaration

char* sort(char* input, int SizeInput); //delcaration of sort function

int main()
{
    char input[] = "Ahoj Nomade, jak pak se mas? :)"; //input for our sort funcion
    int SizeInput = sizeof(input) -1; //declaration of size withnout the null pointer
    if (MAX_SIZE < SizeInput || SizeInput < 1) //check if the input is of a reasonable size
    {
        return -1; //error code
    }

    char* sortedOutput = sort(input, SizeInput); //call the sort function and save the pointer to the start
    if (sortedOutput != NULL) //if there are any sorted data print them
    {
        printf("sorted by ASCII chart: %s", sortedOutput); //printing characters till is gets to the null
        free(sortedOutput); // Free the allocated memory
        //this is important step that is often missed
    }

    return 0; //no errors
}

char* sort(char* input, int SizeInput)
{
    char* output;
    output = (char*)calloc(SizeInput +1, sizeof(char)); //alocated memory with added size for the null pointer


    if (output == NULL)
    {
        return NULL; // Return NULL in case of memory allocation failure
    }

    int OutputNum = 0;

    for (int ASCII_NUM = ASCII_Start_Alphabet; ASCII_NUM <= ASCII_End_ALPHABET; ASCII_NUM++) //looping through all ascii characters
    {
        for (int inputNum = 0; inputNum < SizeInput; inputNum++) //looping through all of input characters 
        {
            if (tolower(input[inputNum]) == ASCII_NUM)
                //if the current input char is same as current ascii num
            {
                output[OutputNum] = tolower(input[inputNum]); //write into an output array current input char
                OutputNum++; //increment by size of an char
            }
        }
    }

    output[OutputNum] = '\0'; // Null-terminate the output string

    return output; //return pointer to the start of an allocated memory
}
