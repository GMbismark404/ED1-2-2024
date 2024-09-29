//---------------------------------------------------------------------------
#ifndef uConjunto_Puntero_ListaH
#define uConjunto_Puntero_ListaH
#include <cstdlib>  // Para rand() y srand()
#include <Vcl.Graphics.hpp>
#include "uPuntero_Lista.h"
//---------------------------------------------------------------------------
typedef int posicion;

class ConjuntoPL {
	private:
		ListaP *elem;
	private:
		int obtenerNumeroAleatorio(int min, int max);
	public:
		ConjuntoPL();
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		posicion ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void Union(ConjuntoPL A, ConjuntoPL B);
		void Interseccion(ConjuntoPL A, ConjuntoPL B);
		bool Equivalente(ConjuntoPL A, ConjuntoPL B);
		void MostrarConjunto(TCanvas *canvas, int x, int y);
};

#endif
