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

void __fastcall TForm1::CrearConjAClick(TObject *Sender)
{
	conjA = new ConjuntoP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearConjBClick(TObject *Sender)
{
	conjB = new ConjuntoP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearConjCClick(TObject *Sender)
{
	conjC = new ConjuntoP;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::insertaElementoClick(TObject *Sender)
{
	if (Edit1->Text == "A")
		conjA->inserta(StrToInt(Edit2->Text));
	else if (Edit1->Text == "B")
		conjB->inserta(StrToInt(Edit2->Text));
	else if (Edit1->Text == "C")
		conjC->inserta(StrToInt(Edit2->Text));
	else
		ShowMessage("No existe el conjunto '" + Edit2->Text + "'");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarConjuntoClick(TObject *Sender)
{
	if (Edit3->Text == "A")
		conjA->MostrarConjunto(Form1->Canvas, 500, 500);
	else if (Edit3->Text == "B")
		conjB->MostrarConjunto(Form1->Canvas, 500, 500);
	else if (Edit3->Text == "C")
		conjC->MostrarConjunto(Form1->Canvas, 500, 500);
	else
		ShowMessage("No existe el conjunto '" + Edit3->Text + "'");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UnirEnCClick(TObject *Sender)
{
	conjC->Union(*conjA, *conjB);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IntersectarEnCClick(TObject *Sender)
{
	conjC->Interseccion(*conjA, *conjB);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SalirClick(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

