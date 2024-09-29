//---------------------------------------------------------------------------
#ifndef uConjunto_PunteroH
#define uConjunto_PunteroH
#include <cstdlib>  // Para rand() y srand()
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
struct Nodo {
	int dato;
	Nodo *sig;
};

typedef Nodo *Direccion;
typedef int posicion;

class ConjuntoP {
	private:
		int cant;
		Direccion ptrConj;
	private:
		int obtenerNumeroAleatorio(int min, int max);
	public:
		ConjuntoP();
		bool EsVacio();
		bool pertenece(int elemento);
		void inserta(int elemento);
		int cardinal();
		posicion ordinal(int elemento);
		void suprime(int elemento);
		int muestrea();
		void Union(ConjuntoP A, ConjuntoP B);
		void Interseccion(ConjuntoP A, ConjuntoP B);
		bool Equivalente(ConjuntoP A, ConjuntoP B);
		void MostrarConjunto(TCanvas *canvas, int x, int y);
};

#endif
