//---------------------------------------------------------------------------

#pragma hdrstop

#include "UPolinomio_m.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Polinomio_m::Polinomio_m() {
	this->nt = 0;
	this->ptr_poli = nulo;
	mem = new CSMemoria();
}

direccion_m Polinomio_m::buscar_exponente(int exp){  //5
direccion_m dir = this->ptr_poli;
	if (dir != nulo) {
		int dir_exp = nulo;
		while ((dir != nulo) && (dir_exp == nulo)) {
			if (mem->obtener_dato(dir, expp) == exp)
				dir_exp = dir;
			dir = mem->obtener_dato(dir,sigp);
		}
		return dir_exp;
	}
return nulo;
}

direccion_m Polinomio_m::buscar_termino_n(int i){
direccion_m dir = this->ptr_poli;
	if (dir != nulo) {
		direccion_m dir_ter = nulo;
		this->nt = 0;
		while ((dir != nulo) && (dir_ter == nulo)){
			this->nt += 1;
			if (this->nt == i) {
				dir_ter = dir;
			}
			dir = mem->obtener_dato(dir,sigp);
		}
		return dir_ter;
	}
return nulo;
}

bool Polinomio_m::es_cero() {
	return this->nt == 0;
}

int Polinomio_m::grado() {
int dir = this->ptr_poli;
	if (dir != nulo) {
		int maxg = mem->obtener_dato(dir, expp);  //5
		while (dir != nulo) {
			if (mem->obtener_dato(dir,expp) > maxg)
				maxg = mem->obtener_dato(dir,expp);
			dir = mem->obtener_dato(dir,sigp);
		}
		return maxg;
	}
}

int Polinomio_m::coeficiente(int exp){
direccion_m dir = buscar_exponente(exp);
	if (dir != nulo) {
		return mem->obtener_dato(dir, coefp);
	}
return nulo;
}

int Polinomio_m::exponente(int nroter){
direccion_m dir = buscar_termino_n(nroter);
	if (dir != nulo) {
		return mem->obtener_dato(dir,expp);
	}
return nulo;
}

void Polinomio_m::asignar_coeficiente(int coef, int exp){
direccion_m dir = buscar_exponente(exp);
	if (dir != nulo) {
		mem->poner_dato(dir, coefp, coef);
		if (coef == 0) {
			//eliminar nodo dir
		}
	}
}

void Polinomio_m::poner_termino(int coef, int exp){
direccion_m dir_existe = buscar_exponente(exp);
	if (dir_existe == nulo) {
		int aux = mem->new_espacio(datos_ids);
		if (aux != nulo) {
			mem->poner_dato(aux, coefp, coef);
			mem->poner_dato(aux, expp, exp);
			mem->poner_dato(aux, sigp, this->ptr_poli);
			this->ptr_poli = aux;
			this->nt += 1;
		}
		cout << "Error/espacio de memoria";
	}else{
		int nuevo_coef = mem->obtener_dato(dir_existe, coefp) + coef;
		mem->poner_dato(dir_existe, coefp, nuevo_coef);
		if (nuevo_coef == 0) {
				if (dir_existe == ptr_poli) { // Se elimina el primero
					ptr_poli = mem->obtener_dato(ptr_poli, sigp);
					// ptr_poli->sig;
				}else {
//					int ant = anterior(dir_existe);
					int existe_sig = mem->obtener_dato(dir_existe, sigp);
					// existe->sig
//					mem->poner_dato(ant, sigp, existe_sig);
					// ant->sig = existe_sig;
				}
				mem->delete_espacio(dir_existe); // delete(existe);
				this->nt--;
		}
	}
}

int Polinomio_m::numero_terminos(){
return this->nt;
}


