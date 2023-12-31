#pragma once
#include <string.h>
#include <stdio.h>
#define MAX_LENGTH_FILENAME 1024

//file name	- char array

class clsEncryption
{
//po vytvoreni objektu z class muzeme zavolat tyto public funkce
public: 
	clsEncryption(); //konstruktor
	bool OpenFile(const char* p_chNameIN, const char* p_chNameOUT); //otevereni slozky, dle parametru, ktere jsme si poslali
	bool CloseFile(); //zavre vsechny otevrene slozky
	bool CopyFile(); //kopirovani slozek

//nemuzeme mimo class pristupovat k private promenym, ale muzeme pristoupit k public funkcim, ktere s temito promenymi mohou manipulovat

private: 
	char* p_mchFileNameIN;	//File name
	FILE* p_mFileIN; //pointer na datatyp FILE
	char* p_mchFileNameOUT;	//File name
	FILE* p_mFileOUT;//pointer na datatyp FILE
	//pouzivaji se pouziva se pri inputu a outputu Files
};

