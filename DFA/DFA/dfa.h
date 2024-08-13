// dfa.h

#ifndef DFA_H
#define DFA_H

#define MAX_STATES 100
#define MAX_ALPHABET 26
#define MAX_TRANSITIONS 1000
#define MAX_STRING 100

// Estructura para representar una transición
typedef struct {
    char current_state[MAX_STRING];
    char symbol;
    char next_state[MAX_STRING];
} Transition;

// Estructura para representar el DFA
typedef struct {
    char states[MAX_STATES][MAX_STRING];
    int num_states;
    char alphabet[MAX_ALPHABET];
    int num_alphabet;
    char initial_state[MAX_STRING];
    char acceptance_states[MAX_STATES][MAX_STRING];
    int num_acceptance_states;
    Transition transitions[MAX_TRANSITIONS];
    int num_transitions;
} DFA;

// Declaraciones de funciones
void read_config_file(char *filename, DFA *dfa);
char* transition(DFA *dfa, char *current_state, char symbol);
int is_acceptance_state(DFA *dfa, char *state);
void process_string(DFA *dfa, char *input_string);

#endif
