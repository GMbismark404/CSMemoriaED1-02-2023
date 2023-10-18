//---------------------------------------------------------------------------

#ifndef ULista_poliH
#define ULista_poliH
#include "UlistaP.h"
//---------------------------------------------------------------------------

class Polinomio {
	private:
		ListaP *pol;

		direccion_p buscar_exponente(int exp);
		direccion_p buscar_termino_n(int i);
	public:
		Polinomio();
		bool es_cero();
		int grado();
		int coeficiente(int exp);
		void asignar_coeficiente(int coef, int exp);
		void poner_termino(int coef, int exp);
		int numero_terminos();
		int exponente(int nter);
		direccion_p sumar(Polinomio *p1, Polinomio *p2);
		direccion_p restar(Polinomio *p1, Polinomio *p2);
		direccion_p multiplicar(Polinomio p1, Polinomio p2);
};
#endif
