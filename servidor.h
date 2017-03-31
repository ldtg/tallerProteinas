//
// Created by tg on 24/03/17.
//

#ifndef TP1_SERVIDOR_H
#define TP1_SERVIDOR_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "codigo_genetico.h"
#include "socket.h"

#define BUFF_RECV_LEN 20
#define MAX_LEN_RESPUESTA 255
#define OK 0
#define ERROR 1

// Pertenece a servidor_t
typedef struct {
  aminoacido_t aminoacido;
  size_t cantidad_contados;
} contador_aminoacidos_t;

// Tipo servidor_t representa al servidor
typedef struct {
  contador_aminoacidos_t contador_aminoacidos[CANT_AMINOACIDOS];
  size_t cantidad_proteinas;
  char respuesta[MAX_LEN_RESPUESTA];
  socket_t socket_recibidor;
  socket_t socket_aceptador;
} servidor_t;

// Inicializa self con el puerto dado
// Pre: self apunta un sector válido de memoria,
// port puntero a un string valido
// Post: en caso de exito retorna OK, caso contrario ERROR
int servidor_crear(servidor_t *self, const char *port);

// Destruye self liberando sus recursos
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int servidor_destruir(servidor_t *self);

// Recibe los datos enviados por un cliente, si no hay clientes conectados
// espera hasta que se conecte alguno
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int servidor_recibir_datos(servidor_t *self);

// Procesa los datos enviados por un cliente
// Pre: self inicializado, datos recibidos con servidor_recibir_datos
// Post: en caso de exito retorna OK, caso contrario ERROR
int servidor_procesar(servidor_t *self);

// Envia el mensaje al cliente
// Pre: self inicializado, datos procesados con servidor_procesar
// Post: en caso de exito retorna OK, caso contrario ERROR
int servidor_enviar_mensaje(servidor_t *self);

#endif //TP1_SERVIDOR_H
