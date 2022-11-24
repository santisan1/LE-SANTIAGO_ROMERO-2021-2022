#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>


using namespace std;

class club{
    //propiedades
    public:
        string nombre;
        string direc;
        int presupuesto;
    //metodos
        club(string name, string dir, int pres){
            this->nombre = name;
            this->direc = dir;
            this->presupuesto = pres;
        }
        vector<string> Prueba;
        void ficharjug();
        void venderjug();
        void jugarpar();
        void escribir();
    };
   
    void (*puntero_funcion) ();
    void default1();
    void agregarclub();
    void listarclub (string);
    void leerdocu ();

int main()
{
    default1 ();
     return 0;
}
void agregarclub(){
    string clubna, clubdir;
    int clubpres;
    cout<<"Ingrese nombre del club, direc y presupuesto"<<endl;
    cout<<"Nombre del club: ";
    cin >>clubna;
    cout<<"Dt: "; 
    cin>> clubdir;
    cout<<"Presupuesto: "; 
    cin>> clubpres;
    club club1(clubna,clubdir,clubpres);
    club1.escribir();
    puntero_funcion=&default1;
    puntero_funcion();
   
 }
void club::escribir (){
    int i=1;
    fstream archivo("Datos.txt", ios::app);
    archivo<<"Club "<<i<<"--> "<<this->nombre<<"||";
    archivo<<" Entrenador "<<i<<"-->  "<<this->direc<<"||";
    archivo<<" Presupuesto "<<i<<"-->  "<<this->presupuesto<<"||"<<endl;
    archivo.close();
    i++;
 }
 void default1 (){
    int ap;
  system ("clear");
  cout<< ("\n -------------------------------------");
  cout<< ("\n|          Programa archivos          |");
  cout<< ("\n|-------------------------------------|");
  cout<< ("\n| 1. Agregar club  |  2.Listar        |");
  cout<< ("\n|-------------------------------------|");
  cout<< ("\n|               3.Salir               |");
  cout<< ("\n ------------------------------------ ↠ " );
  cin>>ap;
  if (ap == 1)
    {
      puntero_funcion = &agregarclub;
      puntero_funcion ();
      
    }
    
    if (ap == 2)
    {
      puntero_funcion = &leerdocu;
      puntero_funcion ();
    }
  
  if (ap == 3)
    {
        exit(1);
    }
}
void listarclub(){ 
    
    cout<<"Los clubes son: ";
    
}
void leerdocu (){
    cout<<"todos los clubes (his): "<<endl;
    string filename("Datos.txt");
    vector<string> lines;
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
    }

    while (getline(input_file, line)){
        lines.push_back(line);
    }

    for (const auto &i : lines)
        cout << i << endl;

    input_file.close();
}