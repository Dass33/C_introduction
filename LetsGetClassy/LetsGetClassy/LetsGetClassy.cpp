#include "stdio.h"
#include "clsGrafika.h"



int main()
{
	clsGrafika* lobjGrafika2; //pointer na objekt ze tridy grafika
	//musime priradit na objekt kam ma ukazovat


	//lobjGrafika2 = gcnew neco; //umoznuje tvorit veci z dotnetu
	lobjGrafika2 = new clsGrafika(); // v pameti vytvori a adresu kde je da pointeru
	lobjGrafika2->mintX = 2; //pro dynamicke objekty

	lobjGrafika2->PrintType();

	delete(lobjGrafika2); //zavola destruktor
	//zrusi se trida ale nase alokovana pamet se neuvolni
	//nevi co je vevnitr
}


//clsGrafika lobjGrafika; //proc tohle nemusime destruktovat
	//lobjGrafika.mintX = 2;
