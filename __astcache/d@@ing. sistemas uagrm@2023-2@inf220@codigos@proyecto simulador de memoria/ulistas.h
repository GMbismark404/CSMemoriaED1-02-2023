//---------------------------------------------------------------------------

#ifndef UListaSH
#define UListaSH
#include <iostream>
#include <string>
#include "UMemoria.h"
//---------------------------------------------------------------------------
using namespace std;

const string datoNL = "elemento,sig";
const string elemNL = "elemento";
const string sigNL = "sig";

 class ListaS{
 //Atributos
 private:
	int ptr_elementos;
	int longit;
	CSMemoria* mem;
 //Métodos
 public:
	ListaS();
	ListaS(CSMemoria* m);
	int fin();
	int primero();
	int siguiente(int dir);
	int anterior( int dir);
	bool vacia();
	int recupera(int dir);
	int longitud();
	void insertar( int dir, int elem);
	void insertar_primero(int elem);
	void insertar_ultimo(int elem);
	void suprime( int dir);
	void modifica( int dir, int elem) ;
	string to_str();
	int localiza(int e);
	void elimina_dato(int e);
	void anula();
    void Mostrar();
 };
#endif
