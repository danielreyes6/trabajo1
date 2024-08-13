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

```plaintext
q0,q1,q2
a,b
q0
q2
q0,a,q1
q1,b,q2
q2,a,q0
q2,b,q1 


Para ejecutar el programa:

1. **Compila el código:**

    ```bash
    gcc main.c dfa.c -o dfa
    ```

2. **Ejecuta el programa:**

    ```bash
    ./dfa
    ```

3. **Cuando se te solicite, ingresa el nombre del archivo de configuración (`config.txt`):**

    ```
    Ingrese el nombre del archivo de configuración: config.txt
    ```

4. **Luego, se te pedirá que ingreses una cadena de entrada. Por ejemplo, ingresa la cadena `ab`:**

    ```
    Ingrese la cadena de entrada: ab
    ```

El programa procesará la cadena `ab` según las transiciones y los estados de aceptación definidos en `config.txt`. Dado el archivo de configuración proporcionado, el programa debería indicar que la cadena es aceptada si el autómata llega a un estado de aceptación después de procesar toda la cadena.

**Salida esperada:**




  
