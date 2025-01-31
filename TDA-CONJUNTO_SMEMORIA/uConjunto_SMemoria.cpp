//---------------------------------------------------------------------------
#pragma hdrstop
#include "uConjunto_SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConjuntoS::ConjuntoS(CSMemoria *mem) { //  Sirve para inicializar el conjunto
	this->cant = 0;
	this->ptrConj = NULO;
	this->m = *mem;
}

bool ConjuntoS::EsVacio() { // Verifica si el conjunto es vacio
	return (cant == 0); //ptrConj == NULO;
}

int ConjuntoS::cardinal() { // Cuenta cuantos elementos tiene el conjunto C
	return cant;
}

bool ConjuntoS::pertenece(int elemento) { // Verifica si elemento E pertence al conjunto C
	bool resp = false;
	direccion pc = ptrConj;
	while (pc != NULO) {
		if (m.obtener_dato(pc, "->dato") == elemento) {
			resp = true;
			pc = NULO;
		} else
			pc = m.obtener_dato(pc, "->sig");
	}
	return resp;
}

void ConjuntoS::inserta(int elemento) { // A�ade el elemento E al conjunto C
	if (!pertenece(elemento)) {
		direccion dir = m.new_espacio("dato,sig");
		if (dir != NULO) {
			m.poner_dato(dir, "->dato", elemento);
			m.poner_dato(dir, "->sig", ptrConj);
			ptrConj = dir;
			cant++; // cant = cant + 1
		} else {
			ShowMessage("Error!. No existe expacio de memoria!");
        }
	} else {
		ShowMessage("Error!. El elemento ya existe en el conjunto C!");
	}
}

posicion ConjuntoS::ordinal(int elemento) { //  Busca el lugar que ocupa el elemento E en C
	posicion resp = 0;
	direccion pc = ptrConj;
	while (pc != NULO) {
		resp = resp + 1;
		if (m.obtener_dato(pc, "->dato") == elemento) {
			return resp;
			pc = NULO;
		}
		pc = m.obtener_dato(pc, "->sig");
	}
	return resp;
}

void ConjuntoS::suprime(int elemento) { // Elimina E del conjunto C
	if (cant != 0) {
		direccion dir = ptrConj;
		direccion pc = ptrConj;
		while (pc != NULO) {
			if (m.obtener_dato(pc, "->dato") == elemento) {
				if (pc == ptrConj) {
					ptrConj = m.obtener_dato(ptrConj, "->sig");
					m.delete_espacio(pc);
					cant = cant - 1;
					pc = NULO;
				} else {
					m.poner_dato(dir, "->sig", m.obtener_dato(pc,"->sig"));
					m.delete_espacio(pc);
					cant = cant - 1;
					pc = NULO;
				}
			} else {
				dir = pc;
				pc = m.obtener_dato(pc, "->sig");
			}
		}

	}
}

int ConjuntoS::muestrea() { //Busca un elemento E al azar que pertenece al conjunto C
	if (cant > 0) {
		int lugar = 0;      //'lugar' es el iterador del conjunto C
		int elemento = 0;
		int lugarBuscado = obtenerNumeroAleatorio(1, cant);	// obtiene una posici�n del conjunto C al azar desde 1<=x<=cant
		direccion pc = ptrConj;
		while (pc != NULO) {
			lugar = lugar + 1;
			if (lugarBuscado == lugar) {
				elemento = m.obtener_dato(pc, "->dato");
				pc = NULO;
			} else
				pc = m.obtener_dato(pc, "->sig");
		}
		return elemento;
	} else {
		ShowMessage("Error!. No existe ning�n elemento en el conjunto C!");
    }
}

int ConjuntoS::obtenerNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void ConjuntoS::MostrarConjunto(TCanvas *canvas, int desde, int hasta) {
	m.Mostrar(canvas, desde, hasta);
}

void ConjuntoS::Union(ConjuntoS A, ConjuntoS B) {  //AUB
//CSMemoria *mem = new CSMemoria;
//ConjuntoS C(mem);
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
//	C.MostrarConjunto(canvas, 0, 11);
}

void ConjuntoS::Interseccion(ConjuntoS A, ConjuntoS B) {
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

bool ConjuntoS::Equivalente(ConjuntoS A, ConjuntoS B) {
	return (A.cardinal() == B.cardinal());
}
