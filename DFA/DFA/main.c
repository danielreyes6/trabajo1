// main.c

#include <stdio.h>
#include "dfa.h"

int main() {
    DFA dfa;
    char filename[MAX_STRING];

    printf("Ingrese el nombre del archivo de configuración: ");
    scanf("%s", filename);

    read_config_file(filename, &dfa);

    char input_string[MAX_STRING];
    printf("Ingrese la cadena de entrada: ");
    scanf("%s", input_string);

    process_string(&dfa, input_string);

    return 0;
}
