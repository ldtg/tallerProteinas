#ifndef TP1_CODIGO_GENETICO_H
#define TP1_CODIGO_GENETICO_H

#include "codon.h"
#include "aminoacido.h"
//Libreria para procesar codones y transformarlos en aminoacidos

// Retorna el aminoacido correspondiente al codon
// Pre: codon inicializado, salida apunta a un aminoacido_t NO inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int codigo_genetico_procesar(codon_t *codon, aminoacido_t *salida);

#endif //TP1_CODIGO_GENETICO_H
