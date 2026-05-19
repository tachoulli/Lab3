#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4

/* que me diga cuantos unos hay en una fila */
int contar_unos_fila(int m[][SIZE], int fila);

/* lo mismo de arriba pero con una columna */
int contar_unos_columna(int m[][SIZE], int col);

/* que me verifiquesi a matriz es identidad */
int es_identidad(int m[][SIZE]);

/* que vea si hay una fila completa de unos */
int tiene_fila_completa(int m[][SIZE]);

/* lo mismo de arriba pero con una columna */
int tiene_columna_completa(int m[][SIZE]);

/* que me imprima una matriz */
void imprimir_matriz(int m[][SIZE]);

int main(void) {
    int m[SIZE][SIZE] = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    };

    int aleatoria[SIZE][SIZE];
    int i;
    int j;

    /* nicializa la semilla para generar valores aleatorios */
    srand(time(NULL));

    /*llena la matriz aleatoria con ceros y unos */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            aleatoria[i][j] = rand() % 2;
        }
    }

    printf("Matriz ingresada:\n");
    imprimir_matriz(m);

    printf("Es identidad: %s\n", es_identidad(m) ? "si" : "no");
    printf("Tiene fila completa de unos: %s\n", tiene_fila_completa(m) ? "si" : "no");
    printf("Tiene columna completa de unos: %s\n", tiene_columna_completa(m) ? "si" : "no");

    printf("\nMatriz aleatoria:\n");
    imprimir_matriz(aleatoria);

    printf("Es identidad: %s\n", es_identidad(aleatoria) ? "si" : "no");
    printf("Tiene fila completa de unos: %s\n", tiene_fila_completa(aleatoria) ? "si" : "no");
    printf("Tiene columna completa de unos: %s\n", tiene_columna_completa(aleatoria) ? "si" : "no");

    return 0;
}

    /* que me imprima todos los elementos de una matriz */
void imprimir_matriz(int m[][SIZE]) {
    int i;
    int j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

/* que me cuente la cantidad de unos que hay en una fila */
int contar_unos_fila(int m[][SIZE], int fila) {
    int j;
    int contador = 0;

    for (j = 0; j < SIZE; j++) {
        if (m[fila][j] == 1) {
            contador++;
        }
    }

    return contador;
}

/* que me cuente la cantidad de unos que hay en una columna */
int contar_unos_columna(int m[][SIZE], int col) {
    int i;
    int contador = 0;

    for (i = 0; i < SIZE; i++) {
        if (m[i][col] == 1) {
            contador++;
        }
    }

    return contador;
}

/* que me verifique si la matriz tiene unos en la diagonal y ceros fuera de ella */
int es_identidad(int m[][SIZE]) {
    int i;
    int j;

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (i == j && m[i][j] != 1) {
                return 0;
            }

            if (i != j && m[i][j] != 0) {
                return 0;
            }
        }
    }

    return 1;
}

/* que me revise si existe una fila con todos sus valores en uno */
int tiene_fila_completa(int m[][SIZE]) {
    int i;

    for (i = 0; i < SIZE; i++) {
        if (contar_unos_fila(m, i) == SIZE) {
            return 1;
        }
    }

    return 0;
}

/* lo mismo de arriba pero para una columna */
int tiene_columna_completa(int m[][SIZE]) {
    int j;

    for (j = 0; j < SIZE; j++) {
        if (contar_unos_columna(m, j) == SIZE) {
            return 1;
        }
    }

    return 0;
}
