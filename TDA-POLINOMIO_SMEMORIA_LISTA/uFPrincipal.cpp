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
void __fastcall TForm1::PonerDatoClick(TObject *Sender)
{
	mem->poner_dato(StrToInt(Edit3->Text), Edit4->Text, StrToInt(Edit5->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CrearListaClick(TObject *Sender)
{
	lista = new ListaS(mem);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CrearPolinomioClick(TObject *Sender)
{
	poli = new PolinomioLS(mem);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	poli->poner_termino(StrToInt(Edit6->Text), StrToInt(Edit7->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
	poli->MostrarPolinomio(Form1->Canvas, StrToInt(Edit8->Text), StrToInt(Edit9->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DerivarClick(TObject *Sender)
{
	PolinomioLS *p1 = new PolinomioLS(mem);
	derivar(poli, p1);
	p1->MostrarPolinomio(Form1->Canvas, StrToInt(Edit8->Text), StrToInt(Edit9->Text));
	delete p1;
}
//---------------------------------------------------------------------------
void TForm1::derivar(PolinomioLS *p, PolinomioLS *p1)
{
	for (int i = 1; i <= p->numero_terminos(); i++) {
		int ex = p->exponente(i);
		int co = p->coeficiente(ex);
		p1->poner_termino(co*ex, ex-1);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SalirClick(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::EvaluarClick(TObject *Sender)
{
	PolinomioLS *p = new PolinomioLS(mem);
	p->poner_termino(1,1);
	p->poner_termino(2,2);
	p->poner_termino(3,3);
	p->MostrarPolinomio(Form1->Canvas, 0, 11);
	delete p;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	CSMemoria M;
	int Y = M.new_espacio("EXAMEN,OP1");
	int H = Y;
	M.poner_dato(0,"->OP1", 100);
	Y = M.obtener_dato(Y, "->EXAMEN") + M.obtener_dato(Y, "->OP1");
	Canvas->TextOut(800, 100, "LA SUMA ES " + IntToStr(Y));
	ListaS L(&M);
	L.inserta(L.primero(), Y);
	L.inserta(L.primero(), Y);
	L.inserta(L.primero(), Y - 85);
	L.inserta(L.fin(), Y + 85);
//	M.delete_espacio(H);
//	PolinomioLS P(&L);
//	P.poner_termino(2,5);
//	L.inserta(L.fin(), Y + 85);
//	P.MostrarPolinomio(Form1->Canvas, 0, 11);
	L.MostrarLista(Form1->Canvas, 0, 11);
//	M.Mostrar(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	CSMemoria memo;
	ListaS lista(&memo);
	PolinomioLS p(&memo);
	PolinomioLS p1(&memo);
	p.poner_termino(5,2);
//	p.poner_termino(3,4);
//    p.poner_termino(9,1);
//	p.poner_termino(7,0);
	p.derivar(&p, &p1);
	p1.MostrarPolinomio(Form1->Canvas, StrToInt(Edit8->Text), StrToInt(Edit9->Text));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	CSMemoria memo;
	ListaS lista(&memo);
	PolinomioLS p(&memo);
	PolinomioLS p1(&memo);
	p.poner_termino(5,2);
	p.poner_termino(3,4);
//	p.poner_termino(9,1);
//    p.poner_termino(7,0);
//	p.derivar(&p, &p1);
	p.MostrarPolinomio(Form1->Canvas, 0, 13);
//	p1.MostrarPolinomio(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

