#include "clsEncryptionEx.h"

clsEncryptionEx:: clsEncryptionEx()
{

}
bool clsEncryptionEx::OpenFile(const char* p_chNameIN, const char* p_chNameOUT)
{
	HANDLE hFile;

	// otevreni souboru
	hFile = CreateFile(L"p_chNameSource", GENERIC_WRITE | GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);

	return false;
}
bool clsEncryptionEx::CloseFile()
{
	return false;
}
bool clsEncryptionEx::Crypt()
{
	return false;
}
bool clsEncryptionEx::Decrypt()
{
	return false;
}