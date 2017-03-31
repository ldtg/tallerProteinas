//
// Created by tg on 24/03/17.
//
#include "codon.h"

#define BASE_A 0
#define BASE_U 1
#define BASE_G 2
#define BASE_C 3
#define ALTO_1 "UAA"
#define ALTO_2 "UAG"
#define ALTO_3 "UGA"
#define INICIO "AUG"

// Convierte el byte codificado en letras que representan un codon
static int a_letras(char byte, char *letras);

// Convierte las letras que representan un codon en un byte codificado
static char a_byte(char *letras);

// Retorna la base i codificada en el byte
static char obtener_la_base(char byte, int i);

// Retorna true o false dependiendo si las letras representan un codon de
// alto o no
static bool es_alto(char *letras);

// Retorna true o false dependiendo si las letras representan un codon de
// inicio o no
static bool es_inicio(char *letras);

int codon_crear_con_byte(codon_t *self, char byte) {
  int err;

  self->byte = byte;
  err = a_letras(self->byte, self->letras);
  self->esAlto = es_alto(self->letras);
  self->esInicio = es_inicio(self->letras);

  if (err == ERROR)
    return ERROR;
  return OK;
}

int codon_crear_con_letras(codon_t *self, char *letras) {
  strncpy(self->letras, letras, 3);
  self->byte = a_byte(self->letras);
  self->esAlto = es_alto(self->letras);
  self->esInicio = es_inicio(self->letras);

  if (self->byte < 0)
    return ERROR;
  return OK;
}

int codon_destruir(codon_t *self) {
  return OK;
}

char codon_get_byte(codon_t *self) {
  return self->byte;
}

bool codon_es_alto(codon_t *self) {
  return self->esAlto;
}

bool codon_es_igual(codon_t *self, char *letras) {
  return strncmp(self->letras, letras, 3) == 0;
}

static int a_letras(char byte, char *letras) {
  char aux[3];
  for (int i = 0; i <= 4; i = i + 2) {
    switch (obtener_la_base(byte, i)) {
      case BASE_A: {
        aux[2 - i / 2] = 'A';
        break;
      }
      case BASE_U: {
        aux[2 - i / 2] = 'U';
        break;
      }
      case BASE_G: {
        aux[2 - i / 2] = 'G';
        break;
      }
      case BASE_C: {
        aux[2 - i / 2] = 'C';
        break;
      }
      default: {
        return ERROR;
      }
    }
  }
  strncpy(letras, aux, 3);
  return OK;
}

static char obtener_la_base(char byte, int i) {
  return (char) (byte & (3 << i)) >> i;
}

static char a_byte(char *letras) {
  char aux = 0;
  for (int i = 2; i >= 0; i--) {
    switch (letras[i]) {
      case 'A': {
        aux = aux + (char) (BASE_A << (-2 * i + 4));
        break;
      }
      case 'U': {
        aux = aux + (char) (BASE_U << (-2 * i + 4));
        break;
      }
      case 'G': {
        aux = aux + (char) (BASE_G << (-2 * i + 4));
        break;
      }
      case 'C': {
        aux = aux + (char) (BASE_C << (-2 * i + 4));
        break;
      }
      default: {
        return -1;
      }
    }
  }
  return aux;
}

static bool es_alto(char *letras) {
  return (strncmp(letras, ALTO_1, 3) == 0) || (strncmp(letras, ALTO_2, 3) == 0)
      || (strncmp(letras, ALTO_3, 3) == 0);
}

static bool es_inicio(char *letras) {
  return (strncmp(letras, INICIO, 3) == 0);
}
