#pragma once
#include "CArticol.h"
class CArticolelectronic:public CArticol
{
private:
	int garantie;
public:
	CArticolelectronic();
	CArticolelectronic(string denumire, float m_pret, int garant);
	void print();
	int get_garantie() { return this->garantie; }
	void set_garantie(int g) { garantie = g; }
	~CArticolelectronic();
};