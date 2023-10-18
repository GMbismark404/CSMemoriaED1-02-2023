//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPolinomio_p.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polinomio_p::Polinomio_p(){
	pol = new ListaP;
}

direccion_p Polinomio_p::buscar_exponente(int exp){
direccion_p dir = pol->siguiente(pol->primero());
	if (dir != NULL) {
		direccion_p dir_exp = NULL;
		while ((dir != NULL) && (dir_exp = NULL)){
			if (pol->recuperar(dir) == exp)
				dir_exp = dir;
			dir = pol->siguiente(pol->siguiente(dir));
		}
	return dir_exp;
	}
	return NULL;
}

bool Polinomio_p::es_cero(){
	return pol->vacio();
}

direccion_p Polinomio_p::buscar_termino_n(int i){
direccion_p dir = pol->primero();
int nt = 0;
	if (dir != NULL) {
		direccion_p dir_ter = NULL;
		while ((dir != NULL) && (dir_ter == NULL)){
			nt++;
			if (nt == i) {
				dir_ter = dir;
			}
		dir = pol->siguiente(pol->siguiente(dir));
		}
	return dir_ter;
	}
return NULL;
}

int Polinomio_p::grado(){
direccion_p dir = pol->siguiente(pol->primero());
	if (dir != NULL) {
		int maxg = pol->recuperar(dir);
		while (dir != NULL){
			if (pol->recuperar(dir) > maxg)
				maxg = pol->recuperar(dir);
			dir = pol->siguiente(pol->siguiente(dir));
		}
	return maxg;
	}
return 0;
}

int Polinomio_p::coeficiente(int exp){
direccion_p dir;
	if (dir != NULL) {
		return pol->recuperar(pol->anterior(dir));
	}
	return 0;
}

void Polinomio_p::asignar_coeficiente(int coef, int exp){
	direccion_p dir;
	if (dir != NULL) {
		direccion_p dir_coef = pol->anterior(dir);
		pol->modifica(dir_coef, coef);
		if (coef == 0) {
			pol->suprime(dir);
			pol->suprime(dir_coef);
		}
	}
	cout << "Error";
}

void Polinomio_p::poner_termino(int coef, int exp){
direccion_p dir_exp;
	if (dir_exp != NULL) {
		direccion_p dir_coef = pol->anterior(dir_exp);
		pol->modifica(dir_coef, pol->recuperar(dir_coef) + coef);
		if (pol->recuperar(dir_coef) == 0) {
			pol->suprime(dir_exp);
            pol->suprime(dir_coef);
		}
	}
}

int Polinomio_p::numero_terminos(){
return pol->longitud() / 2;
}

int Polinomio_p::exponente(int nter){
direccion_p dir = buscar_termino_n(nter);
	if (dir != NULL) {
		return pol->recuperar(pol->siguiente(dir));
	}
return 0;
}

void Polinomio_p::sumar(Polinomio_p *p1, Polinomio_p *p2){
Polinomio_p *pr = new Polinomio_p();
	for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(co, ex);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(co, ex);
	}
}

void Polinomio_p::restar(Polinomio_p *p1, Polinomio_p *p2){
Polinomio_p * pr = new Polinomio_p();
    for (int i = 1; i <= p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		pr->poner_termino(co, ex);
	}
	for (int i = 1; i <= p2->numero_terminos(); i++) {
		int ex = p2->exponente(i);
		int co = p2->coeficiente(ex);
		pr->poner_termino(co, -ex);
	}
}

void Polinomio_p::derivar(){
int n = numero_terminos();
	int *exn = new int[n];
	int *con = new int[n];
	int c = 0;
	while(!es_cero()){
		int ex = exponente(1);
		int co = coeficiente(ex);
		poner_termino(-co, ex);
		exn[c] = ex;
		con[c] = co;
		c++;
	}
	for (int i = 0; i < n; i++) {
		int ex = exn[i];
		int co = con[i];
		poner_termino(co*ex, ex - 1);
	}
}

string Polinomio_p::convertir_string() {
	string s = "";
	for (int i = 1; i <= numero_terminos(); i++) {
		int ex = exponente(i);
		int co = coeficiente(ex);
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}
	return s;
}
