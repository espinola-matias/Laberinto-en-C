# 🧩 Generador y Solucionador de Laberintos en C

Este proyecto implementa un generador y un solucionador de laberintos utilizando **búsqueda en profundidad (DFS)** y **backtracking**, todo desarrollado en lenguaje C.

El programa:

1. Inicializa un tablero de dimensiones fijas.
2. Genera un laberinto aleatorio utilizando DFS.
3. Muestra el laberinto generado.
4. Resuelve el laberinto desde la entrada hasta la salida.
5. Marca la solución encontrada.
6. Calcula y muestra el tiempo total de resolución.

---

## 🚀 Características principales

### ✔️ Generación de laberintos
- Utiliza un algoritmo DFS que cava caminos en saltos de 2 celdas.
- Mezcla aleatoriamente las direcciones para generar laberintos distintos en cada ejecución.
- Deja siempre un camino válido desde la entrada hasta la salida.

### ✔️ Resolución automática
- Implementación de un algoritmo DFS con backtracking.
- Marca el camino correcto con el símbolo `-`.
- Evita revisitar celdas mediante una matriz de control de visitados.

### ✔️ Medición de rendimiento
- Utiliza `clock()` para medir el tiempo real de ejecución del solucionador.

---

## 📌 Representación del tablero

El laberinto se representa mediante caracteres:

| Símbolo | Significado |
|--------|-------------|
| `#`     | Muro |
| `' '`   | Camino |
| `E`     | Entrada |
| `S`     | Salida |
| `-`     | Camino de solución |

La dimensión del tablero es configurable mediante:

```c
#define DIMENSION 11

## 🛠️ Requerimientos

Para ejecutar este proyecto necesitás:

1. **Compilador de C**  
   - GCC (Linux / Windows con MinGW)  
   - Clang (macOS / Linux)  

2. **Sistema operativo**  
   - Compatible con Windows, Linux o macOS.

3. **Terminal / Consola**  
   - Para compilar y ejecutar el programa.

## ▶️ Cómo compilar

Desde la terminal / consola, ubicándote en la carpeta del proyecto:

```bash
gcc main.c -o laberinto

## Ejecutarlo desde la misma terminal
´´´´bash
./laberinto      # Linux / macOS
laberinto.exe    # Windows