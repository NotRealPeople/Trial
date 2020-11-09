#pragma once
#include "CArticol.h"
class CArticolalim:public CArticol
{
private:
	string data_exp;
public:
	CArticolalim();
	CArticolalim(string nume, int m_pret, string data);
	CArticolalim(const CArticolalim &A);
	void print();
	string get_data() { return this->data_exp; };
	void set_data(string s) { data_exp = s; }
	friend bool operator>(CArticolalim &Alim, string data);
	~CArticolalim();
};