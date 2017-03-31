//
// Created by tg on 28/03/17.
//

#include <memory.h>
#include "aminoacido.h"

static char *AMINOACIDO_STRING_PRINT[] = {
    "Fenilanina", "Leucina", "Serina", "Tirosina", "Cisteína", "Triptófano",
    "Prolina",
    "Histidina", "Ácido glutámico", "Isoleucina", "Metionina", "Treonina",
    "Asparagina",
    "Lisina", "Arginina", "Valina", "Alanina", "Ácido aspártico", "Glicina"
};
static char *AMINOACIDO_STRING[] = {
    "Fenilanina", "Leucina", "Serina", "Tirosina", "Cisteina", "Triptofano",
    "Prolina",
    "Histidina", "Acido glutamico", "Isoleucina", "Metionina", "Treonina",
    "Asparagina",
    "Lisina", "Arginina", "Valina", "Alanina", "Acido aspartico", "Glicina"
};

int aminoacido_crear(aminoacido_t *self, aminoacido_e aminoacido) {
  self->aminoacido = aminoacido;
  strncpy(self->str_aminoacido,
          AMINOACIDO_STRING[aminoacido],
          MAX_LEN_AMINOACIDO);
  return OK;
}

int aminoacido_destruir(aminoacido_t *self) {
  return OK;
}

int aminoacido_to_string(aminoacido_t *self, char *dest) {
  strncpy(dest, AMINOACIDO_STRING_PRINT[self->aminoacido], MAX_LEN_AMINOACIDO);
  return OK;
}

int aminoacido_comparar(aminoacido_t *self, aminoacido_t *otro) {
  return strncmp(self->str_aminoacido,
                 otro->str_aminoacido,
                 MAX_LEN_AMINOACIDO);
}

int aminoacido_to_int(aminoacido_t *self) {
  return self->aminoacido;
}

aminoacido_e aminoacido_from_int(int i) {
  return (aminoacido_e) i;
}



