//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPuntero_Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP() // Constructor: Inicializa longitud con 0, PtrElementos con NULL
{
	this->PtrElementos = nullptr;
	this->longitud = 0;
}

Direccion ListaP::primero() {
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a!"); return nullptr;
	} else {
		return PtrElementos;
	}
}

Direccion ListaP::fin(){
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a!"); return nullptr;
	} else {
		Direccion ptrfin = nullptr;
		for (Direccion x = PtrElementos; x != nullptr; x = x->sig) {
			ptrfin = x;
		}
	return ptrfin;
	}
}

void ListaP::inserta(Direccion p, int elemento) {
	Direccion x = new Nodo;
	if (x == nullptr) {
		ShowMessage("La Memoria est� llena!"); return; // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
	} else {
	// Si la asignaci�n de memoria fue exitosa, continuamos con la inserci�n del nodo
		x->elementos = elemento;
		x->sig = nullptr;
		if (EsVacio()) {
			PtrElementos = x;
			longitud = 1;
		} else {
		longitud++;
			if (p == primero()) {
				x->sig = p;
				PtrElementos = x;
			} else {
				Direccion ant = anterior(p);
				ant->sig = x;
				x->sig = p;
			}
		}
	}
}

void ListaP::inserta_primero(int elemento){
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elementos = elemento;
		x->sig = PtrElementos;
		longitud++;
		PtrElementos = x;
	}else{
		ShowMessage("La lista est� llena!"); return; // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
	}
}

void ListaP::inserta_ultimo(int elemento){
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elementos = elemento;
		x->sig = nullptr;
		if (longitud != 0) {
			fin()->sig = x;
		} else {
			PtrElementos = x;
		}
		longitud++;
	} else {
		ShowMessage("La lista est� llena!"); return; // Lanzar una excepci�n en caso de falla en la asignaci�n de memoria
    }
}

Direccion ListaP::siguiente(Direccion p){
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a!"); return nullptr;;
	} else {
		if (p == fin()) {
			ShowMessage("El final de la lista no existe su siguiente!"); return nullptr;
		} else {
			if (p != nullptr)
				return p->sig;
			else
				return nullptr;
		}
	}
}

Direccion ListaP::anterior(Direccion p) {
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a!"); return nullptr;
    } else if (p == primero()) {
		ShowMessage("No tiene un anterio el primero por lo tanto NULL!"); return nullptr;
    } else {
        Direccion anterior = nullptr;
		Direccion actual = PtrElementos;

        while (actual != nullptr && actual != p) {
			anterior = actual;
            actual = actual->sig;
        }

		if (actual == nullptr) {
			ShowMessage("La direcci�n no se encuentra en la lista!"); return nullptr;
		} else {
            return anterior;
        }
    }
}

bool ListaP::EsVacio() {
	return (longitud == 0) || (PtrElementos == nullptr);
}

int ListaP::LongitudLista() {
	return longitud;
}

int ListaP::recupera(Direccion p) {
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a!"); return -1;
	}else{
		return p->elementos;
	}
}

void ListaP::suprime(Direccion p) {
	if (longitud == 0 || p == nullptr) {
		ShowMessage("La lista est� vac�a o la direcci�n es nula!"); return;
    } else {
		if (p == PtrElementos) {
			PtrElementos = p->sig;
        } else {
            Direccion actual = PtrElementos;
            while (actual != nullptr && actual->sig != p) {
				actual = actual->sig;
			}
			if (actual == nullptr) {
				ShowMessage("La direcci�n no se encuentra en la lista!"); return;
			}
			actual->sig = p->sig;
        }
		delete p;
        longitud--;
    }
}

void ListaP::anula() {
	if (!EsVacio()) {
		for (Direccion x = primero(); x != nullptr; x = primero()) {
			suprime(x);
		}
		ShowMessage("Memoria lipia!");
	} else {
		ShowMessage("La lista est� vac�a!");
	}
}

Direccion ListaP::buscar(ListaP L, int elemento) {
	if (L.EsVacio()) {
		return nullptr;
	} else {
		Direccion p = L.primero();
		while (p != nullptr) {
			int e = L.recupera(p);
			if (e == elemento)
				return p;
			else
				p = L.siguiente(p);
		}
		return p;
	}
}

void ListaP::MostrarLista(TCanvas *canvas, int x, int y) {
AnsiString cad = "<| ";
	for (Direccion p = primero(); p != nullptr; p = siguiente(p)) {
		if (recupera(p) != -1)
			cad =  cad + AnsiString(IntToStr(recupera(p))) + ", ";
		else
			cad = "La lista est� vac�a!";
	}

//	label->Caption = cad.Delete(cad.Length()- 1, 2) + " |>";
	canvas->Font->Size = 38;
	canvas->TextOutW(x, y, cad.Delete(cad.Length() - 1, 2) + L" |>");
}
