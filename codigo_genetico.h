//
// Created by tg on 24/03/17.
//


#ifndef TP1_CODIGO_GENETICO_H
#define TP1_CODIGO_GENETICO_H
#define CANT_AMINOACIDOS 19
#include "codon.h"
#include "aminoacido.h"

int codigo_genetico_crear();
int codigo_genetico_destruir();

int codigo_genetico_procesar(codon_t *codon, aminoacido_t *salida);

#endif //TP1_CODIGO_GENETICO_H
