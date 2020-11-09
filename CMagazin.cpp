#include "CMagazin.h"
CMagazin::CMagazin()
{
}
CMagazin::CMagazin(const char * nume):name(nume)
{
}
CMagazin::CMagazin(string nume):name(nume)
{
}
CMagazin::CMagazin(const CMagazin & M)
{
	this->name = M.name;
	this->articole = M.articole;
	this->alim = M.alim;
	this->electric = M.electric;
}
void CMagazin::addArticol(const char * denumire, float pret, const char * expira)
{
	string den(denumire);
	string exp(expira);
	articole.push_back(new CArticolalim(den, pret, exp));
	alim.push_back(CArticolalim(den, pret, exp));
}
void CMagazin::addArticol(const char * denumire, float pret, int garantie)
{
	string den(denumire);
	articole.push_back(new CArticolelectronic(den,pret,garantie));
	electric.push_back(CArticolelectronic(den, pret, garantie));
}
void CMagazin::deleteArticol(const char * denumire)
{
	string den(denumire);
	for (int i = 0; i < articole.size(); i++)
	{
		if (articole[i]->get_name() == den)
		{
			articole.erase(articole.begin() + i);
			break;
		}
	}
}
void CMagazin::print()
{
	cout << this->name << endl;
	for (int i = 0; i < articole.size(); i++)
		articole[i]->print();
}
void CMagazin::printExpirable(const char * data)
{
	cout << "Alimente expirate:" << endl;
	string datum(data);
	for (int i = 0; i < alim.size(); i++)
	{
		if ((alim[i] > datum)==0)
			alim[i].print();
	}
}
CMagazin operator+(CMagazin &M1, CMagazin &M2) {
	string new_name(M1.name);
	new_name += '&';
	new_name += M2.name;
	CMagazin *new_shop=new CMagazin(new_name);
	for (int i = 0; i < M1.alim.size(); i++)
	{
		new_shop->alim.push_back(M1.alim[i]);
	}
	for (int i = 0; i < M1.alim.size(); i++)
	{
		new_shop->electric.push_back(M1.electric[i]);
	}
	for (int i = 0; i < M2.alim.size(); i++)
	{
		int ok = 1;
		for (int j = 0; j < new_shop->alim.size(); j++)
		{
			if (new_shop->alim[j].get_name() == M2.alim[i].get_name())
			{
				ok = 0;
				if (new_shop->alim[j].get_pret() > M2.alim[i].get_pret())
					new_shop->alim[j].set_pret(M2.alim[i].get_pret());
				if (new_shop->alim[j].get_data() > M2.alim[i].get_data())
					new_shop->alim[j].set_data(M2.alim[i].get_data());
				break;
			}
		}
		if (ok == 1)
			new_shop->alim.push_back(M2.alim[i]);
	}
	for (int i = 0; i < M2.electric.size(); i++)
	{
		int ok = 1;
		for (int j = 0; j < new_shop->electric.size(); j++)
		{
			if (new_shop->electric[j].get_name() == M2.electric[i].get_name())
			{
				ok = 0;
				if (new_shop->electric[j].get_pret() > M2.electric[i].get_pret())
					new_shop->electric[j].set_pret(M2.electric[i].get_pret());
				if (new_shop->electric[j].get_garantie() < M2.electric[i].get_garantie())
					new_shop->electric[j].set_garantie(M2.electric[i].get_garantie());
				break;
			}
		}
		if (ok == 1)
			new_shop->electric.push_back(M2.electric[i]);
	}
	for (int i = 0; i < new_shop->alim.size(); i++)
	{
		new_shop->articole.push_back(new CArticolalim(new_shop->alim[i].get_name(), new_shop->alim[i].get_pret(), new_shop->alim[i].get_data()));
	}
	for (int i = 0; i < new_shop->electric.size(); i++)
	{
		new_shop->articole.push_back(new CArticolelectronic(new_shop->electric[i].get_name(), new_shop->electric[i].get_pret(), new_shop->electric[i].get_garantie()));
	}
	return *new_shop;
}
CMagazin & CMagazin::operator=(const CMagazin & M)
{
	this->name = M.name;
	this->articole = M.articole;
	this->alim = M.alim;
	this->electric = M.electric;
	return *this;
}
CMagazin::~CMagazin()
{
	for (int i = 0; i < articole.size(); i++)
	{
		if (articole[i] != nullptr)
		{
			delete articole[i];
			articole[i] = nullptr;
		}
	}
}