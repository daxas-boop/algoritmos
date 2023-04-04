#include <iostream>
#define TOPE 300

//Precondicion: @texto, @subtexto_buscado y @subtexto_remplazo son cadena de caracteres
//@texto tiene una dimension suficiente para los reemplazos a realizar
//Postcondicion: Reemplaza en @texto las apariciones de @subtexto_buscado por @subtexto_remplazo
void RemplazarTexto(char texto[], char subtexto_buscado[], char subtexto_remplazo[]);

// Precondicion: @texto_origen es una cadena de caracteres y @texto_destino tiene una dimension suficiente
// Postcondicion: Copia en @texto_destino los caracteres de @texto_origen 
void CopiarTexto(char texto_origen[], char texto_destino[]);

 // Precondicion: @texto y @subtexto_buscado son cadenas de caracteres, // @indice_inicio se encuentra dentro del rango de @texto
// Postcondicion: Devuelve true si el @subtexto_buscado se encuentra dentro del texto despues de @indice_inicio
bool ContieneSubtexto(char texto[], char subtexto_buscado[], int indice_inicio);

// Precondicion: @texto y @texto_a_adjuntar son cadenas de caracteres
// Postcondicion: Al final de @texto agrega la cadena @texto_a_adjuntar
void AdjuntarTexto(char texto[], char texto_a_adjuntar[]);

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Devuelve la cantidad de caracteres en @texto
int CalcularTamanioTexto(char texto[]);

// Precondicion: @texto es una cadena de caracteres
// Postcondicion: Agrega al final de @texto el caracter @caracter
void AdjuntarCaracter(char texto[], char caracter);

int main() {
	char texto[TOPE] = "BOCA AS BOCA AS BOCA AS BOCA AS";
	char subtexto_buscado[] = "BOCA";
	char subtexto_remplazo[] = "RACING";

	std::cout << "Texto sin modificar: " << texto << std::endl;
	RemplazarTexto(texto, subtexto_buscado, subtexto_remplazo);
	std::cout << "Texto modificado: " << texto << std::endl;
}

void RemplazarTexto(char texto[], char subtexto_buscado[], char subtexto_remplazo[]) {
	char texto_generado[TOPE] = {};
	int tamanio_subtexto_buscado = CalcularTamanioTexto(subtexto_buscado);
	int indice = 0;

	while (texto[indice]!= '\0') {
		if (ContieneSubtexto(texto, subtexto_buscado, indice)) {
			AdjuntarTexto(texto_generado, subtexto_remplazo);
			indice += tamanio_subtexto_buscado;
		}
		else {
			AdjuntarCaracter(texto_generado, texto[indice]);
			indice++;
		}
	}
	
	CopiarTexto(texto_generado, texto);
}

void CopiarTexto(char texto_origen[], char texto_destino[]) {
	int indice = 0;
	while (texto_origen[indice] != '\0') {
		texto_destino[indice] = texto_origen[indice];
		indice++;
	}
}

bool ContieneSubtexto(char texto[], char subtexto_buscado[], int indice_inicio) {
	int indice_texto = indice_inicio;
	int indice_subtexto_buscado = 0;
	while (subtexto_buscado[indice_subtexto_buscado] != '\0') {
		if (texto[indice_texto] == '\0') {
			return false;
		}
		if (subtexto_buscado[indice_subtexto_buscado] != texto[indice_texto]) {
			return false;
		}
		indice_subtexto_buscado++;
		indice_texto++;
	}
	return true;
}

void AdjuntarTexto(char texto[], char texto_a_adjuntar[]) {
	int tamanio_texto = CalcularTamanioTexto(texto);
	int indice = 0;
	while (texto_a_adjuntar[indice] != '\0') {
		texto[tamanio_texto + indice] = texto_a_adjuntar[indice];
		indice++;
	}
}

void AdjuntarCaracter(char texto[], char caracter) {
	int tamanio_texto = CalcularTamanioTexto(texto);
	texto[tamanio_texto] = caracter;
}


int CalcularTamanioTexto(char texto[]) {
	int cantidad_caracteres = 0;
	while (texto[cantidad_caracteres] != '\0') {
		cantidad_caracteres++;
	}
	return cantidad_caracteres;
}

