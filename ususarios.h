void insertarUsuario( char nombre[15], char cedula[15]);
void imprimirUsu();
int cantidadUsu();
typedef struct{
    char nombreUs[15];
    char cedulaUs[15];
    struct usuarios *sig;
    struct usuarios *ant;
}usuarios;


