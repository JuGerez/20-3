#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

void ejercicios();
void muestraEjercicios();
void ejercicioClase19_3();
void ejercicioClase19_32();
void ejercicioClase20_3();
void ejercicioClase20_32();
void cargaPilaRandom(Pila*k);
void muestraPila(Pila k);
void pasaPila(Pila* k, Pila*l);
int cuentaElementosPila(Pila l);
int sumaElementosPila(Pila l);
int encuentraElemento(Pila k, int dato);
int ingresaDato();


int main()
{
    ejercicios();
        return 0;
}

void ejercicios()
{
    char opcion;

    do{
        system("cls");
        muestraEjercicios();

        opcion = getche();

    switch(opcion){
    case '1':
        ejercicioClase19_3();
        break;
    case '2':
        ejercicioClase19_32();
        break;
    case '3':
        ejercicioClase20_3();
        break;
    case '4':
        ejercicioClase20_32();
        break;
    }
    system("pause");
    }while(opcion!=27);
}
void muestraEjercicios()
{
    printf("Ingrese caso:\n\n\n");
    printf("\n 1 - Ejercicios 1ra Clase 19-3");
    printf("\n 2 - Ejercicios 2da Clase 19-3");
    printf("\n 3 - Ejercicios 3ra Clase 20-3");
    printf("\n 4 - Ejercicios 4ra Clase 20-3");

    printf("\n\n\n");
    printf("ESC para salir o cualquier tecla para continuar.\n");
}
void ejercicioClase19_3()
{
    Pila origen, destino;
    inicpila (&origen);
    inicpila (&destino);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int cantidad=cuentaElementosPila(origen);
    printf(" Cantidad elementos: %d \n", cantidad);

    int total=sumaElementosPila(origen);
    printf(" Suma elementos: %d \n", total);

    pasaPila(&origen, &destino);
    printf("Pila origen final:\n");
    muestraPila(origen);
    printf("Pila destino:\n");
    muestraPila(destino);
}

void ejercicioClase19_32()
{
    Pila origen;
    inicpila (&origen);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int flag=encuentraElemento(origen, 33);
    if(flag == 1){
        printf("El elemento esta presente.\n");
    } else {
        printf("El elemento no esta presente.\n");
    }

}
void ejercicioClase20_3()
{
    int existe;
    Pila origen;
    inicpila(&origen);

    cargaPilaRandom(&origen);

    printf("\nPila origen:\n");
    muestraPila(origen);

    int dato=ingresaDato();
    existe == encuentraElemento(origen, dato);
    if(existe){
           printf("El elemento no esta presente.\n");
    } else {
        printf("El elemento esta presente.\n");
    }

}
void ejercicioClase20_32()
{
    printf("\nCodigo ASCII de caracteres:\n");
    for(int i = 0; i <257; i++){
        printf("\n Codigo: %d - %c", i, i);
    }
}
void cargaPilaRandom(Pila* k)
{
    int numero;
    srand(time(NULL));

    for (int i = 0; i < 50; i++)
    {
        numero = rand()%100+1;
        apilar(k, numero);
    }
}
void muestraPila(Pila k)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&k))
    {
        printf("%d - ",tope(&k));
        apilar(&aux, desapilar(&k));
    }
}
void pasaPila(Pila*k, Pila*l)
{
    while(!pilavacia(k))
    {
        apilar(l, desapilar(k));
    }
}

int cuentaElementosPila(Pila l)
{
    int contador = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        apilar(&aux, desapilar(&l));
        contador++;
    }
    return contador;
}

int sumaElementosPila(Pila l)
{
    int acumulador = 0;
    int topepila;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(&l))
    {
        topepila = tope(&l);
        acumulador = acumulador + topepila;// acumulador = acumulador + tope(&l);
        apilar(&aux, desapilar(&l));
    }
    return acumulador;
}

int encuentraElemento(Pila k, int dato)
{
    int flag = 0;
    Pila aux;
    inicpila (&aux);

    while(!pilavacia(&k) && flag == 0)
    {
        if(tope(&k) == dato)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(&k));
        return flag;
    }
}
int ingresaDato()
{
    int dato;
    printf("\n Ingrese el dato a buscar: \n");
    scanf("%d", &dato);

    return dato;
}
