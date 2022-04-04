#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <fstream>
#include "Nodo.h"

using namespace std;

class Cola
{
	private:
		int frente;
		int fondo;
		pnodo cola[5];
	
	public:
	Cola()
	{
		frente = 0;
        fondo = -1;
        for(int i = 0; i < 5; i++)
		{
			cola[i] = NULL;
        }
    }
    bool colaVacia () {return fondo < frente;}        
	void insertar (string v);
	void eliminar ();
	void imprimir (int i);
	pnodo getNodo(int i);
	void insertNodo (string caracter, int i);
	void leerArch (int arch);
	void leerTodosArch ();
	void aPosfijoYEval (int i);
	void solucion ();
};

/*--------------------------------------------------------------------------------------------*/
/*-------------------------------------Metodos-de-la-cola-------------------------------------*/
/*--------------------------------------------------------------------------------------------*/

void Cola::insertar(string v)
{
	if(fondo < 5-1)
	{
		fondo++;
        cola[fondo] = new Nodo(v);      
    }
	else
        cout<<"La cola esta llena";
}

void Cola::insertNodo (string caracter, int i)
{
	pnodo aux = cola[i];
	
	while(aux->siguiente != NULL)
		aux = aux->siguiente;
	
	aux->siguiente = new Nodo(caracter);
}

void Cola::eliminar()
{
	if(!colaVacia())
        frente++;
        
    else
    	cout<<"La cola esta vacia";  
}

void Cola::imprimir(int i)
{
	if(i > 4 || i < 0)
	{
		cout<<"Error: El indice de la cola empieza en 0 y termina en 4."<<endl;
		return;
    }
	pnodo aux = cola[i];
	
	while(aux)
	{
		cout << aux->caracter <<" ";
		aux = aux->siguiente;
	}
	cout<<endl;
}

void Cola::leerArch(int arch)
{
	string archivo = "";

	if(arch == 1)
	    archivo = "Arch1.txt";
	if(arch == 2)
	    archivo = "Arch2.txt";
	if(arch == 3)
	    archivo = "Arch3.txt";
	if(arch == 4)
	    archivo = "Arch4.txt";
	if(arch == 5)
	    archivo = "Arch5.txt";
	
	ifstream file(archivo.c_str());
    string linea;
    
    while(!file.eof()){
    	getline(file, linea);
    	
    	if (cola[arch - 1] == NULL)
    	    cola[arch - 1] = new Nodo(linea);
    	else
    	    insertNodo(linea, arch - 1);
   }
   fondo = fondo + 1;
}

void Cola::leerTodosArch(){
	
	int aux = 1;
	
	while(aux <= 5){
		leerArch(aux);
		aux = aux + 1;
	}
	return;
}

bool esOperador (string & c){ //Funcion auxiliar, retorna true si el string que recibe es un operador matematico.

	if(c == "+") return true;
	if(c == "-") return true;
	if(c == "*") return true;
	if(c == "/") return true;
	if(c == "^") return true;
	if(c == "(") return true;
	if(c == ")") return true;
	else
	    return false;
	    
}

bool prioriMayorAfuera (string strDentro, string strFuera){ // Metodo que ayuda a evaluar la prioridad entre dos caracteres, retorna true si la de afuera es mayor.
	
	if (strDentro == "(")
	    return true;
	if (strFuera == "(" | strFuera == "^")
	    return true;

	else{
		if (strDentro == strFuera)
		    return false;
		else{
			if (strFuera == "+" | strFuera == "-")
			    return false;
			else{
				if(strFuera == "*" | strFuera == "/"){
					if (strDentro == "^")
					    return false;
					return true;
				}
			}
		}
	}
}

pnodo Cola::getNodo (int i){
	
	if(i > 4 || i < 0){
		cout<<"Error: El indice de la cola empieza en 0 y termina en 4."<<endl;
		return NULL;
    }
	pnodo aux = cola[i];
	return aux;
}
#endif
