//---------------------------------------------------------------------------

#pragma hdrstop

#include "Menpoli.h"
#include "UnIMEM.h"
#include <vcl.h>
#include <iostream>
#include <math.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

	direccion polimem::BExp(int Exp){
		direccion dir = this->ptr;
	if (dir != NULO) {
		direccion dirEx = NULO;
		while (dir != NULO && dirEx == NULO) {
			if (Cm->obtenerDato(dir, "->exp") == Exp) {
				dirEx = dir;
			}
			dir = Cm->obtenerDato(dir, "->sig");
		}
		return dirEx;
	} else {
		//ShowMessage("No existe ese termino!");
		return NULO;
	}
	}

	direccion polimem::BTer(int I){
		direccion dir = this->ptr;
	if (dir != NULO) {
		direccion dirTer = NULO;
		int nt = 0;
		while (dir != NULO && dirTer == NULO) {
			nt++;
			if (nt == I) {
				dirTer = dir;
			}
			dir = Cm->obtenerDato(dir, "->sig");
		}
		return dirTer;
	} else {
		//ShowMessage("No existe terminos!");
		return NULO;
	}
	}

	/*polimem::polimem(){
		Nt=0;
		ptr=NULO;
		Cm= new CSmemoria();
	} */

	polimem::polimem(CSmemoria *m){
		Nt=0;
		ptr=NULO;
		Cm=m;
	}

	bool polimem::EsCero(){
		return (Nt==0);
	}

	int polimem::Grado(){
		direccion dir = this->ptr;
	if (dir != NULO) {
		int MaxG = Cm->obtenerDato(dir, "->exp");
		while (dir != NULO) {
			if (Cm->obtenerDato(dir, "->exp") > MaxG) {
				MaxG = Cm->obtenerDato(dir, "->exp");
			}
			dir = Cm->obtenerDato(dir, "->sig");
		}
		return MaxG;
	} else {
		//ShowMessage("No existe ese termino!");
		return NULO;
	}
	}

	int polimem::coef(int Exp){
	direccion dir = BExp(Exp);
	if (dir != NULO) {
		return Cm->obtenerDato(dir, "->coef");
	} else {
		ShowMessage("No existe ese termino!");
	}
	}

	void polimem::Ascoef(int coef,int exp){
	direccion dir = BTer(coef);
	if (dir != NULO) {
		Cm->poner_dato(dir, "->coef", coef);
		if (coef == 0) {
			Cm->Delete_espacio(dir);
		}
	} else {
		//ShowMessage("No existe ese termino!");
	}
	}

	int polimem::Poterm(int coef,int exp){
	direccion existe = BExp(exp);
	if (existe == NULO) {
		direccion nuevoNodo = Cm->new_espacio("coef,exp,sig");
		if (nuevoNodo != NULO) {
			Cm->poner_dato(nuevoNodo, "->coef", coef);
			Cm->poner_dato(nuevoNodo, "->exp", exp);
			Cm->poner_dato(nuevoNodo, "->sig", ptr);
			ptr = nuevoNodo;
			Nt=Nt+1;
			//ShowMessage(IntToStr(Nt));
		} else {
			//ShowMessage("Error espacio de memoria!");
		}
	} else {
		int nuevoCoef = Cm->obtenerDato(existe, "->coef") + coef;
		Cm->poner_dato(existe, "->coef", nuevoCoef);
		if (nuevoCoef == 0) {
			Cm->Delete_espacio(existe);
		}
	}
	}

	int polimem::Nterm(){
		return Nt;
	}

	int polimem::exp(int nroter){
		direccion dir = BTer(nroter);
	if (dir != NULO) {
		return Cm->obtenerDato(dir, "->exp");
	} else {
		ShowMessage("No existe ese termino!");
        return NULO;
	}
	}

	void polimem::derivar(polimem *p,polimem *p1){
	ShowMessage(IntToStr(p->Nterm()));
	int Temp=p->Nterm();
	for (int i = 1; i <= Temp; i++) {
		int ex = p->exp(i);
		int co = p->coef(ex);
		p1->Poterm(co*ex, ex-1);
	}
	}
	double polimem::Evaluar(double valx)
	{
		double val=0;
		int ex,co;
		for (int i = 1; i <= Nterm(); i++) {
			ex=exp(i);
			co=coef(ex);
			val=val+(co*pow(valx,ex));
		}
		return val;
	}
	void polimem::Grafico(TCanvas *Canvas, double A, double B)
	{
		if (A >= B)
		{
			ShowMessage("El valor A debe ser menor que el valor B");
			return;
		}
		int XF=1750;//width
		int YF=1000;//HEIGH

//		Canvas->Brush->Color = clWhite; // Color de fondo blanco
//		TRect drawArea(XF-1000, 0, XF, YF);
//		Canvas->FillRect(drawArea);

		//dibuja el eje
		Canvas->MoveTo(1250,500);  //y
		Canvas->LineTo(1250,1000);
		Canvas->LineTo(1250,0);
		Canvas->MoveTo(1250,500); //x
		Canvas->LineTo(1750,500);
		Canvas->LineTo(750,500);

		int Ntm=Nterm();
		//DIBUJO DEL POLINOMIO
		//Canvas->Pen->Color = clBlue;
		for (int x = (A*20); x < (B*20); x++) {
		Nt=Ntm;
		double xf = x / 20.0;  // Escala de zoom horizontal
		double yf = Evaluar(xf);  // Evaluar la funci�n polin�mica
		int XIN = 1250 + x;          // Convertir a coordenadas de pantalla
		int YIN = YF / 2 - (int)(yf * 20); // Ajustar escala vertical

		if (x == A*20){
				Canvas->MoveTo(XIN, YIN);
		}
		else{
			Canvas->LineTo(XIN, YIN);
			//Canvas->LineTo(XIN, 1000);
		}
	}

			Canvas->Font->Color = clBlack;  // Color de la fuente
		for (int x = -(XF-750) / 2; x <= YF / 2; x += 20) {
			int XIN = (XF+750) / 2 + x;
			int YIN = YF / 2;

		// Dibujar marcas de escala: screenY = 390
			Canvas->MoveTo(XIN, YIN - 5); // P0(0,385)
			Canvas->LineTo(XIN, YIN + 5); // P1(0,395)

		// Mostrar los n�meros de la escala
			if (x != 0) {  // No dibujar el n�mero 0 en el eje X
				String label = IntToStr(x / 20);  // "-25"
				Canvas->TextOut(XIN - 5, YIN + 10, label);
			}
		}

		// Dibujar escalas num�ricas en el eje Y
		for (int y = -YF / 2; y <= YF / 2; y += 20) {
			int XIN = (XF+750) / 2;
			int YIN = YF / 2 - y;

		// Dibujar marcas de escala
		Canvas->MoveTo(XIN - 5, YIN); // L�nea a la izquierda
		Canvas->LineTo(XIN + 5, YIN); // L�nea a la derecha

		// Mostrar los n�meros de la escala
		if (y != 0) {  // No dibujar el n�mero 0 en el eje Y
			String label = IntToStr(y / 20);  // Convertir la escala a su valor num�rico
			Canvas->TextOut(XIN + 10, YIN - 5, label);
		}
	}
	//Intervalo
		Canvas->Font->Color = clRed;
		Canvas->Pen->Color = clYellow;  // Puedes cambiar por otro color LAS LINEAS
		Canvas->Pen->Width = 3;
		Canvas->MoveTo(1250+(A*20), 0); //(X,Y)
		Canvas->LineTo(1250+(A*20), 650);
		Canvas->TextOut(1250+(A*20)-10,480, "A");
		Canvas->MoveTo(1250+(B*20), 0);
		Canvas->LineTo(1250+(B*20), 650);
		Canvas->TextOut(1250+(B*20)+5,480, "B");
		Canvas->Pen->Color = clBlack;  // Puedes cambiar por otro color
		Canvas->Pen->Width = 1;
	}


   /*	AnsiString polimem::Polimonio()
	{
		//double val=0;
		AnsiString polim;
		int ex,co;
		for (int i = 1; i <= Nterm(); i++) {
			ex=exp(i);
			co=coef(ex);
			if (i==1) {
				polim=IntToStr(co)+"X"+"^"+IntToStr(ex);
			}else{
				polim=polim+"+"+IntToStr(co)+"X"+"^"+IntToStr(ex);
            }
		}
		return polim;
	}*/

