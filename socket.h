//
// Created by tg on 24/03/17.
//

#ifndef TP1_SOCKET_H
#define TP1_SOCKET_H
#include <stdio.h>
#include "buffer.h"
typedef struct{
    int socket;
}socket_t;

int socket_create(socket_t *self);
int socket_destroy(socket_t *self);
int socket_connect(socket_t *self, const char *host, const char *service);
int socket_bindandlisten(socket_t *self, unsigned short port);
int socket_accept(socket_t *self, socket_t *new_socket);
int socket_shutdown(socket_t *self, int how);
int socket_send(socket_t *self,void *data, size_t data_len);
int socket_receive(socket_t *self,void *data, size_t data_len);
int socket_receive_until_close(socket_t *self,buffer_t buffer);
#endif //TP1_SOCKET_H
