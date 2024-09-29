//---------------------------------------------------------------------------
#ifndef uListaPunteroH
#define uListaPunteroH
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
struct Nodo {
	int elemento;
	Nodo *sig;
};

typedef Nodo *Direccion;

class ListaP {
private: //Atributos
	Direccion PtrElementos;
	int longitud;
public: //Metodos publicos:
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
    void MostrarLista(TCanvas *canvas, int x, int y);
};


#endif
