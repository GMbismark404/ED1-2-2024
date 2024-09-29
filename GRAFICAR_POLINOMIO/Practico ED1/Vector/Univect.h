//---------------------------------------------------------------------------

#ifndef UnivectH
#define UnivectH
//---------------------------------------------------------------------------
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
using namespace std;

const int TamanoCelda1 = 35;
const int TamanoCeldaX1 = 80;
const int TamanoCeldaY1 = 35;
const int MAX1= 100;
const int NULO1 = 0;
typedef int direccion;
class Lisv{
	private:

	int vect[];
	int longi;
	direccion PtrElementos;

	public:
	Lisv();
		 int getLong() {
		return longi ;
	}

	direccion Listfind();
	direccion Listinid();
	direccion Sigdir(int p);
	direccion Antdir(int p);
	bool Lisvacio();
	int Lrecu(int p);
	int longit();
	void Lins(int p, int ele);
	void Linspr(int ele);
	void Linsfi(int ele);
	void Lsupr(int p);
	void Lmod(int p, int ele);
	void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas);
	void imprimir(TColor FormColor, TCanvas *Canvas);
};
#endif
