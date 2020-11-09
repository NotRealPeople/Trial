#pragma once
#include "CArticol.h"
#include "CArticolalim.h"
#include "CArticolelectronic.h"
#include <vector>
class CMagazin
{
private:
	string name;
	vector<CArticol*> articole;
	vector<CArticolalim> alim;
	vector<CArticolelectronic>electric;
public:
	CMagazin();
	CMagazin(const char *nume);
	CMagazin(string nume);
	CMagazin(const CMagazin &M);
	void addArticol(const char *denumire, float pret, const char *expira);
	void addArticol(const char *denumire, float pret, int garantie);
	void deleteArticol(const char *denumire);
	void print();
	void printExpirable(const char *data);
	friend CMagazin operator+(CMagazin &M1, CMagazin &M2);
	CMagazin &operator=(const CMagazin &M);
	~CMagazin();
};