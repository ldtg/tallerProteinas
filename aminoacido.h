#ifndef TP1_AMINOACIDO_H
#define TP1_AMINOACIDO_H
#define MAX_LEN_AMINOACIDO 20
#define CANT_AMINOACIDOS 19
#define OK 0
#define ERROR 1

// Tipo aminoacido_e representa en un enum los tipos de aminoacidos existentes
typedef enum AMINOACIDO {
  FENILALANINA,
  LEUCINA,
  SERINA,
  TIROSINA,
  CISTEINA,
  TRIPTOFONO,
  PROLINA,
  HISTIDINA,
  ACIDO_GLUTAMICO,
  ISOLEUCINA,
  METIONINA,
  TREONINA,
  ASPARAGINA,
  LISINA,
  ARGININA,
  VALINA,
  ALANINA,
  ACIDO_ASPARTICO,
  GLICINA
} aminoacido_e;

// Tipo aminoacido_t representa un aminoacido
typedef struct {
  aminoacido_e aminoacido;
  char str_aminoacido[MAX_LEN_AMINOACIDO];
} aminoacido_t;

// Inicializa self con el tipo de aminoacido dado
// Pre: self apunta un sector válido de memoria
// Post: en caso de exito retorna OK, caso contrario ERROR
int aminoacido_crear(aminoacido_t *self, aminoacido_e aminoacido);

// Destruye self liberando sus recursos
// Pre: self inicializado
// Post: en caso de exito retorna OK, caso contrario ERROR
int aminoacido_destruir(aminoacido_t *self);

// Retorna en dest un string con el nombre del aminoacido
// Pre: self inicializado, dest apunta a un sector valido de memoria
// con al menos MAX_LEN_AMINOACIDO bytes disponibles para escritura
// Post: en caso de exito retorna OK, caso contrario ERROR
int aminoacido_to_string(aminoacido_t *self, char *dest);

// Retorna un entero que representa univocamente a un aminoacido
// Pre: self inicializado
// Post: retorno entre 0 y 18
int aminoacido_to_int(aminoacido_t *self);

// Compara dos aminoacidos
// Pre: self,otro inicializados
// Post: retorna -1, 0, 1 dependiendo si self es menor, igual, o mayor a otro
int aminoacido_comparar(aminoacido_t *self, aminoacido_t *otro);

// Retorna un aminoacido_e a partir de un entero
// Pre: i entre 0 y 18
aminoacido_e aminoacido_from_int(int i);

#endif //TP1_AMINOACIDO_H
