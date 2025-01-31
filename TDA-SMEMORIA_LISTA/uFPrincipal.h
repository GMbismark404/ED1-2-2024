//---------------------------------------------------------------------------

#ifndef uFPrincipalH
#define uFPrincipalH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "uCSMemoria.h"
#include "uListaCSMemoria.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *CrearSM;
	TButton *PedirEspacio;
	TButton *LiberarEspacio;
	TButton *CrearLista;
	TButton *InsertarInicio;
	TButton *InsertarFinal;
	TButton *MostrarMemoria;
	TButton *MostrarLista;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit11;
	TButton *PonerDato;
	TButton *Button1;
	TButton *Button2;
	void __fastcall CrearSMClick(TObject *Sender);
	void __fastcall PedirEspacioClick(TObject *Sender);
	void __fastcall LiberarEspacioClick(TObject *Sender);
	void __fastcall CrearListaClick(TObject *Sender);
	void __fastcall InsertarInicioClick(TObject *Sender);
	void __fastcall InsertarFinalClick(TObject *Sender);
	void __fastcall MostrarMemoriaClick(TObject *Sender);
	void __fastcall MostrarListaClick(TObject *Sender);
	void __fastcall PonerDatoClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
	CSMemoria *memo;
    ListaS *SMLista;
	int espacio_actual = 0;
	int x = 0;
    int y = 0;
	int desde = 0;
	int hasta = 11;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	void LimpiarCanvas(TCanvas *canvas);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
