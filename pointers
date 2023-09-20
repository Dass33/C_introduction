// Online C compiler to run C program online
#include <stdio.h>

typedef unsigned char byte;

int main() {
    int a;
    int* p_a;
    //pointer co ukazuje na interger

    a = 257;
    p_a = (byte*) & a;
    //jaka je tva adresa

    //printf("%p\n", p_a);
    //co mas v sobe ulozene

    //printf("%i", *p_a);
    //co je na miste kam ukaujes a vispis jako intiger
    
    for (int i = 0; i < sizeof(int); i++)
    {
        printf("%i\n", *p_a);
        *p_a++;
    }

    return 0;
}
