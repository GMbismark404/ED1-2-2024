//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomio_SMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioS::PolinomioS(CSMemoria *mem) {
	this->ptr_Poli = NULO;
	this->nt = 0;
    this->m = *mem;
}

direccion PolinomioS::BuscarExponente(int exp) {
	direccion dir = this->ptr_Poli;
	if (dir != NULO) {
		direccion dirEx = NULO;
		while (dir != NULO && dirEx == NULO) {
			if (m.obtener_dato(dir, "->exp") == exp) {
				dirEx = dir;
			}
			dir = m.obtener_dato(dir, "->sig");
		}
		return dirEx;
	} else {
		ShowMessage("No existe ese termino!");
		return NULO;
	}
}

direccion PolinomioS::BuscarTerminoN(int i) {
	direccion dir = this->ptr_Poli;
	if (dir != NULO) {
		direccion dirTer = NULO;
		nt = 0;
		while (dir != NULO && dirTer == NULO) {
			nt++;
			if (nt == i) {
				dirTer = dir;
			}
			dir = m.obtener_dato(dir, "->sig");
        }
		return dirTer;
	} else {
		ShowMessage("No existe terminos!");
        return NULO;
	}
}

bool PolinomioS::EsCero() {
	return (nt == 0);
}

int PolinomioS::Grado() {
	direccion dir = this->ptr_Poli;
	if (dir != NULO) {
		int MaxG = m.obtener_dato(dir, "->exp");
		while (dir != NULO) {
			if (m.obtener_dato(dir, "->exp") > MaxG) {
				MaxG = m.obtener_dato(dir, "->exp");
			}
			dir = m.obtener_dato(dir, "->sig");
		}
		return MaxG;
	} else {
		ShowMessage("No existe ese termino!");
        return NULO;
	}
}

int PolinomioS::coeficiente(int exp) {
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		return m.obtener_dato(dir, "->coef");
	} else {
		ShowMessage("No existe ese termino!");
	}
}

int PolinomioS::exponente(int nroter) {
	direccion dir = BuscarTerminoN(nroter);
	if (dir != NULO) {
		return m.obtener_dato(dir, "->exp");
	} else {
		ShowMessage("No existe ese termino!");
        return NULO;
	}
}

void PolinomioS::AsignarCoeficiente(int coef, int exp) {
	direccion dir = BuscarTerminoN(coef);
	if (dir != NULO) {
		m.poner_dato(dir, "->coef", coef);
		if (coef == 0) {
			m.delete_espacio(dir);
		}
	} else {
		ShowMessage("No existe ese termino!");
	}
}

void PolinomioS::poner_termino(int coef, int exp) {
	direccion existe = BuscarExponente(exp);
	if (existe == NULO) {
		direccion aux = m.new_espacio("coef,exp,sig");
		if (aux != NULO) {
			m.poner_dato(aux, "->coef", coef);
			m.poner_dato(aux, "->exp", exp);
			m.poner_dato(aux, "->sig", ptr_Poli);
			ptr_Poli = aux;
			nt++;
		} else {
			ShowMessage("Error espacio de memoria!");
		}
	} else {
		int nuevoCoef = m.obtener_dato(existe, "->coef") + coef;
		m.poner_dato(existe, "->coef", nuevoCoef);
		if (nuevoCoef == 0) {
			m.delete_espacio(existe);
		}
    }
}

int PolinomioS::numero_terminos() {
    return nt;
}

void PolinomioS::MostrarPolinomio(TCanvas *canvas, int desde, int hasta) {
	m.Mostrar(canvas, desde, hasta);
}

void PolinomioS::suma(PolinomioS *p1, PolinomioS *p2) {
	// poner polinomio en 0
	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex);
		poner_termino(co, ex);
	}

}

void PolinomioS::resta(PolinomioS *p1, PolinomioS *p2) {
	// poner polinomio en 0
	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex)*(-1);
		poner_termino(co, ex);
	}
}

void PolinomioS::multiplicacion(PolinomioS *p1, PolinomioS *p2) {
	//Desarrolle el algoritmo//
}

void PolinomioS::Mostrar_Intergral(PolinomioS *p, TCanvas *canvas) {
AnsiString cadena = "";
	for (int i = 0; i < p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		cadena = "(" + IntToStr(co) + "x^" + IntToStr(ex+1) + ")/" + IntToStr(ex+1) + "+";
	}
			canvas->TextOutW(500,500, L"" + cadena + "C");
}


void PolinomioS::derivar(PolinomioS *p, PolinomioS *p1) { //p es este polinomio
	for (int i = 1; i <= p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);      //2x^5 -> 10x^4
	}
}
