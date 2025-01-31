//---------------------------------------------------------------------------
#pragma hdrstop
#include "uListaPuntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaP::ListaP() {
	this->longitud = 0;
	this->PtrElementos = nullptr;
}

Direccion ListaP::primero() {
	if (!EsVacio()) {
		return PtrElementos; //por que en esta direccion esta el primer elemento
	} else {
//		ShowMessage("La lista est� vac�a");
		return nullptr;  //La lista est� vac�a
	}
}

Direccion ListaP::fin() {
	if (EsVacio()) {
		return nullptr; // La lista est� vac�a
	} else {
		Direccion x = PtrElementos;
		Direccion ptrfin = nullptr;
		while (x != nullptr) {
			ptrfin = x;
			x = x->sig;
		}
		return ptrfin;
    }
}

void ListaP::inserta(Direccion p, int elemento) {
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elemento = elemento;
		x->sig = nullptr;
		if (EsVacio()) {
			PtrElementos = x; longitud = 1;
		} else {
			longitud = longitud + 1;
			if (p == primero()) {
				x->sig = p;
				PtrElementos = x;
			} else {
				Direccion ant = anterior(p);
				ant->sig = x;
				x->sig = p;
            }
        }
	} else {
		ShowMessage("No existe espacio de memoria");
	}
}

void ListaP::inserta_primero(int elemento) {
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elemento = elemento;
		x->sig = PtrElementos;
		longitud = longitud + 1;
		PtrElementos = x;
	} else {
		ShowMessage("No existe espacio de memoria");
    }
}

void ListaP::inserta_ultimo(int elemento) {
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elemento = elemento;
		x->sig = nullptr;
		if (longitud != 0) {
			fin()->sig = x;
		} else {
			PtrElementos = x;
			longitud = longitud + 1;
        }
	} else {
		ShowMessage("No existe espacio de memoria");
    }
}

Direccion ListaP::siguiente(Direccion p) {
	if (EsVacio()) {
		return nullptr;
	} else {
		if (p == fin()) {
			return nullptr; //Direccion error
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
		return nullptr; //Lista Vac�a
	} else {
		if (p == primero()) {
			return nullptr; // No existe anterior de primero
		} else {
			Direccion x = PtrElementos;
			Direccion ant = nullptr;
			while (x != nullptr) {
				if (x == p) {
					return ant;
				}
				ant = x;
				x = x->sig;
			}
			return ant;
		}
	}
}

bool ListaP::EsVacio() {
	return (longitud == 0);
}

int ListaP::recupera(Direccion p) {
	if (EsVacio()) {
		return -1; // Lista Vac�a
	} else {
		return p->elemento;
	}
}

int ListaP::LongitudLista() {
	return longitud;
}

void ListaP::suprime(Direccion p) {
	if (longitud == 0) {
		return; //Lista Vac�a
	} else {
		if (p == PtrElementos) {
			Direccion x = PtrElementos;
			PtrElementos = PtrElementos->sig;
			delete x;
		} else {
			Direccion ant = anterior(p);
			ant->sig = siguiente(p);
			delete p;
		}
		longitud = longitud - 1;
    }
}

void ListaP::modifica(Direccion p, int elemento) {
	if (EsVacio()) {
		return; //Lista vac�a
	} else {
        p->elemento = elemento;
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

Direccion ListaP::buscar(ListaP L, int elemento) { // lista->buscar(&lista, 5);
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



