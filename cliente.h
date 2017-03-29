//
// Created by tg on 24/03/17.
//

#ifndef TP1_CLIENTE_H
#define TP1_CLIENTE_H

#include <stdio.h>
#include "socket.h"
#define BUFF_LEN 60
#define MAX_LEN_RESPUESTA 255

typedef struct{
    FILE *in_file;
    char *host;
    char *service;
    socket_t socket;
    char respuesta[MAX_LEN_RESPUESTA];
}cliente_t;

int cliente_crear(cliente_t *self, FILE *file, char *host, char *service);
int cliente_destruir(cliente_t *self);
int cliente_enviar_datos(cliente_t *self);
int cliente_recibir_datos(cliente_t *self);
void cliente_imprimir_mensaje(cliente_t *self);
#endif //TP1_CLIENTE_H
