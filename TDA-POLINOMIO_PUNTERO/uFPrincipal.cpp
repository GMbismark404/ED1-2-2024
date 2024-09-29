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
	poli = new PolinomioP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	poli->poner_termino(StrToInt(Edit1->Text), StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
    poli->MostrarPolinomio(Form1->Canvas, 400, 200);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DerivarClick(TObject *Sender)
{
	PolinomioP *p1 = new PolinomioP;
    poli->derivar(poli, p1);
	p1->MostrarPolinomio(Form1->Canvas, 400, 200);
	delete p1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SalirClick(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

