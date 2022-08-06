1
typedef struct{
    int codPedido;
    int codProducto;
    int codUsuario;
    struct pedido *sig;
    struct pedido *ant;
}pedido[50];
