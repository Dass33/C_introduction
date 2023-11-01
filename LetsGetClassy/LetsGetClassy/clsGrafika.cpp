#include "clsGrafika.h"

clsGrafika::clsGrafika()
{
	p_mchName = new char[BUFFER_SIZE];
	strcpy_s(p_mchName, BUFFER_SIZE,"point");
}

clsGrafika::clsGrafika()
{
	delete(p_mchName);
}

//funkce printtype ktera je clenem clsGrafika?
void clsGrafika::PrintType()
{
	printf("%s", p_mchName);
}