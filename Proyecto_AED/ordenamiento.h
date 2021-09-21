//Ordenamiento

string nombrearchivo_ordenamiento = "ordenamiento.txt";

int menu_ordenamiento() {
   int opc;
   cout  << "   " <<"_____________________________________________________" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << setw(41) << " ALGORITMO - ORDENAMIENTO " <<setw(13) <<"|"<< endl;
   cout << "  |" << setw(54) << "_____________________________________________________|" << endl;
   cout << "  |" << setw(54) << " |" << endl;
   cout << "  |" << "1  BURBUJA" << setw(44) << " |" << endl;
   cout << "  |" << "2  SELECCION" << setw(42) << " |" << endl;
   cout << "  |" << "3  INSERCCION" << setw(41) << " |" << endl;
   cout << "  |" << "4  MERGESORT" << setw(42) << " |" << endl;
   cout << "  |" << "5  QUICKSORT" << setw(42) << " |" << endl;
   cout << "  |" << "6  HEAPSORT" << setw(43) << " |" << endl;
   cout << "  |" << "0  SALIR" << setw(46) << " |" << endl;
   cout << "  |" << "_____________________________________________________|" << endl << endl;
   do
   {
     cout << "   OPCION: ";
     cin >> opc;
     if (opc < 0 || opc > 6)
     {
       cout << endl << "ERROR! La opcion ingresada no es valida... Ingrese nuevamente." << endl << endl;
       }
    } while (opc < 0 || opc > 6);
	return opc;
}

// 1.Burbuja
void ordenarBurbuja(int a[],int m,int n)
{
  int i,j,aux;
  for(i=0;i<(n*m);i++)
  {
    for(j=0;j<((n*m)-1);j++)
    {
      if(a[j]>a[j+1])
      {
        aux=a[j];
        a[j]=a[j+1];
        a[j+1]=aux;
      }
    }
  }
}

// 2.Seleccion

void ordenamientoSeleccion(int a[],int m,int n)
{
    int i,j,aux,min;

    for (i=0 ; i<(n*m) ; i++)
    {
        min = i;

        for (j= i+1 ; j<(n*m) ; j ++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
}

// 3.-Insercion

void inserccion(int a[], int m,int n)
{
  int aux;
    for (int i=0; i<(n*m); i++)
    {  
        aux=a[i];
        int p=i;
        while (p>0)
        {
           if (a[p-1]>aux)
            {
                a[p]=a[p-1];
                a[p-1]=aux;
            }
            p--;
        }
        
    }
}

//4.- MergeSort

void Fusionar(int a[],int pinicial, int pfinal, int medio)
{
        
	int i, j, k, temp[pfinal-pinicial+1];
	i = pinicial;
	k = 0;
	j = medio + 1;
	
	while (i <= medio && j <= pfinal)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}
	
	while (i <= medio)
	{
		temp[k] = a[i];
		k++;
		i++;
	}
	
	while (j <=pfinal)
	{
		temp[k] = a[j];
		k++;
		j++;
	}
	
	for (i = pinicial; i <= pfinal; i++)
	{
		a[i] = temp[i-pinicial];
	}
	
}

void dividir(int a[], int inicial, int final)
{
    int mitad;
    if (inicial < final)
	{
		mitad=(inicial+final)/2;
		
		dividir(a,inicial,mitad);
		dividir(a,mitad+1,final);
		Fusionar(a,inicial,final,mitad);
	} 
}


//5.-QuickSort

int mitad(int a[],int pinicial, int pfinal)
{
    return a[(pinicial+pfinal)/2];
}


void ordenar(int a[],int pinicial, int pfinal)
{

    int i=pinicial;
    int j=pfinal;
    int temp;
    int piv=mitad(a,pinicial,pfinal);

    do
    {
        while(a[i]<piv)
        {
            i++;
        }
        while(a[j]>piv)
        {
            j--;
        }
        if(i<=j)
        {
            temp =a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(pinicial<j)
    {
        ordenar(a,pinicial,j);
    }
    if(i<pfinal)
    {
      ordenar(a,i,pfinal);
    }
}

//6.-HeapSort

void Heapsort(int b[],int n, int m)
{
  int valor, temp, a;
  for(int i=(n*m); i>0; i--)
  {
    for(int j=1;j<=i;j++)
    {
      valor=b[j];
      a=j/2;
      while(a>0 && b[a]<valor)
      {
        b[j]=b[a];
        j=a;
        a=a/2;
      }
      b[j]=valor;
    }
    temp=b[1];
    b[1]=b[i];
    b[i]=temp;
  }
}

//Escribir 

void escribir_ordenamiento(int a[],int n, int m,int op)
{
  bool heap = false;
  ofstream archivo_ordenamiento;
  archivo_ordenamiento.open(nombrearchivo_ordenamiento.c_str(),ios::out);
  string algoritmo;
  archivo_ordenamiento << "___________________________________________________________________________" << endl;
  archivo_ordenamiento << setw(50) <<"REPORTE DE CALIFICACIONES" << endl;
	archivo_ordenamiento << "___________________________________________________________________________" << endl;
	archivo_ordenamiento << "Calificaciones Ordenadas" << endl << endl;
  if(op==1){
    algoritmo = "Burbuja";
  }
  else if(op==2){
    algoritmo = "Seleccion";
  }
  else if(op==3){
    algoritmo = "Inserccion";
  }
  else if(op==4){
    algoritmo = "MergeSort";
  }
  else if(op==5){
    algoritmo = "QuickSort";
  }
  else if(op==6){
    algoritmo = "HeapSort";
    heap = true;
  }
  else{
    algoritmo=" ";
  }
	archivo_ordenamiento << "ALGORITMO: " << algoritmo << endl;
	archivo_ordenamiento << "___________________________________________________________________________" << endl;
  archivo_ordenamiento << endl << "Nº-: ";
  if(heap == true)
  {
    for (int i = 1; i<=(n*m);i++)
  {
    archivo_ordenamiento<<"["<<a[i]<<"]";
  }
  }
  else
  { 
  for (int i = 0; i<(n*m);i++)
  {
    archivo_ordenamiento<<"["<<a[i]<<"]";
  }
  }
  archivo_ordenamiento << endl <<endl << endl << right <<setw(50) << "____________________" << endl;
  archivo_ordenamiento << right <<setw(44) << "Docente " << endl << setw(39) << nombre << " " << apellido << endl <<setw(41) << cedula << endl;
	archivo_ordenamiento << "___________________________________________________________________________";
  archivo_ordenamiento.close();
}

//Procesos 

void imprimir_heap(int a[],int m,int n)
{
  cout << "   " << "Las calificaciones ordenadas son : ";
  for (int i = 1; i<=(n*m);i++)
  {
    cout << "[" << a[i] << "]";
  }
  cout << endl;
}

void ordenar_heap(int a[][50],int m,int n)
{
  int k = 1;
  //Convertir el arreglo de dos dimensiones en uno de una sola dimension.
  for(int fila = 0; fila < m; fila++){
    for(int col = 0; col < n; col++){
      arreglo[k] = a[fila][col];
      k++;
      }
  } 
}