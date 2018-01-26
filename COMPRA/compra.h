/*
 * compra.h
 *
 *  Created on: 1 feb. 2017
 *      Author: Jorge
 */

#ifndef COMPRA_H_
#define COMPRA_H_
#include<iostream>
#include<string>
#include<fstream>
#include"producto.h"

class Compra
{
	friend void operator>> (std::istream &ci, Compra* c1);

	friend void Imprimir(Producto []);
private:
	Producto p;
	char fecha[15];
public:
	void PerdirCantidadesProducto(Producto aProducto [], int &);
	void BuscarProducto(Producto aProducto [],int &);
	Compra();
	char* DevolverFecha();
	void AsignarNombreProducto(char[40]);
	char* DevolverNombreProducto();
	void CalcularPrecioProducto(Producto aProducto[], int &);
	void EliminarProducto(Producto aProducto[], int&);
	void ImprimirTicket(Producto aProducto[], int&);
	float TotalCompra(Producto aProducto[],int&);
};


#endif /* COMPRA_H_ */
