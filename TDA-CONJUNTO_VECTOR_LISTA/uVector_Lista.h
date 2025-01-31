//---------------------------------------------------------------------------
#ifndef uVector_ListaH
#define uVector_ListaH
//---------------------------------------------------------------------------
using namespace std;

const int MAX = 20;
const int NULO = -1;

typedef int direccion;

class ListaV {
private:
	int elementos[MAX];
	int longitud;
public:
	ListaV();
	direccion fin();
	direccion primero();
	direccion siguiente(direccion p);
	direccion anterior(direccion p);
	bool EsVacio();
	int recupera(direccion p);
	int LongitudLista();
	void inserta(direccion p, int elemento);
	void inserta_primero(int elemento);
	void inserta_ultimo(int elemento);
	void suprime(direccion p);
	void modifica(direccion p,int elemento);
	void anula();
	direccion buscar(ListaV L, int elemento);
	void MostrarLista(TCanvas *canvas, int x, int y);
};

#endif
