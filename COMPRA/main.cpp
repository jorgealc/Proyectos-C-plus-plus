/*
 * main.cpp
 *
 *  Created on: 1 feb. 2017
 *      Author: Jorge
 */

#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include"producto.h"
#include"compra.h"
#include<new>
#include <windows.h>
#include<limits>
HANDLE wHnd;
HANDLE rHnd;
using namespace std;
int main()
{
	wHnd=GetStdHandle(STD_OUTPUT_HANDLE);
	rHnd==GetStdHandle(STD_INPUT_HANDLE);
	SMALL_RECT windowSize={0,0,130,130};
	SetConsoleWindowInfo(wHnd,1,&windowSize);
	float preciototal;
	int i=0;
	char respuesta;
	int colour=0x0a;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<"BiENVENIDO AL PROGRAMA 'CONOCERELPRECIO' DE TU CARRO DE COMPRA.\nDESAROLLADO POR MI EN LENGUAJE POO C++ MEDIANTE ECLIPSE.\nSI QUIERES QUE FUNCIONE CORRECTAMENTE(NECESITAS .TXT) O QUIERES QUE TE ENVIE EL CODIGO PONTE EN CONTACTO CONMIGO\nA TRAVES DE MI EMAIL:j.alcauzar@outlook.es.\n\n QUE TE AYUDE\n\n";

	ofstream archivoEntrada3;
	archivoEntrada3.open("indice.txt",ios::out);
			archivoEntrada3<<i;
			archivoEntrada3.close();


			Producto *aProducto=new Producto [20];

			ifstream archivoSalida3;
				archivoSalida3.open("indice.txt", ios::in);
				archivoSalida3>>i;
				archivoSalida3.close();
do
{


		Compra *compra=new Compra;
		cin>>compra;

		compra->BuscarProducto(aProducto,i);
		colour=0x0f;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<"\n\nIntroduce una";
		colour=0x0a;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<" S(minuscula)";
		colour=0x0f;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<" para continuar con la compra\nUna";
		colour=0x0a;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<"	N(minuscula)";
		colour=0x0f;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<" para finalizar la compra\n";
		cin>>respuesta;


}while(respuesta=='s');

		archivoSalida3.open("indice.txt",ios::in);
		archivoSalida3>>i;
		archivoSalida3.close();
		Compra *compra1=new Compra;
		compra1->PerdirCantidadesProducto(aProducto,i);
		compra1->EliminarProducto(aProducto,i);
		archivoSalida3.open("indice.txt",ios::in);
		archivoSalida3>>i;
		archivoSalida3.close();
		compra1->CalcularPrecioProducto(aProducto,i);
		archivoSalida3.open("indice.txt",ios::in);
		archivoSalida3>>i;
		archivoSalida3.close();
		compra1->ImprimirTicket(aProducto,i);
		preciototal=compra1->TotalCompra(aProducto,i);
		cout<<"---------------------------------------------------------------------------------------------"<<endl;
		cout<<"                                                                          TOTAL|"<<setw(5)<<fixed<<setprecision(2)<<preciototal<<"€"<<endl;
		system("pause");

	return 0;
}
