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
    poli = new PolinomioLP;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	int coef = StrToInt(Edit1->Text);
	int exp = StrToInt(Edit2->Text);
	poli->poner_termino(coef, exp);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
    poli->MostrarPolinomio(Form1->Canvas, 400, 200);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DerivarClick(TObject *Sender)
{
//	poli->derivada()
	PolinomioLP *p1 = new PolinomioLP;
	poli->derivar(poli, p1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SalirClick(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PolinomioLP *p = new PolinomioLP;
	PolinomioLP *p1 = new PolinomioLP;

	p->poner_termino(5,2);
	p->poner_termino(3,4);
	p->MostrarPolinomio(Form1->Canvas, 400, 200);
}
//---------------------------------------------------------------------------

