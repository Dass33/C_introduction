// Online C compiler to run C program online
#include <stdio.h>

typedef unsigned char byte;
#define MOJE_VESELA_KONSTANTA 10

void Copy(byte* source, byte* dest, int bytes)
{
    //ze zdrojove adresy bude kopirovat na cilovou adresu 
    for (int i = 0;i < bytes;i++)
    {
        *dest = *source;
        //hodnoty kam pointery ukazuji
        source++;
        dest++;
        //posun adresy i kopirovani i cile
    }
}

int main() {
    int a, b;

    a = MOJE_VESELA_KONSTANTA;
    b = 20;

    Copy((byte*) & b,(byte*) & a, sizeof(int));
    //b=a; zkopirovani b do a, rikame take jak je velky int, prekopirovali jsme byty

    printf("%i, %i", a, b);

    return 0;
}
