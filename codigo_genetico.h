//
// Created by tg on 24/03/17.
//


#ifndef TP1_CODIGO_GENETICO_H
#define TP1_CODIGO_GENETICO_H
#define CANT_AMINOACIDOS 19
#include "codon.h"

typedef enum AMINOACIDO {FENILALANINA, LEUCINA, SERINA, TIROSINA, CISTEINA, TRIPTOFONO, PROLINA, HISTIDINA,
    ACIDO_GLUTAMICO, ISOLEUCINA, METIONINA, TREONINA, ASPARAGINA, LISINA, ARGININA, VALINA,
    ALANINA, ACIDO_ASPARTICO, GLICINA}aminoacido_t;

static char *AMINOACIDO_STRING[] = {
        "Fenilanina", "Leucina", "Serina", "Tirosina", "Cisteína", "Triptófano", "Prolina",
        "Histidina", "Ácido glutámico", "Isoleucina", "Metionina", "Treonina", "Asparagina",
        "Lisina", "Arginina", "Valina", "Alanina", "Ácido aspártico", "Glicina"
};

int codigo_genetico_crear();
int codigo_genetico_destruir();

aminoacido_t codigo_genetico_procesar(codon_t *codon);

#endif //TP1_CODIGO_GENETICO_H
