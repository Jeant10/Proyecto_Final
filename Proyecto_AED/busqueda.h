// Busqueda

string nombrearchivo_busqueda = "busqueda.txt";

int menu_Busqueda() {
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(38) << " ALGORITMO - BUSQUEDA " <<setw(16) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  LINEAL" << setw(45) << " |" << endl;
   cout << "  |" << "2  BINARIA" << setw(44) << " |" << endl;
   cout << "  |" << "3  INTERPOLACION" << setw(38) << " |" << endl;
   cout << "  |" << "0  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 0 || opc > 3)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > 3);
	return opc;
}

//Escribir

void escribir_busqueda(int dato,int posicion,int op)
{
  ofstream archivo_busqueda;
  archivo_busqueda.open(nombrearchivo_busqueda.c_str(),ios::out);
  string algoritmo;
  archivo_busqueda << "___________________________________________________________________________" << endl;
  archivo_busqueda << setw(50) <<"REPORTE DE CALIFICACIONES" << endl;
	archivo_busqueda << "___________________________________________________________________________" << endl;
	archivo_busqueda << "Búsqueda de Calificaciones" << endl << endl;
  if(op==1){
    algoritmo = "Lineal";
  }
  else if(op==2){
    algoritmo = "Binaria";
  }
  else if(op==3){
    algoritmo = "Interpolacion";
  }
  else{
    algoritmo = " ";
  }
	archivo_busqueda << "ALGORITMO: " << algoritmo << endl;
	archivo_busqueda << "___________________________________________________________________________" << endl << endl;
	archivo_busqueda << "La calificación a buscar fue: " << dato << endl << endl;
  archivo_busqueda << "Calificacion encontrada en la posicion: " << posicion << endl;
  archivo_busqueda << endl << endl << right <<setw(50) << "____________________"<<endl;
  archivo_busqueda << right <<setw(44) << "Docente " << endl << setw(39) << nombre << " " << apellido << endl <<setw(41) << cedula << endl;
  archivo_busqueda << "___________________________________________________________________________";
  archivo_busqueda.close();
}

// 1.Lineal
int busquedaLineal(int a[],int m,int n,int dato)
{
    for (int i=0; i<=(n*m); i++)
    {
        if(a[i]==dato)
        {
            return i+1;
        }
    }  
    return -1;
}

// 2.Binaria

void BusquedaBinaria(int a[],int m,int n, int dato,int op)
{
  ofstream Binario;
  int i,j,k;
  i=0;
  j=(n*m)-1;
  
  do
  {
      k=(i+j)/2;
      if(a[k]<=dato)
        {
          i=k+1;
        }
      if (a[k]>=dato)
        {
          j=k-1;
        }
  }while (i<=j);

  if(a[k]==dato)
  {
      cout << "   " << "Elemento encontrado en la posición: "<< k+1 << endl;
      escribir_busqueda(dato,k+1,op);
  }
  else 
  {
      cout << "   " << "Elemento no encontrado" << endl;
  }
}

//3.-Interpolacion

void interpolacion(int a[],int m, int n, int dato,int op)
{
    int primero=0;
    int contador=0;
    int ultimo=(n*m)-1;
    int medio;
    while(a[primero]!=dato && contador<(n*m))
    {   
      
    medio = primero + ((dato-a[primero])*(ultimo-primero))/(a[ultimo]-a[primero]);
    
    if(a[medio]<dato)
          primero = medio+1;
          
    else if(a[medio]>dato)
    
          ultimo = medio-1;
    else
          primero = medio;
      
      contador++; 
      break;
    }
    
    if(a[primero]==dato)
    {
        cout << "   " << "ELEMENTO ENCONTRADO EN LA POSICION: " << primero+1 << endl;
        escribir_busqueda(dato,primero+1,op);
    }
    else
    {
        cout << "   " << "ELEMENTO NO ENCONTRADO" << endl;
    }
}


