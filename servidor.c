//
// Created by tg on 24/03/17.
//

#include <stdlib.h>
#include "servidor.h"
#define OK 0
#define ERROR 1

static void inicializar_estado(servidor_t *self);
static int comparar_contador(const void * a, const void * b);
static int contar_aminoacidos_distintos(contador_aminoacidos_t *contador_aminoacidos);
static int generar_respuesta(servidor_t *self);

int servidor_crear(servidor_t *self, unsigned short port) {
    int error_crear_aceptador = ERROR;
    int error_crear_recibidor = ERROR;
    int error_bindandlisten = ERROR;

    inicializar_estado(self);

    error_crear_aceptador = socket_create(&(self->socket_aceptador));
    error_crear_recibidor = socket_create(&(self->socket_recibidor));
    error_bindandlisten = socket_bindandlisten(&(self->socket_aceptador),port);

    if(error_crear_aceptador == ERROR || error_crear_recibidor == ERROR || error_bindandlisten == ERROR)
        return ERROR;

    return OK;
}

int servidor_destruir(servidor_t *self) {
    int error_destruir_aceptador = ERROR;
    int error_destruir_recibidor = ERROR;

    error_destruir_aceptador=socket_destroy(&(self->socket_aceptador));
    error_destruir_recibidor=socket_destroy(&(self->socket_recibidor));

    if(error_destruir_aceptador == ERROR || error_destruir_recibidor == ERROR)
        return ERROR;

    return OK;
}

int servidor_recibir_datos(servidor_t *self) {
    codon_t codon_aux;
    unsigned char codon_byte=0;
    aminoacido_t aminoacido_aux;
    int socket_rcv_status=-1;

    if(socket_accept(&(self->socket_recibidor),&(self->socket_aceptador))==ERROR)
        return ERROR;

    socket_rcv_status = socket_receive(&(self->socket_recibidor),&codon_byte,sizeof(codon_byte));

    while(socket_rcv_status > 0){//TODO: excep
        codon_crear_con_byte(&codon_aux,codon_byte);

        if(!codon_es_alto(&codon_aux)){
            aminoacido_aux = codigo_genetico_procesar(&codon_aux);
            self->contador_aminoacidos[aminoacido_aux].cantidad_contados += 1;
        }
        else
            self->cantidad_proteinas+=1;
        socket_rcv_status = socket_receive(&(self->socket_recibidor),&codon_byte,sizeof(codon_byte));
    }

    if(socket_rcv_status < 0)
        return ERROR;

    return OK;
}

int servidor_procesar(servidor_t *self) {
    int cant_aminoacidos_distintos = 0;

    qsort((void*)&(self->contador_aminoacidos[0]),CANT_AMINOACIDOS,sizeof(contador_aminoacidos_t),comparar_contador);
    cant_aminoacidos_distintos = contar_aminoacidos_distintos(&(self->contador_aminoacidos));
    generar_respuesta(self);

    return OK;
}

static void inicializar_estado(servidor_t *self){
    for(int i=0;i<CANT_AMINOACIDOS;i++){
        self->contador_aminoacidos[i].cantidad_contados=0;
        self->contador_aminoacidos[i].aminoacido=i;
    }
    strncpy(self->respuesta,"",MAX_LEN_RESPUESTA);
    self->cantidad_aminoacidos_distintos = 0;
    self->cantidad_proteinas = 0;
}

static int comparar_contador (const void * a, const void * b){
    contador_aminoacidos_t *aux_a,*aux_b;
    aux_a = (contador_aminoacidos_t*)a;
    aux_b = (contador_aminoacidos_t*)b;

    if(aux_a->cantidad_contados > aux_b->cantidad_contados)
        return -1;
    else if(aux_a->cantidad_contados < aux_b->cantidad_contados)
        return 1;

    //son iguales comparo nombres
    return strcmp(AMINOACIDO_STRING[aux_a->aminoacido],AMINOACIDO_STRING[aux_b->aminoacido]);
}

static int contar_aminoacidos_distintos(contador_aminoacidos_t *contador_aminoacidos){
    int contador = 0;

    for(int i=0;i<CANT_AMINOACIDOS;i++){
        if(contador_aminoacidos[i].cantidad_contados > 0)
            contador++;
        else
            break;
    }
}

static int generar_respuesta(servidor_t *self){
    if(self->cantidad_aminoacidos_distintos < 3){
        if(self->cantidad_aminoacidos_distintos == 0)
            return ERROR;
        else if (self->cantidad_aminoacidos_distintos == 1){
            snprintf(self->respuesta,MAX_LEN_RESPUESTA,"Cantidad de proteínas encontradas: %d\n"
                             "Aminoácidos más frecuentes:\n"
                             "1) %s: %d\n", self->cantidad_proteinas, AMINOACIDO_STRING[self->contador_aminoacidos[0].aminoacido]);
            return OK;
        } else{
            snprintf(self->respuesta,MAX_LEN_RESPUESTA,"Cantidad de proteínas encontradas: %d\n"
                             "Aminoácidos más frecuentes:\n"
                             "1) %s: %d\n"
                             "2) %s: %d\n", self->cantidad_proteinas,AMINOACIDO_STRING[self->contador_aminoacidos[0].aminoacido],
                     AMINOACIDO_STRING[self->contador_aminoacidos[1].aminoacido]);
            return OK;
        }
    } else {
        snprintf(self->respuesta,MAX_LEN_RESPUESTA,"Cantidad de proteínas encontradas: %d\n"
                "Aminoácidos más frecuentes:\n"
                "1) %s: %d\n"
                "2) %s: %d\n"
                "3) %s: %d\n", self->cantidad_proteinas,AMINOACIDO_STRING[self->contador_aminoacidos[0].aminoacido],
                 AMINOACIDO_STRING[self->contador_aminoacidos[1].aminoacido],
                AMINOACIDO_STRING[self->contador_aminoacidos[2].aminoacido]);
        return OK;
    }
    return ERROR;
}
