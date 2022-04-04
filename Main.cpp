#include <iostream>
#include "Nodo.h"
#include "Cola.h"
#include "Pila.h"
#include "Funciones.h"

using namespace std;

int main()
{
	Cola cola;
	
	cola.leerTodosArch();
	
	for(int i = 0; i<=4; i++)
		cola.imprimir(i);	
}
