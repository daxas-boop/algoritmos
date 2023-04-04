#include <iostream>
using namespace std;

int ContarApariciones(char texto[], char subTexto[]);
bool EstaContenidoDesde(char texto[], char subTexto[], int indiceComienzoTexto);
int TamanioCadenaCaracteres(char texto[]);

int main()
{
  char texto[] = "CAMINO CAMION BOCA";
  char subTexto[] = "CA";
  int cantidadApariciones = ContarApariciones(texto, subTexto);
  cout << cantidadApariciones << endl;
}

int ContarApariciones(char texto[], char subTexto[])
{
  int cantidadApariciones = 0;
  int posicion = 0;
  int tamanioTexto = TamanioCadenaCaracteres(texto);
  int tamanioSubTexto = TamanioCadenaCaracteres(subTexto);
  int posicionLimite = tamanioTexto - tamanioSubTexto;
  while (posicion <= posicionLimite)
  {
    if (EstaContenidoDesde(texto, subTexto, posicion))
    {
      cantidadApariciones++;
    };
    posicion++;
  }
  return cantidadApariciones;
}

bool EstaContenidoDesde(char texto[], char subTexto[], int indiceComienzoTexto)
{
  int i = indiceComienzoTexto;
  int j = 0;
  while (subTexto[j] != '\0')
  {
    if (texto[i] != subTexto[j])
    {
      return false;
    }
    i++;
    j++;
  }
  return true;
}

int TamanioCadenaCaracteres(char texto[])
{
  int cantidadCaracteres = 0;
  while (texto[cantidadCaracteres] != '\0')
  {
    cantidadCaracteres++;
  }
  return cantidadCaracteres;
}
