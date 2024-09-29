//---------------------------------------------------------------------------
#ifndef uPolinomio_Lista_MemoriaH
#define uPolinomio_Lista_MemoriaH
#include <Vcl.Graphics.hpp>
#include <Vcl.Dialogs.hpp>
#include "uListaMemoria.h"
//---------------------------------------------------------------------------

class PolinomioLS {
private:
	ListaS pol;
    int nt;
private:
	direccion BuscarExponente(int exp);
	direccion BuscarTerminoN(int i);
public:
	PolinomioLS(CSMemoria *mem);
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	int exponente(int nroter);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	void MostrarPolinomio(TCanvas *canvas, int desde, int hasta);
	void derivar(PolinomioLS *p, PolinomioLS *p1);
	void graficarPolinomio(TCanvas *Canvas, int A, int B);
	double evaluarPolinomio(double xf);
	void suma(PolinomioLS *p1, PolinomioLS *p2);
	void resta(PolinomioLS *p1, PolinomioLS *p2);
	void multiplicacion(PolinomioLS *p1, PolinomioLS *p2);
	void Mostrar_Intergral(PolinomioLS *p, TCanvas *canvas);
};


#endif
