//---------------------------------------------------------------------------

#pragma hdrstop

#include "ULista_poli.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polinomio::Polinomio(){
	pol = new ListaP;
}

direccion_p Polinomio::buscar_exponente(int exp){
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

bool Polinomio::es_cero(){
	return pol->vacio();
}

direccion_p Polinomio::buscar_termino_n(int i){
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

int Polinomio::grado(){
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

int Polinomio::coeficiente(int exp){
direccion_p dir;
	if (dir != NULL) {
		return pol->recuperar(pol->anterior(dir));
	}
	return 0;
}

void Polinomio::asignar_coeficiente(int coef, int exp){
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

void Polinomio::poner_termino(int coef, int exp){
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

int Polinomio::numero_terminos(){
return pol->longitud() / 2;
}

int Polinomio::exponente(int nter){
direccion_p dir = buscar_termino_n(nter);
	if (dir != NULL) {
		return pol->recuperar(pol->siguiente(dir));
	}
return 0;
}

direccion_p Polinomio::sumar(Polinomio *p1, Polinomio *p2){

}
