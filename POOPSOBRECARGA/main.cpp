/* main.cpp
 *
 *  Created on: 17 ene. 2017
 *      Author: Jorge
 */

#include<iostream>
#include<iomanip>
#include<string>
#include<cstring>
#include<fstream>
#include<new>
#include<cstdlib>
#include"Sobrecarga.h"
#include"Fecha.h"

using namespace std;
int Menu();
int main()
{
	//char cadena[15];
	int opc, num, numero,numero1,z;

	fstream citasSalida;
	//ofstream citasEntrada;

	num=0;
	Sobrecarga *aSobreCarga[20];//A un puntero se le puede asignar el valor de otro puntero del mismo tipo

	do
	{


		opc=Menu();
		Sobrecarga *sobrecargas=new Sobrecarga();
		if(opc==1)
		{
			cin>>sobrecargas;
			//Sobrecarga *aSobrecarga[20]; Si declaro aquie el array siempre q entre al 1 se va a eliminar el anterior
			aSobreCarga[num]=sobrecargas;
			num=num+1;

		}


		else if(opc==2)
		{
			for(int i=0;i<num;i++)
			{
				cout<<"Cita "<<i+1<<endl;
				aSobreCarga[i]->mostrarInfo();

			}
		}
		else if(opc==3)
		{

			int numero;
			ofstream archivoCitas;
				archivoCitas.open("citas.txt",ios::app);
					if(!archivoCitas)
						{
							cerr<<"No se pudo abrir el archivo"<<endl;
							exit(EXIT_FAILURE);
						}
					for(int a=0;a<num;a++)
					{
					archivoCitas<<"Cita "<<a+1;
					archivoCitas<<"\n";
					archivoCitas<<"Asunto:"<<aSobreCarga[a]->DevolverAsunto()<<"\n";
					archivoCitas<<"Fecha:";
					archivoCitas<<aSobreCarga[a]->DevolverDiaFecha();
					archivoCitas<<"/";
					archivoCitas<<aSobreCarga[a]->DevolverMesFecha();
					archivoCitas<<"/";
					archivoCitas<<aSobreCarga[a]->DevolverAnoFecha();
					archivoCitas<<"    ";
					archivoCitas<<"Inicio: ";
					archivoCitas<<aSobreCarga[a]->DevolverHorasInicial();
					archivoCitas<<":";
					archivoCitas<<aSobreCarga[a]->DevolverMinutosInicial();
					archivoCitas<<"   Final: ";
					archivoCitas<<aSobreCarga[a]->DevolverHorasFinal();
					archivoCitas<<":";
					archivoCitas<<aSobreCarga[a]->DevolverMinutosFinal();
					archivoCitas<<"\n";
					archivoCitas<<"Lugar: ";
					archivoCitas<<aSobreCarga[a]->DevolverLugar();
					numero=aSobreCarga[a]->DevolverTipo();
								if(numero==1)
									archivoCitas<<" Tipo:Trabajo";
								else
									archivoCitas<<" Tipo::Personal";

								archivoCitas<<"\n\n";

					}
					archivoCitas.close();
		}

		else if(opc==4)

	{
		Sobrecarga* s=new Sobrecarga;
		citasSalida.open("citas.dat",ios::out|ios::binary);//mode app da fallo ,mode ate me elimina lo que habia
			if(!citasSalida)
			{
				cerr<<"No se pudo abrir el archivo."<<endl;
				exit(EXIT_FAILURE);

			}

			for(z=0;z<num;z++)
			{
				s=aSobreCarga[z];

				citasSalida.write(reinterpret_cast<const char *>(&s),sizeof(Sobrecarga *));
			}
			citasSalida.close();
	}
		else if(opc==5)
	{
			//int y;
		Sobrecarga *p=new Sobrecarga;
		citasSalida.open("citas.dat",ios::in|ios::binary);
			if(!citasSalida)
				{
					cerr<<"No se pudo abrir el archivo."<<endl;
					exit(EXIT_FAILURE);

				}

			//for(y=0;y<num;y++)

		citasSalida.read(reinterpret_cast< char *>(&p),sizeof(Sobrecarga *));// Lee el archivo pero aún no es final de archivo, entonces entra al while


			while( !citasSalida.eof())
				{
				//citasEntrada.seekp((y+1-1)*sizeof(Sobrecarga*));

				cout<<"Asunto: ";
				cout<<p->DevolverAsunto();
				cout<<"\n";
				cout<<"Fecha:";
				cout<<p->DevolverDiaFecha();
				cout<<"/";
				cout<<p->DevolverMesFecha();
				cout<<"/";
				cout<<p->DevolverAnoFecha();
				cout<<"    ";
				cout<<"Inicio: ";
				cout<<p->DevolverHorasInicial();
				cout<<":";
				cout<<p->DevolverMinutosInicial();
				cout<<"   Final: ";
				cout<<p->DevolverHorasFinal();
				cout<<":";
				cout<<p->DevolverMinutosFinal();
				cout<<"\n";
				cout<<"Lugar: ";
				cout<<p->DevolverLugar();
				numero1=p->DevolverTipo();
					if(numero1==1)
						cout<<" Tipo:Trabajo";
					else
						cout<<" Tipo::Personal";
				cout<<"\n\n";
				citasSalida.read(reinterpret_cast< char *>(&p),sizeof(Sobrecarga *));

			}
				citasSalida.close();
	}
		else if (opc==6)
				{
					string linea;
					ifstream archivoCitas_entrada;
					archivoCitas_entrada.open("citas.txt");
					if(archivoCitas_entrada.fail())
					{
						cout<<"\n El archivo no se abrio con exito"
								<<"\n Compruebe que el archivo existe en realidad."
								<<endl;
						exit(1);
					}
					while (getline(archivoCitas_entrada,linea))

						cout<<linea<<endl;
						cout<<"\n";

					archivoCitas_entrada.close();
				}
				else
					opc=8;


	}while(opc<7);
cout<<"\n\n";

system("pause");
return 0;
//delete [] aSobreCarga;


}
int Menu()
{
	int opc;

	cout<<"\t\t** Menu Citas ** \n"
			<<"\t\t1. Agregar Cita\n"
			<<"\t\t2. Ver Cita \n"
			<<"\t\t3. Grabar citas en un archivo de texto\n"
			<<"\t\t4. Grabar citas en un archivo binario\n"
			<<"\t\t5. Leer datos binarios\n"
			<<"\t\t6. Leer todas las citas creadas durante las distintas veces de ejecucio\n"
			<<"\t\t   y que han sido guardas en el archivo de texto previamente\n"
			<<"\t\t7. Salir"<<endl;
			do
				{
				cout<<"Que quieres hacer?"<<endl;
				cin>>opc;
				}while(opc<1 || opc>7);

return opc;
}

