//---------------------------------------------------------------------------

#ifndef UPolinomio_mH
#define UPolinomio_mH
#include "UMemoria.h"
//---------------------------------------------------------------------------
const string datos_ids = "coef,exp,sig";
const string coefp = "coef";
const string expp = "exp";
const string sigp = "sig";

struct NodoMP {
	int coef;
	int exp;
	int sig;
};

typedef int direccion_m;

class Polinomio_m {
	private:
		CSMemoria *mem;
		direccion_m ptr_poli;
		int nt;
		direccion_m buscar_exponente(int exp);
		direccion_m buscar_termino_n(int i);
	public:
		Polinomio_m();
		bool es_cero();
		int grado();
		int coeficiente(int exp);
		void asignar_coeficiente(int coef, int exp);
		void poner_termino(int coef, int exp);
		int numero_terminos();
		int exponente(int nroter);
};
#endif
