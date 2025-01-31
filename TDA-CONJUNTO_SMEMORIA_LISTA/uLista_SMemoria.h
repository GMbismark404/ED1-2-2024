//---------------------------------------------------------------------------
#ifndef uLista_SMemoriaH
#define uLista_SMemoriaH
#include <Vcl.Graphics.hpp>
#include <Vcl.Dialogs.hpp>
#include "uCSMemoria.h"
//---------------------------------------------------------------------------
using namespace std;

class ListaS {
private:
	direccion PtrElementos;
	int longitud;
	CSMemoria m;
public:
	ListaS(CSMemoria *mem);
	direccion fin();
	direccion primero();
	direccion siguiente(direccion p);
	direccion anterior(direccion p);
	int recupera(direccion p);
	int LongitudLista();
	bool EsVacio();
	void inserta(direccion p, int elemento);
	void inserta_primero(int elemento);
	void inserta_ulitmo(int elemento);
	void suprime(direccion p);
	void modifica(direccion p, int elemento);
	void anula();
    direccion buscar(ListaS L, int elemento);
	void MostrarLista(TCanvas *canvas, int desde, int hasta);
};

#endif
