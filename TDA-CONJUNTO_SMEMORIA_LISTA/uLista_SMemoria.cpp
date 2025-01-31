//---------------------------------------------------------------------------
#pragma hdrstop
#include "uLista_SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaS::ListaS(CSMemoria *mem) {
	this->longitud = 0;
	this->PtrElementos = NULO;
//	this->mem = new CSMemoria;
	this->m = *mem;
}

direccion ListaS::fin() {
	if (EsVacio()) {
		//exepcion
	} else {
		direccion x = PtrElementos;
		direccion ptrFin = NULO;
		while (x != NULO) {
			ptrFin = x;
			x = m.obtener_dato(x, "->sig");
		}
		return ptrFin;
	}
}

direccion ListaS::primero() {
	if (EsVacio()) {
		return NULO;
	} else {
		return PtrElementos;
	}
}

direccion ListaS::siguiente(direccion p) {
	if (EsVacio()) {
		return NULO;
	} else {
		if (p == fin()) {
            return NULO;
		} else {
			if (p != NULO)
				return m.obtener_dato(p,"->sig");
			else
				return NULO;
		}
    }
}

direccion ListaS::anterior(direccion p) {
	if (EsVacio()) {
		//exepcion lista vacia
		ShowMessage("direccion error");
        return NULO;
	} else if (p == primero()) {
		//exepcion direccion error
		ShowMessage("direccion error");
		return NULO;
	} else {
		direccion x = PtrElementos;
		direccion ant = NULO;
		while ( x != NULO) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = m.obtener_dato(x,"->sig");   //  x = m.obtener_dato(x,"->sig");
		}
		return NULO;
	}
}

bool ListaS::EsVacio() {
	return (longitud == 0);
}

int ListaS::recupera(direccion p) {
	if (EsVacio()) {
        return -1;
	} else {
		return m.obtener_dato(p, "->elemento");
    }
}

int ListaS::LongitudLista() {
    return longitud;
}

void ListaS::inserta(direccion p, int elemento) {
	direccion x = m.new_espacio("elemento,sig");
	if (x != NULO) {
		m.poner_dato(x, "->elemento", elemento);
		m.poner_dato(x, "->sig", NULO);
		if (EsVacio()) {
			PtrElementos = x; longitud = 1;
		} else {
			longitud = longitud + 1;
			if (p == primero()) {
				m.poner_dato(x, "->sig", p);
				PtrElementos = x;
			} else {
				direccion ant = anterior(p);
				m.poner_dato(ant, "->sig", x);
				m.poner_dato(x, "->sig", p);
			}
		}
	} else {
		ShowMessage("Memoria llena, no es posible asignar memoria");
	}
}

void ListaS::inserta_primero(int elemento) {
	direccion x = m.new_espacio("elemento,sig");
	if (x != NULO) {
		m.poner_dato(x, "->elemento", elemento);
		m.poner_dato(x, "->sig", PtrElementos);
		longitud++; //longitud = longitud + 1;
		PtrElementos = x;
	} else {
		ShowMessage("Memoria llena, no es posible asignar memoria");
	}
}

void ListaS::inserta_ulitmo(int elemento) {
	direccion x = m.new_espacio("elemento,sig"); // pedir memoria de un Nodo
	if (x != NULO) {
		m.poner_dato(x, "->elemento", elemento);
		m.poner_dato(x, "->sig", NULO);
		if (longitud != 0) {
			m.poner_dato(fin(), "->sig", x);
		} else {
			PtrElementos = x;
		}
		longitud++; //longitud = longitud + 1;
	} else {
		ShowMessage("Memoria llena, no es posible asignar memoria");
	}
}

void ListaS::suprime(direccion p) {
	if (longitud == 0) {
		ShowMessage("La lista est� vac�a"); return;
	} else if (p == PtrElementos) {
		direccion x = PtrElementos;
		PtrElementos = m.obtener_dato(PtrElementos, "->sig");
		m.delete_espacio(x);
	} else {
		direccion ant = anterior(p);
		m.poner_dato(ant, "sig", m.obtener_dato(p, "sig"));
		m.delete_espacio(p);
	}
	longitud--; //longitud = longitud - 1;
}

void ListaS::modifica(direccion p, int elemento) {
	if (EsVacio()) {
		ShowMessage("La lista est� vac�a");
	} else {
		m.poner_dato(p, "->elemento", elemento);
    }
}

void ListaS::anula() {
	if (!EsVacio()) {
		for (direccion x = primero(); x != NULO; x = primero()) {
			suprime(x);
		}
		ShowMessage("Memoria Limpia!");
	} else {
        ShowMessage("La lista est� vac�a!");
    }
}

direccion ListaS::buscar(ListaS L, int elemento) { // Busca la posicion de un elemento
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

void ListaS::MostrarLista(TCanvas *canvas, int desde, int hasta) {
    m.Mostrar(canvas, desde, hasta);
}
