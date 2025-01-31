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

direccion PolinomioS::BuscarTerminoN(int i) {   //busca el t�rmino de un polinomio dado una posici�n
	direccion dir = this->ptr_Poli;
	if (dir != NULO) {
		direccion dirTer = NULO;
		int numTer = 0;
		while (dir != NULO && dirTer == NULO) {
			numTer++;
			if (numTer == i) {
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

int PolinomioS::Grado() {  //devuelve el mayor Grado del polinomio
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

int PolinomioS::coeficiente(int exp) {  //dado el exp obtienes el coef
	direccion dir = BuscarExponente(exp);
	if (dir != NULO) {
		return m.obtener_dato(dir, "->coef");
	} else {
		ShowMessage("No existe ese termino!");
		return NULO;
	}
}

int PolinomioS::exponente(int nroter) { // dado la posici�n del termino obtienes el exp
	direccion dir = BuscarTerminoN(nroter); //Busca el termino dado la posici�n
	if (dir != NULO) {
		return m.obtener_dato(dir, "->exp");
	} else {
		ShowMessage("No existe ese termino!");
        return NULO;
	}
}

void PolinomioS::AsignarCoeficiente(int coef, int exp) { //Modifica el coef dado un exp
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

void PolinomioS::poner_termino(int coef, int exp) { //Modifica si existe el exp sino crea un nuevo Nodo
	direccion existe = BuscarExponente(exp);
	if (existe == NULO) {
		direccion nuevoNodo = m.new_espacio("coef,exp,sig");
		if (nuevoNodo != NULO) {
			m.poner_dato(nuevoNodo, "->coef", coef);
			m.poner_dato(nuevoNodo, "->exp", exp);
			m.poner_dato(nuevoNodo, "->sig", ptr_Poli);
			ptr_Poli = nuevoNodo;
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

int PolinomioS::numero_terminos() { //Determina el numero de terminos que tiene el polinomio
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

void PolinomioS::graficarPolinomio(TCanvas *Canvas, int A, int B) {  // Intervalo [A,B]
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

double PolinomioS::evaluarPolinomio(double xf) {
	double yf = 0;
	int coef, exp;
	for (int i = 1; i <= numero_terminos(); i++) {
		exp = exponente(i);
		coef = coeficiente(exp);
		yf = yf + coef*pow(xf, exp);
	}
	return yf;
}
