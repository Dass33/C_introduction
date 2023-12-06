#include "clsEncryptionEx.h"

clsEncryptionEx:: clsEncryptionEx()
{

}
bool clsEncryptionEx::OpenFile(LPCWSTR p_chNameIN, LPCWSTR p_chNameOUT)
{
	// otevreni souboru
	hFile = CreateFile(p_chNameIN, GENERIC_WRITE | GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	//pametove mapovani
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);
	//pouziva se proto abychom mohli pracovat se soubory vetsi nez je nase operacni pamet
	//namapujeme vzdy jen cast souboru

	//namapovani pohledu do souboru
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);
	//da nam pointer na prvni byte v pameti 



	return false;
}
bool clsEncryptionEx::CloseFile()
{
	//ulozeni zmen
	FlushViewOfFile(p_mSourceFirstByte, 0);

	//odmapovani
	UnmapViewOfFile(p_mSourceFirstByte);
	
	//uzavreni handles
	CloseHandle(hFileMapping);
	CloseHandle(hFile);
	return false;
}
bool clsEncryptionEx::Crypt()
{
	//zjistime jak je dlouhy soubor
	//zakryptovani souboru
	//cesarova 

	//co je to za metodu sifrovani
	//jak funguje, ze je funkcni


	return false;
}
bool clsEncryptionEx::Decrypt()
{
	return false;
}