//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uCSMemoria.h"
#include "uLista_SMemoria.h"
#include "uConjunto_Lista_SMemoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearMemoria;
	TButton *PedirEspacioSM;
	TButton *CrearLista;
	TButton *CrearConjA;
	TButton *CrearConjB;
	TButton *CrearConjC;
	TButton *InsertaElemento;
	TButton *MostrarConjunto;
	TButton *UnirEnC;
	TButton *IntersectarEnC;
	TButton *MostrarMemoriaConj;
	TButton *Salir;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button1;
	void __fastcall CrearMemoriaClick(TObject *Sender);
	void __fastcall PedirEspacioSMClick(TObject *Sender);
	void __fastcall CrearConjAClick(TObject *Sender);
	void __fastcall CrearConjBClick(TObject *Sender);
	void __fastcall CrearConjCClick(TObject *Sender);
	void __fastcall InsertaElementoClick(TObject *Sender);
	void __fastcall MostrarConjuntoClick(TObject *Sender);
	void __fastcall UnirEnCClick(TObject *Sender);
	void __fastcall IntersectarEnCClick(TObject *Sender);
	void __fastcall MostrarMemoriaConjClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall CrearListaClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
	CSMemoria *mem;
	ListaS *lista;
	ConjuntoLS *conjA;
	ConjuntoLS *conjB;
	ConjuntoLS *conjC;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
