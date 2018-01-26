/*
 * fecha.h
 *
 *  Created on: 18 ene. 2017
 *      Author: Jorge
 */

#ifndef FECHA_H_
#define FECHA_H_
#include<iostream>
class Fecha
{
	int dia;
	int mes;
	int ano;
public:
	Fecha();
	//void SetFechaDia(int);
	friend void operator >>(std::istream &fe, Fecha &);
	friend void operator <<(std::ostream &fs, Fecha &);
	 int DevolverDia();
	 int DevolverMes();
	 int DevolverAno();
	 char* DevolverFechas();

};



#endif /* FECHA_H_ */
