#pragma once
#include <Windows.h>
#include "clsProtoEncryption.h"

class clsEncryptionEx : public clsProtoEncryption
{
public:
	clsEncryptionEx();//prazdny konstruktor; //konstruktor
	//virutal, bude se funkce dedit a prepisovat
	virtual bool OpenFile(const char* p_chNameIN, const char* p_chNameOUT);//je abstraktni 
	virtual bool CloseFile(); //zavre vsechny otevrene slozky
	virtual bool Crypt(); //kryptovani slozek
	virtual bool Decrypt(); //kryptovani slozek
};

