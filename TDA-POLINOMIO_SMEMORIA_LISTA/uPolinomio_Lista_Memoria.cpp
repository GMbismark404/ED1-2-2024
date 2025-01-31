//---------------------------------------------------------------------------
#pragma hdrstop
#include "uPolinomio_Lista_Memoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PolinomioLS::PolinomioLS(CSMemoria *mem) : pol(mem){
	this->nt = 0;
}

direccion PolinomioLS::BuscarExponente(int exp) {
	direccion dir = pol.siguiente(pol.primero());
	if (dir != NULO) {
		direccion dirExp = NULO;
		while (dir != NULO && dirExp == NULO) {
			if (pol.recupera(dir) == exp) {
				dirExp = dir;
			}
			dir = pol.siguiente(pol.siguiente(dir));
		}
		return dirExp;
	} else {
		ShowMessage("El polinomio no tiene terminos!");	return NULO;
	}
}

direccion PolinomioLS::BuscarTerminoN(int i) {
	direccion dir = pol.primero();
	nt = 0;
	if (dir != NULO) {
		direccion dirTer = NULO;
		while (dir != NULO && dirTer == NULO) {
			nt++; // nt = nt + 1;
			if (nt == i) {
				dirTer = dir;
			}
			dir = pol.siguiente(pol.siguiente(dir));
		}
		return dirTer;
	} else {
		ShowMessage("El polinomio no tiene terminos!");
		return NULO;
	}
}

bool PolinomioLS::EsCero() {
	return (pol.LongitudListas() == 0);
}

int PolinomioLS::Grado() {
	direccion dir = pol.siguiente(pol.primero());
	if (dir != NULO) {
		int MaxG = pol.recupera(dir);
		while (dir != NULO) {
			if (pol.recupera(dir) > MaxG) {
				MaxG = pol.recupera(dir);
			}
			dir = pol.siguiente(pol.siguiente(dir));
		}
		return MaxG;
	} else {
		ShowMessage("El polinomio no tiene terminos!");
		return NULO;
	}
}

int PolinomioLS::coeficiente(int exp) {
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		return pol.recupera(pol.anterior(dir));
	} else {
		ShowMessage("El polinomio no tiene ese termino!");
	}
}

int PolinomioLS::exponente(int nroter) {
	direccion dir = BuscarTerminoN(nroter);
	if (dir != NULO) {
		return pol.recupera(pol.siguiente(dir));
	} else {
		ShowMessage("No existe ese numero de termino!");
	}
}

void PolinomioLS::AsignarCoeficiente(int coef, int exp) {
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		direccion dirCoef = pol.anterior(dir);
		pol.modifica(dirCoef, coef);
		if (coef == 0) {
			pol.suprime(dir);
			pol.suprime(dirCoef);
		}
	} else {
		ShowMessage("El polinomio no tiene ese termino!");
	}
}

void PolinomioLS::poner_termino(int coef, int exp) {
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
			pol.inserta_ulitmo(exp);
			pol.inserta(pol.fin(), coef);
		} else {
            //si el coef es 0 entonces no se a�ade el polinomio!.
        }
	}
}

int PolinomioLS::numero_terminos() {
	return pol.LongitudListas() / 2;
}

void PolinomioLS::MostrarPolinomio(TCanvas *canvas, int desde, int hasta) {
	pol.MostrarLista(canvas, desde, hasta);
}

