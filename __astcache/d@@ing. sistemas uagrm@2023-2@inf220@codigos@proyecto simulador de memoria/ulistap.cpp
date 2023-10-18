//---------------------------------------------------------------------------

#pragma hdrstop

#include "UListaP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP(){
	ptr = NULL;
	cantidad = 0;
}

direccion_p ListaP::primero(){     // |5|10|12|
	if (!vacio()) {
		return this->ptr;
	}else{
		return ptr = NULL;
	}
}

direccion_p ListaP::fin(){
	if (vacio()) {
		return ptr = NULL;
	}else{
		NodoL *aux1 = ptr;
		NodoL *aux2;
		while (aux1 != NULL){
			aux2 = aux1;
			aux1 = aux1->sig;
		}
	return aux2;
	}
}

direccion_p ListaP::siguiente(direccion_p p){
	if (vacio()) {
		return ptr = NULL;
	}else{
		if (p == fin()) {
			return ptr = primero();
//			cout << "Direccion primera";
		}else{
			return p->sig;
		}
	}
}

direccion_p ListaP::anterior(direccion_p p){
	if (vacio()) {
		return ptr = NULL;
	}else{
		direccion_p x = ptr;
		direccion_p ant = NULL;
		while(x != NULL){
			if(x == p){
				return ant;
			}
		 ant = x;
		 x = x->sig;
		}
	 return NULL;
	}
}

bool ListaP::vacio(){
	return cantidad == 0;
}

int ListaP::recuperar(direccion_p p){
	if (vacio()) {
		return p->elemento = 0;
//		cout << "ERROR/recuperar: Lista vacia";
	}else{
		return p->elemento;
    }
}

int ListaP::longitud(){
	return cantidad;
}

void ListaP::insertar(NodoL *p, int element){   // insertar(primero(), 12)
NodoL *nuevo_nodo = new NodoL;
  if(nuevo_nodo != NULL){
	nuevo_nodo->elemento = element;
	nuevo_nodo->sig = NULL;
	if(vacio()){ //caso1 lista vacia
		ptr = nuevo_nodo;
		cantidad = 1;
	}else{
	   if(p == primero()){ //caso2 inserta al primero
		  nuevo_nodo->sig = p;
		  ptr = nuevo_nodo;
	   }else{    //caso3 a la izq de la direccion
		 NodoL *ant = anterior(p);
		 ant->sig = nuevo_nodo;
		 nuevo_nodo->sig = p;
	   }
	   cantidad++;
    }
  }
}

void ListaP::insertar_primero(int element){
NodoL *x = new NodoL;
  if(x != NULL){
	x->elemento = element;
	x->sig = ptr;
	ptr = x;
	cantidad++;
  }
}

void ListaP::insertar_ultimo(int element){
NodoL* x = new NodoL;
  if (x != NULL) {
		x->elemento = element;
		x->sig = NULL;
		if (vacio())
			ptr = x;
		else
			fin()->sig = x;
		cantidad++;

  } else{
	  cout<<"ERROR: No existe espacio en la memoria\n";
  }
}

void ListaP::suprime(direccion_p p){
	if (cantidad == 0){
		cout << "ERROR: LISTA VACIA\n";
		return;
	}

	if (p == ptr) {
		direccion_p x = ptr;
		ptr = ptr->sig;
		delete(x);
	}else{
		direccion_p ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
cantidad--;
}

void ListaP::modifica(direccion_p p, int element) {
	if (vacio())
		cout << "ERROR: LISTA VACIA\n";
	else
		p->elemento = element;
}

void ListaP::Mostrar(){
NodoL *aux = primero();
cout << "<|";
	while (aux != NULL){
		cout << aux->elemento << ",";
		aux = aux->sig;
	}
cout << "|>" << endl;
}
