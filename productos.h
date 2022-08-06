typedef struct{
    int codigo;
    char nombre[15];
    int cantidad;
    float precio;
    struct nodo *sig;
    struct nodo *ant;
} nodo;

void liberar();
int vacia();
int cantidadpro();
void imprimir();
void insertarpro( char nombrep[15], int cantidadp, float preciop );
int extraer(int pos);
void borrar(int pos);
int ordenada();
int existe(int x);
int descontarProducto(int x, int cant);
int codNombre(char nom[15]);
