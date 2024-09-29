//---------------------------------------------------------------------------

#pragma hdrstop

#include "Univect.h"
#include <vcl.h>
#include <algorithm>
#include <iostream>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Lisv::Lisv(){
longi= 0;
}

direccion Lisv::Listfind(){
   if (!longi==0) {
	  return longi;
   }else {
   MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
   }
}
direccion Lisv::Listinid(){
  if (!longi==0) {
	return 1;
  }else{
   MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
  }
}
direccion Lisv::Sigdir(int p){
	if (longi==0) {
		MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else if(p>longi){
		return 0;
		//MessageDlg("NO HAY UNA DIRECCION SIGUIENTE", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "No hay una direccion siguiente" << std::endl;
	}else return p++;
}
direccion Lisv::Antdir(int p){
	if (longi==0) {
		MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else if(p==1){
		MessageDlg("NO HAY UNA DIRECCION ANTERIOR", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "No hay una direccion anterior" << std::endl;
	}else return p--;
}
bool Lisv::Lisvacio(){
	return (longi==0);
}
int Lisv::Lrecu(int p){
	if (Lisvacio()) {
		MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else if(!(p>=1 && p<= longi)){
		MessageDlg("DIRECCION ERRONEA", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "Direccion erronea" << std::endl;
	}else return vect[p] ;
}
int Lisv::longit(){
	return longi;
}

void Lisv::Lins(int p, int ele){
	if (longi==MAX1) {
		MessageDlg("LISTA LLENA", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "LISTA LLENA" << std::endl;
	}else if(!(p>=1 && p<=longi)){
		MessageDlg("DIRECCION ERRONEA", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "Direccion erronea" << std::endl;
	}
	for (int i = longi+1; i >= p+1; i--) {
	  vect[i]=vect[i-1];
	}
	vect[p]=ele;
	longi++;
}
void Lisv::Linspr(int ele){
	if (longi==MAX1) {
		MessageDlg("LISTA LLENA.", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "LISTA LLENA" << std::endl;
	}
	for (int i = longi+1; i > 1; i--) {
		vect[i]=vect[i-1];
	}
	vect[1]=ele;
	longi++;
}
void Lisv::Linsfi(int ele){
	if (longi==MAX1) {
	   MessageDlg("LISTA LLENA.", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "LISTA LLENA" << std::endl;
	}else {
	   longi++;
	   vect[longi]=ele;
	}
}
void Lisv::Lsupr(int p){
	if (longi==0) {
	  MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	} else if (!(p>=1 && p<=longi-1)) {
	   MessageDlg("DIRECCION ERRONEA.", mtWarning, TMsgDlgButtons() << mbOK, 0);//std::cout << "Direccion erronea" << std::endl;
	  }
	for (int i = p; i <= longi-1; i++) {
	   vect[i]=vect[i+1];
	}
	longi--;
}
void Lisv::Lmod(int p, int ele){
	if (longi==0) {
	   MessageDlg("LISTA ACTUALMENTE VACIA.", mtWarning, TMsgDlgButtons() << mbOK, 0);
	}else if (!(p>=1 && p<=longi)) {
			std::cout << "" << std::endl;
		  }
	vect[p]=ele;
}
void Lisv::Pintado(int posX, int posY, String cad, TColor color, TCanvas *Canvas){
	//           x1  y1    x2                   y2
	TRect rect(posX,posY,posX+TamanoCeldaX1,posY+TamanoCeldaY1);
	Canvas->Brush->Color = color;

	Canvas->FillRect(rect);

	Canvas->TextOutW(posX-5,posY+1,cad);

}

void Lisv::imprimir(TColor FormColor, TCanvas *Canvas){
			int	posX = 110;
			int	posY = 500;
			int auxX = posX;
			int auxY = posY;
			Canvas->Font->Size =16;
	if (Lisvacio()==false) {

			Pintado(posX,posY-10,"Lista",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY1;

			direccion x = Listinid();
			Pintado(posX,posY,"< ",FormColor,Canvas);
			posX+=40;
			while (x<=longi && !(x<=0)){
			Pintado(posX,posY,IntToStr(Lrecu(x)),FormColor,Canvas);
			posX+=40;
				if (x<longi) {
				Pintado(posX,posY,", ",FormColor,Canvas);
				posX+=40;
				}
				x++;
				//x=Sigdir(x);
			}
			Pintado(posX,posY,">",FormColor,Canvas);
			posX+=40;
	}else{
			Pintado(posX,posY,"LISTA ACTUALMENTE VACIA",FormColor,Canvas);
			posX= auxX;
			posY+= TamanoCeldaY1;
	}

}

