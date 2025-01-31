//---------------------------------------------------------------------------
#pragma hdrstop
#include "uConjunto_Puntero_Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoPL::ConjuntoPL() {
	elem = new ListaP;
}

bool ConjuntoPL::EsVacio() {
	return (elem->LongitudLista());
}

bool ConjuntoPL::pertenece(int elemento) {
	if (!elem->EsVacio()) {
		Direccion p = elem->primero();
		while (p != nullptr) {
			int ele = elem->recupera(p);
			if (elemento == ele)
				return true;
			else
				p = elem->siguiente(p);
		}
		return false;
	} else {
		ShowMessage("Error!. El conjunto C no tiene elementos"); return false;
    }
}

void ConjuntoPL::inserta(int elemento) {
	if (!pertenece(elemento)) {
		elem->inserta(elem->primero(), elemento);
	}
}

int ConjuntoPL::cardinal() {
	return elem->LongitudLista();
}

posicion ConjuntoPL::ordinal(int elemento) {
	if (!elem->EsVacio()) {
		int cont = 0;
		Direccion p = elem->primero();
		while (p != nullptr) {
			cont = cont + 1;
			int ele = elem->recupera(p);
			if (elemento == ele)
				return cont;
			else
				p = elem->siguiente(p);
		}
		return cont;
	} else {
        ShowMessage("Error!. El conjunto C no tiene elementos!");
    }
}

void ConjuntoPL::suprime(int elemento) {
	if (pertenece(elemento)) {
		Direccion dir = nullptr;
		Direccion p = elem->primero();
		while (p != nullptr) {
			int ele = elem->recupera(p);
			if (elemento == ele) {
				dir = p;
				p = nullptr;
			} else
				p = elem->siguiente(p);
		}

		if (dir != nullptr)
			elem->suprime(dir);
	} else {
		ShowMessage("Error!. El conjunto C no tiene dicho elemento!");
    }
}

int ConjuntoPL::muestrea() {
	int lug = obtenerNumeroAleatorio(1, elem->LongitudLista());
	Direccion dir = elem->primero();
	Direccion dirElem = nullptr;
	int cont = 0;
	for (int i = 0; i < elem->LongitudLista(); i++) {
		cont = cont + 1;
		if (cont == lug)
			dirElem = dir;
		else
			dir = elem->siguiente(dir);
	}
	return elem->recupera(dirElem);
}

void ConjuntoPL::Union(ConjuntoPL A, ConjuntoPL B) {
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


void ConjuntoPL::Interseccion(ConjuntoPL A, ConjuntoPL B) {
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

bool ConjuntoPL::Equivalente(ConjuntoPL A, ConjuntoPL B) {
	return (A.cardinal() == B.cardinal());
}

void ConjuntoPL::MostrarConjunto(TCanvas *canvas, int x, int y) {
    elem->MostrarLista(canvas, x, y);
}
