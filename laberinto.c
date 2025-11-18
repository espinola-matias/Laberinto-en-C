#include <stdio.h>
#include <stdbool.h>  
#include <stdlib.h>   
#include <time.h>

#define DIMENSION 11
#define SOLUCION '-'
#define MUROS '#'
#define CAMINO ' '
#define ENTRADA 'E'
#define SALIDA 'S'

char laberinto_tablero[DIMENSION][DIMENSION];
bool visitados[DIMENSION][DIMENSION];

// declaraciones de funciones a utilizar 
void inicializar_tablero();
void imprimir_tablero();
bool resolver_tablero(int fila_actual, int columna_actual);
void generar_laberinto(int fila_actual, int columna_actual);
void mezclar(int arr[4][2]);

int main() {
    srand(time(NULL)); // inicializo y utiliza el tiempo actual como semilla 

    inicializar_tablero();
    generar_laberinto(0, 0);
    laberinto_tablero[0][0] = ENTRADA;
    imprimir_tablero();
    clock_t tiempo_inicio = clock();   // utiliza ticks y guarda en el momento de la ejecucion 

    bool resuelto = resolver_tablero(0, 0);
    laberinto_tablero[DIMENSION -1][DIMENSION -1] = SALIDA;

    if (resuelto == false) {
        printf("No se encontro la salida!\n");
    } else {
        printf("Se encontro la solucion \n");
        clock_t tiempo_fin = clock();  
        double tiempo_total = ((double)(tiempo_fin - tiempo_inicio)) / CLOCKS_PER_SEC;  // dividimos los ticks para obtener en segundos reales 
        printf("Tiempo de resolucion: %f segundos\n", tiempo_total);
        imprimir_tablero();
    }
    return 0;
}

void inicializar_tablero() {
    for (int i = 0; i < DIMENSION; i++) {
        for (int j = 0; j < DIMENSION; j++){
            laberinto_tablero[i][j] = MUROS;
        }
    }
}

void imprimir_tablero() {
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            printf("%c", laberinto_tablero[i][j]);
        }
        printf("\n");
    }
}

void mezclar(int arr[4][2]) {
    for (int i = 0; i < 4; i++) {
        int j = rand() % 4;  // indice random y aseguramos que el valor sea valido
        // cambiar arr[i] a arr[j]
        int temporal0 = arr[i][0];
        int temporal1 = arr[i][1];
        arr[i][0] = arr[j][0];
        arr[i][1] = arr[j][1];
        arr[j][0] = temporal0;
        arr[j][1] = temporal1;
    }
}

// recorrido a profundidad generando caminos randon con bactracking
void generar_laberinto(int fila_actual, int columna_actual) {
    int salida_fila = DIMENSION -1;
    int salida_columna = DIMENSION -1;


    laberinto_tablero[fila_actual][columna_actual] = CAMINO;
    
    if (salida_fila == fila_actual && salida_columna == columna_actual) {
        return;
    } else {
        int direcciones[4][2] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}}; //  para generar caminos con espacios que serian los muros 
        mezclar(direcciones); // mezcla para hacer direcciones aleatorias 
        for (int direccion = 0; direccion < 4; direccion++) {
            int nueva_fila = fila_actual + direcciones[direccion][0];
            int nueva_columna = columna_actual + direcciones[direccion][1];
            if (nueva_fila >= 0 && nueva_fila < DIMENSION && nueva_columna >= 0 && nueva_columna < DIMENSION) {
                if (laberinto_tablero[nueva_fila][nueva_columna] == MUROS) {
                    // limpiar muro intermedio
                    int fila_muro = (fila_actual+nueva_fila)/2;
                    int columna_muro = (columna_actual + nueva_columna)/2;
                    laberinto_tablero[fila_muro][columna_muro] = CAMINO;
                    generar_laberinto(nueva_fila, nueva_columna); // realiza la llamada recursiva para seguir generando caminos disponibles 
                }
            }
        }
    }
}

// recorrido por profundidad + bactracking
bool resolver_tablero(int fila_actual, int columna_actual){
    int salida_fila = DIMENSION -1;
    int salida_columna = DIMENSION -1;
    bool resuelto = false;

    if (salida_fila == fila_actual && salida_columna == columna_actual) {
    return true;
    }else {
        int direcciones[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // defino direcciones en un array de array
        for (int direccion = 0; direccion < 4; direccion++) {
            int nueva_fila = fila_actual + direcciones[direccion][0];
            int nueva_columna = columna_actual + direcciones[direccion][1];
            if (nueva_fila >= 0 && nueva_fila < DIMENSION && nueva_columna >= 0 && nueva_columna < DIMENSION) {
                if (laberinto_tablero[nueva_fila][nueva_columna] != MUROS) {
                    if (visitados[nueva_fila][nueva_columna] == false){
                        visitados[nueva_fila][nueva_columna] = true;   
                        // guardo en una variable y llamamos a recursividad y chequeamos si retorna true la condicion y rompe el bucle  
                        resuelto = resolver_tablero(nueva_fila, nueva_columna);
                        if (resuelto) {
                          laberinto_tablero[nueva_fila][nueva_columna] = SOLUCION;
                          break;  
                        }
                    }
                }
            }
        }
    }
    return resuelto;
}