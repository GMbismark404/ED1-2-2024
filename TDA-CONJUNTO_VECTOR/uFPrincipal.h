//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uConjunto_Vector.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearConjA;
	TButton *CrearConjB;
	TButton *CrearConjC;
	TButton *InsertarElemento;
	TButton *MostrarConjunto;
	TButton *UnirEnC;
	TButton *IntersectarEnC;
	TButton *Salir;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	void __fastcall CrearConjAClick(TObject *Sender);
	void __fastcall CrearConjBClick(TObject *Sender);
	void __fastcall CrearConjCClick(TObject *Sender);
	void __fastcall InsertarElementoClick(TObject *Sender);
	void __fastcall MostrarConjuntoClick(TObject *Sender);
	void __fastcall UnirEnCClick(TObject *Sender);
	void __fastcall IntersectarEnCClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	ConjuntoV *conjA;
	ConjuntoV *conjB;
	ConjuntoV *conjC;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
