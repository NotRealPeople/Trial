#include "CArticolalim.h"
CArticolalim::CArticolalim()
{
}
CArticolalim::CArticolalim(string nume, int m_pret, string data):CArticol(nume,m_pret),data_exp(data)
{
}
CArticolalim::CArticolalim(const CArticolalim & A)
{
	this->name = A.name;
	this->data_exp = A.data_exp;
	this->pret = A.pret;
}
void CArticolalim::print()
{
	cout << "A,";
	cout << this->name << "," << this->pret << "," << this->data_exp << endl;
	//this was modified by C
}
bool operator>(CArticolalim &Alim,string data)
{
	if (Alim.get_data() > data)
		return 0;
	return 1;
}
CArticolalim::~CArticolalim()
{
}
