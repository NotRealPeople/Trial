#pragma once
#include <iostream>
using namespace std;
#include <conio.h>
#include <string>
class CArticol
{
protected:
	string name;
	float pret;
public:
	CArticol();
	CArticol(string nume, float m_pret);
	string get_name() { return this->name; }
	float get_pret() { return this->pret; }
	void set_pret(float pret) { this->pret = pret; }
	virtual void print() = 0;
	virtual ~CArticol();
};