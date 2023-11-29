#pragma once
//abstraktni trida -nelze z ni udelat objekt
//pouzivaji ji ostatni classy
class clsProtoEncryption
{
	//po vytvoreni objektu z class muzeme zavolat tyto public funkce
public:
	clsProtoEncryption() {};//prazdny konstruktor; //konstruktor
	//virutal, bude se funkce dedit a prepisovat
	virtual bool OpenFile(const char* p_chNameIN, const char* p_chNameOUT) = 0;//je abstraktni 
	virtual bool CloseFile() = 0; //zavre vsechny otevrene slozky
	virtual bool Crypt() = 0; //kryptovani slozek
	virtual bool Decrypt() = 0; //kryptovani slozek
};
