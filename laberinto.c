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