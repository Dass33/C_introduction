//trida open file close file, copy file, cript with copy,
//vsechny kontroly, zkontrolovat jestli jsou vsechny soubory zavrene v destruktoru

#include <iostream>
#include "clsCrypto.h"

int main()
{
	clsCrypto* p_lobjCrypto;

	//vytvorit projekt
	p_lobjCrypto = new clsCrypto();

	//otervrit soubor
	p_lobjCrypto->Openfile("test"); //sem prijde jmeno 

	// zruseni objektu
	delete(p_lobjCrypto);
}
