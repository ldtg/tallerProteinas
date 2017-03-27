#include <stdio.h>
#include "codon.h"
int main() {
    codon_t codon;
    char letras[3];
    codon_crear_con_byte(&codon,16);
    if(codon_es_alto(&codon)) puts("ok alto");
    codon_get_letras(&codon,letras);
    if(strncmp(letras,"UAA",3)) puts("ok byte");
    return 0;
}