#pragma once
class clsCrypto
{
public:
	clsCrypto(); //konstrukotor nic nevraci pozor
	bool Openfile(const char* p_chName); //otevreni souboru
	bool Closefile();

private:
	char* p_mchFileName;


};

