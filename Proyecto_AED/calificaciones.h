//1.- Calificaciones

string nombrearchivo_notas = "calificaciones.txt";

void ingresar(string a[],string b[],string c[],int d[][50],int m, int n)
{
  for(int i=0;i<m;i++)
  {
    cout << "   " << "_____________________________________________________" << endl;
    cout << "  |" << setw(54) << " |" << endl;
    cout << "  |" << setw(32) << "ESTUDIANTE #" << i+1 << setw(21) << "|" << endl;
    cout << "  |" <<"_____________________________________________________|" << endl;
    cout << "   " <<"_____________________________________________________" << endl;
    cout << "   " << "Nombre: ";
    cin>>a[i];
    cout << "   " << "Apellido: ";
    cin>>b[i];
    cout << "   " << "Correo: ";
    cin>>c[i];
    for(int j=0;j<n;j++)
    { 
      do
      {
        cout << "   " << "Ingresa la calificacion "<<j+1<<" (de 0 a 20) : ";
        cin>>d[i][j];
        if(d[i][j]<0 || d[i][j]>20)
        {
          cout << endl << "   " <<"ERROR! Nota fuera del rango (0 - 20) ... Intentelo de nuevo"<<endl<<endl;
        }
      }while(d[i][j]<0 || d[i][j]>20);
      total[i][n] += d[i][j];
      suma += d[i][j]; 
    }
    cout << "   " << "_____________________________________________________" << endl;
	}
}

void rango(int m,int n){
  for(int i=0;i<m;i++)
  { 
      if((total[i][n]/n)>=1 && (total[i][n]/n)<=8){
        reprobados += 1;
      }
      else if((total[i][n]/n)>=9 && (total[i][n]/n)<=13){
        suspendidos +=1;
      }
      else{
        aprobados +=1;
      }
    } 
}

//Escribir

void escribir_notas(string a[],string b[],string c[],int d[][50],int m, int n)
{
  ofstream archivo_notas;
  archivo_notas.open(nombrearchivo_notas.c_str(),ios::out);
  archivo_notas << "___________________________________________________________________________" << endl;
  archivo_notas << setw(50) <<"REPORTE DE CALIFICACIONES" << endl;
	archivo_notas << "___________________________________________________________________________" << endl;
	archivo_notas << "Año Lectivo: 2020-2021" << endl;
	archivo_notas << "Materia: " << materia << endl;
	archivo_notas << "___________________________________________________________________________";
	archivo_notas << endl << "No. ";
	archivo_notas << setw(6) << right << "Nombre" << " ";
  archivo_notas << setw(18) << left << "Apellido";
  archivo_notas << setw(8) << "Correo" << " ";
  archivo_notas << setw(9) << left << " " << "Notas" << setw(14);
  archivo_notas << " " << "Promedio" << endl;
	archivo_notas << "___________________________________________________________________________";
  for(int i=0;i<m;i++)
  {
    archivo_notas << endl << i + 1 << ":  ";
    archivo_notas << setw(6) << right << a[i] << "  ";
    archivo_notas << setw(18) << left << b[i];
    archivo_notas << setw(8) << c[i] << "";
    archivo_notas << setw(9) << left << "";
    for(int j=0;j<n;j++)
    {
      archivo_notas << "[" << d[i][j] << "]";
    }
    archivo_notas << setw(5) << left << " " << total[i][n]/n;
	}
  archivo_notas << endl << "___________________________________________________________________________" << endl;
  archivo_notas << "RESUMEN"<<endl;
  archivo_notas << "___________________________________________________________________________" << endl;
  archivo_notas << "Promedio del curso: " << setw(10) << setprecision(2) << suma/(m*n) << endl;
  archivo_notas << "___________________________________________________________________________" << endl;
  archivo_notas << "TOTAL" << endl;
  archivo_notas << " * Aprobados (14 - 20): " << aprobados << endl; 
  archivo_notas << " * Estudiantes en suspenso (09 - 13): " << suspendidos << endl;
  archivo_notas << " * Reprobados (01 - 08): " << reprobados << endl;;
  archivo_notas << "___________________________________________________________________________" << endl;
  archivo_notas << endl << endl << right << setw(50) << "____________________"<<endl;
  archivo_notas << right << setw(44) << "Docente " << endl << setw(39) << nombre << " " << apellido << endl <<setw(41) << cedula << endl;
  archivo_notas.close();
}