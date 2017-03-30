//
// Created by tg on 24/03/17.
//

#include <stdlib.h>
#include <sys/socket.h>
#include "servidor.h"
#define OK 0
#define ERROR 1

static void inicializar_estado(servidor_t *self);
static int comparar_contador(const void * a, const void * b);
static int contar_aminoacidos_distintos(contador_aminoacidos_t *contador_aminoacidos);
static int generar_respuesta(servidor_t *self, int cant_dist);

int servidor_crear(servidor_t *self, const char *port) {
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

    error_destruir_aceptador = socket_destroy(&(self->socket_aceptador));
    error_destruir_recibidor = socket_destroy(&(self->socket_recibidor));

    if(error_destruir_aceptador == ERROR || error_destruir_recibidor == ERROR)
        return ERROR;

    return OK;
}

int servidor_recibir_datos(servidor_t *self) {
    codon_t codon_aux;
    unsigned char codon_byte = 0;
    aminoacido_t aminoacido_aux;
    int socket_rcv_status = -1;
    int err_cod_gen = ERROR;

    if(socket_accept(&(self->socket_aceptador), &(self->socket_recibidor)) == ERROR)
        return ERROR;

    socket_rcv_status = socket_receive(&(self->socket_recibidor),
                                       &codon_byte, sizeof(codon_byte));

    while(socket_rcv_status > 0){//TODO: excep
        codon_crear_con_byte(&codon_aux,codon_byte);

        if(!codon_es_alto(&codon_aux)){
            err_cod_gen = codigo_genetico_procesar(&codon_aux, &aminoacido_aux);
            if(err_cod_gen == OK)
                self->contador_aminoacidos[aminoacido_to_int(&aminoacido_aux)].cantidad_contados += 1;
        }
        else
            self->cantidad_proteinas+=1;
        socket_rcv_status = socket_receive(&(self->socket_recibidor),
                                           &codon_byte,sizeof(codon_byte));
        codon_destruir(&codon_aux);
    }

    if(socket_rcv_status < 0)
        return ERROR;

    return OK;
}

int servidor_procesar(servidor_t *self) {
    int cant_aminoacidos_distintos = 0;
    int error_generar_respuesta = ERROR;
    cant_aminoacidos_distintos = contar_aminoacidos_distintos(self->contador_aminoacidos);
    qsort((void*)&(self->contador_aminoacidos), CANT_AMINOACIDOS, sizeof(contador_aminoacidos_t), comparar_contador);

    error_generar_respuesta = generar_respuesta(self, cant_aminoacidos_distintos);

    if(error_generar_respuesta == ERROR)
        return ERROR;
    return OK;
}

int servidor_enviar_mensaje(servidor_t *self) {
    int enviados=0;
    size_t len_respuesta =  strlen(self->respuesta);

    enviados = socket_send(&(self->socket_recibidor)
            ,(void *)&(self->respuesta), len_respuesta);

    socket_shutdown(&self->socket_recibidor, SHUT_WR); //PROTOCOLO
    if(enviados < 0 || enviados < len_respuesta)
        return ERROR;
    return OK;
}

static void inicializar_estado(servidor_t *self){
    for(int i=0;i<CANT_AMINOACIDOS;i++){
        self->contador_aminoacidos[i].cantidad_contados=0;
        aminoacido_crear(&self->contador_aminoacidos[i].aminoacido,i);
    }

    strncpy(self->respuesta,"",MAX_LEN_RESPUESTA);
    self->cantidad_proteinas = 0;
}

static int comparar_contador (const void * a, const void * b){
    contador_aminoacidos_t *aux_a,*aux_b;

    aux_a = (contador_aminoacidos_t*)a;
    aux_b = (contador_aminoacidos_t*)b;
    /*aminoacido_to_string(&aux_a->aminoacido,str_a);
    aminoacido_to_string(&aux_b->aminoacido,str_b);*/

    if(aux_a->cantidad_contados > aux_b->cantidad_contados)
        return -1;
    else if(aux_a->cantidad_contados < aux_b->cantidad_contados)
        return 1;

    //son iguales comparo aminoacidos
    return aminoacido_comparar(&aux_a->aminoacido, &aux_b->aminoacido);
}

static int contar_aminoacidos_distintos(contador_aminoacidos_t *contador_aminoacidos){
    int contador = 0;

    for(int i=0;i<CANT_AMINOACIDOS;i++){
        if(contador_aminoacidos[i].cantidad_contados > 0)
            contador++;
    }
    return contador;
}

static int generar_respuesta(servidor_t *self, int cant_dist){
    aminoacido_t primer_aminoacido, segundo_aminoacido, tercer_aminoacido;
    char str_primer_aminoacido[MAX_LEN_AMINOACIDO] = "";
    char str_segundo_aminoacido[MAX_LEN_AMINOACIDO] = "";
    char str_tercer_aminoacido[MAX_LEN_AMINOACIDO] = "";
    size_t contados_primer, contados_segundo, contados_tercero;

    primer_aminoacido = self->contador_aminoacidos[0].aminoacido;
    segundo_aminoacido = self->contador_aminoacidos[1].aminoacido;
    tercer_aminoacido = self->contador_aminoacidos[2].aminoacido;
    aminoacido_to_string(&primer_aminoacido,str_primer_aminoacido);
    aminoacido_to_string(&segundo_aminoacido,str_segundo_aminoacido);
    aminoacido_to_string(&tercer_aminoacido,str_tercer_aminoacido);
    contados_primer = self->contador_aminoacidos[0].cantidad_contados;
    contados_segundo = self->contador_aminoacidos[1].cantidad_contados;
    contados_tercero = self->contador_aminoacidos[2].cantidad_contados;


    if(cant_dist < 3){
        if(cant_dist == 0)
            return ERROR;
        else if (cant_dist == 1){
            snprintf(self->respuesta,MAX_LEN_RESPUESTA,
                     "Cantidad de proteínas encontradas: %zd\n\n"
                     "Aminoácidos más frecuentes:\n"
                     "1) %s: %zd\n",self->cantidad_proteinas,
                     str_primer_aminoacido, contados_primer);
            return OK;
        } else{
            snprintf(self->respuesta,MAX_LEN_RESPUESTA,"Cantidad de proteínas encontradas: %zd\n\n"
                    "Aminoácidos más frecuentes:\n"
                    "1) %s: %zd\n"
                    "2) %s: %zd\n",self->cantidad_proteinas,
                    str_primer_aminoacido, contados_primer,
                    str_segundo_aminoacido, contados_segundo);
            return OK;
        }
    } else {
        snprintf(self->respuesta,MAX_LEN_RESPUESTA,"Cantidad de proteínas encontradas: %zd\n\n"
                "Aminoácidos más frecuentes:\n"
                "1) %s: %zd\n"
                "2) %s: %zd\n"
                "3) %s: %zd\n", self->cantidad_proteinas,
                 str_primer_aminoacido,
                 contados_primer,
                 str_segundo_aminoacido,
                 contados_segundo,
                 str_tercer_aminoacido,
                 contados_tercero);
        return OK;
    }
    return ERROR;
}
