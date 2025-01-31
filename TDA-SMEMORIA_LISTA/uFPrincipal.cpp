//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <string>
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
void __fastcall TForm1::CrearSMClick(TObject *Sender)
{
	memo = new CSMemoria;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PedirEspacioClick(TObject *Sender)
{
	AnsiString text = Edit1->Text;
	espacio_actual = memo->new_espacio(std::string(text.c_str()));

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LiberarEspacioClick(TObject *Sender)
{
	memo->delete_espacio(StrToInt(Edit2->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CrearListaClick(TObject *Sender)
{
	SMLista = new ListaS(memo);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertarInicioClick(TObject *Sender)
{
	SMLista->inserta_primero(StrToInt(Edit3->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::InsertarFinalClick(TObject *Sender)
{
	SMLista->inserta_ulitmo(StrToInt(Edit4->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarMemoriaClick(TObject *Sender)
{
	LimpiarCanvas(Form1->Canvas); // Limpia el canvas antes de dibujar
	memo->Mostrar(Form1->Canvas, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarListaClick(TObject *Sender)
{
	LimpiarCanvas(Form1->Canvas); // Limpia el canvas antes de dibujar
	SMLista->MostrarLista(Form1->Canvas, StrToInt(Edit7->Text), StrToInt(Edit8->Text));
}
//---------------------------------------------------------------------------
void TForm1::LimpiarCanvas(TCanvas *canvas)
{
	// Define el �rea que deseas limpiar
    TRect rect(0, 0, ClientWidth, ClientHeight); // Limpia todo el formulario
    canvas->Brush->Color = clWhite; // Color de fondo (blanco)
	canvas->FillRect(rect); // Rellena el �rea con el color de fondo
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PonerDatoClick(TObject *Sender)
{
	int dir = StrToInt(Edit9->Text);
	AnsiString cad_id = Edit10->Text;
	int valor = StrToInt(Edit11->Text);
	memo->poner_dato(dir, cad_id.c_str(), valor);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//	CSMemoria mem = new CSMemoria;
//	int x = mem->new_espacio("hoy");
//	int y = mem->new_espacio("prac, exa");
//	mem->poner_dato(x, "->hoy", 100);
//	mem->delete_espacio(x);
	CSMemoria mem;
	int x = mem.new_espacio("hoy");
	int y = mem.new_espacio("prac, exa");
	mem.poner_dato(x, "->hoy", 100);
	mem.delete_espacio(x);
	ListaS lista(&mem);
	lista.inserta(lista.primero(), 500);
	lista.inserta(lista.primero(), 200);
	lista.inserta(lista.siguiente(lista.primero()), 300);
	lista.MostrarLista(Form1->Canvas, 0, 10);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	CSMemoria M;
	int Y = M.new_espacio("EXAMEN,OP1");
	int H = Y;
	M.poner_dato(0,"->OP1", 100);
	Y = M.obtener_dato(Y, "->EXAMEN") + M.obtener_dato(Y, "->OP1");
	Canvas->TextOut(800, 100, "LA SUMA ES " + IntToStr(Y));
	ListaS L(&M);
	L.inserta(L.primero(), Y);
	L.inserta(L.primero(), Y - 85);
    L.inserta(L.fin(), Y + 85);
	L.MostrarLista(Form1->Canvas, 0, 11);
}
//---------------------------------------------------------------------------

