#include<stdio.h>
#include<conio.h>
#include"productos.h"

nodo *raiz=NULL;


void liberar()
{
    nodo *reco = raiz;
    nodo *bor;
    while (reco != NULL)
    {
        bor = reco;
        reco = reco->sig;
        free(bor);
    }
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

int cantidadpro()
{
    nodo *reco = raiz;
    int cant = 0;
    while (reco != NULL)
    {
        cant++;
        reco = reco->sig;
    }
    return cant;
}

void imprimir()
{
    nodo *reco=raiz;
    while (reco!=NULL)
    {
        printf("\n\n*********************************\n");
        printf("<<<<<<<<<<  %s  >>>>>>>>>>>\n",reco->nombre);
        printf("\t codigo : %i \n",reco->codigo);
        printf("\t precio : %f \n",reco->precio);
        printf("\n\n");
        reco=reco->sig;
    }
    printf("\n");
}


void insertarpro( char nombrep[15], int cantidadp, float preciop )
{
    static int x = 0;
    x++;
    int pos = cantidadpro()+1;
    if(!existe(x)){
        if (pos <= cantidadpro() + 1)
        {
            nodo *nuevo;
            nuevo=malloc(sizeof(nodo));
            nuevo->codigo = x;
            strcpy(nuevo->nombre, nombrep);
            nuevo->cantidad = cantidadp;
            nuevo->precio = preciop;
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
            {
                if (pos == cantidadpro() + 1)
                {
                    nodo *reco = raiz;
                    while (reco->sig != NULL)
                    {
                        reco = reco->sig;
                    }
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                }
                else
                {
                    nodo *reco = raiz;
                    int f;
                    for (f = 1; f <= pos - 2; f++)
                        reco = reco->sig;
                    nodo *siguiente = reco->sig;
                    reco->sig = nuevo;
                    nuevo->ant = reco;
                    nuevo->sig = siguiente;
                    siguiente->ant = nuevo;
                }
            }
        }
    }
}

int extraer(int pos)
{
    if (pos <= cantidadpro())
    {
        int informacion;
        nodo *bor;
        if (pos == 1)
        {
            informacion = raiz->codigo;
            bor = raiz;
            raiz = raiz->sig;
            if ((raiz != NULL))
                raiz->ant = NULL;
        }
        else
        {
            nodo *reco;
            reco = raiz;
            int f;
            for (f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            nodo *prox = reco->sig;
            bor = prox;
            reco->sig = prox->sig;
            nodo *siguiente = prox->sig;
            if (siguiente != NULL)
                siguiente->ant = reco;
            informacion = prox->codigo;
        }
        free(bor);
        return informacion;
    }
    else
        return -1;
}

void borrar(int pos)
{
    if (pos <= cantidadpro())
    {
        nodo *bor;
        if (pos == 1)
        {
            bor = raiz;
            raiz = raiz->sig;
            if (raiz != NULL)
                raiz->ant = NULL;
        }
        else
        {
            nodo *reco;
            reco = raiz;
            int f;
            for (f = 1; f <= pos - 2; f++)
                reco = reco->sig;
            nodo *prox = reco->sig;
            bor = prox;
            reco->sig = prox->sig;
            nodo *siguiente = prox->sig;
            if (siguiente != NULL)
                siguiente->ant = reco;
        }
        free(bor);
    }
}

int ordenada()
{
    if (cantidadpro()>1)
    {
         nodo *reco1 = raiz;
         nodo *reco2 = raiz->sig;
        while (reco2 != NULL)
        {
            if (reco2->codigo<reco1->codigo     )
            {
                return 0;
            }
            reco2 = reco2->sig;
            reco1 = reco1->sig;
        }
    }
    return 1;
}

int existe(int x)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
            return 1;
        reco = reco->sig;
    }
    return 0;
}



int descontarProducto(int x, int cant)
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (reco->codigo == x)
        {
            if(reco->cantidad >= cant)
            {
                reco->cantidad -= cant;
                return 1;
            }else
                return 0;
        }
        reco = reco->sig;
    }
    return 0;
}



int codNombre(char nom[15])
{
     nodo *reco = raiz;
    while (reco != NULL)
    {
        if (strcmp(reco->nombre, nom)== 0)
            return reco->codigo;
        else
            reco = reco->sig;
    }
    return 0;
}
