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