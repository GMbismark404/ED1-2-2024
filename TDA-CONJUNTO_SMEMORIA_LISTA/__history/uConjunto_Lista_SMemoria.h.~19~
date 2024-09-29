//---------------------------------------------------------------------------
#ifndef uConjunto_Lista_SMemoriaH
#define uConjunto_Lista_SMemoriaH
#include <cstdlib>  // Para rand() y srand()
#include <Vcl.Graphics.hpp>
#include "uLista_SMemoria.h"
#include "uCSMemoria.h"
//---------------------------------------------------------------------------

class ConjuntoLS {
	private: //Atributos
		ListaS elem;
	private: //Metodos privados
        int obtenerNumeroAleatorio(int min, int max);
	public: //Metodos publicos
		ConjuntoLS(CSMemoria *mem);
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		int ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void Union(ConjuntoLS A, ConjuntoLS B);
		void Interseccion(ConjuntoLS A, ConjuntoLS B);
		bool Equivalente(ConjuntoLS A, ConjuntoLS B);
		void MostrarConjunto(TCanvas *canvas, int desde, int hasta);
};
#endif
