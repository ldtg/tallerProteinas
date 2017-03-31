#include "cliente.h"
#include "codon.h"
#include <string.h>

// Lee el archivo, guarda en buff la cantidad leida y setea eof si EOF
static size_t leer_archivo(const cliente_t *self, char *buff, bool *eof);

// Retorna en bytes_to_send los bytes a enviar al servidor a partir del buffer
// leido con leer_archivo y la cantidad de bytes leidos
static int obtener_bytes_a_enviar(size_t bytes_read,
                                  const char *buff,
                                  char *bytes_to_send);

int cliente_crear(cliente_t *self, FILE *file, char *host, char *service) {
  int err_create = ERROR;
  int err_connect = ERROR;

  self->host = host;
  self->service = service;
  strncpy(self->respuesta, "", MAX_LEN_RESPUESTA);

  if (file == NULL)
    return ERROR;
  self->in_file = file;

  err_create = socket_create(&(self->socket));
  if (err_create == ERROR)
    return ERROR;

  err_connect = socket_connect(&(self->socket), host, service);
  if (err_connect == ERROR)
    return ERROR;

  return OK;
}

int cliente_destruir(cliente_t *self) {
  int err_d;

  err_d = socket_destroy(&self->socket);

  if (err_d != OK)
    return ERROR;

  return OK;
}

int cliente_enviar_datos(cliente_t *self) {
  int bytes_send = 0;
  size_t bytes_read = 0;
  int total_bytes_read = 0;
  int err;
  char bytes_to_send[BUFF_SEND_LEN];
  char buff[BUFF_READ_LEN];
  bool eof = false;

  do {
    bytes_read = leer_archivo(self, buff, &eof);
    err = obtener_bytes_a_enviar(bytes_read, buff, bytes_to_send);
    bytes_send += socket_send(&(self->socket), bytes_to_send, bytes_read / 3);
    total_bytes_read += bytes_read;
  } while (!eof && bytes_send >= 0 && err != ERROR);

  if (ferror(self->in_file) || bytes_send * 3 != total_bytes_read
      || err == ERROR)
    return ERROR;

  socket_shutdown(&(self->socket), SHUTWR); //PROTOCOLO

  return OK;
}

int cliente_recibir_datos(cliente_t *self) {
  char respuesta[MAX_LEN_RESPUESTA] = "";
  int rcv_status;

  rcv_status = socket_receive(&self->socket, respuesta, MAX_LEN_RESPUESTA);

  if (rcv_status == 0)
    strncpy(self->respuesta, respuesta, MAX_LEN_RESPUESTA);
  else
    return ERROR;

  return OK;
}

void cliente_imprimir_mensaje(cliente_t *self) {
  fputs(self->respuesta, stdout);
}

static size_t leer_archivo(const cliente_t *self, char *buff, bool *eof) {
  size_t f_read = 0;
  size_t b_read = 0;
  memset(buff, 0, BUFF_READ_LEN);

  f_read = fread(buff, 1, BUFF_READ_LEN, self->in_file);

  if (f_read < BUFF_READ_LEN && strlen(buff) > 0) {
    if (buff[f_read - 1] == '\n')
      b_read = strlen(buff) - 1;
    else
      b_read = strlen(buff);
    *eof = true;
  } else {
    b_read = f_read;
  }

  return b_read;
}

static int obtener_bytes_a_enviar(size_t bytes_read,
                                  const char *buff,
                                  char *bytes_to_send) {
  codon_t codon[BUFF_SEND_LEN];
  char codon_str[3];

  memset(bytes_to_send, 0, BUFF_SEND_LEN);

  for (int i = 0; i < bytes_read / 3; i++) {
    strncpy(codon_str, buff + 3 * i, 3);
    if (codon_crear_con_letras(&(codon[i]), codon_str) == ERROR)
      return ERROR;
    bytes_to_send[i] = codon_get_byte(&codon[i]);
  }
  return OK;
}
