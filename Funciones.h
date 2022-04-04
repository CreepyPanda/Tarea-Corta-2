#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include "Nodo.h"

using namespace std;

/*---------------------------------------------------------------------------------------------------------*/
/*------------------------------Funciones-para-crear-la-exprecion-postfijo---------------------------------*/
/*---------------------------------------------------------------------------------------------------------*/

int prioridadDentro(string caracter)
{
	if(caracter == "+")
		return 1;
    if(caracter == "-")
		return 1;
	if(caracter == "*")
		return 2;
    if(caracter == "/")
		return 2;
    if(caracter == "(")
		return 0;
    if(caracter == "^")
		return 3;
    else
    	return -1;
}

int prioridadFuera(string caracter)
{
	if(caracter == "+")
		return 1;
    if(caracter == "-")
		return 1;
	if(caracter == "*")
		return 2;
    if(caracter == "/")
		return 2;
    if(caracter == "(")
		return 5;
    if(caracter == "^")
		return 4;
    else
    	return -1;
}

bool validacionOperador(string caracter)
{
	if(caracter == "+")
		return true;
    if(caracter == "-")
		return true;
	if(caracter == "*")
		return true;
    if(caracter == "/")
		return true;
    if(caracter == "(")
		return true;
	if(caracter == ")")
		return true;
    if(caracter == "^")
		return true;
    else
    	return false;
}

#endif
