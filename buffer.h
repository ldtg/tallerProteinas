//
// Created by tg on 25/03/17.
//

#ifndef TP1_BUFFER_H
#define TP1_BUFFER_H

#include <stdio.h>

typedef struct {
    void **buffer;
    size_t tam_elemento;
    size_t cantidad_elementos;
}buffer_t;

int buffer_crear(buffer_t *self, size_t tam_elemento);

void buffer_destruir(buffer_t *self);

int buffer_guardar(buffer_t *self, void *dat);

#endif //TP1_BUFFER_H
