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

void __fastcall TForm1::CrearSMemoriaClick(TObject *Sender)
{
    mem = new CSMemoria;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PedirEspacioSMClick(TObject *Sender)
{
    mem->new_espacio(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearConjAClick(TObject *Sender)
{
	conjA = new ConjuntoS(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearConjBClick(TObject *Sender)
{
	conjB = new ConjuntoS(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearConjCClick(TObject *Sender)
{
	conjC = new ConjuntoS(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertarElementoConjClick(TObject *Sender)
{
	if (Edit2->Text == "A")
		conjA->inserta(StrToInt(Edit3->Text));
	else if (Edit2->Text == "B")
		conjB->inserta(StrToInt(Edit3->Text));
	else if (Edit2->Text == "C")
		conjC->inserta(StrToInt(Edit3->Text));
	else
		ShowMessage("No existe el conjunto '" + Edit2->Text + "'");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarConjuntoClick(TObject *Sender)
{
	if (Edit4->Text == "A")
		conjA->MostrarConjunto(Form1->Canvas, 0, 11);
	else if (Edit4->Text == "B")
		conjB->MostrarConjunto(Form1->Canvas, 0, 11);
	else if (Edit4->Text == "C")
		conjC->MostrarConjunto(Form1->Canvas, 0, 11);
	else
		ShowMessage("No existe el conjunto '" + Edit2->Text + "'");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::UnirEnCClick(TObject *Sender)   // Unir y poner en C el resultado
{
	conjC->Union(*conjA, *conjB); //AUB
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IntersectarEnCClick(TObject *Sender) // Intersectar y poner en C el resultado
{
	conjC->Interseccion(*conjA, *conjB);
//	conjC->MostrarConjunto(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarSMemoriaClick(TObject *Sender)
{
	mem->Mostrar(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SalirClick(TObject *Sender)
{
    Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//  UNION (A,B)
	conjA->inserta(8);
	conjA->inserta(5);
	conjA->inserta(3);
	conjA->inserta(1);
	conjB->inserta(8);
	conjB->inserta(5);
	conjB->inserta(2);
	conjB->inserta(1);
	conjC->Union(*conjA, *conjB);
	conjC->MostrarConjunto(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

