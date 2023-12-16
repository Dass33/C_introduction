#include "clsEncryptionEx.h"

clsEncryptionEx:: clsEncryptionEx()
{
	key = { 0x21, 0x50, 0x03, 0x55, 0x50, 0x03, 0x04, 0x55, 0x03, 0x04, 0x55 };
}
bool clsEncryptionEx::OpenFile(LPCWSTR p_chNameIN)
{
	// otevreni souboru
	hFile = CreateFile(p_chNameIN, GENERIC_WRITE | GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	if (hFile == INVALID_HANDLE_VALUE)
	{
		// Handle error opening file
		return false;
	}

	//pametove mapovani
	hFileMapping = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 100, NULL);
	//pouziva se proto abychom mohli pracovat se soubory vetsi nez je nase operacni pamet
	//namapujeme vzdy jen cast souboru
	
	if (hFileMapping == NULL)
	{
		// Handle error creating file mapping
		CloseHandle(hFile);
		return false;
	}
	
	//namapovani pohledu do souboru
	p_mSourceFirstByte = (PBYTE)MapViewOfFile(hFileMapping, FILE_MAP_COPY, 0, 0, 0);
	//da nam pointer na prvni byte v pameti 

	if (p_mSourceFirstByte == NULL)
	{
		// Handle error mapping view of file
		CloseHandle(hFileMapping);
		CloseHandle(hFile);
		return false;
	}

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
	// Get the file size
	GetFileSizeEx(hFile, &lpFileSize);

	// Move the file pointer to the beginning of the file
	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	// Reverse the text before encryption
	Reverse();

	// Substitution cipher encryption...
	for (DWORD i = 0; i < lpFileSize.QuadPart; ++i)
	{
		p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] + key[i % key.size()]) % 256;
	}

	// Move the file pointer to the beginning of the file
	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	// Save the encrypted data back to the file...
	DWORD dwBytesWritten;
	WriteFile(hFile, p_mSourceFirstByte, lpFileSize.QuadPart, &dwBytesWritten, NULL);

	return true;
}

bool clsEncryptionEx::Decrypt()
{
	// Get the file size
	GetFileSizeEx(hFile, &lpFileSize);

	// Move the file pointer to the beginning of the file
	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	// Substitution cipher decryption...
	for (DWORD i = 0; i < lpFileSize.QuadPart; ++i)
	{
		p_mSourceFirstByte[i] = (p_mSourceFirstByte[i] - key[i % key.size()] + 256) % 256;
	}

	// Reverse the text after decryption
	Reverse();

	// Move the file pointer to the beginning of the file
	SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

	// Save the decrypted data back to the file...
	DWORD dwBytesWritten;
	WriteFile(hFile, p_mSourceFirstByte, lpFileSize.QuadPart, &dwBytesWritten, NULL);

	return true;
}

void clsEncryptionEx::Reverse()
{
	std::reverse(p_mSourceFirstByte, p_mSourceFirstByte + lpFileSize.QuadPart);
}

void clsEncryptionEx::Shuffle()
{
	GetFileSizeEx(hFile, &lpFileSize);
	int iTmpVal;
	int iHalfLength = lpFileSize.QuadPart / 2;

	for (int i = 0; i <iHalfLength ; i++)
	{
		iTmpVal = p_mSourceFirstByte[iHalfLength + i];
		p_mSourceFirstByte[i + iHalfLength] = p_mSourceFirstByte[i];
		p_mSourceFirstByte[i] = iTmpVal;
	}
	DWORD dwBytesWritten;
	WriteFile(hFile, p_mSourceFirstByte, lpFileSize.QuadPart, &dwBytesWritten, NULL);

}
