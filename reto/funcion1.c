#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* leerArchivo() {
    char nombre[100];
    printf("reto.txt ");
    fgets(nombre, sizeof(nombre), stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    FILE *f = fopen("reto.txt", "r");
    if (!f) return NULL;

    fseek(f, 0, SEEK_END)
    long len = ftell(f)
    rewind(f);

    char *txt = malloc(len + 1)
    fread(txt, 1, len, f);
    txt[len] = '\0';
    fclose(f);
    return txt;
}
