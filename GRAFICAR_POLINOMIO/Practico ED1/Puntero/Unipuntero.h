//---------------------------------------------------------------------------

#ifndef UnipunteroH
#define UnipunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <tchar.h>
#include <iomanip>
#include <Graphics.hpp>

struct Nodolista{
	int elemento;
	Nodolista* sig;
};

class ptrlista{
	private:
	int longitud;
	public:   	Nodolista* ptrelemento;
	ptrlista();
    Nodolista* fin();
	Nodolista* primero();
	Nodolista* siguiente(Nodolista* direccion);
	Nodolista* anterior(Nodolista* direccion);
	bool vacia();
	int recupera(Nodolista* d);
	int getlongitud();
	void elimLista();
	void inserta_primero(int ele);
	void inserta_ultimo(int ele);
	void suprime(Nodolista* d);
	void modifica(Nodolista* d,int ele);
	void imprimir(TColor FormColor, TCanvas *Canvas);
	void eliminarvalores(int valor);
    void anular();
};

#endif
