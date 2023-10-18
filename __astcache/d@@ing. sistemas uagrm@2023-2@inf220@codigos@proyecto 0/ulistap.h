//---------------------------------------------------------------------------

#ifndef UListaPH
#define UListaPH
#include <iostream>
#include <string>

using namespace std;
//---------------------------------------------------------------------------

struct NodoL{
	int elemento;
	NodoL *sig;
};

typedef NodoL *direccion_p;

class ListaP{
	private:
		NodoL *ptr;
		int cantidad;
	public:
		ListaP();
		direccion_p primero();
		direccion_p fin();
		direccion_p siguiente(direccion_p p);
		direccion_p anterior(direccion_p p);
		bool vacio();
		int recuperar(direccion_p p);
		int longitud();
		void insertar(NodoL *p, int element);
		void insertar_primero(int element);
		void insertar_ultimo(int element);
		void suprime(direccion_p p);
		void modifica(direccion_p p, int element);
		void Mostrar();
};
#endif
