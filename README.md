# DFA Automaton in C

Este proyecto implementa un Autómata Finito Determinista (DFA, por sus siglas en inglés) en C. El programa lee un archivo de configuración que define los estados, el alfabeto, el estado inicial, los estados de aceptación y las transiciones del autómata. Luego, el programa procesa una cadena de entrada y determina si es aceptada o rechazada por el DFA.

## Archivos del Proyecto

- **main.c**: Contiene la función principal que lee el archivo de configuración, solicita la cadena de entrada y utiliza el DFA para procesarla.
- **dfa.h**: Define las estructuras y funciones necesarias para representar y operar el DFA.
- **dfa.c**: Implementa las funciones declaradas en `dfa.h` para configurar y operar el DFA.
- **config.txt**: Archivo de configuración que define la estructura del DFA.

## Configuración

El archivo de configuración (`config.txt`) debe tener el siguiente formato:

1. Lista de estados separados por comas.
2. Alfabeto (símbolos) separado por comas.
3. Estado inicial.
4. Estados de aceptación separados por comas.
5. Transiciones, una por línea, en el formato: `estado_actual,símbolo,estado_siguiente`.

### Ejemplo de `config.txt`

```dsdas
q0,q1,q2
a,b
q0
q2
q0,a,q1
q1,b,q2
q2,a,q0
q2,b,q1 




  
