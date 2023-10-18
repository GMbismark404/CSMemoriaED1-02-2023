//---------------------------------------------------------------------------
#pragma hdrstop
#include "UMemoria.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)

CSMemoria::CSMemoria(){
	mem = new NodoM[max];
	for (int i = 0; i < max - 1; i++) {
		mem[i].link = i + 1;
	}
	mem[max - 1].link = -1;
	libre = 0;
}

int CSMemoria::new_espacio(string cad) { // añade los ids y devuelve una direccion
	int cant = numero_ids(cad);         // cad = "ci,fono,edad" -> 3
	int dir = libre;
	int d = libre;
	for (int i = 0; i < cant - 1; i++) {
		mem[d].id = obtener_id(cad,i);
		d = mem[d].link;
	}

	libre = mem[d].link;
	mem[d].link = -1;
	mem[d].id = obtener_id(cad, cant - 1);
return dir;
}

int CSMemoria::numero_ids(string id) { // "dia,mes,año"
int c = 0;
	if (id == "")
		return c;

	for (int i = 0; i < id.length() - 1; i++) {
		if ((id[i] != ',') && (id[i+1] == ',')) {
			c++;
		}
	}

	if (id[id.length() - 1] != ',') {
		c++;
	}
return c;
}

string CSMemoria::obtener_id(string cad, int pos) {  // "ca,na,ma"
int p = 0; string s = "";
	for (int i = 0; i < cad.length(); i++) {
		if (cad[i] == ',') {
			p++; i++;
		}

		if (p == pos) {
			s = s + cad[i];
		}
	}
return s;
}

void CSMemoria::delete_espacio(int dir) {
int x = dir;
	while(mem[x].link != nulo){
		x = mem[x].link;
	}

	mem[x].link = libre;
	libre = dir;
}

int CSMemoria::espacio_disponible() {//cuenta la cantidad de espacio disponibles
int x = libre;
int c = 0;
	while (x != nulo){
		c++;
		x = mem[x].link;
	}
return c;
}

bool CSMemoria::dir_libre(int dir) {  //tu le das una direccion y te verifica
bool c = false;                      //si esta libre esa direccion
int x = libre;
	while ((x != nulo) && (c == false)){
		if (x == dir) {
			c = true;
		}
		x = mem[x].link;
	}
return c;
}

int CSMemoria::obtener_dato(int dir, string cadena_id) {
int z = dir; bool ex = false;
eliminar_flecha(cadena_id);
	while (z != nulo){
		if (mem[z].id == cadena_id) {
			return mem[z].dato;
		}
	z = mem[z].link;
	}
return z;  //si pones la dir incorrecta entonces te manda un -1
}

void CSMemoria::eliminar_flecha(string cad_id){

}

int CSMemoria::espacio_ocupado() {
	int c = max - espacio_disponible();
	return c;
}

void CSMemoria::poner_dato(int dir, string cad_id, int valor){
int z = dir;
eliminar_flecha(cad_id);
	while (z != nulo) {
		if (mem[z].id == cad_id){
			mem[z].dato = valor;
		}
		z = mem[z].link;
	}
}

void CSMemoria::Mostrar(){
cout << "+-------------------------------------------------------+" << endl;
cout << "|  DIRECCION  |    DATO     |     ID      |     LINK    |" << endl;
cout << "+-------------------------------------------------------+" << endl;
	for (int i = 0; i <= max - 1; i++) {
		cout << "|" << add_space(to_string(i)) << "|" << add_space(to_string(mem[i].dato))<< "|" << add_space(mem[i].id) << "|" << add_space(to_string(mem[i].link)) << "|"<< endl;
	}
cout << "+-------------------------------------------------------+" << endl;
cout << "libre -> "<< libre << endl;
cout << "espacios disponibles -> "<< espacio_disponible() << endl;
cout << "espacios ocupados -> "<< espacio_ocupado() << endl;
cout << endl;
}

string CSMemoria::add_space(string cad){
string s = cad;
	for (int i = cad.length(); i <= 12; i++) {
		s = s + " ";
	}
return s;
}
