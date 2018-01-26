/*
 * producto.h
 *
 *  Created on: 1 feb. 2017
 *      Author: Jorge
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include<iostream>
#include<string>
#include<fstream>

class Producto
{
	friend void operator >>(std::istream &entrada, Producto &pr);
private:
	char nombre[50];
	int unidades;
	float precio;
	float precio_final;
public:
	Producto();
	char* DevolverNombre();
	int DevolverUnidades();
	float DevolverPrecio();
	Producto DevolverProducto();
	void AsignaNombre(char[40]);
	void AsignarPrecio(float);
	void AsignarUnidades(int);
	void AsignarPreciofinal(float);
	float DevolverPrecioFinal();
};



#endif /* PRODUCTO_H_ */
