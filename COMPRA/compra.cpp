/*
 * compra.cpp
 *
 *  Created on: 1 feb. 2017
 *      Author: Jorge
 */
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<fstream>
#include"producto.h"
#include"compra.h"
#include<limits>
#include <windows.h>
using namespace std;

Compra::Compra()
	:p(Producto()), fecha("")
	{

	}

char* Compra::DevolverFecha()
{
	return fecha;
}

void Compra::AsignarNombreProducto(char nombreproducto[40])
{
	p.AsignaNombre(nombreproducto);
}
char* Compra::DevolverNombreProducto()
{
	return p.DevolverNombre();
}
void operator>> (istream &ci, Compra* c1)
{
	int colour;
	colour=0x07;
	int i;
	char *nombre;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<"Que producto quieres comprar"<<endl;

	ci>>c1->p;
	cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
	strcpy(nombre,c1->DevolverNombreProducto());
	//nombre=c1->DevolverNombreProducto();
	for(i=0;i<strlen(nombre);i++)
		{
			nombre[i]=toupper(nombre[i]);
		}
	c1->AsignarNombreProducto(nombre);

	//cout<<c1->DevolverNombreProducto();
}
void Compra::BuscarProducto(Producto aProducto[] ,int &a)
{
	Producto *aProducto1=new Producto [20];
	float precio;
	int indice;
	int b=0;
	int num,i,opc;
	char* nombre;
	char producto [50];
	ifstream archivoSalida;
		archivoSalida.open("productos.txt", ios::in);
	ofstream archivoEntrada;

		ifstream archivoSalida1;
		archivoSalida1.open("indice.txt", ios::in);


	strcpy(nombre,DevolverNombreProducto());

		while (archivoSalida.getline(producto,50))
		{
			num=0;
			for(i=0;i<strlen(nombre);i++)
				{
					if(nombre[i]==producto[i])
					{

						num++;

					}
					else
					{
						num=0;
					}

					if(num==strlen(nombre))
						{
					 aProducto1[b].AsignaNombre(producto);
					 cout<<aProducto1[b].DevolverNombre()<<endl;
					 archivoSalida>>precio;
					 aProducto1[b].AsignarPrecio(precio);
					 cout<<aProducto1[b].DevolverPrecio()<<endl;
								b++;
								num=0;

							}
						}
		}
		archivoSalida.close();
				if(b==1)
				{
					archivoSalida1>>a;
					archivoSalida1.close();
					aProducto[a]=aProducto1[0];
					a=a+1;
					archivoEntrada.open("indice.txt", ios::out);
					archivoEntrada<<a;
					archivoEntrada.close();
				}
				else  if(b==2)
				{
					cout<<"Tengo dos producto que coincides con ese nombre"<<endl;
					cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 ambos)"<<endl;
					cin>>opc;
						if(opc==1)
						{
							cout<<"Has elegido "<<aProducto1[0].DevolverNombre();
							//archivoSalida1.open("indice.txt", ios::in);
							archivoSalida1>>a;
							archivoSalida1.close();
							aProducto[a]=aProducto1[0];
							a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
						}
							if(opc==2)
								{
									cout<<"Has elegido "<<aProducto1[1].DevolverNombre();
									//archivoSalida1.open("indice.txt", ios::in);
									archivoSalida1>>a;
									archivoSalida1.close();
									aProducto[a]=aProducto1[1];
									a=a+1;
									archivoEntrada.open("indice.txt", ios::out);
									archivoEntrada<<a;
									archivoEntrada.close();
								}
							if(opc==3)
								{
									cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<"y "<<aProducto1[1].DevolverNombre();
								//	archivoSalida1.open("indice.txt", ios::in);
									archivoSalida1>>a;
									archivoSalida1.close();
									aProducto[a]=aProducto1[0];
									aProducto[a+1]=aProducto1[1];
									a=a+2;
									archivoEntrada.open("indice.txt", ios::out);
									archivoEntrada<<a;
									archivoEntrada.close();
								}

							}

				else if(b==3)
											{
												cout<<"Tengo tres productos que coincides con ese nombre"<<endl;
												cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero y 4 ambos)"<<endl;
												cin>>opc;
												if(opc==1)
													{
														cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
														//archivoSalida1.open("indice.txt", ios::in);
														archivoSalida1>>a;
														archivoSalida1.close();
														aProducto[a]=aProducto1[0];
														a=a+1;
														archivoEntrada.open("indice.txt", ios::out);
														archivoEntrada<<a;
														archivoEntrada.close();
													}
												if(opc==2)
													{
														cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
														//archivoSalida1.open("indice.txt", ios::in);
														archivoSalida1>>a;
																			archivoSalida1.close();
																							aProducto[a]=aProducto1[1];
																							a=a+1;
														archivoEntrada.open("indice.txt", ios::out);
														archivoEntrada<<a;
														archivoEntrada.close();
													}

												if(opc==3)
												{
													cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
													//archivoSalida1.open("indice.txt", ios::in);
													archivoSalida1>>a;
													archivoSalida1.close();
													aProducto[a]=aProducto1[2];
													a=a+1;
													archivoEntrada.open("indice.txt", ios::out);
													archivoEntrada<<a;
													archivoEntrada.close();
												}

												if(opc==4)
												{
													cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<"y "<<aProducto[2].DevolverNombre()<<endl;
													//archivoSalida1.open("indice.txt", ios::in);
													archivoSalida1>>a;
													archivoSalida1.close();
													aProducto[a]=aProducto1[0];
													aProducto[a+1]=aProducto1[1];
													aProducto[a+2]=aProducto1[2];
													a=a+3;
													archivoEntrada.open("indice.txt", ios::out);
													archivoEntrada<<a;
													archivoEntrada.close();
												}

											}

				else if(b==4)
									{
										cout<<"Tengo cuatro productos que coincides con ese nombre"<<endl;
										cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero, 4 cuarto y 5 ambos)"<<endl;
										cin>>opc;
										if(opc==1)
											{
												cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
												//archivoSalida1.open("indice.txt", ios::in);
												archivoSalida1>>a;
												archivoSalida1.close();
												aProducto[a]=aProducto1[0];
												a=a+1;
												archivoEntrada.open("indice.txt", ios::out);
												archivoEntrada<<a;
												archivoEntrada.close();
											}
										if(opc==2)
											{
												cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
												//archivoSalida1.open("indice.txt", ios::in);
												archivoSalida1>>a;
												archivoSalida1.close();
												aProducto[a]=aProducto1[1];
												a=a+1;
												archivoEntrada.open("indice.txt", ios::out);
												archivoEntrada<<a;
												archivoEntrada.close();
											}

										if(opc==3)
											{
												cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
												//archivoSalida1.open("indice.txt", ios::in);
												archivoSalida1>>a;
												archivoSalida1.close();
												aProducto[a]=aProducto1[2];
												a=a+1;
												archivoEntrada.open("indice.txt", ios::out);
												archivoEntrada<<a;
												archivoEntrada.close();
											}

										if(opc==4)
											{
												cout<<"Has elegido "<<aProducto1[3].DevolverNombre()<<endl;
											//	archivoSalida1.open("indice.txt", ios::in);
												archivoSalida1>>a;
																					archivoSalida1.close();
																					aProducto[a]=aProducto1[3];
																					a=a+1;
												archivoEntrada.open("indice.txt", ios::out);
												archivoEntrada<<a;
												archivoEntrada.close();
											}
										if(opc==5)
										{
											cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<"y "<<aProducto1[2].DevolverNombre()<<aProducto1[3].DevolverNombre()<<endl;
											//archivoSalida1.open("indice.txt", ios::in);
											archivoSalida1>>a;
											archivoSalida1.close();
											aProducto[a]=aProducto1[0];
											aProducto[a+1]=aProducto1[1];
											aProducto[a+2]=aProducto1[2];
											aProducto[a+3]=aProducto1[3];
											a=a+4;
											archivoEntrada.open("indice.txt", ios::out);
											archivoEntrada<<a;
											archivoEntrada.close();
										}

									}


				else if(b==5)
						{
							cout<<"Tengo cinco productos que coincides con ese nombre"<<endl;
							cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero, 4 cuarto, 5 quinto y 6 ambos)"<<endl;
							cin>>opc;
							if(opc==1)
							{
								cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
								//archivoSalida1.open("indice.txt", ios::in);
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
								}
							if(opc==2)
							{
								cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[1];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}

							if(opc==3)
								{
								cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
								}

							if(opc==4)
							{
								cout<<"Has elegido "<<aProducto1[3].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}
							if(opc==5)
							{
							cout<<"Has elegido "<<aProducto1[4].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
							}
							if(opc==6)
							{
								cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<"y ";
								cout<<aProducto1[2].DevolverNombre()<<aProducto1[3].DevolverNombre()<<aProducto1[4].DevolverNombre()<<endl;
								archivoSalida1>>a;
								archivoSalida1.close();
								aProducto[a]=aProducto1[0];
								aProducto[a]=aProducto1[0];
								aProducto[a+1]=aProducto1[1];
								aProducto[a+2]=aProducto1[2];
								aProducto[a+3]=aProducto1[3];
								aProducto[a+4]=aProducto1[4];
								a=a+5;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}

				}

			else if(b==6)
					{
					cout<<"Tengo seis productos que coincides con ese nombre"<<endl;
					cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero, 4 cuarto, 5 quinto, 6 sexto y 7 ambos)"<<endl;
					cin>>opc;
						if(opc==1)
						{
							cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
						}
						if(opc==2)
						{
							cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada<<a;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada.close();
						}

						if(opc==3)
						{
							cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
							}

						if(opc==4)
							{
								cout<<"Has elegido "<<aProducto1[3].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}
						if(opc==5)
							{
									cout<<"Has elegido "<<aProducto1[4].DevolverNombre()<<endl;
									archivoSalida1>>a;
																		archivoSalida1.close();
																		aProducto[a]=aProducto1[0];
																		a=a+1;
									archivoEntrada.open("indice.txt", ios::out);
									archivoEntrada<<a;
									archivoEntrada.close();
							}
						if(opc==6)
							{
							cout<<"Has elegido "<<aProducto1[5].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
							}
						if(opc==7)
						{
							cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<"y "<<aProducto1[2].DevolverNombre();
							cout<<aProducto1[3].DevolverNombre()<<aProducto1[4].DevolverNombre()<<aProducto1[5].DevolverNombre()<<endl;
							archivoSalida1>>a;
							archivoSalida1.close();
							aProducto[a]=aProducto1[0];
							aProducto[a+1]=aProducto1[1];
							aProducto[a+2]=aProducto1[2];
							aProducto[a+3]=aProducto1[3];
							aProducto[a+4]=aProducto1[4];
							aProducto[a+4]=aProducto1[5];
							a=a+6;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
						}


					}
		else if(b==7)
					{
					cout<<"Tengo siete productos que coincides con ese nombre"<<endl;
					cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero, 4 cuarto, 5 quinto, 6 sexto 7 y 8 todos)"<<endl;
					cin>>opc;
					if(opc==1)
					{
					cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
					archivoSalida1>>a;
														archivoSalida1.close();
														aProducto[a]=aProducto1[0];
														a=a+1;
					archivoEntrada.open("indice.txt", ios::out);
					archivoEntrada<<a;
					archivoEntrada.close();
					}
					if(opc==2)
						{
						cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
						archivoSalida1>>a;
															archivoSalida1.close();
															aProducto[a]=aProducto1[0];
															a=a+1;
						archivoEntrada.open("indice.txt", ios::out);
						archivoEntrada<<a;
						archivoEntrada.close();
						}

					if(opc==3)
						{
							cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
						}

					if(opc==4)
						{
							cout<<"Has elegido "<<aProducto1[3].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
							}
					if(opc==5)
							{
								cout<<"Has elegido "<<aProducto1[4].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}
					if(opc==6)
							{
							cout<<"Has elegido "<<aProducto1[5].DevolverNombre()<<endl;
							archivoSalida1>>a;
																archivoSalida1.close();
																aProducto[a]=aProducto1[0];
																a=a+1;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
							}
					if(opc==7)
							{
								cout<<"Has elegido "<<aProducto1[6].DevolverNombre()<<endl;
								archivoSalida1>>a;
																	archivoSalida1.close();
																	aProducto[a]=aProducto1[0];
																	a=a+1;
								archivoEntrada.open("indice.txt", ios::out);
								archivoEntrada<<a;
								archivoEntrada.close();
							}
					if(opc==8)
						{
							cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<", "<<aProducto1[2].DevolverNombre()<<", ";
							cout<<aProducto1[3].DevolverNombre()<<", "<<aProducto1[4].DevolverNombre()<<", "<<aProducto1[5].DevolverNombre();
							cout<<aProducto1[6].DevolverNombre()<<endl;
							archivoSalida1>>a;
							archivoSalida1.close();
							aProducto[a]=aProducto1[0];
							aProducto[a+1]=aProducto1[1];
							aProducto[a+2]=aProducto1[2];
							aProducto[a+3]=aProducto1[3];
							aProducto[a+4]=aProducto1[4];
							aProducto[a+4]=aProducto1[5];
							aProducto[a+5]=aProducto1[6];
							aProducto[a+6]=aProducto1[7];
							a=a+7;
							archivoEntrada.open("indice.txt", ios::out);
							archivoEntrada<<a;
							archivoEntrada.close();
						}


					}
				if(b==8)
				 {
				 			cout<<"Tengo ocho productos que coincides con ese nombre"<<endl;
				 			cout<<"Cual quieres elegir (1 el primero, 2 el segundo, 3 el tercero, 4 cuarto, 5 quinto, 6 sexto 7,septimo, 8 octavo y 9 todos)"<<endl;
				 			cin>>opc;
				 			if(opc==1)
				 				{
				 					cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<endl;
				 					archivoSalida1>>a;
				 					archivoSalida1.close();
				 					aProducto[a]=aProducto1[0];
				 					a=a+1;
				 					archivoEntrada.open("indice.txt", ios::out);
				 					archivoEntrada<<a;
				 					archivoEntrada.close();
				 				}
				 			if(opc==2)
				 					{
				 					cout<<"Has elegido "<<aProducto1[1].DevolverNombre()<<endl;
				 					archivoSalida1>>a;
				 					archivoSalida1.close();
				 					aProducto[a]=aProducto1[1];
				 					a=a+1;
				 					archivoEntrada.open("indice.txt", ios::out);
				 					archivoEntrada<<a;
				 					archivoEntrada.close();
				 					}

				 			if(opc==3)
				 				{
				 					cout<<"Has elegido "<<aProducto1[2].DevolverNombre()<<endl;
				 					archivoSalida1>>a;
				 					archivoSalida1.close();
				 					aProducto[a]=aProducto1[2];
				 					a=a+1;
				 					archivoEntrada.open("indice.txt", ios::out);
				 					archivoEntrada<<a;
				 					archivoEntrada.close();
				 				}

				 			if(opc==4)
				 				{
				 					cout<<"Has elegido "<<aProducto1[3].DevolverNombre()<<endl;
				 					archivoSalida1>>a;
				 					archivoSalida1.close();
				 					aProducto[a]=aProducto1[3];
				 					a=a+1;
				 					archivoEntrada.open("indice.txt", ios::out);
				 					archivoEntrada<<a;
				 					archivoEntrada.close();
				 					}
				 			if(opc==5)
				 				{
				 					cout<<"Has elegido "<<aProducto1[4].DevolverNombre()<<endl;
				 					archivoSalida1>>a;
				 					archivoSalida1.close();
				 					aProducto[a]=aProducto1[4];
				 					a=a+1;
				 					archivoEntrada.open("indice.txt", ios::out);
				 					archivoEntrada<<a;
				 					archivoEntrada.close();
				 				}
				 					if(opc==6)
				 							{
				 							cout<<"Has elegido "<<aProducto1[5].DevolverNombre()<<endl;
				 							archivoSalida1>>a;
				 																archivoSalida1.close();
				 																aProducto[a]=aProducto1[5];
				 																a=a+1;
				 							archivoEntrada.open("indice.txt", ios::out);
				 							archivoEntrada<<a;
				 							archivoEntrada.close();
				 							}
				 					if(opc==7)
				 							{
				 								cout<<"Has elegido "<<aProducto1[6].DevolverNombre()<<endl;
				 								archivoSalida1>>a;
				 																	archivoSalida1.close();
				 																	aProducto[a]=aProducto1[6];
				 																	a=a+1;
				 								archivoEntrada.open("indice.txt", ios::out);
				 								archivoEntrada<<a;
				 								archivoEntrada.close();
				 							}
				 					if(opc==8)
				 						{
				 						cout<<"Has elegido "<<aProducto1[7].DevolverNombre()<<endl;
				 						archivoSalida1>>a;
				 															archivoSalida1.close();
				 															aProducto[a]=aProducto1[7];
				 															a=a+1;;
				 						archivoEntrada.open("indice.txt", ios::out);
				 						archivoEntrada<<a;
				 						archivoEntrada.close();
				 						}
				 					if(opc==9)
				 					{
				 						cout<<"Has elegido "<<aProducto1[0].DevolverNombre()<<", "<<aProducto1[1].DevolverNombre()<<", "<<aProducto1[2].DevolverNombre()<<", "<<aProducto1[3].DevolverNombre()<<", ";
				 						cout<<aProducto1[4].DevolverNombre()<<", "<<aProducto1[5].DevolverNombre();
				 						cout<<", "<<aProducto1[6].DevolverNombre()<<", "<<aProducto1[7].DevolverNombre()<<endl;
				 						archivoSalida1>>a;
				 						archivoSalida1.close();
				 						aProducto[a]=aProducto1[0];
				 						aProducto[a+1]=aProducto1[1];
				 						aProducto[a+2]=aProducto1[2];
				 						aProducto[a+3]=aProducto1[3];
				 						aProducto[a+4]=aProducto1[4];
				 						aProducto[a+5]=aProducto1[5];
				 						aProducto[a+6]=aProducto1[6];
				 						aProducto[a+7]=aProducto1[7];
				 						aProducto[a+8]=aProducto1[8];
				 						a=a+8;
				 						archivoEntrada.open("indice.txt", ios::out);
				 						archivoEntrada<<a;
				 						archivoEntrada.close();
				 					}
				 					else{}

				}

		else if(b==0)
				{
					cout<<"No está ese producto en este momento"<<endl;
					num=0;
				}
}
void Compra::PerdirCantidadesProducto(Producto aProducto [], int &a)
{
	int unidadesproducto;
	int i;
	int colour;
	colour=0x07;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour),cout<<"Ahora vamos a introducir las cantidades que vas a necesitar de cada producto\n";
	cout<<"Un 0 si al final has decidido no comprar el producto \n";
	cout<<"Iremos producto a producto en orden que elegiste en el orden que los fuiste añadiendo\n";
	cout<<"Introduce unidades validas(>0) O 0 para eliminar el producto de la compra\n";
	for(i=0;i<a;i++)
	{
		do
		{
					cout<<"\n\nCuantas unidades quieres del producto "<<aProducto[i].DevolverNombre()<<"\n";

					cin>>unidadesproducto;
					if(unidadesproducto==0)

						aProducto[i].AsignaNombre("");

					aProducto[i].AsignarUnidades(unidadesproducto);


		} while(unidadesproducto<0);
	}

}
void Compra::CalcularPrecioProducto(Producto aProducto[], int &a)
{
	int unidades;
	float precio;
	int i;
	float precioproducto;
	for(i=0;i<a;i++)
	{
		precio=aProducto[i].DevolverPrecio();
		unidades=aProducto[i].DevolverUnidades();
		precioproducto=precio*unidades;
		aProducto[i].AsignarPreciofinal(precioproducto);
	}
}
void Compra::EliminarProducto(Producto aProducto[], int& a)
{
	int indice;
	int num=0;
	char* nombre;
	int b=0;
	int i;
	ifstream archivoSalida;
	ofstream archivoEntrada;
	for(i=0;i<a;i++)
	{
				if(strcmp(aProducto[i].DevolverNombre(),"")==0)
				{
				//	num++;
					archivoSalida.open("indice.txt", ios::in);
										archivoSalida>>indice;
										archivoSalida.close();
										indice=indice-num;
										archivoEntrada.open("indice.txt", ios::out);
															archivoEntrada<<indice;
															archivoEntrada.close();
//num=0;
				}
				else
				{
					aProducto[b]=aProducto[i];
					b++;
				//num=0;
				}

		}

	}


void Compra:: ImprimirTicket(Producto aProducto[], int&a)
{
	int colour=0x09;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colour);
	cout<<"N\tProducto\t\t\t\tCantidad\tPrecio Unidad\tPrecio Total\n\n";
	for(int i=0;i<a;i++)
	{
			cout<<i+1<<"\t"<<left<<setw(40)<<aProducto[i].DevolverNombre()<<setw(4)<<aProducto[i].DevolverUnidades()<<"\t\t"<<setw(5)<<fixed<<setprecision(2)<<aProducto[i].DevolverPrecio()<<"\t\t"<<aProducto[i].DevolverPrecioFinal()<<endl;


	}

}
float Compra::TotalCompra(Producto aProducto[],int&a )
{
	int i;
	float preciototal=0.00;
	for(i=0;i<a;i++)
		{
		preciototal=preciototal+aProducto[i].DevolverPrecioFinal();

	}
	return preciototal;
}
