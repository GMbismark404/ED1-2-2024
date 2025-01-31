//---------------------------------------------------------------------------
#ifndef uPolinomio_SMemoriaH
#define uPolinomio_SMemoriaH
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include "uCSMemoria.h"
#include <cmath>
//---------------------------------------------------------------------------
using namespace std;

class PolinomioS {
private: //Atributos:
	direccion ptr_Poli;
	int nt;
	CSMemoria m;
private: //Metodos privados:
	int BuscarExponente(int exp);
	int BuscarTerminoN(int i);
public:	//Metodos publicos:
	PolinomioS(CSMemoria *mem);
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	int exponente(int nroter);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	void MostrarPolinomio(TCanvas *canvas, int desde, int hasta);
	void derivar(PolinomioS *p, PolinomioS *p1);
	void graficarPolinomio(TCanvas *Canvas, int A, int B);
	double evaluarPolinomio(double xf);
	void suma(PolinomioS *p1, PolinomioS *p2);
	void resta(PolinomioS *p1, PolinomioS *p2);
	void multiplicacion(PolinomioS *p1, PolinomioS *p2);
	void Mostrar_Intergral(PolinomioS *p, TCanvas *canvas);
};

#endif