void PolinomioLS::suma(PolinomioLS *p1, PolinomioLS *p2) {
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

void PolinomioLS::resta(PolinomioLS *p1, PolinomioLS *p2) {
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

void PolinomioLS::multiplicacion(PolinomioLS *p1, PolinomioLS *p2) {
	//Desarrolle el algoritmo//
}

void PolinomioLS::Mostrar_Intergral(PolinomioLS *p, TCanvas *canvas) {
AnsiString cadena = "";
	for (int i = 0; i < p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		cadena = "(" + IntToStr(co) + "x^" + IntToStr(ex+1) + ")/" + IntToStr(ex+1) + "+";
	}
			canvas->TextOutW(500,500, L"" + cadena + "C");
}


void PolinomioLS::derivar(PolinomioLS *p, PolinomioLS *p1) { //p es este polinomio
	for (int i = 1; i <= p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);      //2x^5 -> 10x^4
	}
}

void PolinomioLS::graficarPolinomio(TCanvas *Canvas, int A, int B) {  // Intervalo [A,B]
	if (!EsCero()) {
		if (A >= B)	{
			ShowMessage("El l�mite A debe ser menor que el l�mite B");
			return;
		}
		// Dimensiones del �rea de dibujo
		int ancho = 1000;		int pOrigenX = 500;
		int alto = 1000;		int pOrigenY = 0;

		// Limpiar el �rea de dibujo
		Canvas->Brush->Color = clWhite; // Color de fondo blanco
		TRect drawArea(pOrigenX, pOrigenY, pOrigenX + ancho, pOrigenY + alto);
		Canvas->FillRect(drawArea);     // Rellenar el �rea completa del formulario

		// Dibujar los ejes X y Y
		Canvas->Pen->Color = clBlack;   // Color del lapiz negro
		Canvas->MoveTo(pOrigenX, pOrigenY + (alto / 2));
		Canvas->LineTo(ancho + pOrigenX, pOrigenY + (alto / 2));  // Eje X
		Canvas->MoveTo(pOrigenX + (ancho / 2), pOrigenY);
		Canvas->LineTo(pOrigenX + (ancho / 2), pOrigenY + alto);  // Eje Y

		// Dibujar escalas num�ricas en el eje X
		Canvas->Font->Color = clBlack;  // Color de la fuente
		for (int x = -ancho / 2; x <= ancho / 2; x += 20) {
			int screenX = pOrigenX + (ancho / 2) + x;
			int screenY = pOrigenY + (alto / 2);

			// Dibujar marcas de escala
			Canvas->MoveTo(screenX, screenY - 5); // L�nea hacia arriba
			Canvas->LineTo(screenX, screenY + 5); // L�nea hacia abajo

			// Mostrar los n�meros de la escala
			if (x != 0) {  // No dibujar el n�mero 0 en el eje X
				String label = IntToStr(x / 20);  // Convertir la escala a su valor num�rico
				Canvas->TextOut(screenX - 5, screenY + 10, label);
			}
		}

		// Dibujar escalas num�ricas en el eje Y
		for (int y = -alto / 2; y <= alto / 2; y += 20) {
			int screenX = pOrigenX + (ancho / 2);
			int screenY = pOrigenY + (alto / 2) - y;

			// Dibujar marcas de escala
			Canvas->MoveTo(screenX - 5, screenY); // L�nea a la izquierda
			Canvas->LineTo(screenX + 5, screenY); // L�nea a la derecha

			// Mostrar los n�meros de la escala
			if (y != 0) {  // No dibujar el n�mero 0 en el eje Y
				String label = IntToStr(y / 20);  // Convertir la escala a su valor num�rico
				Canvas->TextOut(screenX + 10, screenY - 5, label);
			}
		}

		// Dibujar el polinomio: ax^2 + bx + c
		Canvas->Pen->Color = clRed; // Color de la l�nea del polinomio
		for (int x = A*20; x <= B*20; x++) {
			double xf = x / 20.0;  // Escala de zoom horizontal
			double yf = evaluarPolinomio(xf);  // Evaluar la funci�n polin�mica
			int screenX = pOrigenX + (ancho / 2) + x;          // Convertir a coordenadas de pantalla
			int screenY = pOrigenY + (alto / 2) - (int)(yf * 20); // Ajustar escala vertical

			if (x == A*20)
				Canvas->MoveTo(screenX, screenY);
			else
				Canvas->LineTo(screenX, screenY);
		}

	} else {
		ShowMessage("Error espacio de memoria vac�a!");
	}
}

double PolinomioLS::evaluarPolinomio(double xf) {
	double yf = 0;
	for (int i = 1; i <= numero_terminos(); i++) {
		int exp = exponente(i);
		int coef = coeficiente(exp);
		yf = yf + coef*pow(xf, exp);
	}
	return yf;
}
