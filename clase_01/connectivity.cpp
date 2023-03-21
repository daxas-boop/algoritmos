#include <iostream>

using namespace std;
#define Ingresos 9;
#define CantidadElementos 8;

void Inicializar(int conexiones[]);
void Conectar(int conexiones[], int p, int q);
bool EstanConectados(int conexiones[], int p, int q);

int main() {
	int p, q;
	int conexiones[8];
	
	Inicializar(conexiones);
	for (int i = 0; i < 100; i++) {
		cin >> p;
		cin >> q;
		if (EstanConectados(conexiones, p , q)) {
			cout << "-" << endl;
		}
		else {
			Conectar(conexiones, p, q);
			cout << p << "-" << q << endl;
		}
		for (auto c : conexiones) {
			cout << c << ", "; 
		}
	}

	return 0;
}

bool EstanConectados(int conexiones[],int p, int q) {
	return p == q || conexiones[p] == conexiones[q];
}

void Conectar(int conexiones[],int p, int q) {
	int primerNumeroConexion = conexiones[p];
	int segundoNumeroConexion = conexiones[q];
	for (int i = 0; i < 8; i++) {
		if (conexiones[i] == primerNumeroConexion) {
			conexiones[i] = segundoNumeroConexion;
		}
	}
}

void Inicializar(int conexiones[]) {
	for (int i = 0; i < 8; i++) {
		conexiones[i] = i;
	}
}
