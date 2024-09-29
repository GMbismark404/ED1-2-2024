//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unipuntero.h"
#include <iostream>
#include <stdexcept>
#include <vcl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

ptrlista::ptrlista(){
	longitud=0;
	ptrelemento=NULL;
}
Nodolista* ptrlista::fin(){
if (vacia()) {
   MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}	else	{
		Nodolista* x= ptrelemento;
		Nodolista* ptrfin;
		while (x != NULL){
			ptrfin=x;
			x=x->sig;
		}
	return ptrfin;
	}
}
Nodolista* ptrlista::primero(){
	if (!vacia()) {
		return ptrelemento;
	}else{
	MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
}
Nodolista* ptrlista::siguiente(Nodolista* direccion){
	if (vacia()) {
		MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else{
	if (direccion == fin()) {
		MessageDlg("LISTA LLENA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	else{
		return direccion->sig;
		}
	}
return NULL;
}
Nodolista* ptrlista::anterior(Nodolista* direccion){
	if (vacia()) {
		MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else if (direccion == primero()) {
		 MessageDlg("LISTA LLENA", mtWarning, TMsgDlgButtons() << mbOK, 0);
		}else{
			Nodolista* x=ptrelemento;
			Nodolista* ant=NULL;
			while (x!=NULL)
			{
				 if (x==direccion) {
					return ant;
				 }else{
					ant = x;
					x = x->sig;
				   }
				}
			}

}
bool ptrlista::vacia(){
	return (longitud==0);
}
int ptrlista::recupera(Nodolista* d){
	if (!vacia()){
			return d->elemento;
		}else{
			MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
		}
}
int ptrlista::getlongitud(){
	return longitud;
	}

void ptrlista::inserta_primero(int ele){
	Nodolista* x=new Nodolista;
	if (x!=NULL) {
		x->elemento=ele;
		x->sig=ptrelemento;
		longitud++;
		ptrelemento=x;
	}
}
void ptrlista::inserta_ultimo(int ele){
	Nodolista* x=new Nodolista;
	if (x!=NULL) {
		x->elemento=ele;
		x->sig=NULL;
		if (longitud!=0) {
			fin()->sig=x;
		}else{
			ptrelemento=x;
			}
		longitud++;
	}
}
void ptrlista::suprime(Nodolista* d){
	if (longitud==0) {
		int x;
	}else if (d==ptrelemento) {
		Nodolista* x= ptrelemento;
		ptrelemento=ptrelemento->sig;
		delete x;
	}else{
		Nodolista* ant = anterior(d);
		ant->sig=siguiente(d);
		delete d;
	}
	longitud--;

}
void ptrlista::modifica(Nodolista* d,int ele){
	if (!vacia()) {
		d->elemento=ele;
	}else{
	MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}
	}
void ptrlista::elimLista(){
if (!vacia()) {
   while (ptrelemento!=NULL){
   suprime(fin());
}
}else{
  MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
}
}

void Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	int TamanoCelda = 35;
	int TamanoCeldaX = 80;
	int TamanoCeldaY = 35;
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX,posY+TamanoCeldaY);
	Canvas->Brush->Color = color;
	Canvas->FillRect(rect);

	Canvas->TextOutW(posX,posY+3,cad);

}

void ptrlista::imprimir(TColor FormColor, TCanvas *Canvas){
	int TamanoCelda = 35;
	int TamanoCeldaX = 80;
	int TamanoCeldaY = 35;
	int	posX = 210;
	int	posY = 500;
	int auxX = posX;
	int auxY = posY;
	Canvas->Font->Size =16;

	if (!vacia()) {

			Pintado(posX,posY,"LISTA",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY;

			Nodolista* x = ptrelemento;
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x != NULL){
			Pintado(posX,posY,IntToStr(x->elemento),FormColor,Canvas);
			posX+=80;
			x = x->sig;
				if (x != NULL) {
				Pintado(posX,posY,",",FormColor,Canvas);
				posX+=40;
				}

			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
			MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}

}

void ptrlista::anular(){
if (!vacia()) {

	  Nodolista* x = primero();
	  while (x!=fin())
		 {

		  suprime(x);

		 x=primero();

		 }
		 if (x==fin()) {
		  suprime(x);
		 }
}
}


  void  ptrlista::eliminarvalores(int valor){

	 if (!vacia()) {
			  Nodolista* x = primero();
			 Nodolista* y;
		while (x!=fin())
		 {
		  if (recupera(x)==valor) {
		  y=x;
		  x=x->sig;
			 suprime(y);
		  }else
			{
				x=x->sig;
            }

		 }
		 if (x==fin()) {
		   if (recupera(x)==valor) {
		  y=x;
		  x=x->sig;
			 suprime(y);
		  }
		 }
	 }

  }
