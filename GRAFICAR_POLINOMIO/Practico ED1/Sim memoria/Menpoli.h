//---------------------------------------------------------------------------

#ifndef MenpoliH
#define MenpoliH
#include "Sim memoria\UnIMEM.h"
#include <iostream>
#include <tchar.h>
#include <string>
#include <iomanip>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
 using namespace std;
struct Nodo1	{
	int Coef;
	int Exp;
	typedef int sig;
};
	typedef int direccion;
class polimem{
	private:
	direccion ptr;
	int Nt;
	CSmemoria* Cm;

	private:
	direccion BExp(int Exp);
	direccion BTer(int I);

	public:
	//polimem();
	polimem(CSmemoria *m);
	bool EsCero();
	int Grado();
	int coef(int Exp);
	void Ascoef(int coef,int exp);
	int Poterm(int coef,int exp);
	int Nterm();
	int exp(int nroter);
	void derivar(polimem *p,polimem *p1);
	double Evaluar(double valx);
	void Grafico(TCanvas *Canvas, double A, double B);
	//string Polimonio();
};

#endif
