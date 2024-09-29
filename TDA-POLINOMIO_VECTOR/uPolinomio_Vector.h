//---------------------------------------------------------------------------
#ifndef uPolinomio_VectorH
#define uPolinomio_VectorH
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
const int MAX = 20;

typedef int direccion;

class PolinomioV{
private:
	int vc[MAX];
	int ve[MAX];
	int nt;
private:
	direccion BuscarExponente(int exp);
	direccion BuscarTerminoN(int i);
public:
	PolinomioV();
	bool EsCero();
	int Grado();
	int coeficiente(int exp);
	void AsignarCoeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nroter);
	void suma(PolinomioV *p1, PolinomioV *p2);
	void resta(PolinomioV *p1, PolinomioV *p2);
	void multiplicacion(PolinomioV *p1, PolinomioV *p2);
};

#endif
