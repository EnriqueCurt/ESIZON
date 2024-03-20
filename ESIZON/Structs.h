#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct{
    char id_cliente[8];
    char nombre[21];
    char direccion[51];
    char localidad[21];
    char provincia[21];
    char email[31];
    char password[16];
    int cartera;
} clientes;

typedef struct{
    char id_transp[5];
    char nombre[21];
    char email[31];
    char password[16];
    char empresa[21];
    char ciudad[21];
} transportistas;

typedef struct{
    char id_prod[8];
    char nombre[15];
    char descrip[51];
    char id_categ[5];
    char id_gestor[5];
    int stock;
    int entrega;
    int importe;
} productos;

typedef struct{
    char id_categ[5];
    char descrip[51];
} categorias;

typedef struct{
    char id_cod[11];
    char descrip[51];
    char tipo[8];
    char estado[9];
    int importe;
    char aplicable[8];
} descuentos;

typedef struct{
    char id_cliente[8];
    char id_cod[11];
    char fecha_asignacion[11];
    char fecha_caducidad[11];
    int estado;
} descuentos_clientes;

typedef struct{
    char id_locker[11];
    char localidad[21];
    char provincia[21];
    char ubicacion[21];
    int num_compT;
    int num_compOcup;
} lockers;

typedef struct{
    char id_locker[11];
    int num_comp;
    char cod_locker[11];
    char estado[8];
    char fecha_ocupacion[11];
    char fecha_caducidad[11];
} compartimentos_lockers;

typedef struct{
    char id_empresa[5];
    char nombre[21];
    char email[31];
    char password[16];
    char perfil_usuario[14];
} admin_prov;

typedef struct{
    char id_pedido[8];
    char fecha_pedido[11];
    char id_cliente[8];
    char lugar[9];
    char id_locker[11];
    char id_cod[11];
} pedidos;

typedef struct{
    char id_pedido[8];
    char id_prod[8];
    char fecha_devolucion[11];
    char motivo[51];
    char estado[11];
    char fecha_aceptacion[11];
    char fecha_caducidad[11]; 
} devoluciones;

typedef struct{
    char id_pedido[8];
    char id_prod[8];
    int num_unid;
    char fecha_entrega[11];
    int importe;
    char estado[15];
    char id_transp[5];
    char id_locker[11];
    char cod_locker[11];
    char fecha_entrega_devolucion[11];
} productos_pedidos;

#endif 