#include "CArticolelectronic.h"
CArticolelectronic::CArticolelectronic()
{
}
CArticolelectronic::CArticolelectronic(string denumire, float m_pret, int garant):CArticol(denumire,m_pret),garantie(garant)
{
}
void CArticolelectronic::print()
{
	cout << "E,";
	cout << this->name << "," << this->pret << "," << this->garantie<< endl;
}
CArticolelectronic::~CArticolelectronic()
{
}