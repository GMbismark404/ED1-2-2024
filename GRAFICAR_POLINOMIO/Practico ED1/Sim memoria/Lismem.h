//---------------------------------------------------------------------------

#ifndef LismemH
#define LismemH
#include "Sim memoria\UnIMEM.h"
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
 using namespace std;
struct Nodo	{
	int elemento;
	int sig;
 };

	typedef int direccion;
	const string datoNL = "Elemento,Sig";
	const string elementNL = "->Elemento";
	const string sigNL = "->Sig";

class Lista{
	private:

	static const int NULO = -1;
	direccion PtrElementos;
	CSmemoria* Cmemoria;

	public:
	int longitud;
	Lista();
	Lista(CSmemoria* m);
	direccion fin();
	direccion primero();
	direccion siguiente(direccion d);
	direccion anterior(direccion d);
	direccion localiza(int tipoElemento);
	bool vacia();
	int recupera(direccion d);
	int getlongitud();
	int getPtr();
	int sumaIntercalada();
    void insertar(direccion d, int elemento);
	void elimLista();
	void inserta_primero(int elemento);
	void inserta_ultimo(int elemento);
	void suprime(direccion d);
	void modifica(direccion d, int elemento);
	void imprimir(TColor FormColor, TCanvas *Canvas);
};

#endif
