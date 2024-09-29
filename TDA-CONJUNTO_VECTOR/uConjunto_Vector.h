//---------------------------------------------------------------------------
#ifndef uConjunto_VectorH
#define uConjunto_VectorH
#include <Vcl.Dialogs.hpp>
 #include <Vcl.Graphics.hpp>
 #include <cstdlib>  // Para rand() y srand()
//---------------------------------------------------------------------------
const int MAX = 100;

class ConjuntoV {
	private:
		int vector[MAX];
		int cant;
	private:
		int obtenerNumeroAleatorio(int min, int max);
	public:
		ConjuntoV();
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		int ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void Union(ConjuntoV A, ConjuntoV B);
		void Interseccion(ConjuntoV A, ConjuntoV B);
		bool Equivalente(ConjuntoV A, ConjuntoV B);
		void MostrarConjunto(TCanvas *canvas, int x, int y);
};

#endif
