//---------------------------------------------------------------------------

#pragma hdrstop

#include "Vecpoli.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
	Poliv::Poliv(){
		nt=0;
	}
	bool Poliv::Escero(){
		return (nt==0);
	}
	int Poliv::grado(){
	if (nt>0) {
		int max=VE[1];
		for (int i = 1;i<= nt; i++) {
			if (VE[i]>max) {
				max=VE[i];
			}
		}
		return max;
	}
	//MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	int Poliv::Besxpo(int exp){
		for (int i = 1; i <= nt; i++) {
			if (VE[i]==exp) {
				return i;
			}
		}
		return -1;
	}
	void Poliv::Acoef(int coef,int exp){
		int lug=Besxpo(exp);
		if (lug != -1) {
			VC[lug]=coef;
			if (VC[lug]==0) {
			  nt--;
			}
		}
	}
	void Poliv::Pter(int coef, int exp){
	}
	int Poliv::Nterm(){
	}
	int Poliv::coef(int exp){
	if (exp >=0 && exp <=grado()) {
	   for (int i = 1; i <= nt; i++) {
		   if (VE[i]=exp) {
			   return VC[i];
		   }
	   }
	}
	}
	int Poliv::expo(int nroter){
	}
	void Poliv::sum(Poliv* P1, Poliv* P2){
	}
	void Poliv::res(Poliv* P1, Poliv* P2){
	}
	//void mul();