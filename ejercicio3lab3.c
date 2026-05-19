#include <stdio.h>

#define MAX_SENSORES 10

typedef enum { NORMAL, ALERTA, FALLO } EstadoSensor;

typedef struct {
    int id;
    float valor;
    EstadoSensor estado;
} Lectura;

EstadoSensor clasificar(float valor);
int contar_estado(Lectura s[], int n, EstadoSensor e);
int lectura_extrema(Lectura s[], int n);
void imprimir_estado(EstadoSensor estado);

int main(void) {
    Lectura sensores[MAX_SENSORES];
    int i;
    int indice_extremo;

    for (i = 0; i < MAX_SENSORES; i++) {
        printf("Ingrese el id del sensor %d: ", i + 1);
        scanf("%d", &sensores[i].id);

        printf("Ingrese el valor del sensor %d: ", i + 1);
        scanf("%f", &sensores[i].valor);

        sensores[i].estado = clasificar(sensores[i].valor);
    }

    printf("\nTabla de lecturas\n");
    printf("ID\tValor\tEstado\n");

    for (i = 0; i < MAX_SENSORES; i++) {
        printf("%d\t%.2f\t", sensores[i].id, sensores[i].valor);
        imprimir_estado(sensores[i].estado);
        printf("\n");
    }

    printf("\nConteo de estados\n");
    printf("NORMAL: %d\n", contar_estado(sensores, MAX_SENSORES, NORMAL));
    printf("ALERTA: %d\n", contar_estado(sensores, MAX_SENSORES, ALERTA));
    printf("FALLO: %d\n", contar_estado(sensores, MAX_SENSORES, FALLO));

    indice_extremo = lectura_extrema(sensores, MAX_SENSORES);

    printf("\nLectura extrema\n");
    printf("ID: %d\n", sensores[indice_extremo].id);
    printf("Valor: %.2f\n", sensores[indice_extremo].valor);

    return 0;
}

EstadoSensor clasificar(float valor) {
    if (valor >= 40.0 && valor <= 60.0) {
        return NORMAL;
    }

    if ((valor >= 20.0 && valor < 40.0) || (valor > 60.0 && valor <= 80.0)) {
        return ALERTA;
    }

    return FALLO;
}

int contar_estado(Lectura s[], int n, EstadoSensor e) {
    int i;
    int contador = 0;

    for (i = 0; i < n; i++) {
        if (s[i].estado == e) {
            contador++;
        }
    }

    return contador;
}

int lectura_extrema(Lectura s[], int n) {
    int i;
    int indice = 0;
    float distancia;
    float mayor_distancia;

    if (s[0].valor >= 50.0) {
        mayor_distancia = s[0].valor - 50.0;
    } else {
        mayor_distancia = 50.0 - s[0].valor;
    }

    for (i = 1; i < n; i++) {
        if (s[i].valor >= 50.0) {
            distancia = s[i].valor - 50.0;
        } else {
            distancia = 50.0 - s[i].valor;
        }

        if (distancia > mayor_distancia) {
            mayor_distancia = distancia;
            indice = i;
        }
    }

    return indice;
}

void imprimir_estado(EstadoSensor estado) {
    if (estado == NORMAL) {
        printf("NORMAL");
    } else if (estado == ALERTA) {
        printf("ALERTA");
    } else {
        printf("FALLO");
    }
}
