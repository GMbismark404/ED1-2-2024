//---------------------------------------------------------------------------
#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uListaMemoria.h"
#include "uCSMemoria.h"
#include "uPolinomio_Lista_Memoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearMemoria;
	TButton *PedirEspacio;
	TButton *LiberarEspacio;
	TButton *PonerDato;
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
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TButton *Evaluar;
	TButton *Button1;
	TButton *CrearLista;
	TButton *Button2;
	TButton *Button3;
	void __fastcall CrearMemoriaClick(TObject *Sender);
	void __fastcall PedirEspacioClick(TObject *Sender);
	void __fastcall LiberarEspacioClick(TObject *Sender);
	void __fastcall CrearPolinomioClick(TObject *Sender);
	void __fastcall PonerTerminoClick(TObject *Sender);
	void __fastcall MostrarPolinomioClick(TObject *Sender);
	void __fastcall DerivarClick(TObject *Sender);
	void __fastcall SalirClick(TObject *Sender);
	void __fastcall PonerDatoClick(TObject *Sender);
	void __fastcall EvaluarClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CrearListaClick(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
	PolinomioLS *poli;
	CSMemoria *mem;
    ListaS *lista;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
    void derivar(PolinomioLS *p, PolinomioLS *p1);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
