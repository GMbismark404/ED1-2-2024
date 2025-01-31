//---------------------------------------------------------------------------
#ifndef uPolinomio_PunteroH
#define uPolinomio_PunteroH
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------

struct Nodo {
	int coef;
	int exp;
	Nodo *sig;
};

typedef Nodo *Direccion;

class PolinomioP {
private: //Atributos
	Direccion ptr_Poli;
	int nt;
private: //Metodos privados
	Direccion BuscarExponente(int exp);
	Direccion BuscarTerminoN(int i);
public: //Metodos publicos
	PolinomioP();
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nroter);
	void suma(PolinomioP *p1, PolinomioP *p2);
	void resta(PolinomioP *p1, PolinomioP *p2);
	void derivar(PolinomioP *p, PolinomioP *p1);
	void multiplicacion(PolinomioP *p1, PolinomioP *p2);
	void MostrarPolinomio(TCanvas *canvas, int x, int y);
};
#endif
