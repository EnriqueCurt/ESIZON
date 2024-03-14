//Fichero Clientes. txt, almacenará la información de los clientes del sistema con los siguientes campos, separados por guiones: o Identificador del cliente (Id_cliente), 7 dígitos. o Nombre completo del cliente (Nomb_cliente), 20 caracteres máximo. o Dirección del cliente (Dir_cliente), 50 caracteres máximo. o Población (Localidad), 20 caracteres máximo. o Provincia (Provincia), 20 caracteres máximo. o Email (email), 30 caracteres máximo, será usado como nombre de usuario para el acceso a la plataforma. o Contraseña para acceder al sistema (Contraseña), con 15 caracteres máximo. o Cartera (Cartera), almacenará el dinero del que dispone el cliente para poder adquirir los productos.
//Fichero Transportistas.txt, almacenará la información de los repartidores de pedidos, con los siguientes campos separados con guiones: o Identificador del transportista (Id_transp), 4 dígitos. o Nombre del transportista (Nombre), 20 caracteres máximo. o Email (email), 30 caracteres máximo, será usado como nombre de usuario para el acceso a la plataforma. o Contraseña para acceder al sistema (Contraseña), con 15 caracteres máximo. o Nombre de la empresa (Nombre), 20 caracteres máximo. o Ciudad de reparto (Ciudad), 20 caracteres máximo.
//Fichero Devoluciones.txt, almacenará la información de las devoluciones de los distintos productos incluidos en los pedidos entregados. Los campos, separados por guiones, son los que se describen a continuación:Identificador del pedido (Id_pedido), 7 dígitos. o Identificador del producto (Id_prod), 7 dígitos. o Fecha de devolución (día, mes y año). o Motivo (Motivo), 50 caracteres máximo. o Estado(Estado): «pendiente» (de aceptación), «aceptado», «denegado», «enviado» (por cliente) o «recibido». o Fecha aceptación (día, mes y año). o Fecha caducidad (día, mes y año).
//Fichero AdminProv.tx, almacenará la información de los administradores y proveedores de productos de ESIZON. Los campos, separados por guiones, son los que se describen a continuación: o Identificador de la empresa administradora o proveedora (Id_empresa), 4 dígitos. o Nombre de la empresa (Nombre), sería ESIZON si es administrador, 20 caracteres máximo. o Email (email), 30 caracteres máximo, será usado como nombre de usuario para el acceso a la plataforma. o Contraseña para acceder al sistema (Contraseña), con 15 caracteres máximo. o Perfil del usuario (Perfil_usuario): «administrador» o «proveedor».
//Fichero Productos.txt, almacenará la información de todos los productos que se pueden adquirir desde la plataforma, con los siguientes campos separados por guiones: o Identificador del producto (Id_prod), 7 dígitos. o Descripción del producto (Descrip), 50 caracteres máximo. o Id de la categoría a la que pertenece (Id_categ), 4 dígitos. o Id del gestor del producto (Id_gestor), 4 digítos. Deberá coincidir con el identificador de la empresa administradora o proveedora del producto. o Stock del producto (Stock). o Compromiso de Entrega (Entrega). Indicará el número de días máximo que transcurrirá desde la fecha de realización del pedido hasta la entrega al cliente. o Importe del producto en euros (Importe).
//Fichero Categorías.txt, almacenará la información de todas las categorías de productos que pueden adquirirse en la plataforma, con los siguientes campos separados por guiones: o Identificador de la categoría (Id_categ), 4 dígitos. o Descripción de la categoría (Descrip), 50 caracteres máximo.
//Fichero Descuentos.txt, almacenará la información de los distintos códigos promocionales de descuentos y cheques regalo a emplear en la compra de productos. Los campos, separados por guiones, son los que se describen a continuación: o Identificador del código promocional o cheque regalo (Id_cod), 10 caracteres máximo. o Descripción del descuento (Descrip), 50 caracteres máximo. o Tipo de descuento (Tipo): «codpro» (código promocional) o «cheqreg» (cheque regalo) o Estado (Estado): «activo» o «inactivo» o Importe del descuento en euros (Importe) Aplicabilidad (Aplicable): «todos» (si es aplicable a todos los productos) o «esizon» (si sólo es aplicable a los gestionados por ESIZON.
//Fichero DescuentosClientes.txt, almacenará la información de los distintos códigos promocionales de descuentos y cheques regalo de cada cliente registrado en la plataforma. Los campos, separados por guiones, son los que se describen a continuación: o Identificador del cliente (Id_cliente), 7 dígitos. o Identificador del código promocional o cheque regalo (Id_cod), 10 caracteres máximo. o Fecha de asignación (día, mes y año) o Fecha de caducidad (día, mes y año) o Estado (Estado): 1 (Aplicado) ó 0 (No aplicado)
//Fichero Lockers.txt, almacenará la información de los distintos respositorios utilizados por la plataforma para las entregas de los pedidos, con los siguientes campos separados por guiones: o Identificador del Locker (Id_locker), 10 caracteres máximo. o Población (Localidad), 20 caracteres máximo. o Provincia (Provincia), 20 caracteres máximo. o Ubicación (Ubica), 20 caracteres máximo. o Número de compartimentos total (Num_compT). o Número de compartimentos ocupados actualmente (Num_compOcup).
//Fichero CompartimentosLockers.txt, almacenará la información de los distintos productos depositados en cada compartimento y el código locker asociado al producto, con los siguientes campos separados por guiones: o Identificador del locker (Id_locker), 10 caracteres máximo. o Número de compartimento (Num_comp). o Código del locker (Cod_locker). o Estado: «ocupado» o «vacío» o Fecha ocupación (día, mes y año). o Fecha caducidad (día, mes y año).
//Fichero Pedidos.txt, almacenará la información de los distintos pedidos realizados por los clientes registrados en la plataforma, con los siguientes campos separados por guiones: o Identificador del pedido (Id_pedido), 7 dígitos. o Fecha del pedido (día, mes y año) o Identificador del cliente que realiza el pedido (Id_cliente), 7 dígitos. o Lugar de entrega (Lugar): «domicilio» o «locker» o Identificador de Locker (Id_locker), 10 caracteres máximo. o Identificador del código promocional o cheque regalo (Id_cod), 10 caracteres máximo.
//Fichero ProductosPedidos.txt, almacenará la información de todos los productos incluidos en los diferentes pedidos realizados. Los campos, separados por guiones, son los que se describen a continuación: o Identificador del pedido (Id_pedido), 7 dígitos. o Identificador del producto (Id_prod), 7 dígitos. o Número de unidades (Num_unid) o Fecha prevista de entrega (día, mes y año). Importe del producto en euros (Importe). Importante que quede constancia del importe al que compra un cliente un producto si la empresa modifica posteriormente su importe. o Estado del pedido: «enPreparación», «enviado», «enReparto», «enLocker», «entregado», «devuelto» o «transportista». o Identificador del transportista (Id_transp), 4 dígitos. o Identificador del locker (Id_locker), 10 caracteres máximo. o Código del locker (Cod_locker). o Fecha de entrega/devolución por el transportista
#ifndef STRUCTS_H
#define STRUCTS_H
//hazme un struct para cada uno de los ficheros
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
    char perfil_usuario[13];
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
#endif /* STRUCTS_H */