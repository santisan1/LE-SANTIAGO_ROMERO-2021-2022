#include <stdio.h>
#include <stdlib.h>

int pisoact=1;
int pisoeleg;

void parado(void);
void subiendo(void);
void bajando(void);

void(*funcion)(void);

int main(){
funcion=&parado;
(*funcion)();
}

void parado(){
    printf("Usted esta parado, seleccione a que piso quiere ir\n");
    printf("|-----------------------------|\n");
    printf("|   (1)  ||  (2)   ||  (3)   |\n");
    printf("|-----------------------------|\n");
    printf("|-----------------------------|\n");
    printf("|   (4)  ||  (5)   ||  (6)   |\n");
    printf("|-----------------------------|\n");
    printf("|-----------------------------|\n");
    printf("|   (7)  ||  (8)   ||  (9)   |\n");
    printf("|-----------------------------|\n");


    scanf("%d", &pisoeleg);
   
    if((pisoeleg>pisoact)&&(pisoeleg>1&&pisoeleg<9)){
        void(*funcion)(void);
        funcion=&subiendo;
        (*funcion)();
    }else if((pisoeleg<pisoact)&&(pisoeleg>1&&pisoeleg<9)){
    (pisoeleg<pisoact);
    void(*funcion)(void);
        funcion=&bajando;
        (*funcion)();
    }else if (pisoeleg==pisoact){
        printf("usted está ya está en ese piso\n");
        (*funcion)();
    }else{
        printf("Ese piso no existe actualmente\n");
        (*funcion)();
    }

}
    void subiendo(){
        int con;
    printf("Usted esta subiendo espere 10 segundos para seleccionar nuevamente\n");
    pisoact=pisoeleg;
        printf("Está en el piso %d ¿Desea ir a otro piso(1) o irse(2)? \n", pisoeleg);
        scanf ("%d",&con);
        if (con==1){
     funcion=&parado;
        (*funcion)();
    }
    else exit (1);
    }

      void bajando(){
          int con;
    printf("Usted esta bajando espere 10 segundos para seleccionar nuevamente\n");
        pisoact=pisoeleg;
    printf("Está en el piso %d ¿Desea ir a otro piso(1) o irse(2)? \n", pisoeleg);
        scanf ("%d",&con);
        if (con==1){
     funcion=&parado;
        (*funcion)();
    }
    else exit (1);
    }

