/*
 * hora.cpp
 *
 *  Created on: 19 ene. 2017
 *      Author: Jorge
 */
#include<iostream>
#include<iomanip>
#include<string>
#include"hora.h"
using namespace std;
Hora::Hora()
	:horas(0), minuto(0)
{

}

void operator >>(istream &entrada, Hora &he)
{
	entrada>>setw( 2 )>>he.horas;
	entrada.ignore();
	entrada>>setw( 2 )>>he.minuto;
}

void operator <<(ostream &salida, Hora &hs)
{
	salida<<hs.horas<<":"<<hs.minuto;
}
int Hora::DevolverHora()
{
	return horas;
}
int Hora::DevolverMinuto()
{
	return minuto;
}

