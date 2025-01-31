//---------------------------------------------------------------------------
#ifndef uListaCSMemoriaH
#define uListaCSMemoriaH
#include "uCSMemoria.h"
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
using namespace std;

class ListaS {
private:
	direccion PtrElementos;
	int longitud;
	CSMemoria m;
private:
	int LongitudListas();
	bool EsVacio();
public:
	ListaS(CSMemoria *mem);
	direccion fin();
	direccion primero();
	direccion siguiente(direccion p);
	direccion anterior(direccion p);
	int recupera(direccion p);
	void inserta(direccion p, int elemento);
	void inserta_primero(int elemento);
	void inserta_ulitmo(int elemento);
	void suprime(direccion p);
	void modifica(direccion p, int elemento);
    direccion buscar(ListaS L, int elemento);
    void anula();
	void MostrarLista(TCanvas *canvas, int desde, int hasta);
};
#endif
