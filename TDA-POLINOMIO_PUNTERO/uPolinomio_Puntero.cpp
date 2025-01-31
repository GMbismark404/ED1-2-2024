//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomio_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
PolinomioP::PolinomioP() {
	this->nt = 0;
	this->ptr_Poli = nullptr;
}

Direccion PolinomioP::BuscarExponente(int exp) {
	Direccion dir = ptr_Poli;
	if (dir != nullptr) {
		Direccion dirEx = nullptr;
		while ((dir != nullptr) && (dirEx == nullptr)) {
			if (dir->exp == exp) {
				dirEx = dir;
			}
			dir = dir->sig;
		}
		return dirEx;
	} else {
		ShowMessage("exception no existe ese termino");
	}
}

Direccion PolinomioP::BuscarTerminoN(int i) {
	Direccion dir = ptr_Poli;
	if (dir != nullptr) {
		Direccion dirTer = nullptr;
		this->nt = 0;
		while ((dir != nullptr) && (dirTer == nullptr)) {
			nt = nt + 1;
			if (nt == i) {
				dirTer = dir;
			}
			dir = dir->sig;
		}
		return dirTer;
	} else {
		ShowMessage("exception no existe terminos!");
	}
}

bool PolinomioP::EsCero() {
	return (nt == 0);
}

int PolinomioP::Grado() {
	Direccion dir = ptr_Poli;
	if (dir != nullptr) {
		int MaxG = dir->exp;
		while (dir != nullptr) {
			if (dir->exp > MaxG) {
				MaxG = dir->exp;
			}
		}
		return MaxG;
	} else {
		ShowMessage("exception no existe ese termino!");
	}
}

int PolinomioP::coeficiente(int exp) {
	Direccion dir = BuscarExponente(exp);
	if (dir != nullptr) {
		return dir->coef;
	} else {
		ShowMessage("exception no existe ese termino!");
    }
}

void PolinomioP::AsignarCoeficiente(int coef, int exp) {
	Direccion dir = BuscarExponente(exp);
	if (dir != nullptr) {
		dir->coef = coef;
		if (coef == 0) {
			//eliminar nodo
		}
	} else {
		ShowMessage("exception no existe ese termino!");
	}
}

int PolinomioP::exponente(int nroter) {
	Direccion dir = BuscarTerminoN(nroter);
	if (dir != nullptr) {
		return dir->exp;
	} else {
		ShowMessage("exception no existe ese termino!");
    }
}

void PolinomioP::poner_termino(int coef, int exp) {
	Direccion existe = BuscarExponente(exp);
	if (existe == nullptr) {
		Direccion aux = new Nodo;
		if (aux != nullptr) {
			aux->coef = coef;
			aux->exp = exp;
			aux->sig = ptr_Poli;
			ptr_Poli = aux;
			nt = nt + 1;
		} else {
			ShowMessage("Error de memoria!");
		}
	} else {
		int NuevoCoef = existe->coef + coef;
		existe->coef = NuevoCoef;
		//eliminar nodo si NuevoCoef es 0
    }
}

int PolinomioP::numero_terminos() {
	return nt;
}

void PolinomioP::suma(PolinomioP *p1, PolinomioP *p2) {
	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p1->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex);
		p2->poner_termino(co, ex);
	}
}

void PolinomioP::resta(PolinomioP *p1, PolinomioP *p2) {
	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p1->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex)*(-1);
		p2->poner_termino(co, ex);
	}
}

void PolinomioP::multiplicacion(PolinomioP *p1, PolinomioP *p2) {
//     Desarrolle el algoritmo
}

void PolinomioP::derivar(PolinomioP *p, PolinomioP *p1) {
	for (int i = 1; i <= p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);      //2x^5 -> 10x^4
	}
}

void PolinomioP::MostrarPolinomio(TCanvas *canvas, int x, int y) {
AnsiString cad = "<| ";
	if (!EsCero()) {
		for (Direccion p = ptr_Poli; p != nullptr; p = p->sig) {
			cad = cad + AnsiString(IntToStr(p->coef)) + ", ";
			cad = cad + AnsiString(IntToStr(p->exp)) + ", ";
		}
		canvas->Font->Size = 38;
		canvas->TextOutW(x, y, cad.Delete(cad.Length() - 1, 2) + L" |>" );
	} else {
		canvas->Font->Size = 38;
		canvas->TextOutW(x, y, cad + L"Vacio |>" );
	}
}

