#ifndef NODO_H
#define NODO_H

#include <iostream>

using namespace std;

class Nodo
{
	public:
		Nodo (string c)
		{
			caracter = c;
			siguiente = NULL;
		}
		
		Nodo (float v)
		{
			valor = v;
			siguiente = NULL;
		}
		Nodo (string c, Nodo * signodo)
		{
			caracter = c;
			siguiente = signodo;
		}
		
		Nodo (float v, Nodo * signodo)
		{
			valor = v;
			siguiente = signodo;
		}
		
		private:
			float valor;
			string caracter;
			Nodo *siguiente;
		
		friend class Pila;
		friend class Cola;

};typedef Nodo *pnodo;

#endif
