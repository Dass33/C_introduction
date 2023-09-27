#include "pokus.h"

//volatile int MojeHodnota;
//neoptimalizovat compilerem kod, protoze jiny software muze zmenit hodnotu
//abychom nali promenou v pameti, kde ji ocekavame
//vetsinou kdyz harware posila promene do pameti automaticky


int MojeHodnota;

void Copy(void* Source, void* Dest, int Len)
{
	//pointer je vzdy adresa, windows 64 => 64 bitu zabira
	// int Len, kolik bajtu se ma zkopirovat

	for (int i = 0; i < Len; i++)
	{
		//velmi omezeny, test pro uceni
	    *(byte*)Dest =  *(byte*)Source;
		//jsi pointer na byte, vis jaky datatyp cist a kolik zabira
		Dest = (byte*)Dest + sizeof(byte);
		Source = (byte*)Source + sizeof(byte);
		//musime pretypovat a posunout o spravne velke misto v pameti
	}
}