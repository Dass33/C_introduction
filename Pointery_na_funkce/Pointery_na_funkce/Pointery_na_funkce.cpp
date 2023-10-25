//predame funkci (API) pointer na funkci a kdzy potrebuje neco predat tak muze zavolat funkci 
//vyrazne zrychluje proces
// --->callback function

//hodne se pouziva na baremetalu
//treba zavolej tuhle funkci pokud na sitovou kartu prijdou data


#include "stdio.h"

#define MAX_LEN 10

typedef int (*td_fce)(int, int);
//vytvoreni noveho datatypu, ktery je pointer na funkci, int se dvema int argumenty

td_fce ArrayFunctionPointers[MAX_LEN];
//definice pole obsahujci pointery na funkce

int MojeFceIndex = 0;
//aktualni prazden misto 

void AddToArray(td_fce pointer)
{
	//melo by se kotrolovat ze je spravny input a i jina osetreni
	ArrayFunctionPointers[MojeFceIndex] = pointer;
	MojeFceIndex++;
}

void CallAllFunctions(int intA, int intB)
{
	for (int i = 0; i < MojeFceIndex;i++)
	{
		ArrayFunctionPointers[i](intA, intB);
	}
}

int secti(int intA, int intB)
{
	printf("sectiz\n");
	return intA + intB;
}

int odecti(int intA, int intB)
{
	printf("odecti\n");
	return intA - intB;
}

int main()
{
	AddToArray(secti);
	AddToArray(odecti);

	CallAllFunctions(2, 5);
	//kdyz se stane nejaky event zavolej vsechny funkce ve tve array
}


//td_fce fce;
//vytvori nam adresu na funkci, pointer

//fce = secti;
//nacteni adresi do 

//fce = secti(); pointer funkce na funkci, ktera ti vrati pointer na funkci
//musela by ale byt typu td_fce, aby nam vracela spravnou hodnotu

//fce(2, 5);
//volame ji uplne stejne jako normalni funkci

//fce = odecti;

//fce(2, 5);

//je to super kdyz nevime dopredu jakou funkci budeme chtit volat, pred zahajenim programu
//ma domenka
