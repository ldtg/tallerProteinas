#ifndef TP1_SOCKET_H
#define TP1_SOCKET_H

#include <stdio.h>

#define ERROR 1
#define OK 0
#define MAX_CLI_ESPERA 2
#define SHUTRD 0          /*Definidas para que se puedan utilizar las*/
#define SHUTWR 1         /*constantes necesarias en socket_shutdown y no*/
#define SHUTRDWR 2      /*incluir sys/socket.h para los usuarios del TDA*/

// Tipo socket_t representa un socket
typedef struct {
  int socket;
} socket_t;

// Inicializa self
// Pre: self apunta un sector válido de memoria
// Post: en caso de exito retorna OK, caso contrario ERROR
int socket_create(socket_t *self);

// Destruye self y libera sus recursos
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int socket_destroy(socket_t *self);

// Conecta self con el host y el servicio dado
// Pre: self inicializado, host y service validos
// Post: en caso de exito retorna OK, caso contrario ERROR y imprime el tipo
// de error por stdout
int socket_connect(socket_t *self, const char *host, const char *service);

// Bindea self en port y pone el estado del socket en listen
// Pre: self inicializado, port valido
// Post: en caso de exito retorna OK, caso contrario ERROR y imprime el tipo
// de error por stdout
int socket_bindandlisten(socket_t *self, const char *port);

// Acepta una coneccion entrante por self y devuelve el socket
// correspondiente a esa coneccion en new_socket. Si no hay conecciones
// entrantes espera hasta que haya alguna.
// Pre: self inicializado, y previamente utilizado en socket_bindandlisten
// Post: en caso de exito retorna OK, caso contrario ERROR y imprime el tipo
// de error por stdout
int socket_accept(socket_t *self, socket_t *new_socket);

// Cierra la coneccion del socket del modo indicado por HOW
// Pre: self inicializado, how puede ser SHUTRD, SHUTRDWR, SHUTWR
// Post: en caso de exito retorna OK, caso contrario ERROR
int socket_shutdown(socket_t *self, int how);

// Envia a traves del socket data_len bytes a partir de la posicion apuntada
// por data
// Pre: self inicializado y conectado, ya sea con socket_connect o por ser el
// new_socket de un socket_accept. data puntero a memoria valido con permisos
// de lectura de al menos data_len bytes.
// Post: en caso de exito retorna OK, caso contrario ERROR y imprime el tipo
// de error por stdout
int socket_send(socket_t *self, void *data, size_t data_len);

// Recibe a traves del socket data_len bytes en la posicion apuntada
// por data
// Pre: self inicializado y conectado, ya sea con socket_connect o por ser el
// new_socket de un socket_accept. data puntero a memoria valido con permisos
// de lectura de al menos data_len bytes.
// Post: en caso de exito retorna OK, caso contrario ERROR y imprime el tipo
// de error por stdout
int socket_receive(socket_t *self, void *data, size_t data_len);

#endif //TP1_SOCKET_H
