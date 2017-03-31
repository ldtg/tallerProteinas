#ifndef TP1_CODON_H
#define TP1_CODON_H

#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define ERROR 1
#define OK 0

// Tipo codon_t representa a un codon
typedef struct {
  char byte;
  char letras[3];
  bool esAlto;
  bool esInicio;
} codon_t;

// Inicializa self a partir de un byte
// Pre: self apunta un sector válido de memoria
// Post: en caso de exito retorna OK, caso contrario ERROR
int codon_crear_con_byte(codon_t *self, char byte);

// Inicializa self a partir de un string
// Pre: self apunta un sector válido de memoria y letras puntero a string con
// 3 bytes de largo
// Post: en caso de exito retorna OK, caso contrario ERROR
int codon_crear_con_letras(codon_t *self, char *letras);

// Destruye self liberando sus recursos
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int codon_destruir(codon_t *self);

// Retorna un byte que representa univocamente al tipo de codon
// Pre: self inicializado
char codon_get_byte(codon_t *self);

// Retorna true o false dependiendo si el codon representa un alto o no
// Pre: self inicializado
bool codon_es_alto(codon_t *self);

// Retorna true o false dependiendo si el codon es representado por el string
// contenido en letras
// Pre: self inicializado, letras string con 3 letras
bool codon_es_igual(codon_t *self, char *letras);

#endif //TP1_CODON_H
