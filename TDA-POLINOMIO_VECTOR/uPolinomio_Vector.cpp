//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomio_Vector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioV::PolinomioV() {
	this->nt = 0;
}

bool PolinomioV::EsCero() {
	return (nt == 0);
}

int PolinomioV::Grado() {
	if (nt > 0) {
		int max = ve[1];
		for (int i = 0; i < nt; i++) {
			if (ve[i] > max) {
				max = ve[i];
			}
		}
		return max;
	} else {
		ShowMessage("error no existe terminos!");
	}
}

void PolinomioV::AsignarCoeficiente(int coef, int exp) {
	direccion lug = -1; // Existe exponente (exp) en la estructura revisando vector ve
	if (lug != -1) {
		vc[lug] = vc[lug] + coef;
		if (vc[lug] == 0) {
			// Desplazar 1 elemento hacia la posicion lug
			nt = nt - 1;
		} else {
			nt = nt + 1;
			vc[nt] = coef;
			ve[nt] = exp;
        }
	} else {
		ShowMessage("error no existe el exponente!");
	}
}

int PolinomioV::numero_terminos() {
	return nt;
}

int PolinomioV::coeficiente(int exp) {
	if (exp >= 0 && exp <= Grado()) {
		for (int i = 0; i < nt; i++) {
			if (ve[i] == exp) {
				return vc[i];
			}
		}
	} else {
		ShowMessage("error no existe termino con ese exponente!);
	}
}

int PolinomioV::exponente(int nroter) {
	return ve[nroter];
}

void PolinomioV::suma(PolinomioV *p1, PolinomioV *p2) {
	 // poner polinomio en 0
	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex);
		p2->poner_termino(co, ex);
	}
}

void PolinomioV::resta(PolinomioV *p1, PolinomioV *p2) {

	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex)*(-1);
		p2->poner_termino(co, ex);
	}
}

void PolinomioV::multiplicacion(PolinomioV *p1, PolinomioV *p2) {
	 //Desarrolle el algoritmo//
}
