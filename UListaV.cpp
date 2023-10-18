//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaV.h"
//---------------------------------------------------------------------------
ListaV::ListaV() {
	this->cantidad = 0;
	elementos = new int[MAX];
}

direccion ListaV::fin() {
	if (!vacio())
		return cantidad - 1;
	else
		return cantidad = 0;
//		cout << "ERROR: LISTA VACIA\n";
}

direccion ListaV::primero() {
	if (!vacio())
		return cantidad;
	else
		return 0;
//		cout << "ERROR: LISTA VACIA\n";
}

direccion ListaV::siguiente(direccion dir) {
	if (vacio())
		return 0;
	else {
		if (dir == cantidad)
			cout << "ERROR: DIRECCION ERRONEA\n";
		else
			return dir + 1;
	}
}

direccion ListaV::anterior(direccion dir) {
	if (vacio())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir > 0 && dir <= cantidad - 1)
			return dir - 1;
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

bool ListaV::vacio() {
	return cantidad == 0;
}

int ListaV::recupera(direccion dir) {
	if (vacio())
		cout << "ERROR: LISTA VACIA\n";
	else {
		if (dir >= 0 && dir <= cantidad - 1)
			return elementos[dir];
		else
			cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

int ListaV::longitud() {
	return cantidad;
}

void ListaV::insertar(direccion dir, int e) {    //inserta(primero(),12)
	if (cantidad == MAX) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	if (vacio()) {
		elementos[0] = e;
		cantidad++;
		return;
	}
	if (dir >= 0 && dir <= cantidad) {
		for (int i = cantidad; i > dir; i--)
			elementos[i] = elementos[i - 1];
		elementos[dir] = e;
		cantidad++;
	}
	else {
		cout << "ERROR: DIRECCION ERRONEA\n";
	}
}

void ListaV::insertar_primero(int e) {
	if (cantidad == MAX) {
		cout << "ERROR: LISTA LLENA\n";
		return;
	}
	for (int i = cantidad; i > 0; i--)
		elementos[i] = elementos[i - 1];
	elementos[0] = e;
	cantidad++;
}

void ListaV::insertar_ultimo(int e) {
	if (cantidad == MAX)
		cout << "ERROR: LISTA LLENA\n";
	else {
		elementos[cantidad] = e;
		cantidad++;
	}
}

void ListaV::suprime(direccion dir) {
	if (cantidad == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (dir >= 0 && dir <= cantidad - 1) {
		for (int i = dir; i < cantidad - 1; i++)
			elementos[i] = elementos[i + 1];
		cantidad--;
	}
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::modifica(direccion dir, int e) {
	if (cantidad == 0) {
		cout << "ERROR: LISTA VACIA\n";
		return;
	}
	if (dir >= 0 && dir <= cantidad - 1)
		elementos[dir] = e;
	else
		cout << "ERROR: DIRECCION ERRONEA\n";
}

void ListaV::Mostrar() {
cout << "[";
	for (int i = 0; i < cantidad - 1; i++) {
		cout << to_string(elementos[i]) << ",";
	}
cout << to_string(elementos[cantidad - 1]) << "]" <<endl;
cout << "cantidad -> "<< longitud() << endl;
}

direccion ListaV::localiza(int e) {
	for(int i = 0;i < cantidad;i++){
		if(elementos[i] == e)
			return i;
	}
	return -1;
}

void ListaV::elimina_dato(int e) {
	int i = 0;
	while(i < cantidad){
		if(elementos[i] == e)
			suprime(i);
		else
			i++;
	}
}

void ListaV::anula() {
	cantidad = 0;
}

#pragma package(smart_init)
