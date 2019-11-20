#include "grafo_MA.h"

void Grafo_MA::iniciar() {
	this->etiquetas = (int*)malloc(SIZEGRAFO*sizeof(int));
	this->matrix = (celda_t**)malloc(SIZEGRAFO*sizeof(celda_t*)); 
	for (int vertice = 0; vertice < SIZEGRAFO; ++vertice) {
		this->matrix[vertice] = (celda_t*)malloc(SIZEGRAFO*sizeof(celda_t)); 
	}
	this->ultimoLleno = 0; 
}


void Grafo_MA::destruir() {
	//liberar memoria. 
}


void Grafo_MA::vaciar() {
	this->ultimoLleno = 0; 
}

bool Grafo_MA::vacio() {
	bool empty = true;
	if (this->ultimoLleno > 0) {
		empty = false; 
	} 	
	return empty; 
}

int Grafo_MA :: agregarVertice(int elemento) {
	int vertice = this->ultimoLleno; 
	if (ultimoLleno <SIZEGRAFO) {
		this->etiquetas[this->ultimoLleno] = elemento; 
		++this->ultimoLleno; 
		
		for (int column_matrix = 0; column_matrix < this->ultimoLleno; ++column_matrix) {
			this->matrix[vertice][column_matrix].conexion = false; 
			//el peso da igual, queda con basura. 
		}
		
		for (int row_matrix = 0; row_matrix < this->ultimoLleno; ++row_matrix) {
			this->matrix[row_matrix][vertice].conexion = false; 
			//el peso da igual, queda con basura. 
		}
	
	}
	else {
		std::cout << "el grafo esta lleno, no se pueden agregar mas vertices " << std::endl; 
	}
	

	
	return vertice; 			//el vertice es un entero que corresponde al vector de etiquetas. 
}

void Grafo_MA :: agregarArista(int vertice_1, int vertice_2, int peso) {
	//los vertices son validos si son menores al ultimo lleno. 
	if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno && vertice_1 != vertice_2) {
		this->matrix[vertice_1][vertice_2].conexion = true;	//se crea la conexion en la matriz de adyacencia.  
		this->matrix[vertice_1][vertice_2].peso = peso; 
		this->matrix[vertice_2][vertice_1].conexion = true;			//hay desperdicio por simetria, pero es no dirigido.  
		this->matrix[vertice_2][vertice_1].peso = peso; 
	}
	else {
		std::cout << "la arista no se pudo agregar porque uno o ambos vertices ingresados son invalidos" << std::endl; 
	}
}

void Grafo_MA :: eliminarArista(int vertice_1, int vertice_2) {
	if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno) {
		this->matrix[vertice_1][vertice_2].conexion = false; 	
		this->matrix[vertice_2][vertice_1].conexion = false; 
	}
	else {
		std::cout << "la arista no se pudo eliminar puesto que no existe" << std::endl; 
	}
}


#if 0 
void shift_vertex_info(int current_vertex, int** matrix) {
	
	
	//desplazar un 5 significa mover todo a la posicion del 4.
	for (int row = 0; row < current_vertex-1; ++row) {
		matrix[row][current_vertex-1].conexion = matrix[row][current_vertex].conexion; 
		matrix[row][current_vertex-1].peso = matrix[row][current_vertex].peso; 
	}
	
	for (int column = 0; column < current_vertex-1; ++column) {
		matrix[current_vertex-1][column].conexion = matrix[current_vertex][column].conexion; 
	}
	
	matrix[current_vertex-1][current_vertex-1].conexion = matrix[current_vertex][current_vertex].conexion; 
	matrix[current_vertex-1][current_vertex-1].peso = matrix[current_vertex][current_vertex].peso; 
	
	
}

#endif 

