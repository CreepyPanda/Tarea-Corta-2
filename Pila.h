#ifndef PILA_H
#define PILA_H

#include <iostream>
#include "Nodo.h"

using namespace std;

class Pila {

   public:
    Pila () {
       primero = NULL;	
	}
    ~Pila ();
	bool pilaVacia () {return primero == NULL;} 
    void push (string c);  //Metodo push para trabajar con caracteres.
    void pushFloat (float v);  //Metodo push para trabajar con enteros.
	void pop ();
	int largoPila ();
	void imprimir ();
	void imprimirFloat();
	string getTope ();     //Metodo para obtener el tope de una pila de caracteres.
	float getTopeFloat();		//Metodo para obtener el tope de una pila de enteros.

   private:
    pnodo primero;

   friend class Lista;
   friend class Cola;
};

/*------------------------------------- METODOS - DE - LA - PILA -------------------------------*/

Pila::~Pila (){ //Destructor
   pnodo aux;
   
   while(primero) {
      aux = primero;
      primero = primero->siguiente;
      delete aux;
   }
  
}

void Pila::push(string c){ //Insertar al inicio.
    
    pnodo aux;
    string preVal, newVal = c;
   
    if (pilaVacia()){
        primero = new Nodo(c);
        return;
    }
        
   	aux = primero;
    
   	while(aux->siguiente != NULL){
   		
	    preVal = aux->caracter;
   		aux->caracter = newVal;
   		newVal = preVal;
   		aux = aux->siguiente;
	}
	   
	preVal = aux->caracter;
	aux->caracter = newVal;
	aux->siguiente = new Nodo(preVal);

}

void Pila::pushFloat(float v){ //Insertar al inicio.
    
    pnodo aux;
    float preVal, newVal = v;
   
    if (pilaVacia()){
        primero = new Nodo(v);
        return;
    }
        
   	aux = primero;
    
   	while(aux->siguiente != NULL){
   		
	    preVal = aux->valor;
   		aux->valor = newVal;
   		newVal = preVal;
   		aux = aux->siguiente;
	}
	   
	preVal = aux->valor;
	aux->valor = newVal;
	aux->siguiente = new Nodo(preVal);

}

void Pila::pop(){ //Borrar al inicio
    
	if (pilaVacia()){
	    return;
    
    }else if (primero->siguiente == NULL) {
        pnodo temp=primero;
        primero= NULL;
        delete temp;
    }else{
        pnodo aux = primero;
        primero=primero->siguiente;
        delete aux;
    }
}

int Pila::largoPila(){ 
    
	int cont = 0;
	pnodo aux;
	aux = primero;
	
    if(pilaVacia())
        return cont;
    while(aux!=NULL) {
        aux = aux->siguiente;
        cont++;
	}
    return cont;
}

void Pila::imprimir() {
    //cout<<"Entro"<<endl;
    pnodo aux;
    if (primero == NULL){
        cout << "---> No hay elementos, pila vacia.\n";
        return;
    }
   	aux = primero;
	while(aux){
		cout << aux->caracter << "-> ";
		aux = aux->siguiente;
	}
	cout << endl;
}

void Pila::imprimirFloat() {

    pnodo aux;
    if (primero == NULL){
        cout << "---> No hay elementos, pila vacia.\n";
        return;
    }
   	aux = primero;
	while(aux){
		cout << aux->valor << "-> ";
		aux = aux->siguiente;
	}
	cout << endl;
}

string Pila::getTope(){
	
	if (primero != NULL)
	    return primero->caracter;
	return "Pila vacia.";
}

float Pila::getTopeFloat(){
	
	if (primero != NULL)
	    return primero->valor;
	return -1;
}


#endif
