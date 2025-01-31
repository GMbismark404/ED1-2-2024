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
void __fastcall TForm1::CrearMemoriaClick(TObject *Sender)
{
	mem = new CSMemoria;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PedirEspacioClick(TObject *Sender)
{
    mem->new_espacio(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LiberarEspacioClick(TObject *Sender)
{
	mem->delete_espacio(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CrearPolinomioClick(TObject *Sender)
{
    poli = new PolinomioS(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	poli->poner_termino(StrToInt(Edit3->Text),StrToInt(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
    poli->MostrarPolinomio(Form1->Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DerivarClick(TObject *Sender)
{
	PolinomioS *p1 = new PolinomioS(mem);
	poli->derivar(poli, p1);
    p1->MostrarPolinomio(Form1->Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SalirClick(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

