#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

#define PARADO 3
#define SUBIENDO 5
#define BAJANDO 5



int pisoact=5;
int pisoeleg;

void parado(void);
void subiendo(void);
void bajando(void);

int main()
{
parado;
}

void parado (void){
    cout << "\tEl ascensor está parado y en el piso "<<pisoact<<endl;
    cout << "Ingrese el piso que desea  ir -->"<<endl;
    cin >> pisoeleg;


    if (pisoeleg>pisoact){
        cout << "\tEl ascensor está subiendo\n"<<endl;
        void (*puntero_funcion)()= &subiendo;
        puntero_funcion();
    }
    if (pisoeleg=pisoact){
        cout << "\tEl ascensor sigue parado\n"<<endl;
    }
       
     if (pisoeleg<pisoact){
         cout << "\tEl ascensor está bajando\n"<<endl;
         void (*puntero_funcion¨)()=&bajando;
         puntero_funcion;

    }

}

void subiendo(){
    pisoact+pisoeleg = pisoact;
    cout << "recibido"<<endl;
}


void bajando(){
    pisoact-pisoeleg = pisoact;
}


