/*
 * fecha.cpp
 *
 *  Created on: 18 ene. 2017
 *      Author: Jorge
 */
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include"fecha.h"
using namespace std;

Fecha::Fecha()
	:dia(0), mes(0), ano(0000)
{

}
void operator<<(ostream &salida, Fecha &f)
{
	salida<<"Fecha:  "<<f.dia<<"/"<<f.mes<<"/"<<f.ano;
}


void operator>>(istream &entrada, Fecha &f)
{
	entrada>>setw( 2 )>>f.dia;
	entrada.ignore();
	entrada>>setw( 2 )>>f.mes;
	entrada.ignore();
	entrada>>setw( 4 )>>f.ano;
}
 int Fecha::DevolverDia()
 {
	 return dia;
 }
 int Fecha::DevolverMes()
 {
	 return mes;
 }
 int Fecha::DevolverAno()
 {
	 return ano;
 }
char* Fecha::DevolverFechas()
{
	char num1[5];
	char num2[5];
	char num3[5];
	char entero[15];
	itoa(dia,num1,10);
	itoa(mes,num2,10);
	itoa(ano,num3,10);
	strcpy(entero,num1);
	strcat(entero,num2);
	strcat(entero,num3);
	return entero;
}
