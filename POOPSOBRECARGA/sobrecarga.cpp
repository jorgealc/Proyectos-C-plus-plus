/*
 * sobrecarga.cpp
 *
 *  Created on: 17 ene. 2017
 *      Author: Jorge
 */

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include"Sobrecarga.h"
#include"fecha.h"
#include"hora.h"
using namespace std;

Sobrecarga::Sobrecarga()
	:f(Fecha()), h_inicial(Hora()), h_final(Hora()), Asunto(""), Lugar(""), tipo(0)
{

}
void operator >>(istream &ci, Sobrecarga *c)
{
	cin.ignore();
	cout<<"Asunto:?";
	ci.getline(c->Asunto,40);//Si solo utilizariamos el cin, únicamente me cogería la primera palabra. Cosa q no quiero
	cout<<"Lugar:?";
	ci.getline(c->Lugar,30);
	cout<<"Fecha-> Dia, Mes, Ayno:?";
	//(*c).SetFecha();//Son lo mismo
	//cout<<c->f;//Son lo mismo
	ci>>c->f;
	cout<<"Hora Inicio-> Hora,Minuto:?";
	ci>>c->h_inicial;
	cout<<"Hora Final->: Hora,Minuto:?";
	ci>>c->h_final;
	cout<<"Tipo <1:Trabajo 2:Personal>:?";
	ci>>c->tipo;


}




int Sobrecarga:: DevolverDiaFecha()
{
	return f.DevolverDia();
}
int Sobrecarga::DevolverMesFecha()
{
	return f.DevolverMes();
}
int Sobrecarga::DevolverAnoFecha()
{
	return f.DevolverAno();
}
int Sobrecarga::DevolverHorasInicial()
{
	return h_inicial.DevolverHora();
}
int Sobrecarga::DevolverMinutosInicial()
{
	return h_inicial.DevolverMinuto();
}
int Sobrecarga::DevolverHorasFinal()
{
	return h_final.DevolverHora();
}
int Sobrecarga::DevolverMinutosFinal()
{
	return h_final.DevolverMinuto();
}
Hora Sobrecarga::DevolverHoraInicio()
{
	return h_inicial;
}
Hora Sobrecarga::DevolverHoraFinal()
{
	return h_final;
}
char* Sobrecarga::DevolverLugar()
{
	return Lugar;
}
char* Sobrecarga::DevolverAsunto()
{
	return Asunto;
}
int Sobrecarga::DevolverTipo()
{
	return tipo;
}

void Sobrecarga::mostrarInfo()
{
	int tipo;
	cout<<"Asunto:";
	cout<<DevolverAsunto()<<endl; //No puede ser porque no recibo ese parámetro
	cout<<f;
	cout<<" Inicio: ";
	cout<<h_inicial;
	cout<<" Final: ";
	cout<<h_final;
	cout<<"\n";
	cout<<"Lugar: ";
	cout<<DevolverLugar();
	tipo=DevolverTipo();
		if(tipo==1)
	cout<<" Tipo:Trabajo"<<endl;
		else
	cout<<"Tipo:Personal"<<endl;
	cout<<"\n\n";
}



