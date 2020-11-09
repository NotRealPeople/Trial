#include "CMagazin.h"
void main()
{
	CMagazin m1("magazin_mixt");
	m1.addArticol("Lapte", 2.5, "20080530");
	m1.addArticol("Televizor", 300, 24);
	m1.print();
	CMagazin m2("la_stroe");
	m2.addArticol("Lapte", 3.5, "20080603");
	m2.addArticol("Laptop", 2500, 12);
	m2.addArticol("Televizor", 350, 20);
	m2.addArticol("Carne", 10, "20080831");
	m2.print();
	CMagazin m3=m1 + m2;
	m3.print();
	m3.deleteArticol("Laptop");
	m3.print();
	m3.printExpirable("20080630");
	_getch();
	//NOTA 8//AMR TEMPLATE
	//modified in main
}