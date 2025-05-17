#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *curso;
    char buffer[100]; 
    int nrc;
    int longitud;

    curso = (char *)malloc(100 * sizeof(char));
    if (curso == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    printf("Ingrese el nombre del curso: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    longitud = strlen(buffer) + 1; 
    curso = (char *)realloc(curso, longitud * sizeof(char));
    if (curso == NULL) {
        printf("Error al redimensionar memoria.\n");
        return 1;
    }
    strcpy(curso, buffer); 

    printf("Ingrese el código NRC del curso: ");
    scanf("%d", &nrc);

    char nrcTexto[20];
    snprintf(nrcTexto, sizeof(nrcTexto), " - NRC: %d", nrc);

    int nuevaLongitud = strlen(curso) + strlen(nrcTexto) + 1;
    curso = (char *)realloc(curso, nuevaLongitud * sizeof(char));
    if (curso == NULL) {
        printf("Error al redimensionar memoria para NRC.\n");
        return 1;
    }

    strcat(curso, nrcTexto); 

    printf("Curso completo: %s\n", curso);

    free(curso);

    return 0;
}