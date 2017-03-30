//
// Created by tg on 24/03/17.
//

#ifndef TP1_SERVIDOR_H
#define TP1_SERVIDOR_H

#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "codigo_genetico.h"
#include "socket.h"

#define BUFF_RECV_LEN 20
#define MAX_LEN_RESPUESTA 255
#define OK 0
#define ERROR 1

typedef struct{
    aminoacido_t aminoacido;
    size_t cantidad_contados;
}contador_aminoacidos_t;

typedef struct{
    contador_aminoacidos_t contador_aminoacidos[CANT_AMINOACIDOS];
    size_t cantidad_proteinas;
    char respuesta[MAX_LEN_RESPUESTA];
    socket_t socket_recibidor;
    socket_t socket_aceptador;
}servidor_t;

int servidor_crear(servidor_t *self,const char *port);
int servidor_destruir(servidor_t *self);
int servidor_recibir_datos(servidor_t *self);
int servidor_procesar(servidor_t *self);
int servidor_enviar_mensaje(servidor_t *self);

#endif //TP1_SERVIDOR_H
