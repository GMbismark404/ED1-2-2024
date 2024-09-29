//---------------------------------------------------------------------------
#pragma hdrstop
#include "uConjunto_Vector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoV::ConjuntoV()
{
	for (int i = 0; i < MAX; i++)
		vector[i] = 0;
}

bool ConjuntoV::pertenece(int elemento) {
	return (vector[elemento] == 1);
}

void ConjuntoV::inserta(int elemento) {
	if (!pertenece(elemento)) {
		vector[elemento] = 1;
		cant++;
	}
}

void ConjuntoV::suprime(int elemento) {
	if (pertenece(elemento)) {
		vector[elemento] = 0;
		cant--;
	}
}

bool ConjuntoV::EsVacio() {
	return (cant == 0);
}

int ConjuntoV::cardinal() {
	return cant;
}

int ConjuntoV::ordinal(int elemento) {
	int resp = 0;
	for (int i = 0; i < MAX; i++) {
		if (vector[i] != 0) {
			resp++;
			if (elemento == i)
				return resp;
		}
	}
	return resp;
}

int ConjuntoV::obtenerNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int ConjuntoV::muestrea() {
	int resp = 0; int elemento = 0;
	int lug = obtenerNumeroAleatorio(1, cant);
	for (int i = 0; i < MAX; i++) {
		if (vector[i] != 0) {
			resp++;
			if (resp == lug) {
				elemento = i;
				break;
			}
		}
	}
	return elemento;
}

void ConjuntoV::Union(ConjuntoV A, ConjuntoV B) {
	while (A.cardinal() != 0) {
		int elemento = A.muestrea();
		inserta(elemento);  // Conjuto C
		A.suprime(elemento);
	}

	while (B.cardinal() != 0) {
		int elemento = B.muestrea();
		inserta(elemento); // Conjuto C
		B.suprime(elemento);
	}
}

void ConjuntoV::Interseccion(ConjuntoV A, ConjuntoV B) {
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

bool ConjuntoV::Equivalente(ConjuntoV A, ConjuntoV B) {
	return (A.cardinal() == B.cardinal());
}

void ConjuntoV::MostrarConjunto(TCanvas *canvas, int x, int y) {
AnsiString cad = "<| ";
	for (int i = 0; i < MAX; i++) {
		if (vector[i] != 0)
			cad = cad + AnsiString(IntToStr(i)) + ", ";
	}
	canvas->Font->Size = 38;
	canvas->TextOutW(x, y, cad.Delete(cad.Length() - 1, 2) + L" |>" );
}
