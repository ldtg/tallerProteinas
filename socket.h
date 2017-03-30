//
// Created by tg on 24/03/17.
//

#ifndef TP1_SOCKET_H
#define TP1_SOCKET_H
#include <stdio.h>

#define ERROR 1
#define OK 0
#define MAX_CLI_ESPERA 2
typedef struct{
    int socket;
}socket_t;

int socket_create(socket_t *self);
int socket_destroy(socket_t *self);
int socket_connect(socket_t *self, const char *host, const char *service);
int socket_bindandlisten(socket_t *self, const char *port);
int socket_accept(socket_t *self, socket_t *new_socket);
int socket_shutdown(socket_t *self, int how);
size_t socket_send(socket_t *self, void *data, size_t data_len);
size_t socket_receive(socket_t *self, void *data, size_t data_len);
#endif //TP1_SOCKET_H
