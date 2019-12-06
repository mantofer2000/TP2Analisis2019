#ifndef GRAFO_MA_H
#define GRAFO_MA_H

#include <sstream>
#include <iostream>

using namespace std; 

#define SIZEGRAFO 100
#define verticeNulo -1

typedef int vertice; 

typedef struct {
	bool conexion; 
	int peso; 
	
} celda_t; 


class Grafo{
	private: 	
		int* etiquetas; 
		celda_t** matrix; 
		int ultimoLleno; 

	
	
	public: 
		void iniciar(); 
		void destruir(); 
		void vaciar(); 
		bool vacia(); 
		//Debe ser tipo etiqueta, no entero
		//Peor de los casos, hacemos la etiqueta de LA un entero
		
		int agregarVertice(int etiqueta); 
		
		void agregarArista(vertice vertice_1, vertice vertice_2, int peso);	
		void eliminarArista(vertice vertice_1, vertice vertice_2); 							
		void eliminarVertice(vertice ver); 																
		
		bool existeArista(vertice vertice_1, vertice vertice_2); //optional
		
		int peso(vertice vertice_1, vertice vertice_2); 
		void modificarPeso(vertice vertice_1, vertice vertice_2, int peso); 
		void modificarEtiqueta(vertice ver, int etiqueta); 
		
		
		// Este tambien, hay que ver que hacerle

		int etiqueta(vertice ver); 
		
		int numVertices(); 
		
		int numAristas(); 
		
		int numVerticesAdy(vertice ver); 
		
		vertice primerVerticeAdy(vertice ver); 
		
		vertice siguienteVerticeAdy(vertice ver, vertice ver_ady); 
		vertice primerVertice(); 
		vertice siguienteVertice(vertice ver); 
		string printEtiquetas(); 
		string printMatrix(); 
		bool esVerticeNulo(vertice ver);
		vertice getVerticeNulo();
		vertice getVertice(int etiqueta); 
};

/*
public: 	
	void iniciar(); 
	void destruir(); 
	void vaciar(); 
	bool vacio(); 
	int agregarVertice(int etiqueta); 
	void agregarArista(int vertice_1, int vertice_2, int peso);	//ambos vertices deben ser validos.  //MODIFICAR. 
	void eliminarArista(int vertice_1, int vertice_2); 												//MODIFICAR.
	void eliminarVertice(int vertice); 																
	bool existeArista(int vertice_1, int vertice_2); //optional
	int peso(int vertice_1, int vertice_2); 
	void modificarPeso(int vertice_1, int vertice_2, int peso); 
	void modificarEtiqueta(int vertice, int etiqueta); 
	int etiqueta(int vertice); 
	int numVertices(); 
	int numAristas(); 
	int numVerticesAdy(int vertice); 
	int primerVerticeAdy(int vertice); 
	int siguienteVerticeAdy(int vertice, int actual_vertice_ady); 
	int primerVertice(); 
	int siguienteVertice(int vertice); 
	string printEtiquetas(); 
	string printMatrix(); 

*/

#endif
