//---------------------------------------------------------------------------
#pragma hdrstop
#include "uCSMemoria.h"
#include <string>
#include <iostream>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)

CSMemoria::CSMemoria()
{
	for (int i = 0; i < MAX - 1; i++) {
		mem[i].link = i + 1;
//		mem[i].id= " ";
		mem[i].dato = 0;
	}
	mem[MAX - 1].link = NULO;
//	mem[MAX - 1].id= " ";
	mem[MAX - 1].dato = 0;
	this->libre = 0;
}

direccion CSMemoria::new_espacio(string cad) { // a�ade los ids y devuelve una direccion
	int cant = numero_ids(cad);         // cad = "ci,fono,edad" -> 3
	int dir = libre;
	int d = libre;
	for (int i = 0; i < cant - 1; i++) {
		mem[d].id = obtener_id(cad,i);
		d = mem[d].link;
	}

	libre = mem[d].link;
	mem[d].link = -1;
	mem[d].id = obtener_id(cad, cant - 1);
return dir;
}

void CSMemoria::delete_espacio(direccion dir) {
	direccion x = dir;
	while (mem[x].link != NULO) {
		x = mem[x].link;
	}
	mem[x].link = libre;
	libre = dir;
}

void CSMemoria::poner_dato(direccion dir, string cadena_id, int valor) {
	eliminar_flecha(cadena_id);
	for (direccion z = dir; z != NULO; z = mem[z].link) {
		if (mem[z].id == cadena_id)
			mem[z].dato = valor;
	}
}

int CSMemoria::obtener_dato(direccion dir, string cadena_id) {
    eliminar_flecha(cadena_id);
	for (direccion z = dir; z != NULO; z = mem[z].link) {
		if (mem[z].id == cadena_id)
			return mem[z].dato;
	}
	return NULO;
}

int CSMemoria::espacio_disponible() {
int contador = 0;
	for (direccion x = libre; (x < MAX) && (x != NULO) ; x = mem[x].link) {
		contador++;
	}
return contador;
}

int CSMemoria::espacio_ocupado() {
	return MAX - espacio_disponible();
}

bool CSMemoria::dir_libre(direccion dir)
{
	for (direccion x = libre; (x != NULO); x = mem[x].link) {
		if (x == dir)
            return true;
	}
	return false;
}
//-------------------------- Metodos privados -----------------------------

int CSMemoria::numero_ids(string id) { // "dia,mes,a�o"
	int c = 0;
	if (id == ""){
		return c;
	}else{
		for (int i = 0; i < id.length() - 1; i++)
			if ((id[i] != ',') && (id[i+1] == ','))
				c++;

		if (id[id.length() - 1] != ',')
			c++;
	}
return c;
}

string CSMemoria::obtener_id(string cad, int pos) {  // "ca,na,ma"
int p = 0; string s = ""; int c = 0;

	while (cad[c] == ',')
		c++;

	for (int i = c; i < cad.length(); i++) {
		if (cad[i] == ',') {
			i++; p++;
		}

		if (p == pos) {
			s = s + cad[i];
		}
	}
return s;
}

void CSMemoria::eliminar_flecha(string &cadena_id) {
	string cad;
	for (char c : cadena_id) {
		if (c != '-' && c != '>') {
			cad += c;
		}
	}
	cadena_id = cad;
}

//-------------------------- Mostrar CSMemoria ----------------------------
void CSMemoria::Mostrar(TCanvas *canvas, int desde, int hasta)
{
int x1, x2, y1, y2;
x1 = 450; x2 = 500; y1 = 50; y2 = 100;

canvas->Font->Name = L"Comic Sans MS";
canvas->Font->Size = 12;
canvas->Font->Color = clBlack;

	for (int i = 0; i < 4; i++) {
		canvas->Brush->Color = clWhite;
		switch (i) {
			case 0: {
				canvas->TextOutW(x1 - 50, y1 - 50 + 15, L"dir");
			} break;
			case 1: {
				canvas->TextOutW(x1 - 70, y1 - 50 + 15, L"datos");
			} break;
			case 2: {
				canvas->TextOutW(x1 - 60, y1 - 50 + 15, L"id");
			} break;
			case 3: {
				canvas->TextOutW(x1 - 60, y1 - 50 + 15, L"link");
			} break;
		}
		x1 += 100;
	}

	x1 = 450; x2 = 500;

	for (int fila = desde; fila <= hasta; ++fila) {  // desde = 0, hasta = 11
		for (int columna = 0; columna < 4; ++columna) {
			switch (columna) {
				case 0: {
					canvas->Brush->Color = clWhite;
					canvas->TextOutW(x1 - 50, y1 + 15, L"" + IntToStr(fila));
				} break;
				case 1: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clLime; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda
//					if (mem[fila].dato != 0) {
						canvas->TextOutW(x1 + 45, y1 + 15, L"" + IntToStr(mem[fila].dato));
//					} else {
//						canvas->TextOutW(x1 + 45, y1 + 15, L"");
//					}
					x1 += 100; x2 += 100;
				} break;
				case 2: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clYellow; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda

					canvas->TextOutW(x1 + 30, y1 + 15, AnsiString(mem[fila].id.c_str()));
					x1 += 100; x2 += 100;
				} break;
				case 3: {
					canvas->Pen->Color = clBlack; // Color del borde
					canvas->Brush->Color = clYellow; // Color de fondo
					canvas->Rectangle(x1, y1, x2 + 50, y2); // Dibujar la celda

					canvas->TextOutW(x1 + 50, y1 + 15, IntToStr(mem[fila].link));
					x1 += 100; x2 += 100;
				}
			}
		}
			x1 = 450; x2 = 500;
			y1 += 50; y2 += 50;
	}

	TRect rect(x1, y1, x2, y2); // Limpia todo el formulario
	canvas->Brush->Color = clWhite; // Color de fondo (blanco)
	canvas->FillRect(rect); // Rellena el �rea con el color de fondo
	canvas->TextOutW(x1 + 30, y1 + 15, L"Libre = " + IntToStr(libre));
}
