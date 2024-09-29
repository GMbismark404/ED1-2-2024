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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	// Obtener los coeficientes del polinomio desde las cajas de texto
    double a = StrToFloat(EditA->Text);
    double b = StrToFloat(EditB->Text);
	double c = StrToFloat(EditC->Text);

    // Obtener el área de dibujo del formulario
	TCanvas *Canvas = PaintBox1->Canvas;
	Canvas->Pen->Color = clBlack;
	Canvas->Brush->Color = clWhite;
	Canvas->FillRect(PaintBox1->ClientRect);

	// Definir los límites y escala del gráfico
    int ancho = PaintBox1->Width;
    int alto = PaintBox1->Height;
    double minX = -10, maxX = 10;  // Rango del eje X
    double scaleX = ancho / (maxX - minX);
	double scaleY = alto / (maxX - minX);  // Mismo rango para X y Y

    // Dibujar el eje X y Y
    Canvas->MoveTo(0, alto / 2);
    Canvas->LineTo(ancho, alto / 2);
    Canvas->MoveTo(ancho / 2, 0);
    Canvas->LineTo(ancho / 2, alto);

    // Graficar la función
    for (double x = minX; x <= maxX; x += 0.1) {
        double y = a * x * x + b * x + c;
        int px = ancho / 2 + x * scaleX;
        int py = alto / 2 - y * scaleY;
        if (x == minX)
            Canvas->MoveTo(px, py);
        else
            Canvas->LineTo(px, py);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	// Obtener los coeficientes a y b desde las entradas: ax^2 + bx + c
	double a = 1;  //ax^2
	double b = 0;  //bx
	double c = 0;  //c

	// Dimensiones del área de dibujo
	int width = ClientWidth;
    int height = ClientHeight;

    // Limpiar el área de dibujo
    Canvas->Brush->Color = clWhite; // Color de fondo blanco
    TRect drawArea(0, 0, width, height);
    Canvas->FillRect(drawArea);     // Rellenar el área completa del formulario

    // Dibujar los ejes
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(0, height / 2);
	Canvas->LineTo(width, height / 2);  // Eje X
	Canvas->MoveTo(width / 2, 0);
	Canvas->LineTo(width / 2, height);  // Eje Y

	// Dibujar el polinomio
	Canvas->Pen->Color = clRed; // Color de la línea del polinomio

	for (int x = -width / 2; x < width / 2; x++)
	{
		double xf = x / 20.0;  // Escala de zoom horizontal
		double yf = a * xf * xf + b * xf + c;  // Evaluar la función polinómica
		int screenX = width / 2 + x;          // Convertir a coordenadas de pantalla
		int screenY = height / 2 - (int)(yf * 20); // Ajustar escala vertical

		if (x == -width / 2)
			Canvas->MoveTo(screenX, screenY);
		else
			Canvas->LineTo(screenX, screenY);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	double a = 1;
	double b = 0;
	double c = 0;

	int width = 2000;
	int height = 1000;
    // Limpiar el área de dibujo
    Canvas->Brush->Color = clWhite; // Color de fondo blanco
	TRect drawArea(0, 0, width, height);
	Canvas->FillRect(drawArea);     // Rellenar el área completa del formulario

	// Dibujar los ejes
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(0, height / 2);
	Canvas->LineTo(width, height / 2);  // Eje X
	Canvas->MoveTo(width / 2, 0);
	Canvas->LineTo(width / 2, height);  // Eje Y

	// Dibujar el polinomio
	Canvas->Pen->Color = clRed; // Color de la línea del polinomio

	for (int x = -width / 2; x < width / 2; x++)
	{
		double xf = x / 20.0;  // Escala de zoom horizontal
		double yf = a * xf * xf + b * xf + c;  // Evaluar la función polinómica
		int screenX = width / 2 + x;          // Convertir a coordenadas de pantalla
		int screenY = height / 2 - (int)(yf * 20); // Ajustar escala vertical

		if (x == -width / 2)
			Canvas->MoveTo(screenX, screenY);
		else
			Canvas->LineTo(screenX, screenY);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button4Click(TObject *Sender)
{
	double a = 0;
	double b = 1;
	double c = 0;

	int width = 1000;
	int height = 1000;
    // Limpiar el área de dibujo
    Canvas->Brush->Color = clWhite; // Color de fondo blanco
	TRect drawArea(0, 0, width, height);
	Canvas->FillRect(drawArea);     // Rellenar el área completa del formulario

	// Dibujar los ejes
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(0, height / 2);
	Canvas->LineTo(width, height / 2);  // Eje X
	Canvas->MoveTo(width / 2, 0);
	Canvas->LineTo(width / 2, height);  // Eje Y

	// Dibujar el polinomio
	Canvas->Pen->Color = clRed; // Color de la línea del polinomio

	for (int x = -width / 2; x < width / 2; x++)
	{
		double xf = x / 20.0;  // Escala de zoom horizontal
		double yf = a * xf * xf + b * xf + c;  // Evaluar la función polinómica
		int screenX = width / 2 + x;          // Convertir a coordenadas de pantalla
		int screenY = height / 2 - (int)(yf  *20); // Ajustar escala vertical

		if (x == -width / 2)
			Canvas->MoveTo(screenX, screenY);
		else
			Canvas->LineTo(screenX, screenY);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int ancho = 1000;			int pOrigenX = 500;
	int alto = 1000;			int pOrigenY = 0;

	for (int x = pOrigenX; x <= ancho + pOrigenX ; x += 20) {
		int screenX = x;
		int screenY = 0;

		// Dibujar marcas de escala
        Canvas->MoveTo(screenX, screenY - 5); // Línea hacia arriba
        Canvas->LineTo(screenX, screenY + 5); // Línea hacia abajo

        // Mostrar los números de la escala
        if (x != 0) {  // No dibujar el número 0 en el eje X
            String label = IntToStr(x / 20);  // Convertir la escala a su valor numérico
            Canvas->TextOut(screenX - 5, screenY + 10, label);
        }
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{

	double A = StrToFloat(Edit2->Text);
    double B = StrToFloat(Edit3->Text);

if (A >= B)
	  {
		ShowMessage("El valor A debe ser menor que el valor B");
		return;
		}
		int XF=1750;
		int YF=1000;//HEIGH
		Canvas->Brush->Color = clWhite; // Color de fondo blanco
		TRect drawArea(0, 0, XF, YF);
		Canvas->FillRect(drawArea);
		Canvas->MoveTo(1250,500);
		Canvas->LineTo(1250,1000);
		Canvas->LineTo(1250,0);
		Canvas->MoveTo(1250,500);
		Canvas->LineTo(1750,500);
		Canvas->LineTo(750,500);
//		int Ntm=Nterm();
		for (int x = (A*20); x < (B*20); x++) {
//		Nt=Ntm;
		double xf = x / 20.0;  // Escala de zoom horizontal
		double yf = 10;//Evaluar(xf);  // Evaluar la función polinómica
		int XIN = 1250 + x;          // Convertir a coordenadas de pantalla
		int YIN = YF / 2 - (int)(yf * 20); // Ajustar escala vertical

		if (x == A*20){
				Canvas->MoveTo(XIN, YIN);
		}
		else
			Canvas->LineTo(XIN, YIN);
	}

			Canvas->Font->Color = clBlack;  // Color de la fuente
		for (int x = -(XF-750) / 2; x <= YF / 2; x += 20) {
			int XIN = (XF+750) / 2 + x;
			int YIN = YF / 2;

		// Dibujar marcas de escala: screenY = 390
			Canvas->MoveTo(XIN, YIN - 5); // P0(0,385)
			Canvas->LineTo(XIN, YIN + 5); // P1(0,395)

		// Mostrar los números de la escala
			if (x != 0) {  // No dibujar el número 0 en el eje X
				String label = IntToStr(x / 20);  // "-50"
				Canvas->TextOut(XIN - 5, YIN + 10, label); //P(-5,510)
			}
		}

		// Dibujar escalas numéricas en el eje Y
		for (int y = -YF / 2; y <= YF / 2; y += 20) {
			int XIN = (XF+750) / 2;
			int YIN = YF / 2 - y;

		// Dibujar marcas de escala
		Canvas->MoveTo(XIN - 5, YIN); // Línea a la izquierda
		Canvas->LineTo(XIN + 5, YIN); // Línea a la derecha

		// Mostrar los números de la escala
		if (y != 0) {  // No dibujar el número 0 en el eje Y
			String label = IntToStr(y / 20);  // Convertir la escala a su valor numérico
			Canvas->TextOut(XIN + 10, YIN - 5, label);
		}
	}
	//Intervalo
		Canvas->Font->Color = clRed;
		Canvas->Pen->Color = clYellow;  // Puedes cambiar 'clRed' por otro color
		Canvas->Pen->Width = 3;
		Canvas->MoveTo(1250+(A*20), 0);
		Canvas->LineTo(1250+(A*20), 1000);
		Canvas->TextOut(1250+(A*20)-10,480, "A");
		Canvas->MoveTo(1250+(B*20), 0);
		Canvas->LineTo(1250+(B*20), 1000);
		Canvas->TextOut(1250+(B*20)+5,480, "B");
		Canvas->Pen->Color = clBlack;  // Puedes cambiar 'clRed' por otro color
		Canvas->Pen->Width = 1;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int ancho = 1000;       double a = 1;		int A = StrToInt(Edit4->Text);
	int alto = 1000;        double b = 0;		int B = StrToInt(Edit5->Text);
	int pOrigenX = 500;     double c = 0;
	int pOrigenY = 0;

	Canvas->Brush->Color = clWhite; // Color de fondo blanco
	TRect drawArea(pOrigenX, pOrigenY, ancho + pOrigenX, alto + pOrigenY);  //drawArea(x1,y1,x2,y2)
	Canvas->FillRect(drawArea);

	// Dibujar los ejes
	Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(pOrigenX, pOrigenY + (alto / 2));
	Canvas->LineTo(ancho + pOrigenX, pOrigenY + (alto / 2));  // Eje X
	Canvas->MoveTo(pOrigenX + (ancho / 2), pOrigenY);
	Canvas->LineTo(pOrigenX + (ancho / 2), pOrigenY + alto);  // Eje Y

	// Dibujar el polinomio
	Canvas->Pen->Color = clRed; // Color de la línea del polinomio

	for (int x = A*20; x <= B*20; x++)
	{
		double xf = x / 20.0;  //
		double yf = a * xf * xf + b * xf + c;  // Evaluar la función polinómica
		int screenX = pOrigenX + (ancho / 2) + x;          // Convertir a coordenadas de pantalla
		int screenY = pOrigenY + (alto / 2) - (int)(yf *20); // Ajustar escala vertical

		if (x == A*20)
			Canvas->MoveTo(screenX, screenY);
		else
			Canvas->LineTo(screenX, screenY);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
    // Obtener los coeficientes a, b desde las entradas
	double a = 0;       int pOrigenX = 500;
	double b = 1;       int pOrigenY = 0;
	double c = 1;

    // Dimensiones del área de dibujo
	int width = 1000;       int B = 10;
	int height = 1000;      int A = 10;

    // Limpiar el área de dibujo
    Canvas->Brush->Color = clWhite; // Color de fondo blanco
	TRect drawArea(pOrigenX, pOrigenY, width + pOrigenX, height + pOrigenY);
    Canvas->FillRect(drawArea);     // Rellenar el área completa del formulario

	// Dibujar los ejes
    Canvas->Pen->Color = clBlack;
	Canvas->MoveTo(pOrigenX, (height / 2) + pOrigenY);
	Canvas->LineTo(width + pOrigenX, (height / 2) + pOrigenY);  // Eje X
	Canvas->MoveTo((width / 2) + pOrigenX, pOrigenY);
	Canvas->LineTo((width / 2) + pOrigenX, height + pOrigenY);  // Eje Y

    // Dibujar escalas numéricas en el eje X
    Canvas->Font->Color = clBlack;  // Color de la fuente
	for (int x = -(width + pOrigenX) / 2; x <= (width + pOrigenX) / 2; x += 20) {
		int screenX = ((width + pOrigenX) / 2) + x;
		int screenY = ((height + pOrigenY) / 2);

		// Dibujar marcas de escala
        Canvas->MoveTo(screenX, screenY - 5); // Línea hacia arriba
        Canvas->LineTo(screenX, screenY + 5); // Línea hacia abajo

        // Mostrar los números de la escala
        if (x != 0) {  // No dibujar el número 0 en el eje X
            String label = IntToStr(x / 20);  // Convertir la escala a su valor numérico
            Canvas->TextOut(screenX - 5, screenY + 10, label);
        }
    }

	// Dibujar escalas numéricas en el eje Y
	for (int y = -(height + pOrigenY) / 2; y <= (height + pOrigenY) / 2; y += 20) {
		int screenX = ((width + pOrigenX) / 2);
		int screenY = ((height + pOrigenY) / 2) - y;

		// Dibujar marcas de escala
		Canvas->MoveTo(screenX - 5, screenY); // Línea a la izquierda
        Canvas->LineTo(screenX + 5, screenY); // Línea a la derecha

        // Mostrar los números de la escala
        if (y != 0) {  // No dibujar el número 0 en el eje Y
            String label = IntToStr(y / 20);  // Convertir la escala a su valor numérico
            Canvas->TextOut(screenX + 10, screenY - 5, label);
        }
    }

    // Dibujar el polinomio
    Canvas->Pen->Color = clRed; // Color de la línea del polinomio
	for (int x = -(width + pOrigenX)/ 2; x < (width + pOrigenX) / 2; x++) {
        double xf = x / 20.0;  // Escala de zoom horizontal
        double yf = a * xf * xf + b * xf + c;  // Evaluar la función polinómica
		int screenX = (width / 2) + pOrigenX + x;          // Convertir a coordenadas de pantalla
		int screenY = (height / 2) + pOrigenY - (int)(yf * 20); // Ajustar escala vertical

        if (x == -(width + pOrigenX) / 2)
			Canvas->MoveTo(screenX, screenY);
        else
			Canvas->LineTo(screenX, screenY);
	}

	Canvas->MoveTo(pOrigenX, pOrigenY + 495);
	Canvas->LineTo(pOrigenX + 20, pOrigenY + 495);
}
//---------------------------------------------------------------------------

