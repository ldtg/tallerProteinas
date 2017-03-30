//
// Created by tg on 24/03/17.
//
#define _POSIX_C_SOURCE 200112L

#include "socket.h"
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>


static int generar_result_cliente(struct addrinfo **result, const char *host, const char *service);
static int generar_result_server(struct addrinfo **ptr, const char *port);
static int conectar_socket(int socket, struct addrinfo *ptr);
static int crear_socket(int *file_descriptor, struct addrinfo *ptr);
static int bind_socket(int file_descriptor, struct addrinfo *ptr);
static int listen_socket(int socket);


int socket_create(socket_t *self) {
    self->socket = -1;//0 es un fd valido
    return OK;
}

int socket_destroy(socket_t *self){
    int err = OK;

    if(self->socket >= 0) //Se inicializa en -1 en create
        err = close(self->socket);
    if(err != OK)
        return ERROR;

    return OK;
}

int socket_connect(socket_t *self, const char *host, const char *service){
    bool se_conecto=false;
    struct addrinfo *result = NULL;
    struct addrinfo *ptr = NULL;
    
    if(generar_result_cliente(&result, host, service) == ERROR)
        return ERROR;

    for (ptr = result; ptr != NULL && se_conecto == false; ptr = ptr->ai_next) {
        if(crear_socket(&(self->socket),ptr) == ERROR)
            return ERROR;
        else if(conectar_socket(self->socket, ptr) == OK)
            se_conecto = true;
    }

    freeaddrinfo(result);

    if(!se_conecto)
        return ERROR;
    return OK;
}

int socket_bindandlisten(socket_t *self, const char *port) {
    struct addrinfo *ptr;

    if(generar_result_server(&ptr, port) == ERROR)
        return ERROR;

    if(crear_socket(&(self->socket),ptr) == ERROR)
        return ERROR;

    if(bind_socket(self->socket,ptr) == ERROR)
        return ERROR;

    freeaddrinfo(ptr);

    if(listen_socket(self->socket) == ERROR)
        return ERROR;

    return OK;
}

int socket_shutdown(socket_t *self,int how) {
    return shutdown(self->socket, how);
}

int socket_accept(socket_t *self, socket_t *new_socket) {
    new_socket->socket = accept(self->socket,NULL,NULL);

    if (new_socket->socket == -1) {
        printf("Error accept: %s\n", strerror(errno));
        return ERROR;
    }
    return OK;
}

size_t socket_send(socket_t *self, void *data, size_t data_len) {
    size_t bytes_eviados=0;
    int s=-1;

    while (bytes_eviados < data_len) {
        s = send(self->socket, (char *)data + bytes_eviados, data_len - bytes_eviados, MSG_NOSIGNAL);

        if (s < 0) {
            printf("Error send: %s\n", strerror(errno));
            return s;
        } else if (s == 0)
            return 0;
        else
            bytes_eviados += s;
    }
    return bytes_eviados;
}

size_t socket_receive(socket_t *self, void *data, size_t data_len) {
    size_t bytes_recibidos = 0;
    int s=0;

    while (bytes_recibidos < data_len) {
        s = recv(self->socket, (char *)data + bytes_recibidos, data_len - bytes_recibidos, MSG_NOSIGNAL);

        if (s <= 0)
            return s;
        else
            bytes_recibidos += s;
    }

    return bytes_recibidos;
}

static int generar_result_cliente(struct addrinfo **result, const char *host, const char *service){
    int s = ERROR;
    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));//Inicializa 0 la estructura
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    s = getaddrinfo(host, service, &hints, result);

    if (s != OK) {
        printf("Error en getaddrinfo: %s\n", gai_strerror(s));
        return ERROR;
    }
    return OK;
}


static int conectar_socket(int socket,struct addrinfo *ptr){
    int s=-1;
    s=connect(socket, ptr->ai_addr, ptr->ai_addrlen);
    if (s == -1) {
        printf("Error en connect: %s\n", strerror(errno));
        close(socket);
        return ERROR;
    }
    return OK;
}


static int crear_socket(int *file_descriptor,struct addrinfo *ptr){
    int enable = 1;
    
    *file_descriptor = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol);

    if (*file_descriptor == -1) {
        printf("Error en crear: %s\n", strerror(errno));
        freeaddrinfo(ptr);
        return ERROR;
    }
    
    if (setsockopt(*file_descriptor, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0) {
        printf("Error en setscokopt: %s\n", strerror(errno));
        close(*file_descriptor);
        freeaddrinfo(ptr);
        return ERROR;
    }

    return OK;
}

static int generar_result_server(struct addrinfo **ptr, const char *port){
    struct addrinfo hints;
    int s;
    memset(&hints, 0, sizeof(struct addrinfo));//Inicializa 0 la estructura

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    s = getaddrinfo(NULL, port, &hints, ptr);//NULL porque es en la maquina local

    if (s != OK) {
        printf("Error en getaddrinfo: %s\n", gai_strerror(s));
        return ERROR;
    }
    return OK;
}

static int bind_socket(int file_descriptor,struct addrinfo *ptr){
    int s=-1;

    s = bind(file_descriptor, ptr->ai_addr, ptr->ai_addrlen);
    if (s == -1) {
        printf("Error bind: %s\n", strerror(errno));
        close(file_descriptor);
        freeaddrinfo(ptr);
        return ERROR;
    }
    return OK;

}

static int listen_socket(int socket){
    int s = -1;
    s = listen(socket, MAX_CLI_ESPERA);
    if (s == -1) {
        printf("Error listen: %s\n", strerror(errno));
        close(socket);
        return ERROR;
    }
    return OK;
}
