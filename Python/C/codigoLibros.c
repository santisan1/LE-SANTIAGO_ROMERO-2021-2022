#include <stdio.h>

int ap;
int num_lib = 0;
int ver = 1;
char cont[500];
temp;
char temp_char[20];
int i = 0;

struct Libros
{
  char nombre[20];
  int precio;
} Libro[500];

void (*puntero_funcion)();
void addbook();
void Ordena(struct Libros);
void Imprimir();
void entro();
void default1();
void borrar();

int main()
{
  system("clear");
  default1();
}

void addbook(void)
{
  do
  {
    system("clear");
    printf("ingrese el nombre del libro: ");
    scanf("%s", &(Libro[i].nombre));
    printf("\ningrese su precio: ");
    scanf("%d", &(Libro[i].precio));
    printf("Quiere ingresar otro libro (1) o salir (2)\n ");
    scanf("%d", &ver);
    i++;
    num_lib++;
  } while (ver == 1);
  puntero_funcion = &default1;
  puntero_funcion();
  return num_lib;
}

void Imprimir()
{
  system("clear");
  int i;
  for (int i = 0; i < num_lib; i++)
  {
    printf("Nombre libro %i--> %s\t Precio--> %i$\n", i + 1,
           Libro[i].nombre, Libro[i].precio);
  }
  int control;
  printf("Desea volver al menu principal (1) o salir (2)?");
  scanf("%d", &control);
  if (control == 1)
  {
    puntero_funcion = &default1;
    puntero_funcion();
  }
}

void OrdenM(struct Libros Libro[num_lib])
{
  int control;
  system("clear");
  struct Libros temp;
  for (int i = 0; i < num_lib; i++)
  {
    for (int j = i + 1; j < num_lib; j++)
      if (Libro[i].precio < Libro[j].precio)
      {
        temp = Libro[i];
        Libro[i] = Libro[j];
        Libro[j] = temp;
      }
  }
  printf("\nOrden por precio (↑): \n");
  for (int i = 0; i < num_lib; i++)
    printf(" %s --->Precio: %d\n", Libro[i].nombre, Libro[i].precio);
  printf("Desea volver al menu principal (1) o salir (2)?");
  scanf("%d", &control);
  if (control == 1)
  {
    puntero_funcion = &default1;
    puntero_funcion();
  }
}

void Ordenm(struct Libros Libro[num_lib])
{
  int control;
  system("clear");
  struct Libros temp;
  for (int i = 0; i < num_lib; i++)
  {
    for (int j = i + 1; j > num_lib; j++)
      if (Libro[i].precio > Libro[j].precio)
      {
        temp = Libro[i];
        Libro[i] = Libro[j];
        Libro[j] = temp;
      }
  }
  printf("\nOrden por precio (↓): \n");
  for (int i = 0; i < num_lib; i++)
    printf(" %s --->Precio: %d\n", Libro[i].nombre, Libro[i].precio);
  printf("Desea volver al menu principal (1) o salir (2)?");
  scanf("%d", &control);
  if (control == 1)
  {
    puntero_funcion = &default1;
    puntero_funcion();
  }
}

void default1()
{
  system("clear");
  printf("\n|-------------------------------------|");
  printf("\n|    BIENVENIDO A LIBRERIA LU y SA    |");
  printf("\n|------------------|------------------|");
  printf("\n| 1. Agregar +     | 2. Imprimir ↵    |");
  printf("\n|-------------------------------------|");
  printf("\n| 3. Ordenar mayor a menor ↑            |");
  printf("\n|-------------------------------------|");
  printf("\n| 4. Ordenar de menor a mayor ↓       |");
  printf("\n|-------------------------------------|");

  scanf("%d", &ap);
  if (ap == 1)
  {
    puntero_funcion = &addbook;
    puntero_funcion();
  }
  if (ap == 2)
  {
    puntero_funcion = &Imprimir;
    puntero_funcion();
  }
  if (ap == 3)
  {
    OrdenM(Libro);
  }
  if (ap == 4)
  {
    Ordenm(Libro);
  }
}
