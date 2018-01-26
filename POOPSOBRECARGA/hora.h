/*
 * hora.h
 *
 *  Created on: 19 ene. 2017
 *      Author: Jorge
 */

#ifndef HORA_H_
#define HORA_H_
#include<iostream>
class Hora
{
	int horas;
	int minuto;

public:
	Hora();
	friend void operator >>(std::istream &entrada, Hora &he);
	friend void operator <<(std::ostream &salida, Hora &hs);
	int DevolverHora();
	int DevolverMinuto();
};
#endif /* HORA_H_ */
