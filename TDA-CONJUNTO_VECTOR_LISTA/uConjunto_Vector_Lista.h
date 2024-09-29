//---------------------------------------------------------------------------
#ifndef uConjunto_Vector_ListaH
#define uConjunto_Vector_ListaH
#include "uVector_Lista.h"
#include "uVector_Lista.h"
//---------------------------------------------------------------------------

class ConjuntoVL {
	private:
		ListaV elem;
	private:
		int obtenerNumeroAleatorio(int min, int max);
	public:
		ConjuntoVL();
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		int ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void Union(ConjuntoVL A, ConjuntoVL B);
		void Interseccion(ConjuntoVL A, ConjuntoVL B);
		bool Equivalente(ConjuntoVL A, ConjuntoVL B);
		void MostrarConjunto(TCanvas *canvas, int x, int y);
};

#endif
