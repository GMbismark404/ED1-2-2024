//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomioListaP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioLP::PolinomioLP() {
	pol = new ListaP;
}

Direccion PolinomioLP::BuscarExponente(int exp) {
	Direccion Dir = pol->siguiente(pol->primero());
	if (Dir != nullptr) {
		Direccion DirExp = nullptr;
		while (Dir != nullptr && DirExp == nullptr) {
			if (pol->recupera(Dir) == exp) {
				DirExp = Dir;
			}
			Dir = pol->siguiente(pol->siguiente(Dir));
		}
		return DirExp;
	} else {
		ShowMessage("El polinomio no tiene terminos!"); return nullptr;
	}

}

Direccion PolinomioLP::BuscarTerminoN(int i) {
	Direccion Dir = pol->primero();
	int Nt = 0;
	if (Dir != nullptr) {
		Direccion DirTer = nullptr;
		while (Dir != nullptr && DirTer == nullptr) {
			Nt = Nt + 1;
			if (Nt != i) {
				DirTer = Dir;
			}
			Dir = pol->siguiente(pol->siguiente(Dir));
		}
		return DirTer;
	} else {
		ShowMessage("El polinomio no tiene ese t�rmino!");
	}
}

bool PolinomioLP::EsCero() {
	return (pol->LongitudLista() == 0);
}

int PolinomioLP::Grado() {
	Direccion Dir = pol->siguiente(pol->primero());
	if (Dir != nullptr) {
		int MaxG = pol->recupera(Dir);
		while (Dir != nullptr) {
			if (pol->recupera(Dir) > MaxG) {
				MaxG = pol->recupera(Dir);
			}
			Dir = pol->siguiente(pol->siguiente(Dir));
		}
		return MaxG;
	} else {
		ShowMessage("El polinomio no tiene terminos!");
    }
}

int PolinomioLP::coeficiente(int exp) {
	Direccion Dir = BuscarExponente(exp);
	if (Dir != nullptr) {
		return pol->recupera(pol->anterior(Dir));
	} else {
		ShowMessage("El polinomio no tiene ese terminos!");
	}
}

void PolinomioLP::AsignarCoeficiente(int coef, int exp) {
	Direccion Dir = BuscarExponente(exp);
	if (Dir != nullptr) {
		Direccion DirCoef = pol->anterior(Dir);
		if (coef == 0) {
			pol->suprime(Dir);
			pol->suprime(DirCoef);
		}
	} else {
		ShowMessage("El polinomio no tiene ese t�rminos!");
	}
}

void PolinomioLP::poner_termino(int coef, int exp) {
	Direccion DirExp = BuscarExponente(exp);
	if (DirExp != nullptr) {
		Direccion DirCoef = pol->anterior(DirExp);
		pol->modifica(DirCoef, pol->recupera(DirCoef) + coef);
		if (pol->recupera(DirCoef) == 0) {
			pol->suprime(DirExp);
			pol->suprime(DirCoef);
		}
	} else {
		if (coef != 0) {
			pol->inserta_ultimo(exp);
			pol->inserta(pol->fin(), coef);
		} else {
            //si el coef es 0 entonces no se a�ade al polinomio!.
        }
	}
}

int PolinomioLP::numero_terminos() {
	return pol->LongitudLista() / 2;
}

int PolinomioLP::exponente(int nroter) {
	Direccion Dir = BuscarTerminoN(nroter);
	if (Dir != nullptr) {
		return pol->recupera(pol->siguiente(Dir));
	} else {
		ShowMessage("No existe ese n�mero de t�rminos!");
	}
}

void PolinomioLP::suma(PolinomioLP *p1, PolinomioLP *p2) {

	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex);
		p1->poner_termino(co, ex);
	}
}

void PolinomioLP::resta(PolinomioLP *p1, PolinomioLP *p2) {

	for (int i = 0; i < p1->numero_terminos(); i++) {
		int ex = p1->exponente(i);
		int co = p1->coeficiente(ex);
		p1->poner_termino(co, ex);
	}

	for (int j = 0; j < p2->numero_terminos(); j++) {
		int ex = p2->exponente(j);
		int co = p2->coeficiente(ex) * (-1);
		p1->poner_termino(co, ex);
	}
}

void PolinomioLP::multiplicacion(PolinomioLP *p1, PolinomioLP *p2) {
	//Desarrolle el algoritmo
}

void PolinomioLP::mostrar_integral(PolinomioLP *p, TCanvas *canvas) {
	canvas->Font->Name = L"Comic Sans MS";
	canvas->Font->Size = 12;
	canvas->Font->Color = clBlack;
	AnsiString mostrar = "";

	for (int i = 0; i < p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		mostrar = ("("+IntToStr(co)+"x^"+IntToStr(ex+1)+")/"+IntToStr(ex+1)+"+");
	}
	canvas->TextOutW(450, 500, L"" + mostrar + "C");
}

void PolinomioLP::derivar(PolinomioLP *p, PolinomioLP *p1) { //p1 es este polinomio
	for (int i = 0; i < p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);
	}
}

void PolinomioLP::MostrarPolinomio(TCanvas *canvas, int x, int y) {
	pol->MostrarLista(canvas, x, y);
}


