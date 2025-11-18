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