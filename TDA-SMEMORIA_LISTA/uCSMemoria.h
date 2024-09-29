//---------------------------------------------------------------------------
#ifndef uCSMemoriaH
#define uCSMemoriaH
#include <string>
#include <iostream>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
using namespace std;

const int MAX = 20;
const int NULO = -1;

typedef int direccion;

struct NodoM {
	int dato;
	string id;
	direccion link;
};

class CSMemoria {
	private: // Atributos
		NodoM mem[MAX];         //Crear memoria estática
		direccion libre;
	private: //Metodos privados
		void eliminar_flecha(string &cadena_id);
		string obtener_id(string cadena, int pos);
		int numero_ids(string cadena);
	public: //Metodos publicos
		CSMemoria();
		direccion new_espacio(string cadena);
		void delete_espacio(direccion dir);
		void poner_dato(direccion dir, string cadena_id, int valor);
		int obtener_dato(direccion dir, string cadena_id);
		int espacio_disponible();
		int espacio_ocupado();
		bool dir_libre(direccion dir);
		void Mostrar(TCanvas *canvas, int desde, int hasta);
};

#endif
