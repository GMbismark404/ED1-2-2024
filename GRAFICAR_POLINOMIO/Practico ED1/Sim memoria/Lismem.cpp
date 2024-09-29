//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lismem.h"
#include "UnIMEM.h"
#include <vcl.h>
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Lista::Lista(){
	 PtrElementos=NULO;
	 longitud=0;
	 Cmemoria = new CSmemoria();
}
Lista::Lista(CSmemoria* m){
	PtrElementos=NULO;
	longitud=0;
	Cmemoria = m;
}
direccion Lista::fin(){
 if (vacia()) {
	 MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
 }
 else
 {
	 int x = PtrElementos;
	 int ptrfin;
	 while (x!=NULO)
		 {
			 ptrfin = x;
			 x=Cmemoria->obtenerDato(x,sigNL);//x=x->sig;
		 }
	 return ptrfin;
 }
}
direccion Lista::primero(){
 if (!vacia()) {
	return PtrElementos;
 }else {
	return NULO;
 }
 }

direccion Lista::siguiente(direccion d){
if (vacia()==true) {
	MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
  return NULO;
}
else{
	if (d == fin()) {
	MessageDlg("NO HAY MAS DATOS SIGUIENTES", mtWarning, TMsgDlgButtons() << mbOK, 0);;return NULO;
	}else{
	return Cmemoria->obtenerDato(d,sigNL);
	}
}

}
direccion Lista::anterior(direccion d){
if (vacia()) {
	MessageDlg("NO HAY MAS DATOS ANTERIORES", mtWarning, TMsgDlgButtons() << mbOK, 0);;  return NULO;
}
else
{
	if (d == primero()) {
	  return NULO;
	  MessageDlg("Se declaro que la direccion es igual a la primera direccion de la lista en anterior", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	else
	{
		direccion x = PtrElementos;//Nodolista* x=ptrelemento;
		direccion ant=NULO;//Nodolista* ant=NULL;
		while (x!=NULO)
			{
			   if (x==d) {
				   return ant;
			   }
			   else
			   {
				ant = x;
				x = Cmemoria->obtenerDato(x,sigNL);//Obtener_dato();x->sig;
			   }
            }
	}
}
}

bool Lista::vacia(){

return longitud==0;
}

int Lista::recupera(direccion d){
if (!vacia()){
return Cmemoria->obtenerDato(d,elementNL);
}else
{
return NULO;}
}

int Lista::getlongitud(){
return longitud;
}

void Lista::inserta_primero(int elemento){
int x = Cmemoria->new_espacio(datoNL);
if (x!=NULO) {
 Cmemoria->poner_dato(x,elementNL,elemento);
 Cmemoria->poner_dato(x,sigNL,PtrElementos);
 PtrElementos=x;
 longitud++;
}else{
	MessageDlg("NO HAY MAS ESPACIO", mtWarning, TMsgDlgButtons() << mbOK, 0);;
}
}
void Lista::inserta_ultimo(int elemento){
  int x= Cmemoria->new_espacio(datoNL);
if (x!=NULO) {
	Cmemoria->poner_dato(x,elementNL,elemento);
	Cmemoria->poner_dato(x,sigNL,NULO);
	if (longitud!=0) {
	   Cmemoria->poner_dato(fin(),sigNL,x);	//fin()->sig=x;
	}
	else
	{
		PtrElementos=x;

	}
	longitud++;
}else
{
	MessageDlg("NO EXISTE ESPACIO", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
}

void Lista::suprime(direccion d){
if (longitud==0) {
	MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
else
{
	if (d==PtrElementos) {
		direccion x = PtrElementos;
		PtrElementos=Cmemoria->obtenerDato(PtrElementos,sigNL);
		Cmemoria->Delete_espacio(x);
	}
	else
	{
		direccion ant = anterior(d);
		Cmemoria->poner_dato(ant,sigNL,siguiente(d));
		Cmemoria->Delete_espacio(d);
	}
   longitud--;
}
}

void Lista::modifica(direccion d, int elemento){
if (!vacia()) {
	Cmemoria->poner_dato(d,elementNL,elemento);//d->elemento=ele;
}
else
{
	MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
}
direccion Lista::localiza(int tipoElemento) {
	direccion actual = PtrElementos;
	if (!vacia()) {

	while (actual != NULO) {

		if (Cmemoria->obtenerDato(actual, elementNL) == tipoElemento)
			return actual;
		actual = siguiente(actual);


	} if (actual==NULO) {
		return NULO;
	  }
	}else{
	return NULO;
	}
}
void Lista::elimLista(){
if (!vacia()) {
   while (PtrElementos!=NULO){
   suprime(fin());
}
} else{
  MessageDlg("NO HAY NADA", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
}
int Lista::sumaIntercalada() {
	int suma = 0;
	direccion actual = PtrElementos;
	bool sumar = true;

	while (actual != NULO) {
		int elemento = Cmemoria->obtenerDato(actual, elementNL);

		if (sumar) {
			suma += elemento;
		}
		sumar = !sumar;
		actual = siguiente(actual);
	}

	return suma;
}

void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;

	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}

void Lista::imprimir(TColor FormColor, TCanvas *Canvas){
			int	posX = 210;
			int	posY = 500;
			int auxX = posX;
			int auxY = posY;
			Canvas->Font->Size =16;
	if (vacia()==false) {

			Pintado(posX,posY-10,"LISTA",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;

			direccion x = PtrElementos;
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x != NULO){
			Pintado(posX,posY,IntToStr(Cmemoria->obtenerDato(x,elementNL)),FormColor,Canvas);
			posX+=40;
				x = Cmemoria->obtenerDato(x,sigNL);
				if (x != NULO) {
				Pintado(posX,posY,", ",FormColor,Canvas);
				posX+=40;
				}
		   //	x = Cmemoria->obtenerDato(x,sigNL);
			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
			Pintado(posX,posY,"LISTA ACTUALMENTE VACIA",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;
	}

}

int Lista::getPtr(){
return PtrElementos;
}
void Lista::insertar(direccion d, int elemento){
  int x= Cmemoria->new_espacio(datoNL);
if (x!=NULO ) {
	Cmemoria->poner_dato(x,elementNL,elemento);
	Cmemoria->poner_dato(x,sigNL,NULO);
	if (!vacia()) {
	   if (d==primero()) {
		Cmemoria->poner_dato(x,sigNL,d);
		PtrElementos=x;
	   }
	   else
	   {
		int ant=anterior(d);
		Cmemoria->poner_dato(ant,sigNL,x);
		Cmemoria->poner_dato(x,sigNL,d);
	   }

	   longitud++;
	}
	else
	{
		PtrElementos=x;
		longitud=1;
	}

}else
{
	MessageDlg("NO HAY ESPACIO O DIRECCION INVALIDA", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
}