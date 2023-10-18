//---------------------------------------------------------------------------

#ifndef UPolinomio_pH
#define UPolinomio_pH
#include "UlistaP.h"
//---------------------------------------------------------------------------

class Polinomio_p {
	private:
		ListaP *pol;

		direccion_p buscar_exponente(int exp);
		direccion_p buscar_termino_n(int i);
	public:
		Polinomio_p();
		bool es_cero();
		int grado();
		int coeficiente(int exp);
		int exponente(int nter);
		void asignar_coeficiente(int coef, int exp);
		void poner_termino(int coef, int exp);
		int numero_terminos();
		void sumar(Polinomio_p *p1, Polinomio_p *p2);
		void restar(Polinomio_p *p1, Polinomio_p *p2);
		void multiplicar(Polinomio_p p1, Polinomio_p p2);
		void derivar();
		string convertir_string();
		void Mostrar();
};
#endif
