#include <stdio.h>
#include "codon.h"
#include "servidor.h"
#include "cliente.h"

int main(int argc, char* argv[]) {
    FILE *file;
    servidor_t server;
    cliente_t cliente;
    if(strcmp(argv[1],"server") == 0){
        servidor_crear(&server,"7070");
        servidor_recibir_datos(&server);
        servidor_procesar(&server);
        servidor_enviar_mensaje(&server);
    }
    if(strcmp(argv[1],"cliente") == 0){
        file = fopen("arn.txt","r");
        cliente_crear(&cliente, file, "127.0.0.1", "7070");
        cliente_enviar_datos(&cliente);
        cliente_recibir_datos(&cliente);
        cliente_imprimir_mensaje(&cliente);
        fclose(file);
    }



    return 0;
}