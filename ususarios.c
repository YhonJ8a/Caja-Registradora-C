
#include<stdio.h>
#include<conio.h>
#include"ususarios.h"

usuarios *raiz=NULL;

 int cantidadUsu()
{
    usuarios *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void insertarUsuario( char nombre[15], char cedula[15])
{
    static int pos = 0;
    pos++;

    if (pos <= cantidadUsu() + 1)
    {
        usuarios *nuevo;
        nuevo=malloc(sizeof(usuarios));
        strcpy(nuevo->nombreUs, nombre);
        strcpy(nuevo->cedulaUs, cedula);
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
            if (pos == cantidadUsu() + 1)
            {
                usuarios *reco = raiz;
                while (reco->sig != NULL)
                {
                    reco = reco->sig;
                }
                reco->sig = nuevo;
                nuevo->ant = reco;
            }
            else
            {
                usuarios *reco = raiz;
                int f;
                for (f = 1; f <= pos - 2; f++)
                    reco = reco->sig;
                usuarios *siguiente = reco->sig;
                reco->sig = nuevo;
                nuevo->ant = reco;
                nuevo->sig = siguiente;
                siguiente->ant = nuevo;
            }
    }
}


void imprimirUsu()
{
    usuarios *reco=raiz;
    printf("LISTA DE USUARIOS.\n");
    while (reco!=NULL)
    {
        printf("%s \n",reco->nombreUs);
        reco=reco->sig;
    }
    printf("\n");
}



