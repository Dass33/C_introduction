#include "clsEncryption.h"
//include nasi heder file

//funkce pro kopirovani slozek, proc neni v tride?
void CopyCryptFile() 
{

}

//funkce pro kryptovani slozek, proc neni v tride?
void Crypt()
{

}


int main()
{
	//pointer na objekt ze tridy
	clsEncryption* p_lobjEncryption;

	//alokuje pamet pro objekt tridy
	p_lobjEncryption = new clsEncryption();

	//otevreni slozky
	p_lobjEncryption->OpenFile("C:\\temp\\test.txt", "C:\\temp\\testvysl.txt");		//Change to scanf!!!

	//zavreni slozky
	p_lobjEncryption->CloseFile();


	//uvolneni pameti
	delete(p_lobjEncryption);
}

