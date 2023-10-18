//---------------------------------------------------------------------------
#pragma hdrstop
#include "UConjunto_lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoL::ConjuntoL(){
	elemento = new ListaP();
}

bool ConjuntoL::vacio(){
	return elemento->vacio();
}

bool ConjuntoL::pertenece(int e){
	if (!vacio()) {
		NodoL *p = elemento->primero();
		while (p != NULL){
			int ele = elemento->recuperar(p);
			if (e == ele) {
				return true;
			}
			p = elemento->siguiente(p);
		}
	}else{
		return false;
    }
}

void ConjuntoL::inserta(int e){
	if (!pertenece(e))
		elemento->insertar(elemento->primero(),e);
}

int ConjuntoL::cardinal(){
	return elemento->longitud();
}

int ConjuntoL::ordinal(int e){
	if (!vacio()) {
		int cont = 0;
		NodoL *p = elemento->primero();
		while (p != NULL){
			cont++;
			int ele = elemento->recuperar(p);
			if (e == ele)
				return cont;
			p = elemento->siguiente(p);
		}
	}else{
		return 0;
    }
}

void ConjuntoL::suprime(int e){
	if (pertenece(e)) {
		NodoL *dir = NULL;
		NodoL *p = elemento->primero();
		while (p != NULL){
			int ele = elemento->recuperar(p);
			if (e == ele)
				dir = p;
			p = elemento->siguiente(p);
		}

		if (dir != NULL)
			elemento->suprime(dir);
	}else{
		cout << "ERROR/ conjunto no dicho elemento";
    }
}

int ConjuntoL::muestrea(){
    if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		NodoL* dir = elemento->primero();
		int cont = 0;
		for (int i = 1; i <= cardinal(); i++) {
			cont++;
			if (cont == lug)
				return elemento->recuperar(dir);
			dir = elemento->siguiente(dir);
		}
	}
}

void ConjuntoL::mostrar_conjunto(){
	elemento->Mostrar();
}
