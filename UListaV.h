//---------------------------------------------------------------------------

#ifndef UListaVH
#define UListaVH
#include <string>
#include <iostream>
//---------------------------------------------------------------------------
using namespace std;

const int MAX = 20;

typedef int direccion;

class ListaV {
private:
	int *elementos; // int elementos[MAXV];
	int cantidad;

public:
	ListaV();
	direccion fin();
	direccion primero();
	direccion siguiente(direccion dir);
	direccion anterior(direccion dir);
	bool vacio();
	int recupera(direccion dir);
	int longitud();
	void insertar(direccion dir, int e);
	void insertar_primero(int e);
	void insertar_ultimo(int e);
	void suprime(direccion dir);
	void modifica(direccion dir, int e);
	void Mostrar();
	direccion localiza(int e);
	void elimina_dato(int e);
	void anula();
};
#endif
