#pragma once
#include "stdio.h"
#include "string.h"
#define	 BUFFER_SIZE 255
class clsGrafika
{
public:
	int mintX, mintY;
	
	char* p_mchName; //pozor neosetrena vyjimka

	clsGrafika(); //konstruktor tridy
	~clsGrafika(); //destruktor, nemuzeme mu poslat parametry
	void PrintType();
};

