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

void __fastcall TForm1::CrearPolinomioClick(TObject *Sender)
{
	pol = new PolinomioVL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	pol->poner_termino(StrToInt(Edit1->Text), StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
	pol->MostrarPolinomio(Form1->Canvas, 400, 200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DerivarClick(TObject *Sender)
{
	PolinomioVL *p1 = new PolinomioVL;
	pol->derivar(pol, p1);
	p1->MostrarPolinomio(Form1->Canvas, 400, 200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SalirClick(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

