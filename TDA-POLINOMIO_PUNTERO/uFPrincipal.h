//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uPolinomio_Puntero.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *PonerTermino;
	TButton *MostrarPolinomio;
	TButton *Derivar;
	TButton *Salir;
	TButton *CrearPolinomio;
	TEdit *Edit1;
	TEdit *Edit2;
	void __fastcall CrearPolinomioClick(TObject *Sender);
	void __fastcall PonerTerminoClick(TObject *Sender);
	void __fastcall MostrarPolinomioClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall DerivarClick(TObject *Sender);
private:	// User declarations
    PolinomioP *poli;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
