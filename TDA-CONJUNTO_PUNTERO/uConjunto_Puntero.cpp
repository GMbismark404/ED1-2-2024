//---------------------------------------------------------------------------
#pragma hdrstop
#include "uConjunto_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoP::ConjuntoP() {
	this->cant = 0;
	this->ptrConj = nullptr;
}

bool ConjuntoP::EsVacio() {
	return (cant == 0); //ptrConj == nullptr;
}

bool ConjuntoP::pertenece(int elemento) { // Verifica si elemento E pertenece al conjunto C
	bool resp = false;
	Direccion pc = ptrConj;
	while (pc != nullptr) {
		if (pc->dato == elemento) {
			resp = true;
			pc = nullptr;
		} else
			pc = pc->sig;
	}
	return resp;
}

int ConjuntoP::cardinal() { // Cuenta cuantos elementos tiene el conjunto
	return cant;
}

void ConjuntoP::inserta(int elemento) { // añade el elemento E al conjunto C
	if (!pertenece(elemento)) {
		Direccion dir = new Nodo;
		if (dir != nullptr) {
			dir->dato = elemento;
			dir->sig = ptrConj;
			ptrConj = dir;
			cant++;
		} else {
			ShowMessage("Error!. No existe espacio de memoria!");
        }
	} else {
		ShowMessage("Error!. Este elemento ya existe!");
	}
}

posicion ConjuntoP::ordinal(int elemento) { // Busca el lugar que ocupa el elemento E en C
	int resp = 0;
	Direccion pc = ptrConj;
	while (pc != nullptr) {
		resp = resp + 1;
		if (pc->dato == elemento)
			pc = nullptr;
		else
			pc = pc->sig;
    }
	return resp;
}

void ConjuntoP::suprime(int elemento) { // Elimina E del conjunto C
	if (cant > 0) {
		Direccion dir = nullptr;
		Direccion pc = ptrConj;
		while (pc != nullptr) {
			if (pc->dato == elemento) {
				if (pc == ptrConj) {
					ptrConj = ptrConj->sig;
					delete pc;
					cant = cant - 1;
					pc = nullptr;
				} else {
					dir->sig = pc->sig;
					delete pc;
					cant = cant - 1;
					pc = nullptr;
                }
			} else {
                dir = pc;
				pc = pc->sig;
			}
		}
	} else {
		ShowMessage("Error!. No existe elementos en el conjunto C");
    }


}

int ConjuntoP::muestrea() { // Busca un elemento E al azar que pertenece al conjunto C
	if (cant > 0) {
		int lugar = 0;
		int elemento = 0;
		int lugarBuscado = obtenerNumeroAleatorio(1, cant);
		Direccion pc = ptrConj;
		while (pc != nullptr) {
			lugar = lugar + 1;
			if (lugarBuscado == lugar) {
				elemento = pc->dato;
				pc = nullptr;
			} else
				pc = pc->sig;
		}
        return elemento;
	} else {
		ShowMessage("Error!. No existe ningún elemento en el conjunto C!");
	}
}

int ConjuntoP::obtenerNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void ConjuntoP::Union(ConjuntoP A, ConjuntoP B) {
	while (A.cardinal() != 0) {
		int elemento = A.muestrea();
		inserta(elemento);
		A.suprime(elemento);
	}

	while (B.cardinal() != 0) {
		int elemento = B.muestrea();
		inserta(elemento);
		B.suprime(elemento);
	}
}

void ConjuntoP::Interseccion(ConjuntoP A, ConjuntoP B) {
	if (A.cardinal() > B.cardinal()) {
		while (A.cardinal() != 0) {
			int elementoA = A.muestrea();
			if (B.pertenece(elementoA)) {
				inserta(elementoA);
				if (!B.EsVacio())
					B.suprime(elementoA);
			}
			A.suprime(elementoA);
		}
	} else if (B.cardinal() > A.cardinal()) {
		while (B.cardinal() != 0) {
			int elementoB = B.muestrea();
			if (A.pertenece(elementoB)) {
				inserta(elementoB);
				if (!A.EsVacio())
					A.suprime(elementoB);
			}
			B.suprime(elementoB);
		}
	} else if (Equivalente(A, B)) {
		while (A.cardinal() != 0) {
			int elementoA = A.muestrea();
			if (B.pertenece(elementoA)) {
				inserta(elementoA);
				if (!B.EsVacio())
					B.suprime(elementoA);
			}
			A.suprime(elementoA);
		}
	}
}

bool ConjuntoP::Equivalente(ConjuntoP A, ConjuntoP B) {
	return (A.cardinal() == B.cardinal());
}

void ConjuntoP::MostrarConjunto(TCanvas *canvas, int x, int y) {
	canvas->TextOut(x, y, L"mostrar conjunto");
}
