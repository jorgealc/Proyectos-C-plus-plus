/*
 * juego.cpp
 *
 *  Created on: 12 ene. 2017
 *      Author: Jorge
 */

#include<time.h>
#include <iostream>
#include <new>
#include<string>
#include<cstdlib>
#include<cstring>
using namespace std;

int main() {
	int opc,i,u,intentos, m, l, b,num, longitud, intentos1;
	char a[1];
	char resp;
	bool valor;
	valor=false;
	char aPalabras[10][20]={{"pelo"},{"cama"},{"preciosa"},{"guapa"},{"arbol"},{"cuatro"},{"sala"},{"ir"},{"par"},{"cinco"}};
	char aPalabras2[10][20]={{"calcetin"},{"frotar"},{"mileruista"},{"saber"},{"ganar"},{"triangulo"},{"defensa"},{"traje"},{"rubio"},{"moreno"}};
	char aPalabras3[10][20]={{"calabaza"},{"cama"},{"gragea"},{"granizo"},{"pelicano"},{"aguilucho"},{"incumbencia"},{"riachuelo"},{"falacia"},{"anticonstitucional"}};
	char Palabra[20];
	char Palabra2[20];
	cout<<"Bienvenido al juego Ahorcado de Jorge!!!!"<<endl;
	cout<<"Las reglas han sido establecidas en base a Jorge,\nsi por algun motivo le parece dificil, pongase en contacto con el. Gracias"<<endl;
	cout<<"A continucacion se os mostrara el numero de letras\nque forman la letra a resolver.!!!"<<endl;
	cout<<"Que comience el juego"<<endl;
	for(i=0;i<=20;i++)
	{
		Palabra[i]='\0';
		Palabra2[i]='\0';
	}

	cout<<"Que nivel de juego quieres\n"<<"1-Facil\n2-Normal\n3-Dificil"<<endl;
	cin>>opc;
	cout<<"\n";
	if (opc==1)
	{
	srand((unsigned)time(NULL));
		num=(rand() % 9)+1;

		strcpy(Palabra,aPalabras[num]);

		longitud=strlen(Palabra);
		intentos=7;
		intentos1=7;
	for(i=0;i<longitud;i++)
	{
		Palabra2[i]='\0';
		cout<<"X ";
	}
	cout<<"\n";
	for(i=0;i<	longitud;i++)
		{

		cout<<"- ";
		}
	cout<<"\n Vas a tener "<<intentos<<" intentos para resolver el juego. Yo lo he conseguido."<<endl;
	do
	{
		cout<<"\nIntroduce un caracter"<<endl;
					cin>>a[0];

				for(b=0;b<longitud;b++)
					{
						if(Palabra[b]==a[0] && valor==false)
							{
							valor=true;
							Palabra2[b]=a[0];
							m=b;

							for(l=b+1;l<=longitud;l++)
								{
									if(Palabra[l]==a[0] && valor==true)
										Palabra2[l]=a[0];
									else
										Palabra2[m]=a[0];
								}

							}


						else if(Palabra2[b]=='\0')
						{

						Palabra2[b]='X';
						}

					}

					if(valor==true)
					{
						cout<<"Si!! :))))).\nTodavía te quedan "<<intentos<<" intentos\n"<<endl;
					}

					else
					{
						intentos--;
						cout<<"No :(((((. La letra introducida no se encuentra en la palabra.\nTe quedan "<<intentos<<" intentos"<<endl;
						if(intentos==(intentos1-1)&& intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n";
						}

						else if(intentos==intentos1-2&& intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<"\n";
						}
						else if(intentos==intentos1-3 && intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<endl;
						}
						else if(intentos==intentos1-4 && intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<endl;
						}
						else if(intentos==intentos1-5 && intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<endl;
						}
						else if(intentos==intentos1-6 && intentos!=0)
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                       "<<"/"<<endl;
						}
						else
						{
							cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                       "<<"/"<<" "<<char(92)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n";

						}
						cout<<"\n\n\n";
					}
				for(int z=0;z<longitud;z++)
					{
						cout<<" "<<Palabra2[z];
					}
						opc=strcmp(Palabra,Palabra2);




				valor=false;



	}while(opc !=0 && intentos>0); //Sigue entrando en el while porque intentos es menor q 9
	}
	else if(opc==2)
	{
		srand((unsigned)time(NULL));
				num=(rand() % 9)+1;

				strcpy(Palabra,aPalabras2[num]);

				longitud=strlen(Palabra);
				intentos=(longitud/2)+1;
				intentos1=(longitud/2)+1;
				if(intentos==8 ||intentos==7)
				{
					intentos1=6;
					intentos=6;
				}
			for(i=0;i<longitud;i++)
			{
				Palabra2[i]='\0';
				cout<<"X ";
			}
			cout<<"\n";
			for(i=0;i<longitud;i++)
				{

				cout<<"- ";
				}
			cout<<"\n Vas a tener "<<intentos<<" intentos para resolver el juego. Yo lo he conseguido."<<endl;
			do
			{
				cout<<"\nIntroduce un caracter"<<endl;
							cin>>a[0];

						for(b=0;b<longitud;b++)
							{
								if(Palabra[b]==a[0] && valor==false)
									{
									valor=true;
									Palabra2[b]=a[0];
									m=b;

									for(l=b+1;l<=longitud;l++)
										{
											if(Palabra[l]==a[0] && valor==true)
												Palabra2[l]=a[0];
											else
												Palabra2[m]=a[0];
										}

									}


								else if(Palabra2[b]=='\0')
								{

								Palabra2[b]='X';
								}

							}

							if(valor==true)
							{
								cout<<"Si!! :))))).\nTodavía te quedan "<<intentos<<" intentos\n"<<endl;
							}

							else
							{
								intentos--;
								cout<<"No :(((((. La letra introducida no se encuentra en la palabra.\nTe quedan "<<intentos<<" intentos"<<endl;
								if(intentos==(intentos1-1)&& intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n";
								}

								else if(intentos==intentos1-2&& intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<"\n";
								}
								else if(intentos==intentos1-3 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<endl;
								}
								else if(intentos==intentos1-4 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<endl;
								}
								else if(intentos==intentos1-5 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<endl;
								}
								else
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                       "<<"/"<<" "<<char(92)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n";

								}
								cout<<"\n\n\n";
							}
						for(int z=0;z<longitud;z++)
							{
								cout<<" "<<Palabra2[z];
							}
								opc=strcmp(Palabra,Palabra2);




						valor=false;



			}while(opc !=0 && intentos>0); //Sigue entrando en el while porque intentos es menor q 9
	}
	else
	{
		srand((unsigned)time(NULL));
				num=(rand() % 9)+1;

				strcpy(Palabra,aPalabras3[num]);

				longitud=strlen(Palabra);
				intentos=longitud/2;
				intentos1=longitud/2;
				if(intentos==8 ||intentos==7||intentos==9)
				{

					intentos1=6;
					intentos=6;
				}
			for(i=0;i<longitud;i++)
			{
				Palabra2[i]='\0';
				cout<<"X ";
			}
			cout<<"\n";
			for(i=0;i<longitud;i++)
				{

				cout<<"- ";
				}
			cout<<"\n Vas a tener "<<intentos<<" intentos para resolver el juego. Yo lo he conseguido."<<endl;
			do
			{
				cout<<"\nIntroduce un caracter"<<endl;
							cin>>a[0];

						for(b=0;b<longitud;b++)
							{
								if(Palabra[b]==a[0] && valor==false)
									{
									valor=true;
									Palabra2[b]=a[0];
									m=b;

									for(l=b+1;l<=longitud;l++)
										{
											if(Palabra[l]==a[0] && valor==true)
												Palabra2[l]=a[0];
											else
												Palabra2[m]=a[0];
										}

									}


								else if(Palabra2[b]=='\0')
								{

								Palabra2[b]='X';
								}

							}

							if(valor==true)
							{
								cout<<"Si!! :))))).\nTodavía te quedan "<<intentos<<" intentos\n"<<endl;
							}

							else
							{
								intentos--;
								cout<<"No :(((((. La letra introducida no se encuentra en la palabra.\nTe quedan "<<intentos<<" intentos"<<endl;
								if(intentos==(intentos1-1)&& intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n";
								}

								else if(intentos==intentos1-2&& intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<"\n";
								}
								else if(intentos==intentos1-3 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<endl;
								}
								else if(intentos==intentos1-4 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<endl;
								}
								else if(intentos==intentos1-5 && intentos!=0)
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<endl;
								}
								else
								{
									cout<<"\n"<<"\n"<<char(221)<<"------------------------"<<char(221)<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                        "<<"0"<<"\n"<<char(221)<<"                        "<<"|"<<"\n"<<char(221)<<"                       "<<char(92)<<"|"<<"/"<<"\n"<<char(221)<<"                        "<<char(221)<<"\n"<<char(221)<<"                       "<<"/"<<" "<<char(92)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n"<<char(221)<<"\n";

								}
								cout<<"\n\n\n";
							}
						for(int z=0;z<longitud;z++)
							{
								cout<<" "<<Palabra2[z];
							}
								opc=strcmp(Palabra,Palabra2);




						valor=false;



			}while(opc !=0 && intentos>0); //Sigue entrando en el while porque intentos es menor q 9
	}
			if(intentos==0)
				{
				cout<<"\n"<<"El juego ha terminado!! \n"<<"\nLa palabra era ";
					for(int p=0;p<longitud;p++)
					{
						cout<<char(Palabra[p]-32);
						cout<<" ";
					}
				cout<<"\n\nQuieres volver a retarlo? Ya sabes"<<endl;
				}
			else
			{
				cout<<"\n"<<"Dificil asumirlo pero has sido mas listo que Jorge\n.\nQuieres volver a retarlo, ya sabes"<<endl;
				cout<<("\n");
			}
				cout<<"Introdue una S(Si) (minusculas) y una N (No)(minusculas) para no\ncontinuar con el juego"<<endl;
				cin>>resp;
				if(resp=='s')
				{
					cout<<"\n\n\n";
					main();
				}

				else
	system("pause");



		return 0;


}
