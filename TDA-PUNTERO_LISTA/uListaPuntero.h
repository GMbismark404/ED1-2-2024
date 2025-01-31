//---------------------------------------------------------------------------
#ifndef uListaPunteroH
#define uListaPunteroH
#include <Vcl.Dialogs.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
using namespace std;

struct Nodo {
	int elementos;
	Nodo *sig;
};

typedef Nodo* Direccion;

class ListaP {
private:
	Direccion PtrElementos;
	int longitud;

public:
	ListaP();
	Direccion fin();
	Direccion primero();
	Direccion siguiente(Direccion p);
	Direccion anterior(Direccion p);
	bool EsVacio();
	int recupera(Direccion p);
	int LongitudLista();
	void inserta(Direccion p, int elemento);
	void inserta_primero(int elemento);
	void inserta_ultimo(int elemento);
	void suprime(Direccion p);
	void modifica(Direccion p, int elemento);
    void anula();
	Direccion buscar(ListaP L, int elemento);
	void MostrarLista(TCanvas *canvas);
};

#endif
