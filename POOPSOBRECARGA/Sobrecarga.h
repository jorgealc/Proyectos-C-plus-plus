/*
 * Sobrecarga.h
 *
 *  Created on: 17 ene. 2017
 *      Author: Jorge
 */

#ifndef SOBRECARGA_H_
#define SOBRECARGA_H_
#include<string>
#include"fecha.h"
#include"hora.h"
#include<fstream>
#include<iostream>
class Sobrecarga
{
	friend void operator>> (std::istream &ci, Sobrecarga *c);
	friend void GuardarArray(int,std::ofstream,int);
private:
	Fecha f;
	Hora h_inicial;
	Hora h_final;
	char Asunto[20];
	char Lugar[30];
	int tipo;
public:
	Sobrecarga();

	Hora DevolverHoraInicio();
	Hora DevolverHoraFinal();
	char* DevolverAsunto();
	char*  DevolverLugar();
	int DevolverTipo();
	void mostrarInfo();
	int DevolverDiaFecha();
	int DevolverMesFecha();
	int DevolverAnoFecha();
	int DevolverHorasInicial();
	int DevolverMinutosInicial();
	int DevolverHorasFinal();
	int DevolverMinutosFinal();
};




#endif /* SOBRECARGA_H_ */
