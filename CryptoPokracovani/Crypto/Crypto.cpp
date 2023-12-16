#include "clsEncryption.h"
#include "clsEncryptionEx.h"
#include "clsProtoEncryption.h"
//include nasi heder file

//funkce pro kopirovani slozek, proc neni v tride?
void CopyCryptFile() 
{

}

int main()
{
	//pointer na objekt ze tridy
	clsEncryption* p_lobjEncryption;
	clsEncryptionEx* p_lobjEncryptionEx;
	clsProtoEncryption* p_objProtoEncryption;

	//alokuje pamet pro objekt tridy
	p_lobjEncryption = new clsEncryption();
	p_lobjEncryptionEx = new clsEncryptionEx();

	p_objProtoEncryption = p_lobjEncryptionEx;

	//dve aplikace si sdileji data pomoci sdilene pameti, ktera se po zavreni smaze
	//je to velmi rychle

	//otevreni slozky
	p_objProtoEncryption->OpenFile("C:\\temp\\test.txt", "C:\\temp\\testcrypt.txt");		//Change to scanf!!!

	//zasifrovat
	p_objProtoEncryption->Crypt();

	//zavreni slozky
	p_objProtoEncryption->CloseFile();

	//otevreni slozky
	p_objProtoEncryption->OpenFile("C:\\temp\\testcrypt.txt", "C:\\temp\\testdecrypt.txt");		//Change to scanf!!!

	//zasifrovat
	p_objProtoEncryption->Decrypt();

	//zavreni slozky
	p_objProtoEncryption->CloseFile();

	//uvolneni pameti
	delete(p_lobjEncryption);
	delete(p_objProtoEncryption);
}

