//---------------------------------------------------------------------------
#ifndef uPolinomioListaPH
#define uPolinomioListaPH
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include "uListaPuntero.h"
//---------------------------------------------------------------------------

class PolinomioLP {
private: //Atributos
	ListaP *pol;
private: //Metodos privados
	Direccion BuscarExponente(int exp);
	Direccion BuscarTerminoN(int i);
public: //Metodos publicos
	PolinomioLP();
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nroter);
	void suma(PolinomioLP *p1, PolinomioLP *p2);
	void resta(PolinomioLP *p1, PolinomioLP *p2);
	void multiplicacion(PolinomioLP *p1, PolinomioLP *p2);
	void mostrar_integral(PolinomioLP *p, TCanvas *canvas); //p es este polinomio
	void derivar(PolinomioLP *p, PolinomioLP *p1); //p1 es este polinomio
	void MostrarPolinomio(TCanvas *canvas, int x, int y);
};


#endif
