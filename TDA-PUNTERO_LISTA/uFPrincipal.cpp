//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFPrincipal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearListaClick(TObject *Sender)
{
	PTRLista = new ListaP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertarInicioClick(TObject *Sender)
{
//	PTRLista->inserta(PTRLista->primero(), StrToInt(Edit1->Text));
  PTRLista->inserta_primero(StrToInt(Edit1->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertarFinalClick(TObject *Sender)
{
	PTRLista->inserta_ultimo(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarListaClick(TObject *Sender)
{
    PTRLista->MostrarLista(Form1->Canvas);
}
//---------------------------------------------------------------------------


