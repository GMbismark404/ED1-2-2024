//---------------------------------------------------------------------------
#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uCSMemoria.h"
#include "uConjunto_SMemoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearSMemoria;
	TButton *PedirEspacioSM;
	TButton *CrearConjA;
	TButton *CrearConjB;
	TButton *CrearConjC;
	TButton *InsertarElementoConj;
	TButton *MostrarConjunto;
	TButton *UnirEnC;
	TButton *IntersectarEnC;
	TButton *MostrarSMemoria;
	TButton *Salir;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	void __fastcall CrearSMemoriaClick(TObject *Sender);
	void __fastcall PedirEspacioSMClick(TObject *Sender);
	void __fastcall CrearConjAClick(TObject *Sender);
	void __fastcall CrearConjBClick(TObject *Sender);
	void __fastcall CrearConjCClick(TObject *Sender);
	void __fastcall InsertarElementoConjClick(TObject *Sender);
	void __fastcall MostrarConjuntoClick(TObject *Sender);
	void __fastcall UnirEnCClick(TObject *Sender);
	void __fastcall IntersectarEnCClick(TObject *Sender);
	void __fastcall MostrarSMemoriaClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	CSMemoria *mem;
	ConjuntoS *conjA;
	ConjuntoS *conjB;
	ConjuntoS *conjC;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
