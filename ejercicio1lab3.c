#include <stdio.h>



/* que me calcule la base elevada al exponente */
int potencia(int base, int exp) {
    int resultado = 1;
    
    /* que multiplique la base las veces que el exponente lo diga */
    while (exp > 0) {
        resultado = resultado * base;
        exp = exp - 1;
    }

    return resultado;
}



/* que me retorne el 1 si el numero es par y  si es impar */
int es_par(int n) {
    if (n % 2 == 0) {
        return 1;
    }

    return 0;
}



int main(void) {
    int base;
    int exp;
    int resultado;

    do {
        printf("Ingrese la base diferente de cero: ");
        scanf("%d", &base);
    } while (base == 0);

    do {
        printf("Ingrese el exponente no negativo: ");
        scanf("%d", &exp);
    } while (exp < 0);

    resultado = potencia(base, exp);

    printf("%d^%d = %d\n", base, exp, resultado);

    if (es_par(resultado)) {
        printf("El resultado es par\n");
    } else {
        printf("El resultado es impar\n");
    }

    return 0;
}
