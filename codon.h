//
// Created by tg on 24/03/17.
//

#ifndef TP1_CODON_H
#define TP1_CODON_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct{
    unsigned char byte;
    char letras[3];
    bool esAlto;
    bool esInicio;
}codon_t;

//
//
int codon_crear_con_byte(codon_t *self, unsigned char byte);
//
//
int codon_crear_con_letras(codon_t *self,char *letras);
//
//
int codon_destruir(codon_t *self);
//
//
unsigned char codon_get_byte(codon_t *self);

//
//
bool codon_es_alto(codon_t *self);

//
//
bool codon_es_igual(codon_t *self,char* letras);
#endif //TP1_CODON_H
