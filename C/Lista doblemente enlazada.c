#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int cnt=0;

typedef struct Libro{
    char nombre [20];
    int precio;
    struct Libro* siguiente;
    struct Libro* anterior;
}Libro;

Libro*Primero=NULL;
Libro*Ultimo=NULL;

void addbook();
void imprimir();
void eliminarLibro();
void (*puntero_funcion) ();

 int main(){
 do{
    system ("clear");
    printf ("\n|-------------------------------------|");
    printf ("\n|      Lista doblemente enlazada      |");
    printf ("\n|-------------------------------------|");
    printf ("\n| 1. Agregar +     | 2. Imprimir ↵    |");
    printf ("\n|-------------------------------------|");
    printf ("\n|         3. Borrar y Salir           |");
    printf ("\n|-------------------------------------|");
    do{
    scanf("%d",&cnt);
 }while((cnt!=1) && (cnt!=2) && (cnt!=3));
 if(cnt==1) addbook();
 if(cnt==2) imprimir();
 if(cnt==3) eliminarLibro();
 }while(cnt!=4);
 
 return 0;	
 
 }
 
 
 void addbook(){
    system ("clear");
    Libro* agregado = (Libro*)malloc (sizeof(Libro));
    printf ("Escriba el nombre del nuevo libro: ");
    scanf ("%s", &agregado->nombre);
    printf ("Escriba el precio del nuevo libro: ");
    scanf ("%d", &agregado->precio);
    if (Primero==NULL){//todavia no tiene nada 
        Primero=agregado;
        Primero->siguiente=NULL;
        Primero->anterior=NULL;
        Ultimo=Primero;
    }
    else {
        Ultimo->siguiente=agregado;
        agregado->siguiente=NULL;
        agregado->anterior=NULL;
        Ultimo=agregado;
    }
    printf("Libro ingresado con exito"); 
 }
 void imprimir(){
    system ("clear");
    int control;
    Libro* actual = (Libro*)malloc (sizeof(Libro));
    actual=Primero;
    if (Primero!=NULL){//todavia no tiene nada 
        while (actual!=NULL){
            printf ("\n|---------------------------------------------------");
            printf ("\n|    Nombre:  %s           Precio: %d",actual->nombre, actual->precio);
            actual=actual->siguiente;
        }
    }
    else ("\nLa lista esta vacia");
    printf ("\n|---------------------------------------------------");
    printf ("\nDesea volver al menu principal (1) o salir (2)?");
  scanf ("%d", &control);
  if (control == 1)
    {
      puntero_funcion = &main;
      puntero_funcion ();
    }
 }
 void eliminarLibro(){
    Libro* actual = (Libro*)malloc (sizeof(Libro));
    while(Primero!=NULL){
        actual=Primero;
        *Primero=*Primero->siguiente;
        free(actual->nombre);
        free(actual->precio);
        free(actual);
    }
}
