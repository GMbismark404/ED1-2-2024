//---------------------------------------------------------------------------

#ifndef VecpoliH
#define VecpoliH
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
class Poliv{
	private:

	int VC[MAX1];
	int VE[MAX1];
	int nt;
	//direccion PtrElementos;

	public:
	Poliv();
	int Besxpo(int exp);
	bool Escero();
	int grado();
	void Acoef(int coef, int exp);
	void Pter(int coef, int exp);
	int Nterm();
	int coef(int exp);
	int expo(int nroter);
	void sum(Poliv* P1, Poliv* P2);
	void res(Poliv* P1, Poliv* P2);
	//void mul();
};
#endif
