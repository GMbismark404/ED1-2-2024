//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uVector_Lista.h"
#include "uPolinomio_Vector_Lista.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearPolinomio;
	TButton *PonerTermino;
	TButton *MostrarPolinomio;
	TButton *Derivar;
	TButton *Salir;
	TEdit *Edit1;
	TEdit *Edit2;
	void __fastcall CrearPolinomioClick(TObject *Sender);
	void __fastcall PonerTerminoClick(TObject *Sender);
	void __fastcall MostrarPolinomioClick(TObject *Sender);
	void __fastcall DerivarClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
private:	// User declarations
    PolinomioVL *pol;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
