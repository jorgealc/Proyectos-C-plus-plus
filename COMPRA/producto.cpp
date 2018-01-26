/*
 * producto.cpp
 *
 *  Created on: 1 feb. 2017
 *      Author: Jorge
 */
#include<iostream>
#include<iomanip>
#include<cstring>
#include<fstream>
#include"producto.h"
using namespace std;

Producto::Producto()
	:nombre(""), unidades(0), precio(0.0),precio_final(0.0)
{

}

char* Producto::DevolverNombre()
{
	return nombre;
}

int Producto::DevolverUnidades()
{
	return unidades;
}

float Producto::DevolverPrecio()
{
	return precio;
}
void Producto::AsignaNombre(char nombreproducto[40])
{
	strcpy(nombre,nombreproducto);
}
void operator >>(istream &entrada, Producto &pr)
{
	entrada>>setw( 40 )>>pr.nombre;

}
void Producto::AsignarPrecio(float precioproducto)
{
	precio=precioproducto;
}
void Producto::AsignarUnidades(int unidadesproducto)
{
	unidades=unidadesproducto;
}
void Producto:: AsignarPreciofinal(float precioproducto)
{
	precio_final=precioproducto;
}
float Producto:: DevolverPrecioFinal()
{
	return precio_final;
}
