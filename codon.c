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
#define ERROR 1
#define OK 0

static int a_letras(unsigned char byte, char *letras);
static unsigned char a_byte(char* letras);
static unsigned char obtener_la_base(unsigned char byte, int i);
static bool es_alto(char* letras);
static bool es_inicio(char* letras);

int codon_crear_con_byte(codon_t *self, unsigned char byte){//TODO: Excepciones
    self->byte=byte;
    a_letras(self->byte,self->letras);
    self->esAlto=es_alto(self->letras);
    self->esInicio=es_inicio(self->letras);
    return OK;
}

int codon_crear_con_letras(codon_t *self,char* letras){ //TODO: Excepciones
    strncpy(self->letras,letras,3);
    self->byte = a_byte(self->letras);
    self->esAlto = es_alto(self->letras);
    self->esInicio = es_inicio(self->letras);
    return OK;
}

int codon_destruir(codon_t *self){
    return OK;
}

unsigned char codon_get_byte(codon_t *self){
    return self->byte;
}

bool codon_es_alto(codon_t *self){
    return self->esAlto;
}

bool codon_es_igual(codon_t *self,char* letras){
    return strncmp(self->letras,letras,3) == 0;
}

static int a_letras(unsigned char byte, char *letras){
    char aux[3];
    for(int i=0;i<=4;i=i+2){
        switch(obtener_la_base(byte,i)){
            case BASE_A:{
                aux[2-i/2]='A';
                break;
            }
            case BASE_U:{
                aux[2-i/2]='U';
                break;
            }
            case BASE_G:{
                aux[2-i/2]='G';
                break;
            }
            case BASE_C:{
                aux[2-i/2]='C';
                break;
            }
            default:{
                return ERROR;
            }
        }
    }
    strncpy(letras,aux,3);
    return OK;
}

static unsigned char obtener_la_base(unsigned char byte, int i){
    return (byte&(3<<i))>>i;
}

static unsigned char a_byte(char* letras){
    unsigned char aux=0;
    for(int i=2;i>=0;i--){
        switch (letras[i]){
            case 'A':{
                aux=aux+(BASE_A<<(-2*i+4));
                break;
            }
            case 'U':{
                aux=aux+(BASE_U<<(-2*i+4));
                break;
            }
            case 'G':{
                aux=aux+(BASE_G<<(-2*i+4));
                break;
            }
            case 'C':{
                aux=aux+(BASE_C<<(-2*i+4));
                break;
            }
        }
    }
    return aux;
}

static bool es_alto(char* letras){
    return (strncmp(letras,ALTO_1,3) == 0)||(strncmp(letras,ALTO_2,3)== 0)||(strncmp(letras,ALTO_3,3)== 0);
}

static bool es_inicio(char* letras){
    return (strncmp(letras,INICIO,3) == 0);
}