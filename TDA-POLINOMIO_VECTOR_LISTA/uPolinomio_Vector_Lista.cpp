//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomio_Vector_Lista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioVL::PolinomioVL() {
	this->nt = 0;
}

direccion PolinomioVL::BuscarExponente(int exp) {
	direccion dir = pol.siguiente(pol.primero());
	if (dir != NULO) {
		direccion dirExp = NULO;
		while (dir != NULO && dirExp == NULO) {
			if (pol.recupera(dir) == exp) {
				dirExp = dir;
				dir = NULO;
			} else
				dir = pol.siguiente(pol.siguiente(dir));
		}
		return dirExp;
	} else {
		ShowMessage("Error!. El polinomio no tiene terminos!"); return NULO;
    }
}

direccion PolinomioVL::BuscarTerminoN(int i) {
	direccion dir = pol.primero();
	int numTer = 0;
	if (dir != NULO) {
		direccion dirExp = NULO;
		while (dir != NULO && dirExp == NULO) {
			numTer++;
			if (numTer == i) {
				dirExp = dir;
				dir = NULO;
			} else
				dir = pol.siguiente(pol.siguiente(dir));
        }
		return dirExp;
	} else {
		ShowMessage("Error!. El polinomio no tiene terminos!"); return NULO;
	}
}

bool PolinomioVL::EsCero() {
	return (pol.LongitudLista() == 0);
}

int PolinomioVL::Grado() {
	direccion dir = pol.siguiente(pol.primero());
	if (dir != NULO) {
		int MaxG = pol.recupera(dir);
		while (dir != NULO) {
			if (pol.recupera(dir) > MaxG) {
				MaxG = pol.recupera(dir);
			} //No poner else
			dir = pol.siguiente(pol.siguiente(dir));
		}
		return MaxG;
	} else {
		ShowMessage("Error!. El polinomio no tiene terminos!"); return NULO;
	}
}

int PolinomioVL::coeficiente(int exp) {
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		return pol.recupera(pol.anterior(dir));
	} else {
		ShowMessage("Error!. El polinomio no tiene terminos!"); return NULO;
    }
}

void PolinomioVL::AsignarCoeficiente(int coef, int exp) {
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		direccion dirCoef = pol.anterior(dir);
		pol.modifica(dirCoef, coef);
		if (coef == 0) {
			pol.suprime(dir);
			pol.suprime(dirCoef);
		}
	} else {
		ShowMessage("Error!. El polinomio no tiene ese terminos!");
    }
}

void PolinomioVL::poner_termino(int coef, int exp) {
	direccion dirExp = BuscarExponente(exp);
	if (dirExp != NULO) {
		direccion dirCoef = pol.anterior(dirExp);
		pol.modifica(dirCoef, pol.recupera(dirCoef) + coef);
		if (pol.recupera(dirCoef) == 0) {
			pol.suprime(dirExp);
			pol.suprime(dirCoef);
		}
	} else {
		if (coef != 0) {
			pol.inserta_ultimo(exp);
			pol.inserta(pol.fin(), coef);
		} else {
            //si el coef es 0 entonces no se a�ade el polinomio!.
		}
	}
}

int PolinomioVL::numero_terminos() {
	return (pol.LongitudLista() / 2);
}

int PolinomioVL::exponente(int nroter) {
	direccion dir = BuscarTerminoN(nroter);
	if (dir != NULO) {
		return pol.recupera(pol.siguiente(dir));
	} else {
		ShowMessage("Error!. El polinomio no tiene terminos!"); return NULO;
    }
}

void PolinomioVL::suma(PolinomioVL *p1, PolinomioVL *p2) {

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

void PolinomioVL::resta(PolinomioVL *p1, PolinomioVL *p2) {

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

void PolinomioVL::multiplicacion(PolinomioVL *p1, PolinomioVL *p2) {
	//Desarrolle el algoritmo
}

void PolinomioVL::mostrar_integral(PolinomioVL *p, TCanvas *canvas) {
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

void PolinomioVL::MostrarPolinomio(TCanvas *canvas, int x, int y) {
AnsiString cad = "<| ";
	if (!EsCero()) {
		for (direccion p = pol.primero(); p != NULO; p = pol.siguiente(p)) {
			if (pol.recupera(p) != 0) {
				cad = cad + AnsiString(IntToStr(pol.recupera(p))) + ", ";
				cad = cad + AnsiString(IntToStr(pol.recupera(pol.siguiente(p)))) + ", ";
			}
		}
		canvas->Font->Size = 38;
		canvas->TextOutW(x, y, cad.Delete(cad.Length() - 1, 2) + L" |>" );
	} else {
		canvas->Font->Size = 38;
		canvas->TextOutW(x, y, cad + L"Vacio |>" );
    }

}

void PolinomioVL::derivar(PolinomioVL *p, PolinomioVL *p1) { //p1 es este polinomio
	for (int i = 0; i < p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);
	}
}
