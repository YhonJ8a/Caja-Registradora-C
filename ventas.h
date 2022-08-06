/**
#include"ususarios.h"
#include"productos.h"


typedef struct {
    int codigoVenta;
    char fecha[11];
    struct usuarios *clien;
    struct ventas *productos;
    struct ventas *sig;
    struct ventas *ant;
}ventas;


int cantidadven();
void insertarVenta( usuarios *cliente , char fechaV[11], nodo *products );
void imprimirventas();
*/

