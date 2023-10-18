//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaCSMemoria::ListaCSMemoria(){
	this->cantidad = 0;
	this->ptr = nulo;
	mem = new CSMemoria();
}

//ListaCSMemoria::ListaCSMemoria(CSMemoria *m){
// 	this->cantidad = 0;
//	this->ptr = nulo;
//	mem = m;
//}

int ListaCSMemoria::primero(){
	if (!vacio()) {
		return ptr;
	}else{
		return ptr = nulo;
	}
}

int ListaCSMemoria::fin(){
	if (vacio()) {
		return ptr = nulo;
	}else{
		int aux1 = ptr;
		int aux2 = 0;
		while (aux1 != nulo){
			aux2 = aux1;
			aux1 = mem->obtener_dato(aux1,sig);
		}
	return aux2;
	}
}

int ListaCSMemoria::siguiente(int dir){
	if (vacio()) {
		return ptr = nulo;
	}else{
		if (dir == fin()) {
			return ptr = nulo;
		}else{
            return mem->obtener_dato(dir, sig);
        }
    }
}

int ListaCSMemoria::anterior(int dir){
	if (vacio()) {
		return nulo;
	}else{
		if (dir == primero()) {
			return nulo;
		}else{
			int aux = ptr;
			int ant = nulo;
			while (aux != nulo){
				if (aux == dir)
					return ant;
				ant = aux;
				aux = mem->obtener_dato(aux,sig);
			}
		return nulo;
        }
    }
}

int ListaCSMemoria::recupera(int dir){
	if (vacio()) {
		return nulo;
	}else{
		return mem->obtener_dato(dir,dato);
    }
}

int ListaCSMemoria::longitud(){
return cantidad;
}

bool ListaCSMemoria::vacio(){
return cantidad == 0;
}

void ListaCSMemoria::inserta(int dir, int elemento){
int direccion = mem->new_espacio(dato_sig);
	if (direccion != nulo) {
		mem->poner_dato(direccion, dato, elemento);
		mem->poner_dato(direccion, sig, nulo);
		if (vacio()) {
			this->ptr = direccion;
			cantidad = 1;
		}else{
			cantidad++;
			if (dir == primero()) {
				mem->poner_dato(direccion, sig, dir);
				ptr = direccion;
			}else{
				int ant = anterior(dir);
				mem->poner_dato(ant, sig, direccion);
				mem->poner_dato(direccion, sig, dir);
            }
        }
	}else{
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
    }
}

void ListaCSMemoria::inserta_primero(int elemento) {
	int direccion = mem->new_espacio(dato_sig); // NodoL* x = new NodoL;
	if (direccion != nulo) {
		mem->poner_dato(direccion, dato, elemento); // x->elemento = e;
		mem->poner_dato(direccion, sig, ptr); // x->sig = ptr_elementos
		ptr = direccion;
		cantidad++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}


void ListaCSMemoria::inserta_ultimo(int elemento) {
	int direccion = mem->new_espacio(dato_sig); // NodoL* x = new NodoL;
	if (direccion != nulo) {
		mem->poner_dato(direccion, dato, elemento); // x->elemento = e;
		mem->poner_dato(direccion, sig, nulo); // x->sig = NULL;
		if (vacio())
			ptr = direccion;
		else
			mem->poner_dato(fin(), sig, direccion); // fin()->sig = x;
		cantidad++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaCSMemoria::suprime(int dir) {
	if (cantidad == 0) {
		cout << "ERROR: LISTA VACIA\n";
	}
	if (dir == ptr) {
		int x = ptr;
		ptr = mem->obtener_dato(ptr, sig);
		mem->delete_espacio(x); // delete(x);
	}
	else {
		int ant = anterior(dir);
		mem->poner_dato(ant, sig, mem->obtener_dato(dir, sig));
		mem->delete_espacio(dir); // delete(d);
	}
	cantidad--;
}

void ListaCSMemoria::modifica(int dir, int elemento) {
	if (vacio())
		cout << "ERROR: LISTA VACIA\n";
	else
		mem->poner_dato(dir, dato, elemento);
}
