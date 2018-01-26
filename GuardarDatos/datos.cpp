/*
 * datos.cpp
 *
 *  Created on: 5 ene. 2017
 *      Author: Jorge
 */
#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>
using namespace std;

int main()
{
	// La intención del programa siguiente será la introducción en un archivo de texto del
	//Nombre Apellidos Dirección y Edad de los alumnos de 5 de Primaria de Salesianos Deusto
	ofstream archivoColegioSalesianos;
	archivoColegioSalesianos.open("salesianos.txt");
	if(!archivoColegioSalesianos)
	{
		cerr<<"No se pudo abrir el archivo"<<endl;
		exit(EXIT_FAILURE);

	}
	cout<<"Escribe Nombre, Apellidos, Dirección y Edad de los alumnos de 5º de Primaria"<<endl
		<<"Escribe fin de archivo para terminar la entrada\n";
		char nombre[15];
		char apellidos[30];
		char direccion[45];
		char edad[5];
		long ubicacion;


		//cin.ignore();
	// Lo haremos con cin pero se intentará tb hacerlo con getline



		while (cin.getline(nombre,15,'\n'),cin.getline(apellidos,30,'\n'),cin.getline(direccion,45,'\n'),cin.getline(edad,5,'\n'))
		{
			ubicacion=archivoColegioSalesianos.tellp();
			archivoColegioSalesianos<< nombre <<"\n"<< apellidos <<"\n"<< direccion <<"\n"<< edad<<"\n";
			nombre[0]='\0';
			apellidos[0]='\0';
			direccion[0]='\0';
			edad[0]='\0';
		}
			cout<<nombre<<endl;
			cout<<apellidos<<endl;
			cout<<direccion<<endl;
			cout<<edad<<endl;
		archivoColegioSalesianos.close();
	/*ifstream archivoLectura("salesianos.txt");
	char linea[50];
	char aNombres[10][50];
	int i=1;
	int m=1;
	int u=0;
	int b;
	while(!archivoLectura.eof())
	{

		archivoLectura.getline(linea,50);
		//cout<<linea<<endl;

		if(m==i)
		{

			strcpy(aNombres[u], linea);
			i=i+4;
			u++;
		}
		m++;
	}
	for(b=0;b<u;b++)
		cout<<aNombres[b]<<endl;*/



		cout<<ubicacion<<endl;
		system("pause");

}




