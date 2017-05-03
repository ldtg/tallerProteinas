#include <stdio.h>
#include "servidor.h"
#include "cliente.h"

void imprimir_uso();

int main(int argc, char *argv[]) {
  FILE *file;
  servidor_t server;
  cliente_t cliente;

  if (strcmp(argv[1], "server") == 0 && argc > 2) {
    if (servidor_crear(&server, argv[2]) == ERROR)
      return ERROR;
    if (servidor_recibir_datos(&server) == ERROR)
      return ERROR;
    if (servidor_procesar(&server) == ERROR)
      return ERROR;
    if (servidor_enviar_mensaje(&server) == ERROR)
      return ERROR;
    if (servidor_destruir(&server) == ERROR)
      return ERROR;
  } else if (strcmp(argv[1], "client") == 0 && argc > 4) {
    file = fopen(argv[4], "r");
    if (file == NULL)
      return ERROR;
    if (cliente_crear(&cliente, file, argv[2], argv[3]) == ERROR)
      return ERROR;
    if (cliente_enviar_datos(&cliente) == ERROR)
      return ERROR;
    if (cliente_recibir_datos(&cliente) == ERROR)
      return ERROR;
    cliente_imprimir_mensaje(&cliente);
    if (cliente_destruir(&cliente) == ERROR)
      return ERROR;
    fclose(file);
  } else {
    imprimir_uso();
  }

  return OK;
}

void imprimir_uso() {
  printf("Uso:\n./tp client <ip> <port> <file> para modo cliente\n"
             "./tp server <port> para modo server\n");
}
