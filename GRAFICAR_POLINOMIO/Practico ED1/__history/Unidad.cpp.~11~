//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unidad.h"
#include <iostream>
#include <stdexcept>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
M= new CSmemoria();
//ME= new CSmemoria();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
String d =Edit1->Text;
M->new_espacio(AnsiString(d).c_str());
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
	String d=Edit2->Text;
M-> Delete_espacio(StrToInt(d));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
   String d=Edit3->Text;
   String p= Edit4->Text;
   Canvas->Brush->Color = clBtnFace;
   Canvas->FillRect(Canvas->ClipRect);
	M->Imprimirrango(Form2->Color,Canvas,800,20,StrToInt(d),StrToInt(p));

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
	String d=Edit5->Text;
	String p= Edit6->Text;
	String v=  Edit7->Text;


 M->poner_dato(StrToInt(AnsiString(d).c_str()),AnsiString(p).c_str(),StrToInt(AnsiString(v).c_str()));

}
//---------------------------------------------------------------------------



void __fastcall TForm2::Button6Click(TObject *Sender)
{
  lista = new Lista(M);
 //lista = new ptrlista  ();
   //lista = new Lisv();
 }
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
lista-> inserta_primero(StrToInt(Edit8->Text));
//lista->Linspr(StrToInt(Edit8->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button8Click(TObject *Sender)
{
lista->  inserta_ultimo(StrToInt(Edit9->Text));
//lista->Linsfi(StrToInt(Edit9->Text));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button9Click(TObject *Sender)
{
	Canvas->Brush->Color = clBtnFace;
	Canvas->FillRect(Canvas->ClipRect);
	lista-> imprimir(Form2->Color,Canvas);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button10Click(TObject *Sender)
{
  M=new CSmemoria();
  int x=M->new_espacio("hoy");
  //Edit9->Text=IntToStr(x);
  int y=M->new_espacio("prac,exa");
  M->poner_dato(x,"->hoy",100);
  M->Delete_espacio(x);
  lista = new Lista(M);
  lista->insertar(lista->primero(),500);
  lista->insertar(lista->primero(),200);
  lista->insertar(lista->siguiente(lista->primero()),300);
  Canvas->Brush->Color = clBtnFace;
  Canvas->FillRect(Canvas->ClipRect);
  M->Imprimirrango(Form2->Color,Canvas,800,20,0,20);

}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button11Click(TObject *Sender)
{
    pol= new polimem(M);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button12Click(TObject *Sender)
{
	pol->Poterm(StrToInt(Edit10->Text),StrToInt(Edit11->Text));
	}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button13Click(TObject *Sender)
{
	CSmemoria *ME = new CSmemoria();
	polimem *p1 = new polimem(ME);
	pol->derivar(pol, p1);
	//p1->MostrarPolinomio(Form1->Canvas, StrToInt(Edit10->Text), StrToInt(Edit11->Text));
	String d=Edit3->Text;
	String p= Edit4->Text;
	ME->Imprimirrango(Form2->Color,Canvas,800,20,StrToInt(d),StrToInt(p));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button14Click(TObject *Sender)
{
	//polimem *p1 = new polimem(ME);
	TRect rect = ClientRect;
	Canvas->Brush->Color = Color;
	String d= Edit13->Text;
	String p= Edit14->Text;
	pol->Grafico(Canvas,StrToInt(d),StrToInt(p));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button15Click(TObject *Sender)
{
    Edit12->Text=FloatToStr(pol->Evaluar(2));
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button16Click(TObject *Sender)
{
	//string p=pol->Polimonio();
	//Edit15->Text="A";
}
//---------------------------------------------------------------------------

