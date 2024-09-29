//---------------------------------------------------------------------------
#pragma hdrstop
#include "uListaVector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ListaV::ListaV() // Constructor: Inicializa longitud con 0
{
	this->longitud = 0;
}

direccion ListaV::fin() {
	if (!EsVacio()){
		return longitud;
	} else {
		ShowMessage("La lista está vacía!"); return NULO;
	}
}

direccion ListaV::primero() {
	if (!EsVacio()) {
		return 0;
	} else {
		ShowMessage("La lista está vacía!"); return NULO;
	}

}

direccion ListaV::siguiente(direccion p) {
	if (EsVacio()) {
		ShowMessage("La lista está vacía!"); return NULO;
	} else if (p == longitud) {
		ShowMessage("La dirección es incorrecta!"); return NULO;
	} else {
		if (p == fin()) {
			return NULO;
		} else {
			if (p != NULO)
				return (p + 1);
			else
				return NULO;
        }
	}
}

direccion ListaV::anterior(direccion p) {
	if (EsVacio()) {
		ShowMessage("La lista está vacía!"); return NULO;
	} else if (p == 0) {
		ShowMessage("La dirección es incorrecta!"); return NULO;
	} else {
		return (p - 1);
	}
}

bool ListaV::EsVacio() {
	return (longitud == 0);
}

int ListaV::LongitudLista() {
	return longitud;
}

int ListaV::recupera(direccion p) {
	if (EsVacio()) {
		ShowMessage("La lista está vacía!"); return NULO;
	} else if (!(p>=0 && p<=longitud)) {
		ShowMessage("La dirección es incorrecta!"); return NULO;
	} else {
		return elementos[p];
	}
}

void ListaV::inserta(direccion p, int elemento) {   //3,10,5
	if (longitud == MAX) {
		ShowMessage("La lista está llena!"); return;
	} else if (!(p>=-1 && p<=longitud)) {
		ShowMessage("La dirección es incorrecta!"); return;
	} else {
		if (p != NULO) {
			for (int i = longitud; i > p; i--)
				elementos[i] = elementos[i - 1];

			elementos[p] = elemento;
			longitud++;
		} else {
			elementos[0] = elemento;
			longitud++;
		}
	}
}

void ListaV::inserta_primero(int elemento) { 	//3,10,5
	if (longitud == MAX) {
		ShowMessage("La lista está llena!"); return;
	} else {
		for (int i = longitud; i > 0; i--)
			elementos[i] = elementos[i - 1];

		elementos[0] = elemento;
		longitud++;
	}
}

void ListaV::inserta_ultimo(int elemento) {     //5,10,3
	if (longitud == MAX) {
		ShowMessage("La lista está llena!"); return;
	} else {
		elementos[longitud++] = elemento;
	}
}

void ListaV::suprime(direccion p) {     //3,10,5 (1)-> 3,5,5 ->3,5
	if (EsVacio()) {
		ShowMessage("La lista está vacía!"); return;
	} else if (!(p>=0 && p<longitud)) {
		ShowMessage("La dirección es incorrecta!"); return;
	} else {
		for (int i = p; i < longitud - 1; i++)
			elementos[i] = elementos[i + 1];

		longitud--;
	}
}

void ListaV::modifica(direccion p,int elemento) {
	if (EsVacio()) {
		ShowMessage("La lista está vacía!"); return;
	} else if (!(p>=0 && p<longitud)) {
		ShowMessage("La dirección es incorrecta!"); return;
	} else {
		elementos[p] = elemento;
	}
}

void ListaV:.anula() {
	if (!EsVacio()) {
		for (direccion x = primero(); x != NULO; x = primero()) {
			suprime(x);
		}
		ShowMessage("Memoria Limpia!");
	} else {
		ShowMessage("La lista está vacía!");
	}
}

direccion ListaV::buscar(ListaV L, int elemento) { // Busca la posicion de un elemento
	if (L.EsVacio()) {
		return NULO;
	} else {
		direccion p = L.primero();
		while (p != NULO) {
			int e = L.recupera(p);
			if (e == elemento)
				return p;
			else
				p = L.siguiente(p);
		}
		return p;
	}
}

void ListaV::MostrarLista(TCanvas *canvas)
{
AnsiString cad = "<| ";
	for (direccion p = primero(); p != NULO; p = siguiente(p)) {
		if (recupera(p) != -1)
			cad = cad + AnsiString(IntToStr(recupera(p))) + ", ";
		else
			cad = "La lista está vacía!";
	}
	canvas->Font->Size = 38;
	canvas->TextOutW(400, 200, cad.Delete(cad.Length() - 1, 2) + L" |>" );
}
