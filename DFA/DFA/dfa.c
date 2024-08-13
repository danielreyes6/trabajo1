// dfa.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dfa.h"

// Función para leer el archivo de configuración y configurar el DFA
void read_config_file(char *filename, DFA *dfa) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char line[MAX_STRING];
    char *token;
    int i;

    // Leer el conjunto de estados (Q)
    fgets(line, MAX_STRING, file);
    token = strtok(line, ",\n");
    i = 0;
    while (token != NULL) {
        strcpy(dfa->states[i++], token);
        token = strtok(NULL, ",\n");
    }
    dfa->num_states = i;

    // Leer el alfabeto (Σ)
    fgets(line, MAX_STRING, file);
    token = strtok(line, ",\n");
    i = 0;
    while (token != NULL) {
        dfa->alphabet[i++] = token[0];
        token = strtok(NULL, ",\n");
    }
    dfa->num_alphabet = i;

    // Leer el estado inicial (q0)
    fgets(line, MAX_STRING, file);
    sscanf(line, "%s", dfa->initial_state);

    // Leer los estados de aceptación (F)
    fgets(line, MAX_STRING, file);
    token = strtok(line, ",\n");
    i = 0;
    while (token != NULL) {
        strcpy(dfa->acceptance_states[i++], token);
        token = strtok(NULL, ",\n");
    }
    dfa->num_acceptance_states = i;

    // Leer las transiciones
    dfa->num_transitions = 0;
    while (fgets(line, MAX_STRING, file) != NULL) {
        Transition t;
        sscanf(line, "%[^,],%c,%s", t.current_state, &t.symbol, t.next_state);
        dfa->transitions[dfa->num_transitions++] = t;
    }

    fclose(file);
}

// Función de transición: devuelve el siguiente estado dado el estado actual y un símbolo
char* transition(DFA *dfa, char *current_state, char symbol) {
    for (int i = 0; i < dfa->num_transitions; i++) {
        if (strcmp(dfa->transitions[i].current_state, current_state) == 0 &&
            dfa->transitions[i].symbol == symbol) {
            return dfa->transitions[i].next_state;
        }
    }
    return NULL; // Retorna NULL si no hay transición definida
}

// Función para verificar si un estado es de aceptación
int is_acceptance_state(DFA *dfa, char *state) {
    for (int i = 0; i < dfa->num_acceptance_states; i++) {
        if (strcmp(dfa->acceptance_states[i], state) == 0) {
            return 1;
        }
    }
    return 0;
}

// Función para procesar la cadena de entrada
void process_string(DFA *dfa, char *input_string) {
    char current_state[MAX_STRING];
    strcpy(current_state, dfa->initial_state);

    for (int i = 0; i < strlen(input_string); i++) {
        char symbol = input_string[i];
        char *next_state = transition(dfa, current_state, symbol);

        if (next_state == NULL) {
            printf("Cadena rechazada.\n");
            return;
        }

        strcpy(current_state, next_state);
    }

    if (is_acceptance_state(dfa, current_state)) {
        printf("Cadena aceptada.\n");
    } else {
        printf("Cadena rechazada.\n");
    }
}
