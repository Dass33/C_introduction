// Online C compiler to run C program online
#include <stdio.h>
#include "pokus.h"
#include <string.h>


int main() {
    int a, b;
    char z[123];
    char y[7123];
    //prvni znak je 0 posledni 122
    
    //strcpy(z, "Ahoj");
    //je nebezpecna, od 123 muze prepisovat jine casti pameti nez by melo
    
    strcpy_s(y, "Ahoj");
    strcpy_s(z, y);
    //za Ahoj napise binarni nulu
    //pri kopiravani tak nekopiruje nic za binarni nulou
    
    //z[3] = '\0';

    strcat_s(z, " karle");

    a = MOJE_VESELA_KONSTANTA;
    b = 20;

    printf("%s", z);

    return 0;
} 

//cpp neznaji sve vnitrky