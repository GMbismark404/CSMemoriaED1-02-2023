//---------------------------------------------------------------------------

#ifndef UListaCSMemoriaH
#define UListaCSMemoriaH
#include "UMemoria.h"
//---------------------------------------------------------------------------
const string sig = "siguiente";
const string dato = "dato";
const string dato_sig = "dato,sig";

class ListaCSMemoria {
	private:
		int ptr;
		int cantidad;
		CSMemoria *mem;
	public:
		ListaCSMemoria();
//		ListaCSMemoria(CSMemoria *m);
		int primero();
		int fin();
		int siguiente(int dir);
		int anterior(int dir);
		bool vacio();
		int recupera(int dir);
		int longitud();
		void inserta(int dir, int elemento);
		void inserta_primero(int elemento);
		void inserta_ultimo(int elemento);
		void suprime(int dir);
		void modifica(int dir, int elemento);
};
#endif
