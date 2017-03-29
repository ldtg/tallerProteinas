//
// Created by tg on 28/03/17.
//

#include <memory.h>
#include "aminoacido.h"
#define OK 0
#define ERROR 1

static char *AMINOACIDO_STRING[] = {
        "Fenilanina", "Leucina", "Serina", "Tirosina", "Cisteína", "Triptófano", "Prolina",
        "Histidina", "Ácido glutámico", "Isoleucina", "Metionina", "Treonina", "Asparagina",
        "Lisina", "Arginina", "Valina", "Alanina", "Ácido aspártico", "Glicina"
};

int aminoacido_crear(aminoacido_t *self, aminoacido_e aminoacido) {
    self->aminoacido = aminoacido;
    strncpy(self->str_aminoacido,AMINOACIDO_STRING[aminoacido],MAX_LEN_AMINOACIDO);
    return OK;
}

int aminoacido_to_string(aminoacido_t *self, char *dest) {
    strncpy(dest,self->str_aminoacido,MAX_LEN_AMINOACIDO);
    return OK;
}

int aminoacido_to_int(aminoacido_t *self) {
    return self->aminoacido;
}

