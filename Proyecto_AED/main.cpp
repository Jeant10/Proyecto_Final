#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>

string nombre;
string cedula;
string materia;
string apellido;
string correo;

float suma;
float total[50][50];
int aprobados=0,suspendidos=0,reprobados=0;
int arreglo[100];

int menu();
void imprimir(int a[],int m,int n);
void ordenarArreglo(int a[][50],int m,int n);

#include "calificaciones.h"
#include "ordenamiento.h"
#include "busqueda.h"


int main()
{
  int m,n,dato;
  string nombres[50];
  string apellidos[50];
  string correos[50];
  int notas[50][50];
  int ultimo;
  int intentos = 0;
  string user, pass;
  const string RegUser = "root", RegPass = "1234";
  while (intentos < 3) 
  {
    cout << "   " <<"_____________________________________________________" << endl;
    cout << "   " << "Usuario: ";
    cin >> user;
    cout << "   " << "Contraseña: ";
    cin >> pass;
    cout << "   " << "_____________________________________________________" << endl;
    if ((user == RegUser) && (pass == RegPass)) 
    {
      cout << "   " <<"_____________________________________________________" << endl;
      cout << "  |" << setw(54) << " |" << endl;
      cout << "  |" << setw(47) << "B I E N V E N I D O   A L   S I S T E M A" << setw(7) << "|" << endl;
      cout << "  |" << "_____________________________________________________|" << endl;
      cin.ignore();
      cout << "   " << "_____________________________________________________" << endl;
      cout << "   " << "INGRESE SUS DATOS" << endl;
      cout << "   " << "Nombre: ";
      getline(cin,nombre);
      cout << "   " << "Apellido: ";
      getline(cin,apellido);
      cout << "   " << "Nº de cedula: ";
      getline(cin,cedula);
      cout << "   " << "Correo electronico: ";
      getline(cin,correo);
      cout << "   " << "MATERIA A CALIFICAR: ";
      getline(cin,materia);
      cout << "   " << "_____________________________________________________" << endl;
      intentos = 3;
      int opcion = menu();
      while (opcion != 4) {
        switch (opcion) {
          case 1:
          {
            cout << "   " << "_____________________________________________________" << endl;
            cout << "   " << "Ingrese la cantidad de alumnos: ";
            cin>>m;
            cout << "   " << "Ingrese el numero de calificaciones: ";
            cin>>n;
            cout << "   " << "_____________________________________________________" << endl;
            ingresar(nombres,apellidos,correos,notas,m,n);
            ordenarArreglo(notas,m,n);
            rango(m,n);
            escribir_notas(nombres,apellidos,correos,notas,m,n);
          }
          break;
          case 2:
          {
            int opcion_ordenamiento = menu_ordenamiento();
            while (opcion_ordenamiento!= 0) {
              switch (opcion_ordenamiento) {
                case 1:
                {
                  cout << "   " <<"_____________________________________________________" << endl;
                  ordenarBurbuja(arreglo,m,n);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir(arreglo,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 2:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  ordenamientoSeleccion(arreglo,m,n);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir(arreglo,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 3:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  inserccion(arreglo,m,n);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir(arreglo,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 4:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  ultimo = m*n;
                  dividir(arreglo,0,ultimo-1);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir(arreglo,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 5:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  ultimo = m*n;
                  ordenar(arreglo,0,ultimo-1);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir(arreglo,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 6:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  ordenar_heap(notas,m,n);
                  Heapsort(arreglo,m,n);
                  escribir_ordenamiento(arreglo,m,n,opcion_ordenamiento);
                  imprimir_heap(arreglo,m,n);
                  ordenarArreglo(notas,m,n);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
              }
            opcion_ordenamiento = menu_ordenamiento();
            }
          }
          break;
          case 3:
          {
            ordenarBurbuja(arreglo,m,n);
            int opcion_Busqueda = menu_Busqueda();
            while (opcion_Busqueda != 0) {
              switch (opcion_Busqueda) {
                case 1:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  cout << "   " << "Ingrese el dato a encontrar: ";
                  cin>>dato;  
                  cout << "   " << "_____________________________________________________" << endl;    
                  if (busquedaLineal(arreglo,m,n,dato) == -1) {
                    cout << "   " <<"NO EXISTE EL ELEMENTO"<<endl;
                  }
                  else {
                    cout << "   " <<"EL elemento si se se encontró y está en la posición: " << busquedaLineal(arreglo,m,n,dato) << endl;
                    escribir_busqueda(dato,busquedaLineal(arreglo,m,n,dato),opcion_Busqueda);
                  }
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 2:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  cout << "   " << "Ingrese el dato a encontrar: ";
                  cin>>dato; 
                  cout << "   " << "_____________________________________________________" << endl;
                  BusquedaBinaria(arreglo,m,n,dato,opcion_Busqueda);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
                case 3:
                {
                  cout << "   " << "_____________________________________________________" << endl;
                  cout << "   " << "Ingrese el dato a encontrar: ";
                  cin >> dato; 
                  cout << "   " << "_____________________________________________________" << endl;
                  interpolacion(arreglo,m,n,dato,opcion_Busqueda);
                  cout << "   " << "_____________________________________________________" << endl;
                }
                break;
              }
            opcion_Busqueda = menu_Busqueda();
            }
          }
          break;
        }
        opcion = menu();
      } 
    }
    else 
    {
      cout << "   " << "Datos incorrectos " << endl;
      intentos++;
      if (intentos == 3) 
      {
        cout << "   " << "Maximo de intentos permitidos" << endl;
      }
    }
  }
  return 0;
}

//Menus

int menu() {
   int opc;
   cout << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(45) << " SISTEMA DE GESTION DE CALIFICACIONES " <<setw(9) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  CALIFICACIONES" << setw(37) << " |" << endl;
   cout << "  |" << "2  ORDENAMIENTO" << setw(39) << " |" << endl;
   cout << "  |" << "3  BUSQUEDA" << setw(43) << " |" << endl;
   cout << "  |" << "4  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 1 || opc > 4)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 1 || opc > 4);
	return opc;
}


// Procesos

void ordenarArreglo(int a[][50],int m,int n)
{
  int k = 0;
  //Convertir el arreglo de dos dimensiones en uno de una sola dimension.
  for(int fila = 0; fila < m; fila++){
    for(int col = 0; col < n; col++){
      arreglo[k] = a[fila][col];
      k++;
      }
  } 
}

void imprimir(int a[],int m,int n)
{
  cout << "   " << "Las calificaciones ordenadas son : ";
  for (int i=0; i<(n*m);i++)
  {
    cout << "[" << a[i] << "]";
  }
  cout << endl;
}

