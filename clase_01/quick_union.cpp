#include <iostream>
#define Ingresos 9;
#define CantidadElementos 8;

using namespace std;

void Inicializar(int conexiones[]);
void Conectar(int conexiones[], int p, int q);
bool EstanConectados(int conexiones[], int p, int q);
int ObtenerRaiz(int conexiones[], int nodo);

int main()
{
  int p, q;
  int conexiones[8];

  Inicializar(conexiones);
  for (int i = 0; i < 100; i++)
  {
    cin >> p;
    cin >> q;
    if (EstanConectados(conexiones, p, q))
    {
      cout << "-" << endl;
    }
    else
    {
      Conectar(conexiones, p, q);
      cout << p << "-" << q << endl;
    }

    cout << "Conexiones:" << endl;
    for (int i = 0; i < 8; i++)
    {
      cout << conexiones[i] << " ";
    }
  }

  return 0;
}

int ObtenerRaiz(int conexiones[], int nodo)
{
  int raiz = conexiones[nodo];
  while (conexiones[raiz] != raiz)
  {
    raiz = conexiones[raiz];
  }
  return raiz;
}

bool EstanConectados(int conexiones[], int p, int q)
{
  int raizQ = ObtenerRaiz(conexiones, p);
  int raizP = ObtenerRaiz(conexiones, q);
  return raizP == raizQ;
}

void Conectar(int conexiones[], int p, int q)
{
  int raizQ = ObtenerRaiz(conexiones, p);
  int raizP = ObtenerRaiz(conexiones, q);
  conexiones[raizP] = raizQ;
}

void Inicializar(int conexiones[])
{
  for (int i = 0; i < 8; i++)
  {
    conexiones[i] = i;
  }
}