#ifndef TP1_CLIENTE_H
#define TP1_CLIENTE_H

#include <stdio.h>
#include "socket.h"

#define BUFF_SEND_LEN 20 // read/3
#define BUFF_READ_LEN 60
#define MAX_LEN_RESPUESTA 255
#define OK 0
#define ERROR 1

// Tipo cliente_t representa a un cliente
typedef struct {
  FILE *in_file;
  char *host;
  char *service;
  socket_t socket;
  char respuesta[MAX_LEN_RESPUESTA];
} cliente_t;

// Inicializa self con el archivo, host y servicio dado
// Pre: self apunta un sector válido de memoria,
// file es un archivo válido inicializado para lectura
// service puntero a un string valido
// Post: en caso de exito retorna OK, caso contrario ERROR
int cliente_crear(cliente_t *self, FILE *file, char *host, char *service);

// Destruye self liberando sus recursos
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int cliente_destruir(cliente_t *self);

// Envia los datos al servidor
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int cliente_enviar_datos(cliente_t *self);

// Recibe los datos del servidor
// Pre: self inicializado y previamente se enviaron los datos con
// cliente_enviar_datos
// Post: en caso de exito retorna OK, caso contrario ERROR
int cliente_recibir_datos(cliente_t *self);

// Imprime por stdout el mensaje recibido
// Pre: self inicializado y previamente se recibieron los datos con
// cliente_recibir_datos
void cliente_imprimir_mensaje(cliente_t *self);

#endif //TP1_CLIENTE_H
