//
// Created by tg on 28/03/17.
//

#ifndef TP1_AMINOACIDO_H
#define TP1_AMINOACIDO_H
#define MAX_LEN_AMINOACIDO 20
typedef enum AMINOACIDO {FENILALANINA, LEUCINA, SERINA, TIROSINA, CISTEINA, TRIPTOFONO, PROLINA, HISTIDINA,
    ACIDO_GLUTAMICO, ISOLEUCINA, METIONINA, TREONINA, ASPARAGINA, LISINA, ARGININA, VALINA,
    ALANINA, ACIDO_ASPARTICO, GLICINA}aminoacido_e;

typedef struct{
    aminoacido_e aminoacido;
    char str_aminoacido[MAX_LEN_AMINOACIDO];
}aminoacido_t;

int aminoacido_crear(aminoacido_t *self, aminoacido_e aminoacido);
int aminoacido_to_string(aminoacido_t *self, char *dest);
int aminoacido_to_int(aminoacido_t *self);

#endif //TP1_AMINOACIDO_H
