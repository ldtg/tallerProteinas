//
// Created by tg on 24/03/17.
//

#include <sys/socket.h>
#include "cliente.h"
#include "codon.h"

#define OK 0
#define ERROR 1
int cliente_crear(cliente_t *self, FILE *file, char *host, char *service) {
    int err_create = ERROR;
    int err_connect = ERROR;

    self->host = host;
    self->service = service;
    strncpy(self->respuesta,"",MAX_LEN_RESPUESTA);

    if(file == NULL)
        return ERROR;
    self->in_file = file;

    err_create = socket_create(&(self->socket));
    if(err_create == ERROR)
        return ERROR;

    err_connect = socket_connect(&(self->socket), host, service);
    if(err_connect == ERROR)
        return ERROR;

    return OK;
}

int cliente_destruir(cliente_t *self) {
    int err_s, err_d;
    err_s = socket_shutdown(&self->socket, SHUT_RDWR);
    err_d = socket_destroy(&self->socket);
    if(err_s != OK|| err_d != OK)
        return ERROR;
    return OK;
}

int cliente_enviar_datos(cliente_t *self) {
    char buff[BUFF_LEN];
    int f_read = 1;
    int bytes_send = 1;
    int bytes_read = 0;
    codon_t codon[BUFF_LEN/3];
    char codon_str[3];
    unsigned char bytes_to_send[BUFF_LEN/3];

    while(f_read > 0 || f_read > 0){
        f_read = fread(buff, BUFF_LEN, 1, self->in_file); /////////ERROR
        if(f_read <= 0)
            bytes_read = strnlen(buff,BUFF_LEN) - 1;
        else
            bytes_read = f_read;

        for(int i = 0; i <= bytes_read/3; i++){
            strncpy(codon_str, buff + 3*i, 3);
            codon_crear_con_letras(&(codon[i]),codon_str);
            bytes_to_send[i] = codon_get_byte(&codon[i]);
        }
        bytes_send = socket_send(&(self->socket), bytes_to_send, bytes_read);
    }

    if(ferror(self->in_file) || bytes_send != BUFF_LEN)
        return ERROR;

    socket_shutdown(&(self->socket), SHUT_WR);
    return OK;
}

int cliente_recibir_datos(cliente_t *self){
    char respuesta[MAX_LEN_RESPUESTA];
    int rcv_status;

    rcv_status = socket_receive(&self->socket, respuesta, MAX_LEN_RESPUESTA);

    if(rcv_status == 0)
        strncpy(self->respuesta,respuesta,MAX_LEN_RESPUESTA);
    else
        return ERROR;
    return OK;
}

void cliente_imprimir_mensaje(cliente_t *self) {
    fputs(self->respuesta,stdout);
}