void Grafo_MA::eliminarVertice(int vertice) { //requiere que el vertice este aislado. 
	
	for (int row = 0; row < vertice; ++row) {
		for (int column = vertice+1; column < this->ultimoLleno; ++column) {
			
			this->matrix[row][column-1].conexion = this->matrix[row][column].conexion; 
			this->matrix[row][column-1].peso = this->matrix[row][column].peso; 
				 
		} 			
	}
	
	for (int row = vertice+1; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < vertice; ++column) {	
			
			this->matrix[row-1][column].conexion = this->matrix[row][column].conexion; 
			this->matrix[row-1][column].peso = this->matrix[row][column].peso; 	
			
		} 		
	}
	
	for (int row = vertice+1; row < this->ultimoLleno; ++row) {
		for (int column = vertice+1; column < this->ultimoLleno; ++column) {
			
			this->matrix[row-1][column-1].conexion = this->matrix[row][column].conexion; 
			this->matrix[row-1][column-1].peso = this->matrix[row][column].peso; 	
				
		}
	}  
			
	/*
	for (int current_vertex = vertice+1; current_vertex < this->ultimoLleno; ++current_vertex) {		
		shift_vertex_info(current_vertex, this->matrix); 
	}
	*/
	

	for (int label = vertice+1; label < this->ultimoLleno; ++label) {
		this->etiquetas[label-1] = this->etiquetas[label]; 
	}
	
	--this->ultimoLleno; 
}
 
 bool Grafo_MA::existeArista(int vertice_1, int vertice_2) {
	 if (vertice_1 < this->ultimoLleno && vertice_2 < this->ultimoLleno) {
		return this->matrix[vertice_1][vertice_2].conexion; 
	 }
	 else {
		std::cout << "se retorna falso porque los vertices ingresados no son validos" << std::endl; 
		return false; 
	 }
 }

int Grafo_MA::peso(int vertice_1, int vertice_2) {
	return this->matrix[vertice_1][vertice_2].peso; 
} 

void Grafo_MA::modificarPeso(int vertice_1, int vertice_2, int peso) {
	this->matrix[vertice_1][vertice_2].peso = peso; 
}

void Grafo_MA::modificarEtiqueta(int vertice, int etiqueta) {
	this->etiquetas[vertice] = etiqueta; 
}

int Grafo_MA::etiqueta(int vertice) {
	return this->etiquetas[vertice];
}

int Grafo_MA::numVertices() {
	return this->ultimoLleno; 
}

int Grafo_MA::numAristas() {
	int counter = 0; 
	for (int row = 0; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < this->ultimoLleno; ++column) {
			if (this->matrix[row][column].conexion == true) {
				++counter; 
			}
		}	
	}
	return counter; 
}

int Grafo_MA::numVerticesAdy(int vertice) {
	int counter = 0; 
	for (int column = 0; column < this->ultimoLleno; ++column) {
		if (column != vertice) {
			if (this->matrix[vertice][column].conexion == true) {
				++counter; 
			}
		}
	}
	return counter; 
}

int Grafo_MA::primerVerticeAdy(int vertice) {
	int vertex = -1; 
	for (int column = 0; column < this->ultimoLleno; ++column) {
		if (vertice != column && this->matrix[vertice][column].conexion == true) {
			vertex = column; column = this->ultimoLleno;  
		} 
	}
	return vertex; 
}

int Grafo_MA::siguienteVerticeAdy(int vertice, int actual_vertice_ady) {
  int vertex = -1; 
  for (int column = actual_vertice_ady+1; column < this->ultimoLleno; ++column) {
		if (column != vertice && this->matrix[vertice][column].conexion == true) {
			vertex = column; 
			column = this->ultimoLleno; 
		} 
  }
	return vertex; 
}

int Grafo_MA::primerVertice() {
	int vertex = -1; 
	if (!vacio()) {
		vertex = 0; 
	} 
	return vertex; 
} 

int Grafo_MA::siguienteVertice(int vertice) {
	int vertex = -1; 
	if (vertice+1 < this->ultimoLleno) {
		vertex = vertice+1; 
	}
	return vertex; 
}


string Grafo_MA::printEtiquetas() {

	stringstream ss; 
	for (int vertex = 0; vertex < this->ultimoLleno; ++vertex) {
		ss << vertex << " ) " << this->etiquetas[vertex] << "\n"; 
	}
		
	return ss.str(); 
	
}


string Grafo_MA::printMatrix() {
	
	stringstream ss; 
	for (int row = 0; row < this->ultimoLleno; ++row) {
		for (int column = 0; column < this->ultimoLleno; ++column) {
			string current_conexion = ""; 
			
			if (this->matrix[row][column].conexion == true) {
				current_conexion = "TRUE"; 
			}
			else {
				current_conexion = "FALSE";
			}
			
			ss << "( " << current_conexion << ", " << this->matrix[row][column].peso << " )" << "  "; 	
		}
		ss << "\n"; 	
	}

	return ss.str(); 	
}
