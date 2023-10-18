// serazeniPodleAbecedy.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <stdio.h>

char* alokacePameti(int);
char serazeniAbeceda(char*, int, char);

int main()
{
    char vstup[] = {"ahoj karle jak se mas"};
    int velikostPole;
    //printf("%s", vstup);
    velikostPole = sizeof(vstup);
    printf("%s", serazeniAbeceda(alokacePameti(velikostPole), velikostPole), vstup);
}

char* alokacePameti(int velikostPole)
{    
    char* pPole;

    pPole = (char*)calloc(velikostPole, sizeof(char));
    return pPole;
}

char serazeniAbeceda(char* pInput, int velikostPole, char source)
{
    char* psource = (char*)&source;
    int temp;

    while (psource != 0)
    {
        if (temp == NULL)
        {
            temp = *psource;
        }
        else if (temp > (int)*pInput)
        {
            temp = (int)*pInput;
        }
        pInput++;
    }
    return ;
}
