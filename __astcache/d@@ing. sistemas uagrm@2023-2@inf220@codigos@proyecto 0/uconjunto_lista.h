//---------------------------------------------------------------------------

#ifndef UConjunto_listaH
#define UConjunto_listaH
#include "UListaP.h"
//---------------------------------------------------------------------------
using namespace std;

class ConjuntoL{
	private:
		ListaP *elemento;
	public:
		ConjuntoL();
		bool vacio();
		bool pertenece(int e);
		void inserta(int e);
		int cardinal();
		int ordinal(int e);
		void suprime(int e);
		int muestrea();
        void mostrar_conjunto();
//		string to_str();
 };

#endif
