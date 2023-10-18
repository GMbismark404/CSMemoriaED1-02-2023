//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaS.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaS::ListaS() {
	ptr_elementos = nulo;
	longit = 0;
	mem = new CSMemoria();
}

ListaS::ListaS(CSMemoria* m) {
	ptr_elementos = nulo;
	longit = 0;
	mem = m;
}

int ListaS::fin() {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		int x = ptr_elementos;
		int ptr_fin;
		while (x != nulo) {
			ptr_fin = x;
			x = mem->obtener_dato(x, sigNL); // x->sig;
		}
		return ptr_fin;
	}
}

int ListaS::primero() {
	if (!vacia())
		return ptr_elementos;
	else
//		cout << "ERROR: LISTA VACIA\n";
		return ptr_elementos = nulo;
}

int ListaS::siguiente(int dir) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == fin())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return mem->obtener_dato(dir, sigNL); // d->sig;
	}
}

int ListaS::anterior(int dir) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir == primero())
			cout << "ERROR: DIRECCION ERRONEA\n";
		else {
			int x = ptr_elementos;
			int ant = nulo;
			while (x != nulo) {
				if (x == dir)
					return ant;
				ant = x;
				x = mem->obtener_dato(x, sigNL); // x->sig;
			}
			return nulo;
		}
	}
}

bool ListaS::vacia() {
	return longit == 0;
}

int ListaS::recupera(int dir) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		return mem->obtener_dato(dir, elemNL); // d->elemento;
}

int ListaS::longitud() {
	return longit;
}

// new Nodo;     mem->new_espacio("elemento,sig"); mem->new_espacio(datosNL);
void ListaS::insertar(int dir, int e) {
	int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
	if (x != nulo) {
		mem->poner_dato(x, elemNL, e); // x->elemento = e;
		mem->poner_dato(x, sigNL, nulo); // x->sig = NULL;
		if (vacia()) {
			ptr_elementos = x;
			longit = 1;
		}
		else {
			longit++;
			if (dir == primero()) {
				mem->poner_dato(x, sigNL, dir); // x->sig = d;
				ptr_elementos = x;
			}
			else {
				int ant = anterior(dir);
				mem->poner_dato(ant, sigNL, x); // ant->sig = x;
				mem->poner_dato(x, sigNL, dir); // x->sig = d;
			}

		}
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::insertar_primero(int e) {
	int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
	if (x != nulo) {
		mem->poner_dato(x, elemNL, e); // x->elemento = e;
		mem->poner_dato(x, sigNL, ptr_elementos); // x->sig = ptr_elementos
		ptr_elementos = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::insertar_ultimo(int e) {
	int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
	if (x != nulo) {
		mem->poner_dato(x, elemNL, e); // x->elemento = e;
		mem->poner_dato(x, sigNL, nulo); // x->sig = NULL;
		if (vacia())
			ptr_elementos = x;
		else
			mem->poner_dato(fin(), sigNL, x); // fin()->sig = x;
		longit++;
	}
	else
		cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

// delete(x)     ->  mem->delete_espacio(x);
void ListaS::suprime(int dir) {
	if (longit == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (dir == ptr_elementos) {
		int x = ptr_elementos;
		ptr_elementos = mem->obtener_dato(ptr_elementos, sigNL);
		// ptr_elementos->sig;
		mem->delete_espacio(x); // delete(x);
	}
	else {
		int ant = anterior(dir);
		mem->poner_dato(ant, sigNL, mem->obtener_dato(dir, sigNL));
		// ant->sig = d->sig;
		mem->delete_espacio(dir); // delete(d);
	}
	longit--;
}

void ListaS::modifica(int dir, int e) {
	if (vacia())
		cout << "ERROR: LISTA VACIA\n";
	else
		mem->poner_dato(dir, elemNL, e); // d->elemento = e;
}

string ListaS::to_str() {
	// mem->mostrar();
	string s = "[";
	int aux = ptr_elementos;
	while (aux != nulo) {
		int el = mem->obtener_dato(aux, elemNL); // aux->elemento
		s += to_string(el);
		aux = mem->obtener_dato(aux, sigNL); // aux->sig;
		if (aux != nulo)
			s += ",";
	}
	return s + "]";
}

int ListaS::localiza(int e) {
	int aux = ptr_elementos;
	while (aux != nulo) {
		if (mem->obtener_dato(aux, elemNL) == e)
			return aux;
		aux = mem->obtener_dato(aux, sigNL); // aux->sig;
	}
	return nulo;
}

void ListaS::elimina_dato(int e) {
	int aux = ptr_elementos;
	while (aux != nulo) {
		if (mem->obtener_dato(aux, elemNL) == e) {
			int sup = aux;
			aux = mem->obtener_dato(aux, sigNL); // aux->sig;
			suprime(sup);
		}
		else
			aux = mem->obtener_dato(aux, sigNL); // aux->sig;
	}
}

void ListaS::anula() {
	while (!vacia())
		suprime(primero());
}

void ListaS::Mostrar(){
	mem->Mostrar();
}
