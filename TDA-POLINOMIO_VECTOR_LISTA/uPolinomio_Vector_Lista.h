//---------------------------------------------------------------------------
#ifndef uPolinomio_Vector_ListaH
#define uPolinomio_Vector_ListaH
#include "uVector_Lista.h"
//---------------------------------------------------------------------------

class PolinomioVL {
	private:
		ListaV pol;
        int nt;
	private:
		direccion BuscarExponente(int exp);
		direccion BuscarTerminoN(int i);
	public:
		PolinomioVL();
		bool EsCero();
		int Grado();
		int coeficiente(int exp);
		void AsignarCoeficiente(int coef, int exp);
		void poner_termino(int coef, int exp);
		int numero_terminos();
		int exponente(int nroter);
		void suma(PolinomioVL *p1, PolinomioVL *p2);
		void resta(PolinomioVL *p1, PolinomioVL *p2);
		void multiplicacion(PolinomioVL *p1, PolinomioVL *p2);
		void derivar(PolinomioVL *p, PolinomioVL *p1);
		void mostrar_integral(PolinomioVL *p, TCanvas *canvas);
		void MostrarPolinomio(TCanvas *canvas, int x, int y);
};

#endif
