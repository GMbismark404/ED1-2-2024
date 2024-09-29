//---------------------------------------------------------------------------
#ifndef uPolinomio_SMemoriaH
#define uPolinomio_SMemoriaH
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include "uCSMemoria.h"
//---------------------------------------------------------------------------

class PolinomioS {
private:
	direccion ptr_Poli;
	int nt;
    CSMemoria m;
private:
	int BuscarExponente(int exp);
	int BuscarTerminoN(int i);
public:
	PolinomioS(CSMemoria *mem);
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	int exponente(int nroter);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	void MostrarPolinomio(TCanvas *canvas, int desde, int hasta);
	void suma(PolinomioS *p1, PolinomioS *p2);
	void resta(PolinomioS *p1, PolinomioS *p2);
	void multiplicacion(PolinomioS *p1, PolinomioS *p2);
	void Mostrar_Intergral(PolinomioS *p, TCanvas *canvas);
	void derivar(PolinomioS *p, PolinomioS *p1); //p es este polinomio
};

#endif
