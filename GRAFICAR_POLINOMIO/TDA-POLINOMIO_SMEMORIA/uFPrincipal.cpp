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
void __fastcall TForm1::MostrarSMClick(TObject *Sender)
{
	mem->Mostrar(Form1->Canvas, StrToInt(Edit6->Text), StrToInt(Edit7->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CrearPolinomioClick(TObject *Sender)
{
    poli = new PolinomioS(mem);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PonerTerminoClick(TObject *Sender)
{
	poli->poner_termino(StrToInt(Edit8->Text),StrToInt(Edit9->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm1::MostrarPolinomioClick(TObject *Sender)
{
	poli->MostrarPolinomio(Form1->Canvas, StrToInt(Edit10->Text), StrToInt(Edit11->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DerivarClick(TObject *Sender)
{
	PolinomioS *p1 = new PolinomioS(mem);
    poli->derivar(poli, p1);
	p1->MostrarPolinomio(Form1->Canvas, StrToInt(Edit10->Text), StrToInt(Edit11->Text));
    delete p1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GraficarPolinomioClick(TObject *Sender)
{
	poli->graficarPolinomio(Form1->Canvas, StrToInt(Edit12->Text), StrToInt(Edit13->Text));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SalirClick(TObject *Sender)
{
	Form1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	PolinomioS *p1 = new PolinomioS(mem);
	p1->poner_termino(1,2);
	p1->poner_termino(-2,0);
	p1->graficarPolinomio(Form1->Canvas, -5, 5);
	PolinomioS *p2 = new PolinomioS(mem);
	p2->poner_termino(2,1);
	p2->poner_termino(1,0);
	p2->graficarPolinomio(Form1->Canvas, -5, 5);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	PolinomioS *p2 = new PolinomioS(mem);
	p2->poner_termino(1, 2);  // f(x) = x^2 - 2
	p2->poner_termino(-2, 0);
	p2->graficarPolinomio(Form1->Canvas, -5, 5);

	PolinomioS *p1 = new PolinomioS(mem);
	p1->poner_termino(2, 1);  // g(x) = 2x + 1
	p1->poner_termino(1, 0);
	p1->graficarPolinomio(Form1->Canvas, -5, 5);

	int ancho = 1000;
	int pOrigenX = 500;
	int alto = 1000;
	int pOrigenY = 0;

	// Validar los valores de Edit10 y Edit11
	int A = StrToInt(Edit10->Text);
	int B = StrToInt(Edit11->Text);
	if (A >= B) {
		ShowMessage("El l�mite A debe ser menor que el l�mite B");
		delete p1;
		delete p2;
		return;
	}

	// Buscar los puntos de intersecci�n
	Canvas->Pen->Color = clGreen; // Color para los puntos de intersecci�n
	for (int x = A * 20; x <= B * 20; x++) {
		double xf = x / 20.0;
		double yf1 = p1->evaluarPolinomio(xf);  // Evaluar p1 en xf
		double yf2 = p2->evaluarPolinomio(xf);  // Evaluar p2 en xf

		if (fabs(yf1 - yf2) < 0.01) {  // Si las funciones est�n muy cerca
			int screenX = pOrigenX + (ancho / 2) + x;
			int screenY = pOrigenY + (alto / 2) - (int)(yf1 * 20);
			Canvas->Ellipse(screenX - 5, screenY - 5, screenX + 5, screenY + 5); // Dibujar el punto

			// Establecer el tama�o de la fuente a 48
			Canvas->Font->Size = 48;
			// Mostrar las coordenadas del punto de intersecci�n
			String label = "(" + FloatToStr(xf) + ", " + FloatToStr(yf1) + ")";
			Canvas->TextOut(screenX + 10, screenY, label);
		}
	}

	// Liberar la memoria de los polinomios
	delete p1;
	delete p2;
}
//---------------------------------------------------------------------------

