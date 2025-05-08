#include <stdio.h>
#include <stdlib.h>

int main() {
    int letras;
    char *nombre_completo;

    printf("¿Cuántos caracteres tiene tu nombre completo (incluyendo espacios)? ");
    scanf("%d", &letras);

    getchar();

    nombre_completo = (char *)malloc((letras + 1) * sizeof(char));

    if (nombre_completo == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Ingresa tu nombre completo: ");
    for (int i = 0; i < letras; i++) {
        nombre_completo[i] = getchar();
    }
    nombre_completo[letras] = '\0';

    printf("¡Hola,bienvenido a la clase de programacion %s!\n", nombre_completo);

    free(nombre_completo);

    return 0;
}
