//
// Created by tg on 24/03/17.
//

#include "codigo_genetico.h"
#define ERROR 1
#define OK 0

static bool es_fenilanina(codon_t *codon);
static bool es_leucina(codon_t *codon);
static bool es_serina(codon_t *codon);
static bool es_tirosina(codon_t *codon);
static bool es_cisteina(codon_t *codon);
static bool es_triptofano(codon_t *codon);
static bool es_prolina(codon_t *codon);
static bool es_histidina(codon_t *codon);
static bool es_glutamico(codon_t *codon);
static bool es_isoleucina(codon_t *codon);
static bool es_metionina(codon_t *codon);
static bool es_treonina(codon_t *codon);
static bool es_asparagina(codon_t *codon);
static bool es_lisina(codon_t *codon);
static bool es_arginina(codon_t *codon);
static bool es_valina(codon_t *codon);
static bool es_alanina(codon_t *codon);
static bool es_aspartico(codon_t *codon);
static bool es_glicina(codon_t *codon);

int codigo_genetico_crear(){
    return OK;
}
int codigo_genetico_destruir(){
    return OK;
}


int codigo_genetico_procesar(codon_t *codon, aminoacido_t *salida){

    int err = ERROR;
    if(es_fenilanina(codon))
        err = aminoacido_crear(salida, FENILALANINA);
    else if(es_leucina(codon))
        err = aminoacido_crear(salida, LEUCINA);
    else if(es_serina(codon))
        err = aminoacido_crear(salida, SERINA);
    else if(es_tirosina(codon))
        err = aminoacido_crear(salida, TIROSINA);
    else if(es_cisteina(codon))
        err = aminoacido_crear(salida, CISTEINA);
    else if(es_triptofano(codon))
        err = aminoacido_crear(salida, TRIPTOFONO);
    else if(es_prolina(codon))
        err = aminoacido_crear(salida, PROLINA);
    else if(es_histidina(codon))
        err = aminoacido_crear(salida, HISTIDINA);
    else if(es_glutamico(codon))
        err = aminoacido_crear(salida, ACIDO_GLUTAMICO);
    else if(es_isoleucina(codon))
        err = aminoacido_crear(salida, ISOLEUCINA);
    else if(es_metionina(codon))
        err = aminoacido_crear(salida, METIONINA);
    else if(es_treonina(codon))
        err = aminoacido_crear(salida, TREONINA);
    else if(es_asparagina(codon))
        err = aminoacido_crear(salida, ASPARAGINA);
    else if(es_lisina(codon))
        err = aminoacido_crear(salida, LISINA);
    else if(es_arginina(codon))
        err = aminoacido_crear(salida, ARGININA);
    else if(es_valina(codon))
        err = aminoacido_crear(salida, VALINA);
    else if(es_alanina(codon))
        err = aminoacido_crear(salida, ALANINA);
    else if(es_aspartico(codon))
        err = aminoacido_crear(salida, ACIDO_ASPARTICO);
    else if(es_glicina(codon))
        err = aminoacido_crear(salida, GLICINA);

    if(err == ERROR)
        return ERROR;
    return OK;
}


bool es_fenilanina(codon_t *codon) {
    return (codon_es_igual(codon,"UUU")||codon_es_igual(codon,"UUC"));
}

bool es_leucina(codon_t *codon) {
    return codon_es_igual(codon,"UUA")||codon_es_igual(codon,"UUG")
           ||codon_es_igual(codon,"CUU")||codon_es_igual(codon,"CUC")
           ||codon_es_igual(codon,"CUA")||codon_es_igual(codon,"CUG");
}

bool es_serina(codon_t *codon) {
    return codon_es_igual(codon,"UCU")||codon_es_igual(codon,"UCC")
            ||codon_es_igual(codon,"UCA")||codon_es_igual(codon,"UCG")
            ||codon_es_igual(codon,"AGU")||codon_es_igual(codon,"AGC");
}

bool es_tirosina(codon_t *codon) {
    return codon_es_igual(codon,"UAU")||codon_es_igual(codon,"UAC");
}

bool es_cisteina(codon_t *codon) {
    return codon_es_igual(codon,"UGU")||codon_es_igual(codon,"UGC");
}

bool es_triptofano(codon_t *codon) {
    return codon_es_igual(codon,"UGG");
}

bool es_prolina(codon_t *codon) {
    return codon_es_igual(codon,"CCU")||codon_es_igual(codon,"CCC")
          ||codon_es_igual(codon,"CCA")||codon_es_igual(codon,"CCG");
}

bool es_histidina(codon_t *codon) {
    return codon_es_igual(codon,"CAU")||codon_es_igual(codon,"CAC");
}

bool es_glutamico(codon_t *codon) {
    return codon_es_igual(codon,"CAA")||codon_es_igual(codon,"CAG")
            ||codon_es_igual(codon,"GAA")||codon_es_igual(codon,"GAG");
}

bool es_isoleucina(codon_t *codon) {
    return codon_es_igual(codon,"AUU")||codon_es_igual(codon,"AUC")
           ||codon_es_igual(codon,"AUA");
}

bool es_metionina(codon_t *codon) {
    return codon_es_igual(codon,"AUG");
}

bool es_treonina(codon_t *codon) {
    return codon_es_igual(codon,"ACU")||codon_es_igual(codon,"ACC")
           ||codon_es_igual(codon,"ACA")||codon_es_igual(codon,"ACG");
}

bool es_asparagina(codon_t *codon) {
    return codon_es_igual(codon,"AAU")||codon_es_igual(codon,"AAC");
}

bool es_lisina(codon_t *codon) {
    return codon_es_igual(codon,"AAA")||codon_es_igual(codon,"AAG ");
}

bool es_arginina(codon_t *codon) {
    return codon_es_igual(codon,"CGU")||codon_es_igual(codon,"CGC")
           ||codon_es_igual(codon,"CGA")||codon_es_igual(codon,"CGG")
           ||codon_es_igual(codon,"AGA")||codon_es_igual(codon,"AGG");
}

bool es_valina(codon_t *codon) {
    return codon_es_igual(codon,"GUU")||codon_es_igual(codon,"GUC")
           ||codon_es_igual(codon,"GUA")||codon_es_igual(codon,"GUG");
}

bool es_alanina(codon_t *codon) {
    return codon_es_igual(codon,"GCU")||codon_es_igual(codon,"GCC")
           ||codon_es_igual(codon,"GCA")||codon_es_igual(codon,"GCG");
}

bool es_aspartico(codon_t *codon) {
    return codon_es_igual(codon,"GAU")||codon_es_igual(codon,"GAC");
}

bool es_glicina(codon_t *codon) {
    return codon_es_igual(codon,"GGU")||codon_es_igual(codon,"GGC")
           ||codon_es_igual(codon,"GGA")||codon_es_igual(codon,"GGG");
}
