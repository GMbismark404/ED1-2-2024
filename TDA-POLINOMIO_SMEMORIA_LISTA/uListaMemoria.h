//---------------------------------------------------------------------------
#ifndef uListaMemoriaH
#define uListaMemoriaH
#include <Vcl.Graphics.hpp>
#include "uCSMemoria.h"
//---------------------------------------------------------------------------

struct Nodo {
	int elemento;
	Nodo *sig;
};

class ListaS : public CSMemoria {
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
	bool EsVacio();
	int recupera(direccion p);
	int LongitudListas();
	void inserta(direccion p, int elemento);
	void inserta_primero(int elemento);
	void inserta_ulitmo(int elemento);
	void suprime(direccion p);
	void modifica(direccion p, int elemento);
	void anula();
	direccion buscar(ListaS L, int elemento);
	void MostrarLista(TCanvas *canvas, int desde, int hasta);
};

//-------------Procedimientos que no pertenecen a la ListaS------------------
#endif
