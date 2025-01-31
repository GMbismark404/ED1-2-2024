//---------------------------------------------------------------------------
#ifndef uConjunto_SMemoriaH
#define uConjunto_SMemoriaH
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
#include <cstdlib>  // Para rand() y srand()
#include "uCSMemoria.h"
//---------------------------------------------------------------------------
typedef int posicion;

class ConjuntoS { // Conjunto C de tipo ConjuntoS: SMemoria
	private:
		int cant;
		direccion ptrConj;
		CSMemoria m;
	private:
		int obtenerNumeroAleatorio(int min, int max);
	public:
		ConjuntoS(CSMemoria *mem);
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		posicion ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void MostrarConjunto(TCanvas *canvas, int desde, int hasta);
		void Union(ConjuntoS A, ConjuntoS B);
		void Interseccion(ConjuntoS A, ConjuntoS B);
        bool Equivalente(ConjuntoS A, ConjuntoS B);
};
#endif
