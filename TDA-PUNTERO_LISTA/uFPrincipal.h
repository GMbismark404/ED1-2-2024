//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uListaPuntero.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearLista;
	TButton *InsertarInicio;
	TButton *InsertarFinal;
	TButton *MostrarLista;
	TEdit *Edit1;
	TEdit *Edit2;
	void __fastcall CrearListaClick(TObject *Sender);
	void __fastcall InsertarInicioClick(TObject *Sender);
	void __fastcall InsertarFinalClick(TObject *Sender);
	void __fastcall MostrarListaClick(TObject *Sender);
private:	// User declarations
    ListaP *PTRLista;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
