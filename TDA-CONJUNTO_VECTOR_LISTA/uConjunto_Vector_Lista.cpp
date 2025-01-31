//---------------------------------------------------------------------------
#pragma hdrstop
#include "uConjunto_Vector_Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoVL::ConjuntoVL() {
	//elem = new ListaV;
}

bool ConjuntoVL::EsVacio() {
	return (elem.LongitudLista() == 0);
}

bool ConjuntoVL::pertenece(int elemento) {
	if (!elem.EsVacio()) {
		direccion p = elem.primero();
		while (p != NULO) {
			int ele = elem.recupera(p);
			if (elemento == ele)
				return true;
			else
				p = elem.siguiente(p);
        }
		return false;
	} else {
		ShowMessage("Error!. El conjunto C no tiene elementos"); return false;
	}
}

void ConjuntoVL::inserta(int elemento) {
	if (!pertenece(elemento))
		elem.inserta(elem.primero(), elemento);
}

int ConjuntoVL::cardinal() {
	return elem.LongitudLista();
}

int ConjuntoVL::ordinal(int elemento) {
	if (!elem.EsVacio()) {
		int cont = 0;
		direccion p = elem.primero();
		while (p != NULO) {
			cont++;
			int ele = elem.recupera(p);
			if (elemento == ele)
				return cont;
			else
				p = elem.siguiente(p);
		}
		return cont;
	} else {
		ShowMessage("Error!. El conjunto C no tiene elementos");
    }
}

void ConjuntoVL::suprime(int elemento) {
	if (pertenece(elemento)) {
		direccion dir = NULO;
		direccion p = elem.primero();
		while (p != NULO) {
			int ele = elem.recupera(p);
			if (elemento == ele) {
				dir = p;
				p = NULO;
			} else
				p = elem.siguiente(p);
		}

		if (dir != NULO)
			elem.suprime(dir);
	} else {
		ShowMessage("Error!. El conjunto C no tiene dicho elemento o no tiene elementos!");
	}
}

int ConjuntoVL::obtenerNumeroAleatorio(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int ConjuntoVL::muestrea() {
	int lug = obtenerNumeroAleatorio(1, elem.LongitudLista());
	direccion dir = elem.primero();
	direccion dirElem = NULO;
	int cont = 0;
	for (int i = 0; i < elem.LongitudLista(); i++) {
		cont = cont + 1;
		if (cont == lug)
			dirElem = dir;
		else
			dir = elem.siguiente(dir);
	}
    return elem.recupera(dirElem);
}

void ConjuntoVL::Union(ConjuntoVL A, ConjuntoVL B) {
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

void ConjuntoVL::Interseccion(ConjuntoVL A, ConjuntoVL B) {
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
	} else if (Equivalente(A,B)) {
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

bool ConjuntoVL::Equivalente(ConjuntoVL A, ConjuntoVL B) {
	return (A.cardinal() == B.cardinal());
}

void ConjuntoVL::MostrarConjunto(TCanvas *canvas, int x, int y) {
    elem.MostrarLista(canvas, x, y);
}