//---------------------------------------------------------------------------
#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uPolinomio_SMemoria.h"
#include "uCSMemoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearMemoria;
	TButton *PedirEspacio;
	TButton *LiberarEspacio;
	TButton *CrearPolinomio;
	TButton *PonerTermino;
	TButton *MostrarPolinomio;
	TButton *Derivar;
	TButton *Salir;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	void __fastcall CrearMemoriaClick(TObject *Sender);
	void __fastcall PedirEspacioClick(TObject *Sender);
	void __fastcall LiberarEspacioClick(TObject *Sender);
	void __fastcall CrearPolinomioClick(TObject *Sender);
	void __fastcall PonerTerminoClick(TObject *Sender);
	void __fastcall MostrarPolinomioClick(TObject *Sender);
	void __fastcall DerivarClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
private:	// User declarations
	PolinomioS *poli;
	CSMemoria *mem;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
