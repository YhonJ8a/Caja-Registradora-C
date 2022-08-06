/**
#include<stdio.h>
#include<conio.h>
#include"ventas.h"

ventas *raiz=NULL;

int cantidadven()
{
    ventas *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}



void insertarVenta( usuarios *cliente , char fechaV[11], nodo *products )
{
    static int x = 0;
    x++;
    int pos = cantidadven()+1;

    if (pos <= cantidadven() + 1)
    {
        ventas *nuevo;
        nuevo = malloc(sizeof( ventas));
        nuevo->codigoVenta = x;
        nuevo->clien = cliente;
        strcpy(nuevo->fecha , fechaV);
        nuevo->productos = products;
        nuevo->ant=NULL;
        nuevo->sig=NULL;
        if (pos == 1)
        {
            nuevo->sig = raiz;
            if (raiz != NULL)
                raiz->ant = nuevo;
            raiz = nuevo;
        }
        else
            if (pos == cantidadven() + 1)
            {
                ventas *reco = raiz;
                while (reco->sig != NULL)
                {
                    reco = reco->sig;
                }
                reco->sig = nuevo;
                nuevo->ant = reco;
            }
            else
            {
                ventas *reco = raiz;
                int f;
                for (f = 1; f <= pos - 2; f++)
                    reco = reco->sig;
                ventas *siguiente = reco->sig;
                reco->sig = nuevo;
                nuevo->ant = reco;
                nuevo->sig = siguiente;
                siguiente->ant = nuevo;
            }
    }
}



void imprimirventas()
{
    ventas *reco=raiz;
    printf("LISTA DE VANTAS.\n");
    while (reco!=NULL)
    {
        printf("%i ",reco->codigoVenta);
        //printf("%i ",reco->clien);
        printf("%s ",reco->fecha);
        //printf("%i ",reco->);
        reco=reco->sig;
    }
    printf("\n");
}

*/
